int __usercall CMS_dataFinal@<eax>(int a1@<ebx>, asn1_string_st *cms, bio_st *cmsbio)
{
  int result; // eax
  asn1_string_st **v4; // edi
  asn1_string_st *v5; // eax
  bio_st *type; // eax
  bio_st *v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // [esp-8h] [ebp-14h]
  unsigned __int8 *parg; // [esp+8h] [ebp-4h] BYREF

  result = (int)CMS_get0_content(a1, cms);
  v4 = (asn1_string_st **)result;
  if ( result )
  {
    v5 = *(asn1_string_st **)result;
    if ( v5 && (v5->flags & 0x20) != 0 )
    {
      type = BIO_find_type(cmsbio, 1025);
      v7 = type;
      if ( !type )
      {
        ERR_put_error(a1, 0x2Eu, 110, 105, ".\\crypto\\cms\\cms_lib.c", 172);
        return 0;
      }
      v10 = a1;
      v8 = BIO_ctrl(a1, type, 3, 0, &parg);
      BIO_set_flags(v7, 512);
      BIO_ctrl(v8, v7, 130, 0, 0);
      ASN1_STRING_set0(*v4, parg, v8);
      (*v4)->flags &= ~0x20u;
      a1 = v10;
    }
    v9 = (int)OBJ_obj2nid((const asn1_object_st *)cms->length);
    if ( v9 > 786 )
    {
LABEL_13:
      ERR_put_error(a1, 0x2Eu, 110, 156, ".\\crypto\\cms\\cms_lib.c", 200);
      return 0;
    }
    else if ( v9 == 786 )
    {
      return 1;
    }
    else
    {
      switch ( v9 )
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
