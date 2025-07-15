int __cdecl ogg_page_continued(const ogg_page *og)
{
  return og->header[5] & 1;
}
