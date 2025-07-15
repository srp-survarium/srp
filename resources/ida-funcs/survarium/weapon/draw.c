// local variable allocation has failed, the output may be wrong!
void __userpurge survarium::weapon::draw(
        survarium::weapon *this@<ecx>,
        float a2@<xmm0>,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *shadow_transform,
        const vostok::math::float4x4 *const matrices,
        const vostok::math::float4x4 *const shadow_matrices,
        unsigned int matrices_count,
        survarium::hud_object_state *hud)
{
  long double v9; // rdi
  vostok::math::float4x4 *v10; // eax
  vostok::math::float4x4 *v11; // eax
  survarium::player *v12; // ecx
  vostok::render::game::renderer *m_renderer; // edi
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // edx
  bool v15; // zf
  survarium::rifle_scope *m_object; // eax
  survarium::player *v17; // ecx
  survarium::weapon *v18; // ecx
  unsigned __int8 v19; // dl
  int v20; // eax
  __int32 v21; // ecx
  survarium::hud_object_state *v22; // eax
  survarium::rifle_scope *v23; // eax
  bool v24; // al
  survarium::weapon_core *v25; // ecx
  unsigned int v26; // [esp+0h] [ebp-58h]
  unsigned int v27; // [esp+0h] [ebp-58h]
  unsigned int v28; // [esp+0h] [ebp-58h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+10h] [ebp-48h] BYREF
  float i; // [esp+14h] [ebp-44h]
  vostok::math::float4x4 v31; // [esp+18h] [ebp-40h] BYREF

  qmemcpy(&this->m_current_transform, transform, sizeof(this->m_current_transform));
  HIDWORD(v9) = transform + 1;
  LODWORD(v9) = &this->m_barrel_locator;
  v10 = survarium::weapon::calculate_locator(v9, *(__m128i *)&a2, &v31, transform, matrices, v26);
  qmemcpy(&this->m_barrel_transform, v10, sizeof(this->m_barrel_transform));
  HIDWORD(v9) = v10 + 1;
  LODWORD(v9) = &this->m_scope_locator;
  v11 = survarium::weapon::calculate_locator(v9, *(__m128i *)&a2, &v31, transform, matrices, v27);
  qmemcpy(&this->m_scope_transform, v11, sizeof(this->m_scope_transform));
  HIDWORD(v9) = v11 + 1;
  LODWORD(v9) = &this->m_scope_locator;
  survarium::weapon::calculate_locator(v9, *(__m128i *)&a2, &v31, shadow_transform, shadow_matrices, v28);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v29,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene);
  m_renderer = this->m_game_scene->m_game->m_renderer;
  p_m_render_model = &this->m_model.m_object->m_render_model;
  v15 = !p_m_render_model->m_object->m_in_scene;
  i = *(float *)&m_renderer;
  if ( !v15
    && (!this->m_is_scope_aimed
     || (m_object = this->m_rifle_scope.m_object) == 0
     || !m_object->m_hide_weapon_on_aim
     || !survarium::player::is_current(v12, (int)this->m_user)) )
  {
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
      &v29,
      transform,
      shadow_transform);
    vostok::render::scene_renderer::update_skeleton(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
      *(vostok::memory::base_allocator **)((char *)&dword_200060 + LODWORD(i)),
      matrices,
      shadow_matrices,
      matrices_count);
    m_renderer = (vostok::render::game::renderer *)LODWORD(i);
  }
  survarium::weapon::update_pfx_transform((survarium::weapon *)v12, (int)this);
  if ( this->m_rifle_scope.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( survarium::player::is_current(v17, (int)this->m_user) )
    {
      if ( this->m_is_scope_aimed )
      {
        if ( !this->m_aimed_scope_added )
          survarium::weapon::add_aimed_rifle_scope_to_scene(v18, (int)this, &v29);
      }
      else if ( this->m_aimed_scope_added )
      {
        survarium::weapon::remove_aimed_rifle_scope_from_scene(v18, (int)this, &v29);
      }
    }
    if ( this->m_is_scope_aimed && survarium::player::is_current((survarium::player *)v18, (int)this->m_user) )
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_rifle_scope.m_object->m_aimed_scope.m_object->m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
        &v29,
        &this->m_scope_transform,
        &v31);
    else
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_rifle_scope.m_object->m_idle_scope.m_object->m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
        &v29,
        &this->m_scope_transform,
        &v31);
  }
  if ( hud )
  {
    hud->show_ammo_indicator = this->m_user->m_is_alive;
    v19 = 0;
    for ( i = *(float *)&this->m_inventory;
          v19 < this->m_ammunition_slots_count;
          v22->ammo_available[0].dict_id = *(_WORD *)(*(_DWORD *)v21 + 282) )
    {
      v20 = v19;
      v21 = LODWORD(i) + 4 * this->m_ammunition_slots[v20] + 272;
      v22 = (survarium::hud_object_state *)((char *)hud + v20 * 4);
      v22->ammo_available[0].amount = *(_WORD *)(*(_DWORD *)v21 + 280);
      ++v19;
    }
    hud->ammo_available[v19].dict_id = 0;
    hud->current_ammo_type = this->m_selected_ammo_id;
    hud->fire_queue_size = this->m_weapon_fire_queue_types[this->m_fire_queue_type];
    hud->ammo_in_magazine = this->m_ammo_in_magazine + this->m_is_round_chambered;
    v24 = (this->m_model.m_object->m_render_model.m_object->m_in_scene
        || (v23 = this->m_rifle_scope.m_object) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v23->m_aimed_scope.m_object->m_render_model.m_object->m_in_scene
         || v23->m_idle_scope.m_object->m_render_model.m_object->m_in_scene))
       && !this->m_aimed
       && this->m_user->m_is_alive;
    hud->show_crosshair = v24;
    if ( v24 )
    {
      survarium::weapon_core::get_buck_dispersion(this);
      i = a2;
      survarium::weapon_core::get_dispersion(v25, (int)this);
      hud->crosshair_size = (float)(s_dispersion_gui_scale_coef_value / survarium::default_vertical_fov)
                          * (float)(i + a2);
    }
    else
    {
      hud->crosshair_size = 0.0;
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
}
