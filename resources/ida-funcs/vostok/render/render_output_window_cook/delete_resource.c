void __thiscall vostok::render::render_output_window_cook::delete_resource(
        vostok::render::render_output_window_cook *this,
        vostok::resources::resource_base *resource)
{
  char *m_end; // ebx
  vostok::buffer_vector<enum survarium::game_action_id> *p_m_output_windows; // esi
  const char *v4; // [esp+0h] [ebp-10h]
  const char *v5; // [esp+4h] [ebp-Ch]
  unsigned int v6; // [esp+8h] [ebp-8h]
  survarium::game_effect *pointer; // [esp+Ch] [ebp-4h] BYREF

  pointer = (survarium::game_effect *)resource;
  m_end = (char *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows.m_end;
  p_m_output_windows = (vostok::buffer_vector<enum survarium::game_action_id> *)&vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows;
  resource = (vostok::resources::resource_base *)stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                                                   (char *)vostok::quasi_singleton<vostok::render::scene_manager>::pinst->m_output_windows.m_begin,
                                                   (int *)&resource,
                                                   m_end);
  if ( resource != (vostok::resources::resource_base *)m_end )
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
      p_m_output_windows,
      (survarium::game_action_id **)&resource);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::base_network_client>(
    vostok::render::g_allocator,
    &pointer,
    v4,
    v5,
    v6);
}
