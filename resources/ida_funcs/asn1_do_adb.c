const ASN1_TEMPLATE_st *__cdecl asn1_do_adb(struct ASN1_VALUE_st **pval, const ASN1_TEMPLATE_st *tt, int nullerr)
{
  const ASN1_TEMPLATE_st *result; // eax
  const ASN1_ITEM_st *v4; // edi
  const asn1_object_st **v5; // eax
  int v6; // eax
  int funcs; // esi
  _DWORD *tcount; // edx
  int v9; // ecx

  if ( (tt->flags & 0x300) == 0 )
    return tt;
  v4 = tt->item();
  v5 = (const asn1_object_st **)((char *)*pval + v4->utype);
  if ( !v5 )
  {
    result = (const ASN1_TEMPLATE_st *)v4->sname;
    if ( result )
      return result;
err_86:
    if ( nullerr )
      ERR_put_error(0xDu, 110, 164, ".\\crypto\\asn1\\tasn_utl.c", 277);
    return 0;
  }
  if ( (tt->flags & 0x100) != 0 )
    v6 = OBJ_obj2nid(*v5);
  else
    v6 = ASN1_INTEGER_get((const asn1_string_st *)*v5);
  funcs = (int)v4->funcs;
  tcount = (_DWORD *)v4->tcount;
  v9 = 0;
  if ( funcs <= 0 )
  {
LABEL_12:
    result = (const ASN1_TEMPLATE_st *)v4->size;
    if ( result )
      return result;
    goto err_86;
  }
  while ( *tcount != v6 )
  {
    ++v9;
    tcount += 6;
    if ( v9 >= funcs )
      goto LABEL_12;
  }
  return (const ASN1_TEMPLATE_st *)(tcount + 1);
}
