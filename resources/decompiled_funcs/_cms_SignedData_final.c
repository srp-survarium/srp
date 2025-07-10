int __cdecl cms_SignedData_final(CMS_ContentInfo_st *cms, bio_st *chain)
{
  const stack_st *type; // ebp
  asn1_string_st *data; // eax
  int v4; // edi
  char *v5; // eax

  if ( OBJ_obj2nid(cms->contentType) == 22 )
  {
    data = cms->d.data;
    if ( data )
      type = (const stack_st *)data[1].type;
    else
      type = 0;
  }
  else
  {
    ERR_put_error(0x2Eu, 133, 108, ".\\crypto\\cms\\cms_sd.c", 71);
    type = 0;
  }
  v4 = 0;
  if ( sk_num(type) <= 0 )
  {
LABEL_9:
    *((_DWORD *)cms->d.data->data + 2) = 0;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v5 = sk_value(type, v4);
      if ( !cms_SignerInfo_content_sign(cms, (CMS_SignerInfo_st *)v5, chain) )
        return 0;
      if ( ++v4 >= sk_num(type) )
        goto LABEL_9;
    }
  }
}
