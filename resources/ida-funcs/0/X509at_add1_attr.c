stack_st_X509_ATTRIBUTE *__cdecl X509at_add1_attr(stack_st_X509_ATTRIBUTE **x, x509_attributes_st *attr)
{
  x509_attributes_st *v2; // edi
  stack_st_X509_ATTRIBUTE *v4; // esi
  char *v5; // eax

  v2 = 0;
  if ( !x )
  {
    ERR_put_error(0, 0xBu, 135, 67, ".\\crypto\\x509\\x509_att.c", 129);
    return 0;
  }
  v4 = *x;
  if ( !*x )
  {
    v4 = (stack_st_X509_ATTRIBUTE *)sk_new_null();
    if ( !v4 )
      goto err_137;
  }
  v5 = (char *)X509_ATTRIBUTE_dup((int)x, attr);
  v2 = (x509_attributes_st *)v5;
  if ( !v5 )
  {
LABEL_9:
    if ( v4 )
      sk_free(&v4->stack);
    return 0;
  }
  if ( !sk_push(&v4->stack, v5) )
  {
err_137:
    ERR_put_error((int)x, 0xBu, 135, 65, ".\\crypto\\x509\\x509_att.c", 149);
    if ( v2 )
      X509_ATTRIBUTE_free(v2);
    goto LABEL_9;
  }
  if ( !*x )
    *x = v4;
  return v4;
}
