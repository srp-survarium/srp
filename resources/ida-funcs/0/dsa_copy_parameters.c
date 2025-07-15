int __cdecl dsa_copy_parameters(evp_pkey_st *to, const evp_pkey_st *from)
{
  int result; // eax
  int v3; // edi
  char *ptr; // edx
  bignum_st *v5; // edi
  bignum_st *v6; // edi
  char *v7; // ecx

  result = (int)BN_dup(*((const bignum_st **)from->pkey.ptr + 3));
  v3 = result;
  if ( result )
  {
    ptr = to->pkey.ptr;
    if ( *((_DWORD *)ptr + 3) )
      BN_free(*((bignum_st **)ptr + 3));
    *((_DWORD *)to->pkey.ptr + 3) = v3;
    v5 = BN_dup(*((const bignum_st **)from->pkey.ptr + 4));
    if ( !v5 )
      return 0;
    if ( *((_DWORD *)to->pkey.ptr + 4) )
      BN_free(*((bignum_st **)to->pkey.ptr + 4));
    *((_DWORD *)to->pkey.ptr + 4) = v5;
    v6 = BN_dup(*((const bignum_st **)from->pkey.ptr + 5));
    if ( v6 )
    {
      v7 = to->pkey.ptr;
      if ( *((_DWORD *)v7 + 5) )
        BN_free(*((bignum_st **)v7 + 5));
      *((_DWORD *)to->pkey.ptr + 5) = v6;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
