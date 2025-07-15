unsigned int __usercall vostok::render::res_texture::width@<eax>(vostok::render::res_texture *this@<ecx>, int a2@<eax>)
{
  if ( *(_BYTE *)(a2 + 457) )
    return *(_DWORD *)(a2 + 128);
  else
    return *(_DWORD *)(a2 + 84);
}
