int __cdecl ogg_page_bos(const ogg_page *og)
{
  return og->header[5] & 2;
}
