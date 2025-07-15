bool __usercall vostok::render::stage_light_propagation_volumes::is_effects_ready@<al>(
        vostok::render::stage_light_propagation_volumes *this@<ecx>,
        _DWORD *a2@<esi>)
{
  unsigned int v2; // eax
  _DWORD *v3; // ecx
  unsigned int v4; // edx
  int v5; // eax
  _DWORD *i; // ecx

  v2 = 0;
  v3 = a2 + 163;
  do
  {
    if ( v2 != 12 && !*v3 )
      return 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 0xF );
  v4 = a2[12];
  v5 = 0;
  if ( v4 )
  {
    for ( i = (_DWORD *)(a2[11] + 400); *i; i += 119 )
    {
      if ( ++v5 >= v4 )
        return a2[178] && a2[179] && a2[180];
    }
    return 0;
  }
  return a2[178] && a2[179] && a2[180];
}
