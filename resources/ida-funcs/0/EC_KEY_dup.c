ec_key_st *__usercall EC_KEY_dup@<eax>(const ec_key_st *a1@<ebx>, const ec_key_st *ec_key)
{
  ec_key_st *v2; // esi

  v2 = EC_KEY_new((int)a1);
  if ( !v2 )
    return 0;
  if ( !EC_KEY_copy(a1, v2, ec_key) )
  {
    EC_KEY_free(v2);
    return 0;
  }
  return v2;
}
