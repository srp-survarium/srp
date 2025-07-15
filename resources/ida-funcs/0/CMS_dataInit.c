bio_st *__cdecl CMS_dataInit(asn1_string_st *cms, bio_st *icont)
{
  bio_st *v2; // edi
  bio_st *result; // eax
  bio_st *inited; // eax

  if ( icont )
    v2 = icont;
  else
    v2 = cms_content_bio(0, cms);
  if ( v2 )
  {
    switch ( (unsigned int)OBJ_obj2nid((const asn1_object_st *)cms->length) )
    {
      case 0x15u:
        return v2;
      case 0x16u:
        inited = cms_SignedData_init_bio((CMS_ContentInfo_st *)cms);
        goto LABEL_12;
      case 0x17u:
        inited = cms_EnvelopedData_init_bio((CMS_ContentInfo_st *)cms);
        goto LABEL_12;
      case 0x19u:
        inited = cms_DigestedData_init_bio((CMS_ContentInfo_st *)cms);
        goto LABEL_12;
      case 0x1Au:
        inited = cms_EncryptedData_init_bio((CMS_ContentInfo_st *)cms);
LABEL_12:
        if ( inited )
        {
          result = BIO_push((int)icont, inited, v2);
        }
        else if ( icont )
        {
LABEL_17:
          result = 0;
        }
        else
        {
          BIO_free((int)v2, 0, v2);
          result = 0;
        }
        break;
      default:
        ERR_put_error((int)icont, 0x2Eu, 111, 156, ".\\crypto\\cms\\cms_lib.c", 145);
        goto LABEL_17;
    }
  }
  else
  {
    ERR_put_error((int)icont, 0x2Eu, 111, 127, ".\\crypto\\cms\\cms_lib.c", 114);
    return 0;
  }
  return result;
}
