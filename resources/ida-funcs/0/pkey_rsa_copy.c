int __usercall pkey_rsa_copy@<eax>(int a1@<ebx>, evp_pkey_ctx_st *dst, evp_pkey_ctx_st *src)
{
  int result; // eax
  _DWORD *data; // esi
  void *v5; // edi

  result = pkey_rsa_init(dst);
  if ( result )
  {
    data = dst->data;
    v5 = src->data;
    *data = *(_DWORD *)v5;
    if ( !*((_DWORD *)v5 + 1) || (result = (int)BN_dup(a1, *((const bignum_st **)v5 + 1)), (data[1] = result) != 0) )
    {
      data[4] = *((_DWORD *)v5 + 4);
      data[5] = *((_DWORD *)v5 + 5);
      return 1;
    }
  }
  return result;
}
