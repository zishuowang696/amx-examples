#include <stdio.h>
#include <amxc/amxc.h>

/* 1) 双向链表 */
typedef struct { amxc_llist_it_t it; int value; } item_t;
static void ex_llist(void) {
    amxc_llist_t list;
    amxc_llist_init(&list);
    item_t a = { .value = 1 }, b = { .value = 2 };
    amxc_llist_append(&list, &a.it);
    amxc_llist_append(&list, &b.it);
    printf("[llist] ");
    amxc_llist_for_each(it, (&list)) {
        item_t* p = amxc_llist_it_get_data(it, item_t, it);
        printf("%d ", p->value);
    }
    printf("\n");
    amxc_llist_clean(&list, NULL);
}

/* 2) 哈希表 */
typedef struct { amxc_htable_it_t it; int value; } entry_t;
static void ex_htable(void) {
    amxc_htable_t ht;
    amxc_htable_init(&ht, 10);
    entry_t e = { .value = 42 };
    amxc_htable_insert(&ht, "answer", &e.it);
    amxc_htable_it_t* it = amxc_htable_get(&ht, "answer");
    entry_t* p = amxc_htable_it_get_data(it, entry_t, it);
    printf("[htable] answer=%d\n", p->value);
    amxc_htable_clean(&ht, NULL);
}

/* 3) 动态字符串 */
static void ex_string(void) {
    amxc_string_t s;
    amxc_string_init(&s, 0);
    amxc_string_set(&s, "hello");
    amxc_string_appendf(&s, " %s #%d", "world", 42);
    printf("[string] %s\n", amxc_string_get(&s, 0));
    amxc_string_clean(&s);
}

/* 4) 通用类型 Variant */
static void ex_variant(void) {
    amxc_var_t v;
    amxc_var_init(&v);
    amxc_var_set(int32_t, &v, 42);
    printf("[variant] int32=%d\n", amxc_var_get_int32_t(&v));
    amxc_var_set(cstring_t, &v, "hi");
    printf("[variant] cstring=%s\n", amxc_var_get_const_cstring_t(&v));
    amxc_var_clean(&v);
}

/* 5) 动态数组 */
static void ex_array(void) {
    amxc_array_t arr;
    amxc_array_init(&arr, 0);
    amxc_array_append_data(&arr, (void*)"a");
    amxc_array_append_data(&arr, (void*)"b");
    printf("[array] %s %s\n", (char*)amxc_array_get_data_at(&arr, 0), (char*)amxc_array_get_data_at(&arr, 1));
    amxc_array_clean(&arr, NULL);
}

/* 6) 字符串集合（flags） */
static void ex_set(void) {
    amxc_set_t set;
    amxc_set_init(&set, false);
    amxc_set_add_flag(&set, "wifi");
    amxc_set_add_flag(&set, "wan");
    printf("[set] wifi=%d lan=%d\n", amxc_set_has_flag(&set, "wifi"), amxc_set_has_flag(&set, "lan"));
    amxc_set_clean(&set);
}

int main(void) {
    ex_llist(); ex_htable(); ex_string(); ex_variant(); ex_array(); ex_set();
    return 0;
}
