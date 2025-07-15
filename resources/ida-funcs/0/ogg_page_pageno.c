int __usercall ogg_page_pageno@<eax>(const ogg_page *og@<eax>)
{
  return og->header[18] | ((og->header[19] | (*((unsigned __int16 *)og->header + 10) << 8)) << 8);
}
