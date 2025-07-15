bignum_st *__cdecl dh_copy_parameters(evp_pkey_st *to, const evp_pkey_st *from)
{
  bignum_st *result; // eax
  bignum_st *v3; // edi
  char *ptr; // edx
  bignum_st *v5; // edi

  result = BN_dup(*((const bignum_st **)from->pkey.ptr + 2));
  v3 = result;
  if ( result )
  {
    ptr = to->pkey.ptr;
    if ( *((_DWORD *)ptr + 2) )
      BN_free(*((bignum_st **)ptr + 2));
    *((_DWORD *)to->pkey.ptr + 2) = v3;
    result = BN_dup(*((const bignum_st **)from->pkey.ptr + 3));
    v5 = result;
    if ( result )
    {
      if ( *((_DWORD *)to->pkey.ptr + 3) )
        BN_free(*((bignum_st **)to->pkey.ptr + 3));
      *((_DWORD *)to->pkey.ptr + 3) = v5;
      return (bignum_st *)1;
    }
  }
  return result;
}
