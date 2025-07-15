int __cdecl pk7_cb(int operation, pkcs7_st **pval, const ASN1_ITEM_st *it, void *exarg)
{
  bio_st *v4; // eax
  int result; // eax

  switch ( operation )
  {
    case 10:
      if ( PKCS7_stream((unsigned __int8 ***)exarg + 2, *pval) <= 0 )
        goto LABEL_4;
      goto $LN5_37;
    case 11:
    case 13:
      if ( PKCS7_dataFinal(*pval, *((bio_st **)exarg + 1)) > 0 )
        goto LABEL_6;
      goto LABEL_4;
    case 12:
$LN5_37:
      v4 = PKCS7_dataInit(*pval, *(bio_st **)exarg);
      *((_DWORD *)exarg + 1) = v4;
      if ( v4 )
        goto LABEL_6;
LABEL_4:
      result = 0;
      break;
    default:
LABEL_6:
      result = 1;
      break;
  }
  return result;
}
