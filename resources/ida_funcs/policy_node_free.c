// attributes: thunk
void __cdecl policy_node_free(X509_POLICY_NODE_st *node)
{
  CRYPTO_free(node);
}
