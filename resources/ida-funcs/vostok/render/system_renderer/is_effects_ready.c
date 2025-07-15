bool __fastcall vostok::render::system_renderer::is_effects_ready(vostok::render::system_renderer *this, _DWORD *a2)
{
  unsigned int v2; // eax
  _DWORD *v3; // ecx

  v2 = 0;
  v3 = a2 + 55;
  do
  {
    if ( v2 != 12 && !*v3 )
      return 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 0xF );
  return a2[50] && a2[53] && a2[23] && a2[71] && a2[70] && a2[54] && a2[49];
}
