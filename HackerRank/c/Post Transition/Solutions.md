#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 11

struct package {
    char* id;
    int weight;
};

struct post_office {
    int min_weight;
    int max_weight;
    struct package* packages;
    int packages_count;
};

struct town {
    char* name;
    struct post_office* offices;
    int offices_count;
};

void print_all_packages(struct town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_packages(struct town* source, int source_office_index, struct town* target, int target_office_index) {
    struct post_office *src = &source->offices[source_office_index];
    struct post_office *tgt = &target->offices[target_office_index];

    // Temporary storage for filtering
    struct package *accepted = malloc(sizeof(struct package) * (src->packages_count + tgt->packages_count));
    struct package *rejected = malloc(sizeof(struct package) * src->packages_count);
    
    int acc_count = 0;
    int rej_count = 0;

    // Keep existing packages in target first
    for (int i = 0; i < tgt->packages_count; i++) {
        accepted[acc_count++] = tgt->packages[i];
    }

    // Filter source packages
    for (int i = 0; i < src->packages_count; i++) {
        int w = src->packages[i].weight;
        if (w >= tgt->min_weight && w <= tgt->max_weight) {
            accepted[acc_count++] = src->packages[i];
        } else {
            rejected[rej_count++] = src->packages[i];
        }
    }

    // Update target office
    free(tgt->packages);
    tgt->packages = malloc(sizeof(struct package) * acc_count);
    for(int i=0; i<acc_count; i++) tgt->packages[i] = accepted[i];
    tgt->packages_count = acc_count;

    // Update source office
    free(src->packages);
    src->packages = malloc(sizeof(struct package) * rej_count);
    for (int i = 0; i < rej_count; i++) {
        src->packages[i] = rejected[i];
    }
    src->packages_count = rej_count;

    free(accepted);
    free(rejected);
}

struct town town_with_most_packages(struct town* towns, int towns_count) {
    int max_p = -1;
    int index = 0;
    for (int i = 0; i < towns_count; i++) {
        int current_p = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            current_p += towns[i].offices[j].packages_count;
        }
        if (current_p > max_p) {
            max_p = current_p;
            index = i;
        }
    }
    return towns[index];
}

struct town* find_town(struct town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) return &towns[i];
    }
    return NULL;
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);
    struct town* towns = malloc(sizeof(struct town) * towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(struct post_office) * towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d %d %d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(struct package) * towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);
    while (queries--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char name[MAX_STRING_LENGTH];
            scanf("%s", name);
            struct town* t = find_town(towns, towns_count, name);
            print_all_packages(*t);
        } else if (type == 2) {
            char source_name[MAX_STRING_LENGTH], target_name[MAX_STRING_LENGTH];
            int source_index, target_index;
            scanf("%s %d %s %d", source_name, &source_index, target_name, &target_index);
            struct town* source = find_town(towns, towns_count, source_name);
            struct town* target = find_town(towns, towns_count, target_name);
            send_all_packages(source, source_index, target, target_index);
        } else if (type == 3) {
            struct town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }
    return 0;
}
