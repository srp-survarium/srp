void __cdecl exnode_free(X509_POLICY_NODE_st *node)
{
  if ( node->data )
  {
    if ( (node->data->flags & 8) != 0 )
      CRYPTO_free(node);
  }
}
