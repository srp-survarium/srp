int __usercall ogg_page_version@<eax>(const ogg_page *og@<eax>)
{
  return og->header[4];
}
