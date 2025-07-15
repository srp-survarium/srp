void __thiscall survarium::weapon_core::deserialize(
        survarium::weapon_core *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // esi
  survarium::profile_slot_enum *m_ammunition_slots; // eax
  survarium::profile_slot_enum v9; // eax
  vostok::particle::particle_system_instance_impl *v10; // esi
  survarium::weapon_ammunition *m_object; // ecx
  vostok::network_core::buffer_reader *v12; // esi
  survarium::dispersion_calculator *v13; // ecx
  bool v14; // al
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  vostok::threading::mutex *v16; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::arg<1> > > v17; // [esp-14h] [ebp-4Ch]
  unsigned int v18; // [esp+0h] [ebp-38h]
  unsigned __int8 v19; // [esp+13h] [ebp-25h]
  unsigned __int8 v20; // [esp+13h] [ebp-25h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v21; // [esp+14h] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+18h] [ebp-20h] BYREF

  survarium::inventory_item::deserialize(&this->survarium::inventory_item, reader, client_reader, time_offset);
  m_pointer = reader->m_pointer;
  v21.m_object = *(vostok::particle::particle_system_instance_impl **)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_random_generator._x = (unsigned int)v21.m_object;
  v6 = reader->m_pointer;
  v21.m_object = *(vostok::particle::particle_system_instance_impl **)v6;
  reader->m_pointer = v6 + 4;
  this->m_last_tick_time_in_ms = (unsigned int)v21.m_object;
  this->m_load_ammo_on_next_activate = vostok::network_core::buffer_reader::r<bool>(reader);
  this->m_ammo_in_magazine = vostok::network_core::buffer_reader::r<unsigned short>(reader);
  this->m_bullets_in_queue = vostok::network_core::buffer_reader::r<unsigned short>(reader);
  v19 = *reader->m_pointer++;
  this->m_fire_queue_type = v19;
  v7 = reader->m_pointer;
  v20 = *v7;
  reader->m_pointer = v7 + 1;
  m_ammunition_slots = this->m_ammunition_slots;
  this->m_selected_ammo_id = v20;
  if ( !m_ammunition_slots || (v9 = m_ammunition_slots[v20], v9 == max_slots_count) )
  {
    m_object = this->m_ammunition.m_object;
    this->m_ammunition.m_object = 0;
    v21.m_object = (vostok::particle::particle_system_instance_impl *)m_object;
  }
  else
  {
    v10 = (vostok::particle::particle_system_instance_impl *)this->m_inventory->m_slots.elems[v9].m_object;
    v21.m_object = 0;
    if ( v10 )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
      v21.m_object = v10;
      _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v21,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_ammunition);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v21);
  v12 = reader;
  if ( this->m_is_there_chamber_a_round_state )
    this->m_is_round_chambered = vostok::network_core::buffer_reader::r<bool>(reader);
  if ( this->m_user )
  {
    survarium::recoil_calculator::deserialize(&this->m_recoil_calculator, reader, time_offset);
    survarium::dispersion_calculator::deserialize(
      v13,
      (vostok::network_core::buffer_reader *)&this->m_dispersion_calculator,
      reader,
      time_offset);
    this->m_aimed = vostok::network_core::buffer_reader::r<bool>(reader);
    survarium::transition_helper::deserialize(&this->m_aim_progress, reader, time_offset);
    if ( this->m_aimed )
      survarium::breath_vibration_calculator::deserialize(
        reader,
        &this->m_breath_vibration_calculator,
        client_reader,
        v18);
    v14 = vostok::network_core::buffer_reader::r<bool>(reader);
    this->m_is_in_sprint_transition = v14;
    if ( v14 )
    {
      (&f.vtable)[1] = 0;
      f.functor.obj_ptr = (void *)this;
      f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core::on_sprint_animation_ended;
      HIDWORD(v17.f_.f_) = survarium::weapon_core::on_sprint_animation_ended;
      *(_QWORD *)&v17.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
      LODWORD(v17.f_.f_) = &f;
      v21.m_object = 0;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        0,
        v17,
        (int)f.functor.vostok_pointer_size_alignment[1]);
      survarium::base_player::subscribe_animation_player(
        (survarium::base_player *)&f,
        (vostok::animation::reserved_channel_ids_enum)this->m_user,
        (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)3,
        &f,
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
        (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v21,
        this->m_user);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v15,
        (int *)&f);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v21);
      v12 = reader;
    }
    this->m_need_to_auto_reload = vostok::network_core::buffer_reader::r<bool>(v12);
    vostok::ai::fsm::deserialize(this->m_logic, v12, client_reader);
    this->m_portable_interactive_object->deserialize(
      this->m_portable_interactive_object,
      v12,
      client_reader,
      time_offset);
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_user->m_profile->modifiers.m_modifiers.elems[4],
      &this->m_move_speed_modifier,
      v16);
  }
}


void __thiscall survarium::weapon_core::deserialize(
        char *this,
        vostok::network_core::buffer_reader *a2,
        vostok::network_core::buffer_reader *a3,
        unsigned int a4)
{
  survarium::weapon_core::deserialize((survarium::weapon_core *)(this - 16), a2, a3, a4);
}
