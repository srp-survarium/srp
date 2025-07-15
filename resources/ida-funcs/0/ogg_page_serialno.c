int __cdecl ogg_page_serialno(const ogg_page *og)
{
  return og->header[14] | ((og->header[15] | (*((unsigned __int16 *)og->header + 8) << 8)) << 8);
}
