void __usercall vostok::render::environment_probe::~environment_probe(
        vostok::render::environment_probe *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::res_texture *v2; // ecx
  int v3; // eax
  bool v4; // zf
  int v5; // eax

  vostok::render::environment_probe::remove_collision(this, a2);
  v3 = *(_DWORD *)(a2 + 408);
  if ( v3 )
  {
    v4 = (*(_DWORD *)(v3 + 4))-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v2, *(const vostok::render::res_texture **)(a2 + 408));
  }
  v5 = *(_DWORD *)(a2 + 404);
  if ( v5 )
  {
    v4 = (*(_DWORD *)(v5 + 4))-- == 1;
    if ( v4 )
      vostok::render::res_texture::destroy_impl(v2, *(const vostok::render::res_texture **)(a2 + 404));
  }
}
