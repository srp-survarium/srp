void __cdecl by_dir_entry_free(lookup_dir_entry_st *ent)
{
  stack_st_BY_DIR_HASH *hashes; // eax

  if ( ent->dir )
    CRYPTO_free(ent->dir);
  hashes = ent->hashes;
  if ( hashes )
    sk_pop_free(&hashes->stack, (void (__cdecl *)(void *))policy_node_free);
  CRYPTO_free(ent);
}
