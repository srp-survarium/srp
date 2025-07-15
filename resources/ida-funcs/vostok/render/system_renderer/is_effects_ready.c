bool __usercall vostok::render::system_renderer::is_effects_ready@<al>(
        vostok::render::system_renderer *this@<ecx>,
        _DWORD *a2@<eax>)
{
  unsigned int v2; // edx
  _DWORD *v3; // ecx

  v2 = 0;
  v3 = a2 + 57;
  do
  {
    if ( v2 != 12 && !*v3 )
      return 0;
    ++v2;
    ++v3;
  }
  while ( v2 < 0xF );
  return a2[52] && a2[55] && a2[23] && a2[24] && a2[25] && a2[72] && a2[56] && a2[51];
}
