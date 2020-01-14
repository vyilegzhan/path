#include "header.h"
#define DEBUG 

int main(int argc, char *argv[]) {
    t_isls isls = mx_create_isls(argc, argv);
    int routes_c = (isls.count * (isls.count - 1)) / 2;
    t_list **shrt_path = (t_list**)malloc(sizeof(t_list*) * routes_c);
    t_used_num_isl used_and_nums_isl;

    used_and_nums_isl.used_isl = (int*)malloc(4 * isls.count);
    used_and_nums_isl.isl_nums = (int*)malloc(4 * isls.count);
    for (int i = 0; i < isls.count; i++)
        used_and_nums_isl.isl_nums[i] = i;
    for (int i = 0; i < isls.count; i++)
        used_and_nums_isl.used_isl[i] = -1;
    for (int i = 0; i < routes_c; i++)
        shrt_path[i] = NULL;
    mx_find_in_depth(shrt_path, isls, used_and_nums_isl.used_isl,
    used_and_nums_isl.isl_nums);
    mx_print_pathes(shrt_path, isls.names, isls.grid, routes_c);
}
