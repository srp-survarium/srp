void __usercall vostok::render::post_process_parameters::~post_process_parameters(
        vostok::render::post_process_parameters *this@<ecx>,
        _DWORD *a2@<edi>)
{
  int v2; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = a2[128];
  if ( v2 )
  {
    v3 = (*(_DWORD *)(v2 + 4))-- == 1;
    if ( v3 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  v4 = a2[127];
  if ( v4 )
  {
    v3 = (*(_DWORD *)(v4 + 4))-- == 1;
    if ( v3 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  v5 = a2[126];
  if ( v5 )
  {
    v3 = (*(_DWORD *)(v5 + 4))-- == 1;
    if ( v3 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
  v6 = a2[125];
  if ( v6 )
  {
    v3 = (*(_DWORD *)(v6 + 4))-- == 1;
    if ( v3 )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)this);
  }
}
