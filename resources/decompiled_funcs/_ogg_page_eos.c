int __cdecl ogg_page_eos(const ogg_page *og)
{
  return og->header[5] & 4;
}
