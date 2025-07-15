void __userpurge survarium::base_player::tick(
        survarium::base_player *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  _DWORD *v5; // edi
  char *v6; // esi
  unsigned int *p_m_current_time_in_ms; // eax
  survarium::inventory *m_current_time_in_ms; // ecx
  bool v9; // zf
  survarium::inventory *m_object; // eax
  survarium::base_player *v11; // ecx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  survarium::body_part_parameters *v17; // ecx
  survarium::damage_model *v18; // edi
  survarium::body_part_parameters *i; // esi
  survarium::base_player *v20; // ecx
  vostok::math::float4x4 *v21; // eax
  survarium::usable_object *current_object; // edi
  survarium::usable_object_vtbl *v23; // eax
  survarium::usable_object *v24; // ecx
  unsigned int *p_m_spotted_time_left_in_ms; // eax
  unsigned int m_spotted_time_left_in_ms; // ecx
  unsigned int v27; // ecx
  unsigned int *p_m_time_left_to_try_spot_in_ms; // ebx
  unsigned int v29; // eax
  survarium::usable_object_user_data *factor; // [esp+8h] [ebp-5Ch]
  unsigned int time_delta_ms; // [esp+1Ch] [ebp-48h]
  unsigned int v32; // [esp+20h] [ebp-44h]
  vostok::math::float4x4 v33; // [esp+24h] [ebp-40h] BYREF

  *(survarium::base_player_vtbl **)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                  + (_DWORD)&loc_1110F
                                  + 1) = *(survarium::base_player_vtbl **)&byte_10E5C[(_DWORD)this];
  v6 = &byte_10E5C[(_DWORD)this + 4];
  v5 = (unsigned int *)((char *)&this->type + (_DWORD)&loc_1110F + 1);
  p_m_current_time_in_ms = &this->m_current_time_in_ms;
  m_current_time_in_ms = (survarium::inventory *)this->m_current_time_in_ms;
  *p_m_current_time_in_ms = (unsigned int)current_time_in_ms;
  *v5 = *(_DWORD *)v6;
  v9 = !this->m_has_to_die;
  v32 = (unsigned int)m_current_time_in_ms;
  time_delta_ms = (char *)current_time_in_ms - (char *)m_current_time_in_ms;
  v5[1] = *((_DWORD *)v6 + 1);
  *(_DWORD *)((char *)&loc_1111C + (_DWORD)this) = (char *)current_time_in_ms - (char *)m_current_time_in_ms;
  if ( !v9 )
  {
    m_object = this->m_inventory.m_object;
    if ( m_object->m_carried_item )
      survarium::inventory::drop_carried_item(m_current_time_in_ms, (int)m_object);
    survarium::base_player::remove_alive((survarium::base_player *)m_current_time_in_ms, (int)this, 1);
    this->on_player_death(this, (unsigned int)current_time_in_ms);
    this->m_need_to_select_animations = 1;
    this->m_has_to_die = 0;
  }
  if ( survarium::inventory::update_weight(m_current_time_in_ms, (int)this->m_inventory.m_object) )
  {
    v12 = *(float *)((char *)&loc_110B8 + (_DWORD)this);
    v13 = (float)(this->m_inventory.m_object->m_carried_weight + this->m_inventory.m_object->m_clothes_weight) - v12;
    v14 = 0.0;
    v15 = v13
        / (float)(survarium::player_params_modifiers_container::apply_modifier(
                    *(survarium::player_params_modifiers_container **)((char *)&loc_110E8 + (_DWORD)this),
                    max_carried_weight_modifier,
                    a2,
                    this->m_stamina.m_params.max_carried_weight,
                    1.0)
                - v12);
    v16 = s_bm_current_air_resistance;
    if ( v15 > 0.0 )
    {
      if ( s_bm_current_air_resistance < v15 )
        v14 = s_bm_current_air_resistance;
      else
        v14 = v15;
    }
    *(float *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
             + (_DWORD)&loc_110EA
             + 2) = *(float *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                             + (_DWORD)&loc_110C1
                             + 3)
                  * v14;
    a2 = (float)((float)(v16 - v14)
               * COERCE_FLOAT(
                   (__int128)*(survarium::base_player_vtbl **)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                             + (_DWORD)&loc_110BF
                                                             + 1)
                 ^ _mask__NegFloat_))
       + *(float *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                  + (_DWORD)&loc_110BF
                  + 1);
    *(float *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
             + (_DWORD)&loc_110F2
             + 2) = a2;
    this->m_need_to_select_animations = 1;
  }
  survarium::base_player::tick_animations(v32, v11, a2, (signed int)this, current_time_in_ms);
  if ( this->m_is_alive )
  {
    v18 = this->m_damage_model.m_object;
    for ( i = v18->m_body_parts.m_first; i; i = i->next )
      survarium::body_part_parameters::tick(v17, (unsigned int)i, a2, time_delta_ms, (unsigned int)current_time_in_ms);
    v18->m_last_tick_time_in_ms = (unsigned int)current_time_in_ms;
  }
  survarium::base_player::set_physics_controller_walk_vector(
    (survarium::base_player *)v17,
    a2,
    (const unsigned int)this,
    time_delta_ms);
  this->m_current_active_object->tick(this->m_current_active_object, (const unsigned int)current_time_in_ms);
  if ( this->m_is_alive && this->m_usable_object_user_data.current_object )
  {
    v21 = survarium::base_player::computed_head_transform(
            v20,
            (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)this,
            &v33);
    current_object = this->m_usable_object_user_data.current_object;
    this->m_usable_object_user_data.current_time_ms = (unsigned int)current_time_in_ms;
    v9 = current_object == survarium::base_player::detect_usable_object(this, v21);
    v23 = current_object->survarium::collision_geometry_subscriber::__vftable;
    factor = &this->m_usable_object_user_data;
    v24 = current_object;
    if ( v9 )
    {
      if ( v23->use_execute(current_object, factor) )
        goto LABEL_22;
      v23 = current_object->survarium::collision_geometry_subscriber::__vftable;
      factor = &this->m_usable_object_user_data;
      v24 = current_object;
    }
    v23->use_finalize(v24, factor);
  }
LABEL_22:
  survarium::base_player::notify_actions_subscribers(v20, (int)this, time_delta_ms);
  p_m_spotted_time_left_in_ms = &this->m_spotted_time_left_in_ms;
  m_spotted_time_left_in_ms = this->m_spotted_time_left_in_ms;
  if ( m_spotted_time_left_in_ms <= time_delta_ms )
    v27 = 0;
  else
    v27 = m_spotted_time_left_in_ms - time_delta_ms;
  p_m_time_left_to_try_spot_in_ms = &this->m_time_left_to_try_spot_in_ms;
  *p_m_spotted_time_left_in_ms = v27;
  if ( *p_m_time_left_to_try_spot_in_ms <= time_delta_ms )
    v29 = 0;
  else
    v29 = *p_m_time_left_to_try_spot_in_ms - time_delta_ms;
  *p_m_time_left_to_try_spot_in_ms = v29;
}
