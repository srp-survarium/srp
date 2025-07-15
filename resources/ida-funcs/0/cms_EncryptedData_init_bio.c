bio_st *__cdecl cms_EncryptedData_init_bio(CMS_ContentInfo_st *cms)
{
  asn1_string_st *data; // eax
  CMS_EncryptedContentInfo_st *type; // ecx

  data = cms->d.data;
  type = (CMS_EncryptedContentInfo_st *)data->type;
  if ( type->cipher && data->data )
    data->length = 2;
  return cms_EncryptedContent_init_bio(type);
}
