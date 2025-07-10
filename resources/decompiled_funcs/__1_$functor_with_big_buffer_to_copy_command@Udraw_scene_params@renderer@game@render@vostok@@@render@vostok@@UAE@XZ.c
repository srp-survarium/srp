void __usercall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::~functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  void (__cdecl *v3)(int, int, int); // eax
  int v4; // eax
  void (__cdecl *v5)(int, int, int); // eax

  vostok::render::game::renderer::draw_scene_params::~draw_scene_params(
    (vostok::render::game::renderer::draw_scene_params *)this,
    (vostok::resources::unmanaged_resource **)(a2 + 152));
  v2 = *(_DWORD *)(a2 + 120);
  if ( v2 )
  {
    if ( (v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(int, int, int))(v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 128, a2 + 128, 2);
    }
    *(_DWORD *)(a2 + 120) = 0;
  }
  v4 = *(_DWORD *)(a2 + 88);
  if ( v4 )
  {
    if ( (v4 & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(int, int, int))(v4 & 0xFFFFFFFE);
      if ( v5 )
        v5(a2 + 96, a2 + 96, 2);
    }
    *(_DWORD *)(a2 + 88) = 0;
  }
}
