int __usercall x509_name_ex_new@<eax>(int a1@<ebx>, struct ASN1_VALUE_st **val)
{
  struct ASN1_VALUE_st *v2; // esi
  stack_st *v3; // eax
  buf_mem_st *v4; // eax
  int result; // eax

  v2 = (struct ASN1_VALUE_st *)CRYPTO_malloc(20, ".\\crypto\\asn1\\x_name.c", 135);
  if ( v2 && (v3 = sk_new_null(), (*(_DWORD *)v2 = v3) != 0) && (v4 = BUF_MEM_new(a1), (*((_DWORD *)v2 + 2) = v4) != 0) )
  {
    result = 1;
    *((_DWORD *)v2 + 3) = 0;
    *((_DWORD *)v2 + 4) = 0;
    *((_DWORD *)v2 + 1) = 1;
    *val = v2;
  }
  else
  {
    ERR_put_error(a1, 0xDu, 171, 65, ".\\crypto\\asn1\\x_name.c", 147);
    if ( v2 )
    {
      if ( *(_DWORD *)v2 )
        sk_free(*(stack_st **)v2);
      CRYPTO_free(v2);
    }
    return 0;
  }
  return result;
}
