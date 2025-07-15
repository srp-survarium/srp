void __thiscall survarium::weapon::on_culled_player_draw(survarium::weapon *this)
{
  survarium::portable_interactive_object_core *m_portable_interactive_object; // edi
  survarium::base_player *m_user; // ecx
  survarium::collision_user_vtbl **v4; // esi
  vostok::math::float4x4 *v5; // eax
  survarium::collision_user_vtbl *v6; // edx
  const vostok::math::float4x4 *v7; // eax
  const vostok::math::float4x4 *v8; // eax
  survarium::player *v9; // ecx
  vostok::render::game::renderer *m_renderer; // edi
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // edx
  survarium::rifle_scope *m_object; // eax
  survarium::rifle_scope *v13; // ebx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // eax
  vostok::math::float4x4 *p_m_scope_transform; // [esp+10h] [ebp-8h]
  vostok::math::float4x4 *right_toe_transform; // [esp+14h] [ebp-4h] BYREF

  m_portable_interactive_object = this->m_portable_interactive_object;
  m_user = m_portable_interactive_object->m_user;
  if ( !*((_BYTE *)&loc_1143B + (_DWORD)m_user) )
  {
    v4 = &m_portable_interactive_object->m_user->__vftable;
    v5 = (vostok::math::float4x4 *)m_user->transform(&m_user->survarium::collision_user);
    v6 = *v4;
    right_toe_transform = v5;
    v7 = v6->transform((survarium::collision_user *)v4);
    survarium::player_equipment_sound_effect::set_toe_transforms(
      right_toe_transform,
      v7,
      (survarium::player_equipment_sound_effect *)(&m_portable_interactive_object[3].m_user_hit_animations_selector.m_animations
                                                 + 1));
  }
  v8 = this->m_user->transform(&this->m_user->survarium::collision_user);
  qmemcpy(&this->m_current_transform, v8, sizeof(this->m_current_transform));
  qmemcpy(&this->m_barrel_transform, v8, sizeof(this->m_barrel_transform));
  p_m_scope_transform = &this->m_scope_transform;
  qmemcpy(&this->m_scope_transform, &this->m_current_transform, sizeof(this->m_scope_transform));
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&right_toe_transform,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene);
  m_renderer = this->m_game_scene->m_game->m_renderer;
  p_m_render_model = &this->m_model.m_object->m_render_model;
  if ( p_m_render_model->m_object->m_in_scene
    && (!this->m_is_scope_aimed
     || (m_object = this->m_rifle_scope.m_object) == 0
     || !m_object->m_hide_weapon_on_aim
     || !survarium::player::is_current(v9, (int)this->m_user)) )
  {
    vostok::render::scene_renderer::update_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
      *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&right_toe_transform,
      &this->m_current_transform,
      &this->m_current_transform);
  }
  survarium::weapon::update_pfx_transform((survarium::weapon *)v9, (int)this);
  v13 = this->m_rifle_scope.m_object;
  if ( v13 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v14 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13->m_aimed_scope.m_object->m_render_model;
      if ( BYTE1(v14->m_object->m_lods[0].m_emitter_instance_list.m_size)
        || (v14 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13->m_idle_scope.m_object->m_render_model,
            BYTE1(v14->m_object->m_lods[0].m_emitter_instance_list.m_size)) )
      {
        vostok::render::scene_renderer::update_model(
          v14,
          *(vostok::render::scene_renderer **)((char *)&dword_200060 + (_DWORD)m_renderer),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&right_toe_transform,
          p_m_scope_transform,
          p_m_scope_transform);
      }
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&right_toe_transform);
}
