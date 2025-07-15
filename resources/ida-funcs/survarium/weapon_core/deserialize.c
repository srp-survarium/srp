void __thiscall survarium::weapon_core::deserialize(
        survarium::weapon_core *this,
        vostok::network_core::packet_reader *reader)
{
  boost::_bi::list1<vostok::network_core::packet_reader &> *v2; // eax
  vostok::network_core::packet_reader *v3; // ecx
  unsigned __int8 v4; // al
  vostok::network_core::packet_reader *v5; // ecx
  vostok::network_core::packet_reader *v6; // ecx
  survarium::inventory *inventory; // eax
  vostok::network_core::packet_reader *v8; // ecx
  vostok::network_core::packet_reader *v9; // ecx
  survarium::game_camera *v10; // ecx
  int v11; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v12; // ecx
  vostok::ai::fsm_state *v13; // ecx
  survarium::base_player *v14; // ecx
  unsigned int v15; // [esp+0h] [ebp-7Ch]
  survarium::weapon_user_animations_container *m_object; // [esp+28h] [ebp-54h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+2Ch] [ebp-50h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *p_m_ammunition; // [esp+30h] [ebp-4Ch]
  survarium::weapon_ammunition *v20; // [esp+34h] [ebp-48h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+38h] [ebp-44h] BYREF
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v22; // [esp+3Ch] [ebp-40h]
  survarium::weapon_user_animations_container *object; // [esp+40h] [ebp-3Ch]
  survarium::weapon_user_animations_container *v24; // [esp+44h] [ebp-38h]
  int v25; // [esp+5Ch] [ebp-20h]
  int destination; // [esp+60h] [ebp-1Ch] BYREF
  char v27; // [esp+6Bh] [ebp-11h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+6Ch] [ebp-10h] BYREF
  vostok::ai::fsm_state *i; // [esp+70h] [ebp-Ch]
  unsigned __int8 target_state_id; // [esp+76h] [ebp-6h]
  unsigned __int8 state_id; // [esp+77h] [ebp-5h]
  vostok::ai::fsm_state *current; // [esp+78h] [ebp-4h]

  survarium::inventory_item::deserialize(&this->survarium::inventory_item, reader);
  this->m_deserializing = 1;
  v2 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)vostok::network_core::packet_reader::r<unsigned int>(
                                                                     (vostok::network_core::packet_reader *)this,
                                                                     (int)reader);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v2,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&this->m_random);
  vostok::network_core::packet_reader::r(reader, 4u, (unsigned __int8 *)&destination, v15);
  v3 = (vostok::network_core::packet_reader *)destination;
  v25 = destination;
  this->m_normal_random.m_seed = destination;
  v4 = vostok::network_core::packet_reader::r<unsigned char>(v3, (int)reader);
  this->m_target = v4;
  this->m_old_actions_mask = vostok::network_core::packet_reader::r<unsigned int>(
                               (vostok::network_core::packet_reader *)v4,
                               (int)reader);
  this->m_ammo_in_magazine = vostok::network_core::packet_reader::r<unsigned short>(
                               (vostok::network_core::packet_reader *)this,
                               (int)reader);
  this->m_bullets_in_queue = vostok::network_core::packet_reader::r<unsigned short>(v5, (int)reader);
  this->m_fire_queue_type = vostok::network_core::packet_reader::r<unsigned char>(
                              (vostok::network_core::packet_reader *)this,
                              (int)reader);
  this->m_ammo_slot = vostok::network_core::packet_reader::r<unsigned char>(v6, (int)reader);
  if ( this->m_ammo_slot == max_slots_count )
  {
    v18.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v18,
      0);
    m_object = v18.m_object;
    v18.m_object = (survarium::weapon_user_animations_container *)this->m_ammunition.m_object;
    this->m_ammunition.m_object = (survarium::weapon_ammunition *)m_object;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
  }
  else
  {
    inventory = survarium::inventory_item::get_inventory(&this->survarium::inventory_item, (int)this);
    v22 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)survarium::inventory::item_in_slot((survarium::inventory *)this->m_ammo_slot, (int)inventory);
    v24 = (survarium::weapon_user_animations_container *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v22);
    object = v24;
    v28.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v28,
      v24);
    p_m_ammunition = &this->m_ammunition;
    v21.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v21,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v28);
    v20 = (survarium::weapon_ammunition *)v21.m_object;
    v21.m_object = (vostok::ai::behaviour *)this->m_ammunition.m_object;
    this->m_ammunition.m_object = v20;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
  }
  if ( this->m_is_there_chamber_a_round_state )
    this->m_is_round_chambered = vostok::network_core::packet_reader::r<unsigned char>(v8, (int)reader);
  if ( this->m_logic->m_current_state )
  {
    this->m_is_shown = vostok::network_core::packet_reader::r<unsigned char>(
                         (vostok::network_core::packet_reader *)this->m_logic->m_current_state,
                         (int)reader);
    survarium::hand_to_weapon_ik_processor::deserialize(&this->m_hand_ik_processor, reader);
    target_state_id = vostok::network_core::packet_reader::r<unsigned char>(v9, (int)reader);
    state_id = 0;
    current = 0;
    survarium::weapon_user_dead_state::finalize(v10);
    i = (vostok::ai::fsm_state *)boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
                                   v12,
                                   v11);
    while ( i )
    {
      v13 = (vostok::ai::fsm_state *)state_id;
      if ( state_id == target_state_id )
      {
        current = i;
        break;
      }
      v13 = i;
      i = i->next;
      ++state_id;
    }
    v27 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v13);
    vostok::ai::fsm::set_initial_state(this->m_logic, current);
    ((void (__thiscall *)(vostok::ai::fsm_state *, vostok::network_core::packet_reader *))this->m_logic->m_current_state->__vftable[1].initialize)(
      this->m_logic->m_current_state,
      reader);
    survarium::weapon_user_animations_selector::deserialize(&this->m_user_animations_selector, reader);
    survarium::base_player::force_animation_selection(v14, (int)this->m_user);
  }
  this->m_deserializing = 0;
}
