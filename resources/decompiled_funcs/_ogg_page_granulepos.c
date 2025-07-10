int __cdecl ogg_page_granulepos(const ogg_page *og)
{
  return og->header[6]
       | ((og->header[7]
         | ((og->header[8]
           | ((og->header[9]
             | ((og->header[10] | ((og->header[11] | (*((unsigned __int16 *)og->header + 6) << 8)) << 8)) << 8)) << 8)) << 8)) << 8);
}
