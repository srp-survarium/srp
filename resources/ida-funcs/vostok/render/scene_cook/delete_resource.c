void __thiscall vostok::render::scene_cook::delete_resource(
        vostok::render::scene_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::buffer_vector<enum survarium::game_action_id> *v2; // esi
  char *m_end; // ebx
  const char *v4; // [esp+0h] [ebp-10h]
  const char *v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]
  vostok::ai::fsm_state *pointer; // [esp+Ch] [ebp-4h] BYREF

  v2 = (vostok::buffer_vector<enum survarium::game_action_id> *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst;
  m_end = (char *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes.m_end;
  pointer = (vostok::ai::fsm_state *)resource;
  resource = (vostok::resources::resource_base *)stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                                                   (char *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_scenes.m_begin,
                                                   (int *)&resource,
                                                   m_end);
  if ( resource != (vostok::resources::resource_base *)m_end )
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(v2, (survarium::game_action_id **)&resource);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
    vostok::render::g_allocator,
    &pointer,
    v4,
    v5,
    v6);
}
