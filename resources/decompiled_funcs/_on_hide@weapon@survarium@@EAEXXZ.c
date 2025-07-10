void __thiscall survarium::weapon::on_hide(survarium::weapon *this)
{
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // eax
  vostok::render::base_scene *m_object; // eax
  vostok::resources::unmanaged_resource *v4; // edi
  survarium::rifle_scope *v5; // eax
  survarium::game_world_ui *m_game_ui; // edx
  survarium::game_world_ui *v7; // edx
  vostok::render::scene_renderer *m_scene; // [esp-Ch] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> scene; // [esp+Ch] [ebp-4h] BYREF

  p_m_render_scene = &this->m_game_scene->m_render_scene;
  this->m_is_in_scene = 0;
  m_object = p_m_render_scene->m_object;
  v4 = 0;
  scene.m_object = 0;
  if ( m_object )
  {
    v4 = m_object;
    scene.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  if ( !this->m_is_scope_aimed || (v5 = this->m_rifle_scope.m_object) == 0 || !v5->m_hide_weapon_on_aim )
  {
    m_scene = this->m_game_scene->m_game->m_renderer->m_scene;
    vostok::render::scene_renderer::remove_model(
      m_scene,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_scene,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
  }
  if ( this->m_rifle_scope.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::scene_renderer::remove_model(
      (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
  }
  m_game_ui = this->m_game_ui;
  this->m_is_scope_aimed = 0;
  if ( m_game_ui )
    survarium::game_world_ui::show_crosshair(m_game_ui, 0);
  v7 = this->m_game_ui;
  if ( v7 )
    survarium::game_world_ui::show_ammo_indicator(v7, 0);
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  }
}
