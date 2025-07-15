void EVP_PBE_cleanup()
{
  sk_pop_free(&pbe_algs->stack, (void (__cdecl *)(void *))policy_node_free);
  pbe_algs = 0;
}
