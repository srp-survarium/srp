void __cdecl def_cleanup_cb(stack_st **str)
{
  sk_pop_free(str[1], (void (__cdecl *)(void *))policy_node_free);
  CRYPTO_free(str);
}
