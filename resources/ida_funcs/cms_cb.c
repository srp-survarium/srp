int __cdecl cms_cb(int operation, struct ASN1_VALUE_st **pval, const ASN1_ITEM_st *it, void *exarg)
{
  CMS_ContentInfo_st *v4; // edi
  bio_st *v5; // eax
  int result; // eax

  if ( !pval )
    return 1;
  v4 = (CMS_ContentInfo_st *)*pval;
  switch ( operation )
  {
    case 10:
      if ( CMS_stream((unsigned __int8 ***)exarg + 2, v4) <= 0 )
        goto LABEL_5;
      goto $LN5_40;
    case 11:
    case 13:
      if ( CMS_dataFinal(v4, *((bio_st **)exarg + 1)) > 0 )
        goto LABEL_7;
      goto LABEL_5;
    case 12:
$LN5_40:
      v5 = CMS_dataInit(v4, *(bio_st **)exarg);
      *((_DWORD *)exarg + 1) = v5;
      if ( v5 )
        goto LABEL_7;
LABEL_5:
      result = 0;
      break;
    default:
LABEL_7:
      result = 1;
      break;
  }
  return result;
}
