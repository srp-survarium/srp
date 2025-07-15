bool __usercall vostok::render::light::is_cast_shadows@<al>(vostok::render::light *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 380);
  if ( (v2 & 0x20) == 0 )
    return 0;
  if ( (v2 & 0xF) != 0 )
    return 1;
  return *(_BYTE *)(a2 + 384)
      || *(_BYTE *)(a2 + 385)
      || *(_BYTE *)(a2 + 386)
      || *(_BYTE *)(a2 + 387)
      || *(_BYTE *)(a2 + 388)
      || *(_BYTE *)(a2 + 389);
}
