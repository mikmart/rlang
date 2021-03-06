#include <rlang.h>

sexp* rlang_r_string(sexp* str) {
  return STRING_ELT(str, 0);
}


// cnd.c

sexp* rlang_test_r_warn(sexp* x) {
  r_warn(CHAR(STRING_ELT(x, 0)));
  return r_null;
}

sexp* rlang_test_warn_deprecated_once(sexp* id, sexp* msg) {
  r_warn_deprecated_once(r_c_string(id), r_c_string(msg));
  return r_null;
}


// env.c

sexp* rlang_test_base_ns_get(sexp* name) {
  return r_base_ns_get(r_c_string(name));
}


// parse.c

sexp* rlang_test_parse(sexp* str) {
  return r_parse(r_c_string(str));
}
sexp* rlang_test_parse_eval(sexp* str, sexp* env) {
  return r_parse_eval(r_c_string(str), env);
}

// node.c

sexp* rlang_test_node_list_clone_until(sexp* node, sexp* sentinel) {
  sexp* sentinel_out;
  node = KEEP(r_node_list_clone_until(node, sentinel, &sentinel_out));

  sexp* out = r_new_vector(r_type_list, 2);
  r_list_poke(out, 0, node);
  r_list_poke(out, 1, sentinel_out);

  FREE(1);
  return out;
}


// sym.c

sexp* rlang_test_is_special_op_sym(sexp* x) {
  return Rf_ScalarLogical(r_is_special_op_sym(x));
}


// squash.c

bool rlang_is_clevel_spliceable(sexp* x) {
  return Rf_inherits(x, "foo");
}


// stack.c

sexp* rlang_test_sys_call(sexp* n) {
  return r_sys_call(r_c_int(n), NULL);
}
sexp* rlang_test_sys_frame(sexp* n) {
  return r_sys_frame(r_c_int(n), NULL);
}
