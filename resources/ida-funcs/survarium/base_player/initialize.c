void __userpurge survarium::base_player::initialize(
        survarium::base_player *this@<ecx>,
        int a2@<ebx>,
        long double a3@<esi:edi>,
        __m128i a4@<xmm0>,
        survarium::loose_ptr_base *time_in_ms,
        const vostok::math::float3 *position,
        float orientation,
        int look_pitch)
{
  unsigned __int8 id; // al
  vostok::physics::bt_character_controller *v10; // ecx
  vostok::animation::animation_player *v11; // ecx
  survarium::game_effect_player *v12; // ecx
  survarium::damage_model *v13; // ecx
  char *v14; // eax
  double v15; // st7
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v16; // ecx
  survarium::inventory *v17; // ecx
  survarium::inventory *v18; // ecx
  survarium::inventory *v19; // ecx
  survarium::inventory *m_object; // esi
  survarium::interactive_object *m_target_active_object; // ecx
  survarium::interactive_object **p_m_current_active_object; // esi
  survarium::base_player *v23; // ecx

  this->m_current_time_in_ms = (unsigned int)time_in_ms;
  this->m_inserted_time_in_ms = (unsigned int)time_in_ms;
  this->m_is_alive = 1;
  this->m_has_to_die = 0;
  this->m_recompute_damage_collision_bones_time_in_ms = (unsigned int)&time_in_ms[-1].m_pointer + 3;
  survarium::base_player::set_transform(
    this,
    a3,
    a4,
    (const vostok::math::float3 *)this,
    position,
    orientation,
    look_pitch);
  id = this->id;
  this->m_input.rotation_delta.x = 0.0;
  this->m_input.rotation_delta.y = 0.0;
  this->m_input.actions_mask = 0;
  vostok::physics::bt_character_controller::initialize(
    v10,
    (unsigned int)&this->m_linear_horizontal_speed,
    *(const vostok::math::float4x4 **)((char *)&dword_10E74 + (_DWORD)this),
    (vostok::math::float4x4 *)&byte_10E2C[(_DWORD)this],
    id);
  (*(void (__thiscall **)(_DWORD, char *, _DWORD, _DWORD, int))(**(_DWORD **)(*(int *)((char *)&dword_10E78
                                                                                     + (_DWORD)this)
                                                                            + 300)
                                                              + 24))(
    *(_DWORD *)(*(int *)((char *)&dword_10E78 + (_DWORD)this) + 300),
    &byte_10E2C[(_DWORD)this],
    LODWORD(a3),
    HIDWORD(a3),
    a2);
  vostok::animation::animation_player::reset(
    v11,
    (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this->m_animation_player);
  survarium::game_effect_player::reset(v12, &this->m_effect_player.m_current_time_in_ms, (unsigned int)time_in_ms);
  survarium::damage_model::reset(
    v13,
    (survarium::loose_ptr<survarium::game_effect,survarium::loose_ptr_data,vostok::threading::single_threading_policy>)this->m_damage_model.m_object,
    time_in_ms);
  v14 = (char *)this + (_DWORD)&loc_1106F + 1;
  v15 = *(float *)(&this->m_children_resources.gapC + (_DWORD)&loc_1106F + 1);
  *((_DWORD *)v14 + 37) = -1;
  *((_DWORD *)v14 + 36) = time_in_ms;
  *((float *)v14 + 35) = v15;
  v14[152] = 0;
  survarium::player_stamina::clear_subscribers(
    v16,
    (survarium::base_player_vtbl **)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                   + (_DWORD)&loc_1106F
                                   + 1));
  survarium::inventory::unload_to_profile(
    v17,
    (survarium::player_profile *)this->m_inventory.m_object,
    *(int *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
           + (_DWORD)&loc_11066
           + 2));
  survarium::inventory::setup_from_profile(
    v18,
    0.0,
    (survarium::player_profile *)this->m_inventory.m_object,
    *(int *)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
           + (_DWORD)&loc_11066
           + 2));
  m_object = this->m_inventory.m_object;
  if ( m_object->m_slots.elems[7].m_object
    && (v19 = (survarium::inventory *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
  {
    survarium::inventory::action(
      (survarium::inventory *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      m_object,
      7,
      1u,
      this->m_current_time_in_ms);
  }
  else if ( m_object->m_slots.elems[10].m_object
         && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::inventory::action(v19, m_object, 10, 1u, this->m_current_time_in_ms);
  }
  else
  {
    this->m_target_active_object = 0;
  }
  m_target_active_object = this->m_target_active_object;
  if ( m_target_active_object )
  {
    p_m_current_active_object = &this->m_current_active_object;
    this->m_current_active_object = m_target_active_object;
    m_target_active_object->set_user(m_target_active_object, this);
    (*p_m_current_active_object)->initialize(*p_m_current_active_object);
    (*p_m_current_active_object)->activate(*p_m_current_active_object, 1);
    survarium::base_player::select_animations(
      v23,
      this,
      (vostok::animation::subscribed_channel **)this->m_current_time_in_ms);
  }
  this->m_spotted_time_left_in_ms = 0;
  this->m_time_left_to_try_spot_in_ms = 0;
  this->m_linear_horizontal_speed = 0.0;
}
