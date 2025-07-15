bool __userpurge vostok::render::bake_decal_parameters::has_texture_type@<al>(
        vostok::render::bake_decal_parameters *this@<ecx>,
        int a2@<edx>,
        vostok::render::decal_texture_type type,
        bool decals_only)
{
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v4 = 0;
  v5 = (_DWORD *)(a2 + 4 * (_DWORD)this + 64);
  do
  {
    if ( *v5 )
      return 1;
    ++v4;
    v5 += 20;
  }
  while ( v4 < 0xA );
  return !(_BYTE)type && *(_DWORD *)(a2 + 4 * (_DWORD)this + 864) != 0;
}
