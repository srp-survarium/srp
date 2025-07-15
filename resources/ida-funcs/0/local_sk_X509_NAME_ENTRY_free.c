// attributes: thunk
void __cdecl local_sk_X509_NAME_ENTRY_free(stack_st_X509_NAME_ENTRY *ne)
{
  sk_free(&ne->stack);
}
