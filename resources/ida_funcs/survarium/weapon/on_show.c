void __thiscall survarium::weapon::on_show(survarium::weapon *this)
{
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *p_m_render_scene; // eax
  vostok::render::base_scene *m_object; // eax
  survarium::base_game_scene *m_game_scene; // edx
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax
  survarium::rifle_scope *v6; // eax
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v7; // edx
  survarium::profile_slot_enum m_ammo_slot; // esi
  survarium::profile_slot_enum ammo_slot; // eax
  survarium::weapon *v10; // ecx
  survarium::game_world_ui *m_game_ui; // edx
  vostok::render::base_scene *v12; // eax
  vostok::resources::unmanaged_intrusive_base *v13; // ecx
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> scene; // [esp+14h] [ebp-44h] BYREF
  vostok::math::float4x4 transform; // [esp+18h] [ebp-40h] BYREF

  p_m_render_scene = &this->m_game_scene->m_render_scene;
  this->m_is_in_scene = 1;
  m_object = p_m_render_scene->m_object;
  scene.m_object = 0;
  if ( m_object )
  {
    scene.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  m_game_scene = this->m_game_scene;
  p_m_render_model = &this->model.m_object->m_render_model;
  qmemcpy((void *)&transform, &this->survarium::weapon_core::m_transform, sizeof(transform));
  vostok::render::scene_renderer::add_model(
    (vostok::render::scene_renderer *)m_game_scene->m_game->m_renderer,
    &scene,
    p_m_render_model,
    &transform);
  v6 = this->m_rifle_scope.m_object;
  if ( v6
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v7 = (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)v6->m_idle_scope.m_object;
    qmemcpy((void *)&transform, &this->survarium::weapon_core::m_transform, sizeof(transform));
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)this->m_game_scene,
      &scene,
      v7 + 66,
      &transform);
  }
  if ( this->m_game_ui )
  {
    m_ammo_slot = this->m_ammo_slot;
    ammo_slot = survarium::weapon_core::get_ammo_slot(this, first_ammo);
    survarium::game_world_ui::set_ammo_type(this->m_game_ui, (m_ammo_slot != ammo_slot) + 1);
    survarium::game_world_ui::set_fire_queue_size(
      this->m_game_ui,
      this->m_weapon_fire_queue_types[this->m_fire_queue_type]);
    survarium::game_world_ui::show_ammo_indicator(this->m_game_ui, 1);
    m_game_ui = this->m_game_ui;
    if ( m_game_ui )
      survarium::game_world_ui::show_crosshair(m_game_ui, 1);
    survarium::weapon::set_ui_ammo(v10, (int)this, 1);
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (unsigned int)this->m_user) + 416) = 1;
  }
  v12 = scene.m_object;
  if ( scene.m_object )
  {
    v13 = &scene.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&scene.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v13, v12);
  }
}
