void __cdecl local_sk_X509_NAME_ENTRY_pop_free(stack_st_X509_NAME_ENTRY *ne)
{
  sk_pop_free(&ne->stack, (void (__cdecl *)(void *))X509_NAME_ENTRY_free);
}
