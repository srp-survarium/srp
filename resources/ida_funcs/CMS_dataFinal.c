int __cdecl CMS_dataFinal(asn1_string_st *cms, bio_st *cmsbio)
{
  int result; // eax
  asn1_string_st **v3; // edi
  asn1_string_st *v4; // eax
  bio_st *type; // eax
  bio_st *v6; // esi
  int v7; // ebx
  int v8; // eax
  unsigned __int8 *parg; // [esp+8h] [ebp-4h] BYREF

  result = (int)CMS_get0_content(cms);
  v3 = (asn1_string_st **)result;
  if ( result )
  {
    v4 = *(asn1_string_st **)result;
    if ( v4 && (v4->flags & 0x20) != 0 )
    {
      type = BIO_find_type(cmsbio, 1025);
      v6 = type;
      if ( !type )
      {
        ERR_put_error(0x2Eu, 110, 105, ".\\crypto\\cms\\cms_lib.c", 172);
        return 0;
      }
      v7 = BIO_ctrl(type, 3, 0, &parg);
      BIO_set_flags(v6, 512);
      BIO_ctrl(v6, 130, 0, 0);
      ASN1_STRING_set0(*v3, parg, v7);
      (*v3)->flags &= ~0x20u;
    }
    v8 = OBJ_obj2nid((const asn1_object_st *)cms->length);
    if ( v8 > 786 )
    {
LABEL_13:
      ERR_put_error(0x2Eu, 110, 156, ".\\crypto\\cms\\cms_lib.c", 200);
      return 0;
    }
    else if ( v8 == 786 )
    {
      return 1;
    }
    else
    {
      switch ( v8 )
      {
        case 21:
        case 23:
        case 26:
          return 1;
        case 22:
          result = cms_SignedData_final((CMS_ContentInfo_st *)cms, cmsbio);
          break;
        case 25:
          result = cms_DigestedData_do_final((CMS_ContentInfo_st *)cms, cmsbio, 0);
          break;
        default:
          goto LABEL_13;
      }
    }
  }
  return result;
}
