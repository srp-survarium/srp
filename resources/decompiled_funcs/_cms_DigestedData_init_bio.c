bio_st *__cdecl cms_DigestedData_init_bio(CMS_ContentInfo_st *cms)
{
  return cms_DigestAlgorithm_init_bio((X509_algor_st *)cms->d.data->type);
}
