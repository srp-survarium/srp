int __cdecl trust_1oid(x509_trust_st *trust, x509_st *x)
{
  if ( x->aux )
    return obj_trust(trust->arg1, x);
  else
    return 3;
}
