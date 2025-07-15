int __cdecl cms_cb(int operation, asn1_string_st **pval, const ASN1_ITEM_st *it, void *exarg)
{
  asn1_string_st *v4; // edi
  bio_st *v5; // eax
  int result; // eax

  if ( !pval )
    return 1;
  v4 = *pval;
  switch ( operation )
  {
    case 10:
      if ( CMS_stream((unsigned __int8 ***)exarg + 2, v4) <= 0 )
        goto LABEL_5;
      goto $LN5_49;
    case 11:
    case 13:
      if ( CMS_dataFinal(v4, *((bio_st **)exarg + 1)) > 0 )
        goto LABEL_7;
      goto LABEL_5;
    case 12:
$LN5_49:
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
