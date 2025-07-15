unsigned int __usercall vostok::render::backend::target_width@<eax>(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  if ( *(_BYTE *)(a2 + 320) )
    return *(_DWORD *)(a2 + 312);
  else
    return *(_DWORD *)(*(_DWORD *)(a2 + 7388) + 152);
}
