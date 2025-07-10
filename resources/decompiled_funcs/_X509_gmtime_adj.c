asn1_string_st *__cdecl X509_gmtime_adj(asn1_string_st *s, int adj)
{
  return X509_time_adj_ex(s, 0, adj, 0);
}
