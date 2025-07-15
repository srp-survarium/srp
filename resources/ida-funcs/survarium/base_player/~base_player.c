void __thiscall survarium::base_player::~base_player(survarium::base_player *this)
{
  vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *p_m_damage_model; // esi
  survarium::damage_model *m_object; // ecx
  vostok::physics::bt_character_controller *v4; // edi
  survarium::damage_model *v5; // ecx
  survarium::body_part_parameters *body_part; // eax
  vostok::physics::bt_character_controller *m_first; // ecx
  vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *p_m_events_subscribers; // eax
  vostok::physics::bt_character_controller *v9; // edx
  vostok::physics::old_bullet_character_controller *m_old_controller; // esi
  void **v11; // esi
  vostok::memory::doug_lea_allocator *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  survarium::vector<vostok::resources::request> *v15; // ecx
  vostok::animation::animation_player *v16; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v17; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v18; // ecx
  survarium::affect_subscriber *p_m_leg_damaged_subscriber; // [esp-4h] [ebp-14h]
  const char *v20; // [esp+0h] [ebp-10h]
  const char *v21; // [esp+4h] [ebp-Ch]
  unsigned int v22; // [esp+8h] [ebp-8h]
  vostok::memory::doug_lea_allocator *v23; // [esp+Ch] [ebp-4h]

  p_m_leg_damaged_subscriber = &this->m_leg_damaged_subscriber;
  p_m_damage_model = &this->m_damage_model;
  m_object = this->m_damage_model.m_object;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::base_player_vtbl *)&survarium::base_player::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::inventory_holder::__vftable = (survarium::inventory_holder_vtbl *)&survarium::base_player::`vftable'{for `survarium::inventory_holder'};
  this->survarium::collision_user::__vftable = (survarium::collision_user_vtbl *)&survarium::base_player::`vftable'{for `survarium::collision_user'};
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::base_player::`vftable'{for `survarium::hit_initiator'};
  this->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::base_player::`vftable'{for `survarium::hit_receiver'};
  this->survarium::spottable_object::__vftable = (survarium::spottable_object_vtbl *)&survarium::base_player::`vftable'{for `survarium::spottable_object'};
  survarium::damage_model::unsubscribe_from_affect(m_object, affects_type_leg_damage, p_m_leg_damaged_subscriber);
  survarium::damage_model::unsubscribe_from_affect(
    p_m_damage_model->m_object,
    affects_type_hand_damage,
    &this->m_hand_damaged_subscriber);
  v4 = (vostok::physics::bt_character_controller *)((char *)&loc_11020 + (_DWORD)this);
  body_part = survarium::damage_model::get_body_part(v5, (int)p_m_damage_model->m_object, "pain");
  m_first = (vostok::physics::bt_character_controller *)body_part->m_events_subscribers.m_first;
  p_m_events_subscribers = &body_part->m_events_subscribers;
  if ( m_first )
  {
    v9 = 0;
    while ( m_first != v4 )
    {
      v9 = m_first;
      m_first = (vostok::physics::bt_character_controller *)m_first[5].m_old_controller;
      if ( !m_first )
      {
        if ( v4 )
          goto LABEL_13;
        break;
      }
    }
    m_old_controller = m_first[5].m_old_controller;
    if ( v9 )
      v9[5].m_old_controller = m_old_controller;
    else
      p_m_events_subscribers->m_first = (survarium::body_part_events_subscriber *)m_old_controller;
    if ( !m_first[5].m_old_controller )
    {
      m_first = v9;
      if ( !v9 )
        m_first = (vostok::physics::bt_character_controller *)p_m_events_subscribers->m_first;
      p_m_events_subscribers->m_last = (survarium::body_part_events_subscriber *)m_first;
    }
  }
LABEL_13:
  v11 = *(void ***)((char *)&dword_10E74 + (_DWORD)this);
  v23 = survarium::g_allocator;
  if ( v11 )
  {
    vostok::physics::bt_character_controller::~bt_character_controller(m_first, v11);
    vostok::memory::doug_lea_allocator::free_impl(v12, (int)v23, (char *)v11, v20, v21, v22);
    *(int *)((char *)&dword_10E74 + (_DWORD)this) = 0;
  }
  survarium::player_stamina::~player_stamina((survarium::player_stamina *)m_first, (int)this + (_DWORD)&loc_1106F + 1);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)((char *)&loc_11020 + (_DWORD)this + 32));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)((char *)&loc_11020 + (_DWORD)this));
  `vector destructor iterator'(
    &byte_10EB8[(_DWORD)this],
    0x28u,
    9,
    (void (__thiscall *)(void *))survarium::affect_subscriber::~affect_subscriber);
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>(v15);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_10E78 + (_DWORD)this));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&dword_10E28 + (_DWORD)this));
  vostok::animation::animation_player::~animation_player(v16, (BOOL)&this->m_animation_player);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_effect_player.m_effects.vostok::threading::mutex);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_damage_model);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v17,
    (int *)&this->m_hand_damaged_subscriber);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v18,
    (int *)&this->m_leg_damaged_subscriber);
  this->m_speed_parameters.m_landing_speed.m_end = this->m_speed_parameters.m_landing_speed.m_begin;
  this->m_speed_parameters.m_multipliers.m_end = this->m_speed_parameters.m_multipliers.m_begin;
  this->survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::hit_receiver_vtbl *)&survarium::hit_receiver::`vftable';
  this->survarium::hit_initiator::__vftable = (survarium::hit_initiator_vtbl *)&survarium::hit_initiator::`vftable';
  this->survarium::collision_user::__vftable = (survarium::collision_user_vtbl *)&survarium::collision_user::`vftable';
  this->survarium::inventory_holder::__vftable = (survarium::inventory_holder_vtbl *)&survarium::inventory_holder::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_inventory);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
