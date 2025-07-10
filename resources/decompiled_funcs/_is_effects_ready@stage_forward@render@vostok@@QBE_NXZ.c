bool __fastcall vostok::render::stage_forward::is_effects_ready(vostok::render::stage_forward *this, _DWORD *a2)
{
  unsigned int v2; // eax
  _DWORD *v3; // ecx

  v2 = 0;
  v3 = a2 + 6;
  do
  {
    if ( v2 != 12 && !*v3 )
      return 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 0xF );
  return a2[5] && a2[4];
}
