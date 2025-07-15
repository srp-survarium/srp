int __usercall add_attribute@<eax>(stack_st_X509_ATTRIBUTE **sk@<ebx>, void *nid, int atrtype, int value)
{
  stack_st_X509_ATTRIBUTE *v4; // eax
  int v6; // esi
  x509_attributes_st *v7; // edi
  char *v8; // eax
  x509_attributes_st *v9; // esi
  x509_attributes_st *v10; // eax
  x509_attributes_st *v11; // edi

  if ( !*sk )
  {
    v4 = (stack_st_X509_ATTRIBUTE *)sk_new_null();
    *sk = v4;
    if ( !v4 )
      return 0;
new_attrib:
    v8 = (char *)X509_ATTRIBUTE_create((int)sk, (unsigned int)nid, atrtype, value);
    v9 = (x509_attributes_st *)v8;
    if ( !v8 )
      return 0;
    if ( !sk_push(&(*sk)->stack, v8) )
    {
      X509_ATTRIBUTE_free(v9);
      return 0;
    }
    return 1;
  }
  v6 = 0;
  if ( sk_num(&(*sk)->stack) <= 0 )
    goto new_attrib;
  while ( 1 )
  {
    v7 = (x509_attributes_st *)sk_value(&(*sk)->stack, v6);
    if ( OBJ_obj2nid(v7->object) == nid )
      break;
    if ( ++v6 >= sk_num(&(*sk)->stack) )
      goto new_attrib;
  }
  X509_ATTRIBUTE_free(v7);
  v10 = X509_ATTRIBUTE_create((int)sk, (unsigned int)nid, atrtype, value);
  v11 = v10;
  if ( !v10 )
    return 0;
  if ( !sk_set(&(*sk)->stack, v6, v10) )
  {
    X509_ATTRIBUTE_free(v11);
    return 0;
  }
  return 1;
}
