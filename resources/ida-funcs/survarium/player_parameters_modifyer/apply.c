void __thiscall survarium::player_parameters_modifyer::apply(
        survarium::player_parameters_modifyer *this,
        survarium::base_player *player)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  survarium::inventory_holder *v7; // eax
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v8; // ecx
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // ecx
  btSoftRigidDynamicsWorld *v15; // ecx
  int v16; // eax
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  const vostok::variant<32> **v19; // eax
  const char *armor; // [esp+0h] [ebp-23Ch]
  float max_health; // [esp+4h] [ebp-238h]
  const vostok::variant<32> **regeneration_speed; // [esp+8h] [ebp-234h]
  const vostok::variant<32> **v23; // [esp+10h] [ebp-22Ch]
  const vostok::variant<32> **v25; // [esp+28h] [ebp-214h]
  survarium::game_camera v26; // [esp+2Ch] [ebp-210h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v27; // [esp+B4h] [ebp-188h]
  float m_max_health; // [esp+B8h] [ebp-184h]
  float m_regeneration_speed; // [esp+BCh] [ebp-180h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *M_left; // [esp+150h] [ebp-ECh]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v31; // [esp+154h] [ebp-E8h]
  int v32; // [esp+158h] [ebp-E4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v33; // [esp+15Ch] [ebp-E0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+17Ch] [ebp-C0h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v35; // [esp+1A0h] [ebp-9Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v36; // [esp+1A4h] [ebp-98h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v37; // [esp+1A8h] [ebp-94h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v38; // [esp+1ACh] [ebp-90h] BYREF
  int j; // [esp+1B0h] [ebp-8Ch]
  float anomaly_scale; // [esp+1B4h] [ebp-88h]
  float health; // [esp+1B8h] [ebp-84h]
  float regen; // [esp+1BCh] [ebp-80h]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> item; // [esp+1C0h] [ebp-7Ch] BYREF
  survarium::weapon_core *wc; // [esp+1C4h] [ebp-78h]
  survarium::dispersion_calculator *dc; // [esp+1C8h] [ebp-74h]
  unsigned int i; // [esp+1CCh] [ebp-70h]
  vostok::fixed_string<16> hit_type_name; // [esp+1D0h] [ebp-6Ch] BYREF
  survarium::hit_type_parameters *current_hit_type_parameters; // [esp+1ECh] [ebp-50h]
  survarium::hit_type_parameters_modifyer *current_hit_type_modifyer; // [esp+1F0h] [ebp-4Ch]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<16> const ,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<vostok::fixed_string<16> const ,survarium::hit_type_parameters_modifyer> > > hit_type_it; // [esp+1F4h] [ebp-48h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<16> const ,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<vostok::fixed_string<16> const ,survarium::hit_type_parameters_modifyer> > > hit_type_it_e; // [esp+1F8h] [ebp-44h] BYREF
  vostok::fixed_string<16> body_part_name; // [esp+1FCh] [ebp-40h] BYREF
  survarium::body_part_parameters *current_body_part_parameters; // [esp+218h] [ebp-24h]
  survarium::body_part_parameters_modifyer *current_body_part_modifyer; // [esp+21Ch] [ebp-20h]
  survarium::inventory *invent; // [esp+220h] [ebp-1Ch]
  survarium::player_stamina *stamn; // [esp+224h] [ebp-18h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> > > body_part_it_e; // [esp+228h] [ebp-14h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> > > body_part_it; // [esp+22Ch] [ebp-10h] BYREF
  survarium::body_part_parameters *body_part; // [esp+230h] [ebp-Ch]
  survarium::bodypart_health_regen_scale_predicate hr_predicate; // [esp+234h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> damage_model; // [esp+238h] [ebp-4h] BYREF

  v32 = 0;
  v31 = (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)player->damage_model(player);
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
    v31,
    (survarium::inventory **)&damage_model);
  M_left = (boost::_bi::list1<vostok::network_core::packet_reader &> *)this->body_part_parameters_modifyers._M_t._M_header._M_data._M_left;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    M_left,
    &v38);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v38,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&body_part_it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->body_part_parameters_modifyers,
    &v37);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v37,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&body_part_it_e);
  while ( body_part_it._M_node != body_part_it_e._M_node )
  {
    vostok::fixed_string<16>::fixed_string<16>(
      &body_part_name,
      (const vostok::fixed_string<16> *)&body_part_it._M_node[1]);
    regeneration_speed = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v2,
                           (int)&body_part_name);
    v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)&damage_model);
    current_body_part_parameters = survarium::damage_model::get_body_part(
                                     (survarium::damage_model *)v4,
                                     (const char *)regeneration_speed);
    current_body_part_modifyer = (survarium::body_part_parameters_modifyer *)stlp_std::map<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::body_part_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                                                                               &this->body_part_parameters_modifyers,
                                                                               &body_part_name);
    m_regeneration_speed = current_body_part_parameters->m_regeneration_speed;
    m_max_health = current_body_part_parameters->m_max_health;
    survarium::body_part_parameters::set_parameters(
      current_body_part_parameters,
      m_max_health + current_body_part_modifyer->health,
      m_regeneration_speed + current_body_part_modifyer->health_regeneration);
    v27 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)current_body_part_modifyer->hit_type_modifyers._M_t._M_header._M_data._M_left;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v27,
      &v36);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v36,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&hit_type_it);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)&current_body_part_modifyer->hit_type_modifyers,
      &v35);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v35,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&hit_type_it_e);
    while ( hit_type_it._M_node != hit_type_it_e._M_node )
    {
      vostok::fixed_string<16>::fixed_string<16>(
        &hit_type_name,
        (const vostok::fixed_string<16> *)&hit_type_it._M_node[1]);
      v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             v5,
             (int)&hit_type_name);
      current_hit_type_parameters = (survarium::hit_type_parameters *)survarium::body_part_parameters::get_hit_parameters(
                                                                        current_body_part_parameters,
                                                                        (const char *)v6);
      current_hit_type_modifyer = (survarium::hit_type_parameters_modifyer *)stlp_std::map<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer,stlp_std::less<vostok::fixed_string<16>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::operator[]<vostok::fixed_string<16>>(
                                                                               &current_body_part_modifyer->hit_type_modifyers,
                                                                               &hit_type_name);
      survarium::hit_type_parameters::set_parameters(
        current_hit_type_parameters,
        current_hit_type_modifyer->armor,
        current_hit_type_modifyer->reduce,
        current_hit_type_modifyer->absorption);
      hit_type_it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(hit_type_it._M_node);
    }
    body_part_it._M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(body_part_it._M_node);
  }
  v7 = player->cast_to_inventory_holder(&player->survarium::collision_user);
  invent = (survarium::inventory *)boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
                                     v8,
                                     (int)v7);
  for ( i = 0; i < 2; ++i )
  {
    v9 = survarium::inventory::item_in_slot((survarium::inventory *)weapon_slots_0[i], (int)invent);
    vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
      (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v9,
      (survarium::inventory **)&item);
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(&item.vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>) )
      goto LABEL_11;
    v23 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)&item);
    wc = (survarium::weapon_core *)(*(int (__thiscall **)(const vostok::variant<32> **))&(*v23)[1].m_storage[28])(v23);
    if ( !wc )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", warning) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v11);
        v32 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\player_parameters_cook.cpp",
          0x55u,
          "void __thiscall survarium::player_parameters_modifyer::apply(struct survarium::base_player *)",
          "game_core:",
          warning,
          "non-weapon item in weapon slot");
      }
      if ( (v32 & 1) != 0 )
      {
        v32 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11,
          (int *)&log_callback);
      }
LABEL_11:
      vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&item);
      continue;
    }
    dc = &wc->m_dispersion_calculator;
    survarium::dispersion_calculator::set_shooting_skill_coeff(
      &wc->m_dispersion_calculator,
      (float)(this->dispersion_correction_perc / 100.0) + *(float *)&clear_value);
    survarium::dispersion_calculator::set_aiming_speed_coeff(
      dc,
      (float)(this->aiming_speed_correction_perc / 100.0) + *(float *)&clear_value);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&item);
  }
  v26.m_inverted_view_matrix.j.z = (float)(this->movement_speed_correction_perc / 100.0) + *(float *)&clear_value;
  player->m_movement_speed_factor = v26.m_inverted_view_matrix.j.z;
  stamn = player->stamina(player);
  v26.m_inverted_view_matrix.j.y = stamn->m_max_carried_weight;
  v26.m_inverted_view_matrix.j.x = v26.m_inverted_view_matrix.j.y + this->additional_max_weight;
  stamn->m_max_carried_weight = v26.m_inverted_view_matrix.j.x;
  survarium::player_stamina::set_regeneration_speed_factor(
    stamn,
    (float)(this->stamina_regen_correction_perc / 100.0) + *(float *)&clear_value);
  v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, (int)&damage_model);
  body_part = survarium::damage_model::get_body_part((survarium::damage_model *)v13, "pain");
  if ( body_part )
  {
    v26.m_inverted_view_matrix.i.z = body_part->m_max_health;
    health = (float)((float)(this->pain_healt_correction_perc / 100.0) + *(float *)&clear_value)
           * v26.m_inverted_view_matrix.i.z;
    regen = body_part->m_regeneration_speed;
    survarium::body_part_parameters::set_parameters(body_part, health, regen);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", warning) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v14);
      v32 |= 2u;
      vostok::logging::append(
        &v33,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\player_parameters_cook.cpp",
        0x75u,
        "void __thiscall survarium::player_parameters_modifyer::apply(struct survarium::base_player *)",
        "game_core:",
        warning,
        "there's no 'pain' bodypart, pain health will not be scaled");
    }
    if ( (v32 & 2) != 0 )
    {
      v32 &= ~2u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v14,
        (int *)&v33);
    }
  }
  v26.m_inverted_view_matrix.i.y = (float)(this->health_regen_correction_perc / 100.0) + *(float *)&clear_value;
  hr_predicate.m_coeff = v26.m_inverted_view_matrix.i.y;
  v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v14,
          (int)&damage_model);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v26);
  v26.__vftable = (survarium::game_camera_vtbl *)&hr_predicate;
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::bodypart_health_regen_scale_predicate>>(
    (vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(v25 + 66),
    (const vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::bodypart_health_regen_scale_predicate> *)&v26);
  survarium::weapon_user_dead_state::finalize(&v26);
  v15 = (btSoftRigidDynamicsWorld *)player;
  player->m_usable_object_user_data.booster_artcont_time_factor = (float)(this->artcontainer_time_corr_perc / 100.0)
                                                                + *(float *)&clear_value;
  if ( this->anomaly_damage_corr_perc != 0.0 )
  {
    anomaly_scale = (float)(this->anomaly_damage_corr_perc / 100.0) + *(float *)&clear_value;
    for ( j = 0; ; ++j )
    {
      v16 = vostok::array_size<char const *,4>(v15);
      if ( j == v16 )
        break;
      max_health = anomaly_scale;
      armor = anomaly_damage_types[j];
      v17 = player->damage_model(player);
      v19 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v18, (int)v17);
      survarium::damage_model::add_damage_protector((survarium::damage_model *)v19, armor, max_health, 0.0);
      v15 = (btSoftRigidDynamicsWorld *)(j + 1);
    }
  }
  player->m_usable_object_user_data.booster_engineer_use_time_factor = (float)(this->engineer_use_time_corr_perc / 100.0)
                                                                     + *(float *)&clear_value;
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&damage_model);
}
