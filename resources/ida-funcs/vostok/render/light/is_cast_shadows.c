bool __usercall vostok::render::light::is_cast_shadows@<al>(vostok::render::light *this@<ecx>, int a2@<eax>)
{
  int v3; // ecx

  if ( !*(_BYTE *)(a2 + 625)
    && *(_DWORD *)(a2 + 620) == 1
    && !vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality )
  {
    return 0;
  }
  v3 = *(_DWORD *)(a2 + 860);
  if ( (v3 & 0x20) == 0 )
    return 0;
  if ( (v3 & 0xF) != 0 )
    return 1;
  return *(_BYTE *)(a2 + 864)
      || *(_BYTE *)(a2 + 865)
      || *(_BYTE *)(a2 + 866)
      || *(_BYTE *)(a2 + 867)
      || *(_BYTE *)(a2 + 868)
      || *(_BYTE *)(a2 + 869);
}
