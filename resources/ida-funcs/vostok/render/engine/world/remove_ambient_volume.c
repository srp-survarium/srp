void __thiscall vostok::render::engine::world::remove_ambient_volume(
        vostok::render::engine::world *this,
        survarium::game_action_id *in_scene,
        vostok::render::find_by_id_predicate<vostok::render::ambient_volume> id)
{
  vostok::render::ambient_volume **v3; // esi
  vostok::render::ambient_volume ***v4; // edi
  survarium::game_action_id *v5; // eax
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // [esp-4h] [ebp-Ch]
  const char *v8; // [esp+0h] [ebp-8h]
  const char *v9; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v3 = *(vostok::render::ambient_volume ***)((char *)&vostok::memory::s_resources.m_buffer[9315] + *in_scene);
  v4 = (vostok::render::ambient_volume ***)((char *)&vostok::memory::s_resources.m_buffer[9314] + *in_scene);
  v5 = (survarium::game_action_id *)stlp_std::find_if<vostok::render::ambient_volume * *,vostok::render::find_by_id_predicate<vostok::render::ambient_volume>>(
                                      *v4,
                                      v3,
                                      id);
  in_scene = v5;
  if ( v5 != (survarium::game_action_id *)v3 )
  {
    v6 = (char *)*v5;
    if ( v6 )
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)vostok::render::g_allocator, v6, v8, v9, savedregs);
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
      (vostok::buffer_vector<enum survarium::game_action_id> *)v4,
      &in_scene);
  }
}
