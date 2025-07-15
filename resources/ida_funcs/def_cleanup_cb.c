void __cdecl def_cleanup_cb(stack_st **a_void)
{
  sk_pop_free(a_void[1], (void (__cdecl *)(void *))policy_node_free);
  CRYPTO_free(a_void);
}
