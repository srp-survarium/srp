bio_st *__cdecl cms_SignedData_init_bio(CMS_ContentInfo_st *cms)
{
  bio_st *v1; // ebx
  CMS_SignedData_st *signedData; // esi
  int v4; // edi
  char *v5; // eax
  bio_st *inited; // eax

  v1 = 0;
  if ( OBJ_obj2nid(cms->contentType) == 22 )
  {
    signedData = cms->d.signedData;
    if ( signedData )
    {
      if ( signedData->encapContentInfo->partial )
        cms_sd_set_version(signedData);
      v4 = 0;
      if ( sk_num(&signedData->digestAlgorithms->stack) <= 0 )
      {
        return v1;
      }
      else
      {
        while ( 1 )
        {
          v5 = sk_value(&signedData->digestAlgorithms->stack, v4);
          inited = cms_DigestAlgorithm_init_bio((X509_algor_st *)v5);
          if ( !inited )
            break;
          if ( v1 )
            BIO_push(v1, inited);
          else
            v1 = inited;
          if ( ++v4 >= sk_num(&signedData->digestAlgorithms->stack) )
            return v1;
        }
        if ( v1 )
          BIO_free_all(v1);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x2Eu, 133, 108, ".\\crypto\\cms\\cms_sd.c", 71);
    return 0;
  }
}
