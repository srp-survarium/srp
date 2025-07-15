void __usercall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>::~functor_with_big_buffer_to_copy_command<vostok::render::decal_properties>(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::decal_properties> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  void (__cdecl *v4)(int, int, int); // eax
  int v5; // eax
  void (__cdecl *v6)(int, int, int); // eax

  v2 = *(_DWORD *)(a2 + 216);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 216) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 216));
  v3 = *(_DWORD *)(a2 + 120);
  if ( v3 )
  {
    if ( (v3 & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(int, int, int))(v3 & 0xFFFFFFFE);
      if ( v4 )
        v4(a2 + 128, a2 + 128, 2);
    }
    *(_DWORD *)(a2 + 120) = 0;
  }
  v5 = *(_DWORD *)(a2 + 88);
  if ( v5 )
  {
    if ( (v5 & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(int, int, int))(v5 & 0xFFFFFFFE);
      if ( v6 )
        v6(a2 + 96, a2 + 96, 2);
    }
    *(_DWORD *)(a2 + 88) = 0;
  }
}


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


void __usercall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>::~functor_with_big_buffer_to_copy_command<vostok::render::sky_ambient_occlusion_properties>(
        vostok::render::functor_command *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  void (__cdecl *v3)(int, int, int); // eax
  int v4; // eax
  void (__cdecl *v5)(int, int, int); // eax

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
