void __thiscall vostok::render::engine::world::remove_sky_ambient_occlusion(
        vostok::render::engine::world *this,
        vostok::render::sky_ambient_occlusion **in_scene,
        vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion> id)
{
  vostok::render::sky_ambient_occlusion **v3; // esi
  vostok::render::sky_ambient_occlusion ***v4; // ebx
  vostok::render::sky_ambient_occlusion **v5; // eax
  survarium::game_action_id v6; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  const char *v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  v3 = *(vostok::render::sky_ambient_occlusion ***)((char *)&vostok::memory::s_resources.m_buffer[8288]
                                                  + (_DWORD)*in_scene);
  v4 = (vostok::render::sky_ambient_occlusion ***)((char *)&vostok::memory::s_resources.m_buffer[8287]
                                                 + (_DWORD)*in_scene);
  v5 = stlp_std::priv::__find_if<vostok::render::sky_ambient_occlusion * *,vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>>(
         *v4,
         v3,
         id);
  in_scene = v5;
  if ( v5 != v3 )
  {
    v6 = (survarium::game_action_id)*v5;
    v7 = vostok::render::g_allocator;
    if ( *v5 )
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v6 + 328));
      vostok::memory::doug_lea_allocator::free_impl(v8, (int)v7, (char *)v6, v9, v10, v11);
    }
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
      (vostok::buffer_vector<enum survarium::game_action_id> *)v4,
      (survarium::game_action_id **)&in_scene);
  }
}
