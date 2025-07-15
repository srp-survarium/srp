int __cdecl x509_name_ex_new(stack_st ***val)
{
  stack_st **v1; // esi
  stack_st *v2; // eax
  buf_mem_st *v3; // eax
  int result; // eax

  v1 = (stack_st **)CRYPTO_malloc(20, ".\\crypto\\asn1\\x_name.c", 135);
  if ( v1 && (v2 = sk_new_null(), (*v1 = v2) != 0) && (v3 = BUF_MEM_new(), (v1[2] = (stack_st *)v3) != 0) )
  {
    result = 1;
    v1[3] = 0;
    v1[4] = 0;
    v1[1] = (stack_st *)1;
    *val = v1;
  }
  else
  {
    ERR_put_error(0xDu, 171, 65, ".\\crypto\\asn1\\x_name.c", 147);
    if ( v1 )
    {
      if ( *v1 )
        sk_free(*v1);
      CRYPTO_free(v1);
    }
    return 0;
  }
  return result;
}
