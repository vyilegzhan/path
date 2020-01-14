#include "header.h"
#define DEBUG 

static void init_used_isl_arr(int *arr, int len, int isl_index) {
    for (int i = 0; i < len; i++)
        if (arr[i] < 0)
            arr[i] = 0;
    arr[isl_index] = 1;
}

static int select_isl(int *used_isl, int n) {
    if (!n)
        return -1;
    for (int i = 0; i < n; i++)
        if (!used_isl[i])
            return i;
    return -1;
}

static void add_isls(t_isls *isls, t_cur_route *cur_route,
int *used_isl, int *isl_nums) {
    while((cur_route->j = select_isl(used_isl + cur_route->pr_isl + 1,
    isls->count - cur_route->pr_isl - 1)) >= 0) {
        cur_route->j += cur_route->pr_isl + 1;
        while (isls->grid[cur_route->i][cur_route->j] < 0
        || used_isl[cur_route->j])
            if (++(cur_route->j) == isls->count)
                break;
        if (cur_route->j == isls->count) {
            cur_route->fl = 1;
            break;
        }
        mx_push_front(&(cur_route->list), &(isl_nums[cur_route->j]));
        cur_route->len += 1;
        cur_route->i = *((int*)((cur_route->list)->data));
        used_isl[cur_route->i] = 1;
        cur_route->pr_isl = -1;
    }
}

void mx_find_in_depth(t_list **shrt_path, t_isls isls,
int *used_isl, int *isl_nums) {
    for (int i = 0; i < isls.count - 1; i++) {
        t_cur_route cur_r = mx_create_cur_route(i, isl_nums);
        init_used_isl_arr(used_isl, isls.count, i);
        while(cur_r.list) {
            add_isls(&isls, &cur_r, used_isl, isl_nums);
            while((cur_r.j = select_isl(used_isl + (cur_r.pr_isl + 1),
            isls.count - cur_r.pr_isl - 1)) < 0 || cur_r.fl) {
                cur_r.j += cur_r.pr_isl + 1;
                cur_r.fl = 0;
                mx_save_route(cur_r, shrt_path, i, isls);
                used_isl[cur_r.i] = 0;
                cur_r.pr_isl = cur_r.i;
                mx_pop_front(&cur_r.list);
                if (cur_r.list)
                    cur_r.i = *((int*)(cur_r.list->data));
                cur_r.len -= 1;
            }
        }
    }
}

