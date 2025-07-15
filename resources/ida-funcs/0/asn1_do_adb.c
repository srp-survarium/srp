const ASN1_TEMPLATE_st *__usercall asn1_do_adb@<eax>(
        int a1@<ebx>,
        struct ASN1_VALUE_st **pval,
        const ASN1_TEMPLATE_st *tt,
        int nullerr)
{
  const ASN1_TEMPLATE_st *result; // eax
  const ASN1_ITEM_st *v5; // edi
  const asn1_object_st **v6; // eax
  void *v7; // eax
  int funcs; // esi
  void **tcount; // edx
  int v10; // ecx

  if ( (tt->flags & 0x300) == 0 )
    return tt;
  v5 = tt->item();
  v6 = (const asn1_object_st **)((char *)*pval + v5->utype);
  if ( !v6 )
  {
    result = (const ASN1_TEMPLATE_st *)v5->sname;
    if ( result )
      return result;
err_88:
    if ( nullerr )
      ERR_put_error(a1, 0xDu, 110, 164, ".\\crypto\\asn1\\tasn_utl.c", 277);
    return 0;
  }
  if ( (tt->flags & 0x100) != 0 )
    v7 = OBJ_obj2nid(*v6);
  else
    v7 = (void *)ASN1_INTEGER_get((const asn1_string_st *)*v6);
  funcs = (int)v5->funcs;
  tcount = (void **)v5->tcount;
  v10 = 0;
  if ( funcs <= 0 )
  {
LABEL_12:
    result = (const ASN1_TEMPLATE_st *)v5->size;
    if ( result )
      return result;
    goto err_88;
  }
  while ( *tcount != v7 )
  {
    ++v10;
    tcount += 6;
    if ( v10 >= funcs )
      goto LABEL_12;
  }
  return (const ASN1_TEMPLATE_st *)(tcount + 1);
}
