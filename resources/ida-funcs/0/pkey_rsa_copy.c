int __cdecl pkey_rsa_copy(evp_pkey_ctx_st *dst, evp_pkey_ctx_st *src)
{
  int result; // eax
  _DWORD *data; // esi
  void *v4; // edi

  result = pkey_rsa_init(dst);
  if ( result )
  {
    data = dst->data;
    v4 = src->data;
    *data = *(_DWORD *)v4;
    if ( !*((_DWORD *)v4 + 1) || (result = (int)BN_dup(*((const bignum_st **)v4 + 1)), (data[1] = result) != 0) )
    {
      data[4] = *((_DWORD *)v4 + 4);
      data[5] = *((_DWORD *)v4 + 5);
      return 1;
    }
  }
  return result;
}
