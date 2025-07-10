void __thiscall survarium::lobby_menu::clear_resources(survarium::lobby_menu *this)
{
  survarium::simple_game_project *m_object; // eax
  void **M_finish; // ebx
  void **i; // edi
  unsigned int v5; // ebx
  int j; // edi
  survarium::simple_game_project *v7; // eax
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  unsigned int v9; // ebx
  int k; // edi
  survarium::simple_game_project *v11; // eax
  int *m_character; // edi
  int v13; // eax

  m_object = this->m_lobby_game_project.m_object;
  this->m_in_destroying = 1;
  if ( m_object )
  {
    M_finish = m_object->m_objects._M_impl._M_finish;
    for ( i = m_object->m_objects._M_impl._M_start; i != M_finish; ++i )
      (*(void (__thiscall **)(void *))(*(_DWORD *)*i + 36))(*i);
    v5 = 0;
    for ( j = 0; ; ++j )
    {
      v7 = this->m_lobby_game_project.m_object;
      if ( v5 >= v7->m_render_visuals_count )
        break;
      v8 = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)v7->m_render_visuals[j].model.m_object;
      if ( v8 )
        vostok::render::scene_renderer::remove_model(
          (vostok::render::scene_renderer *)this->m_game,
          this->m_game->m_renderer->m_scene,
          &this->m_render_scene,
          v8 + 66);
      ++v5;
    }
    v9 = 0;
    for ( k = 0; ; ++k )
    {
      v11 = this->m_lobby_game_project.m_object;
      if ( v9 >= v11->m_static_collision_objects_count )
        break;
      survarium::static_collision::remove(&v11->m_static_collision_objects[k], this->m_physics_world);
      ++v9;
    }
    this->m_lobby_game_project.m_object = 0;
    if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
    m_character = (int *)this->m_character;
    if ( *m_character
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::player::remove(
        (survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        *m_character);
    }
    v13 = *m_character;
    *m_character = 0;
    if ( v13 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v13 + 496), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(v13 + 496),
        (vostok::resources::unmanaged_resource *)(v13 + 288));
    this->show_ui(this, 0);
  }
}
