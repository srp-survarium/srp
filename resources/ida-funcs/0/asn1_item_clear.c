void __usercall asn1_item_clear(struct ASN1_VALUE_st **pval@<esi>, const ASN1_ITEM_st *it)
{
  const ASN1_ITEM_st *v2; // eax
  unsigned int itype; // ecx
  const ASN1_TEMPLATE_st *templates; // ecx
  _DWORD *funcs; // ecx
  void (__cdecl *v6)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *); // ecx

  v2 = it;
  itype = it->itype;
  while ( 2 )
  {
    switch ( itype )
    {
      case 0u:
        templates = v2->templates;
        if ( !templates )
          goto LABEL_10;
        if ( (templates->flags & 0x306) != 0 )
          goto $LN1_6;
        v2 = templates->item();
        itype = v2->itype;
        if ( itype <= 6 )
          continue;
        break;
      case 1u:
      case 2u:
      case 3u:
      case 6u:
        goto $LN1_6;
      case 4u:
        funcs = v2->funcs;
        if ( funcs && (v6 = (void (__cdecl *)(struct ASN1_VALUE_st **, const ASN1_ITEM_st *))funcs[3]) != 0 )
          v6(pval, v2);
        else
$LN1_6:
          *pval = 0;
        break;
      case 5u:
LABEL_10:
        asn1_primitive_clear(pval, v2);
        break;
      default:
        return;
    }
    break;
  }
}
