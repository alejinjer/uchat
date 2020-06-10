#include <stdio.h>
#include "uchat.h"

int main() {
   sqlite3 *db = mx_opendb("test.db");

   mx_add_user(db, "admin1", "privet1111");
   mx_add_user(db, "adm2", "poka2");
   mx_add_user(db, "adm3", "admin3333");
   
   mx_print_db(db, "USER");
   mx_printstr("===============================\n\n");
   int i = mx_get_user_id_by_login(db, "adm2");
   mx_printint(i);
   // mx_print_db(db, "USER");
   mx_closedb(db);
   return 0;
   // // t_user *usr = mx_get_usertable(db);

   // // printf("%d \t %s \t %s \n", usr->user_id, usr->user_login, usr->user_pass);
   // // mx_printstr("\n");

   // // t_user *next = mx_get_user_by_login(db, "log");

   // mx_print_db(db, "USER");
   // // printf("%d \t %s \t %s \n", next->user_id, next->user_login, next->user_pass);
   // mx_printstr("===============================deleted adm2 and del admin1\n\n");

   // mx_delete_user_by_login(db, "adm2");
   // mx_print_db(db, "USER");

   // mx_delete_user_by_id(db, 1);
   // mx_printstr("===============================\n\n");
   
   // mx_print_db(db, "USER");

   mx_printstr("=============================== GROUP_MEMBER TABLE\n\n");
   mx_add_group_member(db, 1, 123);
   mx_add_group_member(db, 2, 222);
   mx_add_group_member(db, 3, 333333);

   mx_print_db(db, "GROUP_MEMBERS");

   // mx_printstr("=============================== GROUP_MEMBER TABLE\n\n");
   mx_delete_by_gr_mem_id(db, 2);
   mx_print_db(db, "GROUP_MEMBERS");
   mx_update_gr_members(db, 3, 321, 3213);
   mx_print_db(db, "GROUP_MEMBERS");

   // mx_printstr("=============================== GROUP_MEMBER TABLE add 1 mem and dell 2-3 \n\n");
   // mx_add_dialog(db, 2, 3);
   // mx_add_dialog(db, 1, 3);
   // mx_add_group_member(db, 1234, 1);
   // mx_add_group(db, 123);
  
   mx_closedb(db);

}

