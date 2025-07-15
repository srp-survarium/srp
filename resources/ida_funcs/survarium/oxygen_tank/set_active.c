void __thiscall survarium::oxygen_tank::set_active(survarium::oxygen_tank *this, bool bactive)
{
  survarium::oxygen_tank *v2; // eax
  survarium::inventory_holder *v3; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  survarium::base_project::resolve_link_object *v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  survarium::inventory_holder *v8; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  survarium::base_project::resolve_link_object *v10; // eax
  int v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  int v14; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v15; // ecx
  const vostok::variant<32> **v16; // eax
  bool has_passed_filters; // al
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v18; // [esp-14h] [ebp-B8h]
  char *body_part_name; // [esp-8h] [ebp-ACh]
  char *v20; // [esp-8h] [ebp-ACh]
  survarium::damage_protector *p_protector; // [esp-4h] [ebp-A8h]
  survarium::damage_protector *v22; // [esp-4h] [ebp-A8h]
  const char *v23; // [esp+4h] [ebp-A0h]
  survarium::inventory_holder *v24; // [esp+8h] [ebp-9Ch]
  survarium::inventory_holder *v25; // [esp+Ch] [ebp-98h]
  survarium::oxygen_tank *thisa; // [esp+10h] [ebp-94h]
  char v27; // [esp+40h] [ebp-64h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+44h] [ebp-60h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+64h] [ebp-40h] BYREF
  void (__thiscall *f)(survarium::oxygen_tank *, const unsigned int); // [esp+74h] [ebp-30h]
  int f_4; // [esp+78h] [ebp-2Ch]
  boost::function2<void,unsigned int,unsigned int> v32; // [esp+7Ch] [ebp-28h] BYREF
  const survarium::oxygen_tank::item_influence *infl; // [esp+9Ch] [ebp-8h]
  unsigned int i; // [esp+A0h] [ebp-4h]

  thisa = this;
  v27 = 0;
  v2 = this;
  LOBYTE(this) = bactive;
  v2->m_active = bactive;
  if ( thisa->m_active )
  {
    f = survarium::oxygen_tank::active_tick;
    f_4 = 0;
    v18 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::oxygen_tank::active_tick,
             (survarium::weapon_core_animation_end_aware_state *)thisa);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      &v32,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::oxygen_tank,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1> > >)v18,
      0);
    v3 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v4,
           (int)v3);
    survarium::scheduler::register_for_update(
      (survarium::scheduler *)&v32,
      1,
      (survarium::scheduler *)v5,
      &thisa->m_scheduler_identifier,
      0x64u,
      1u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v6,
      (int *)&v32);
  }
  else
  {
    v8 = survarium::inventory::holder((survarium::inventory *)this, (int)thisa->m_inventory);
    v10 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
            v9,
            (int)v8);
    survarium::scheduler::unregister((survarium::scheduler *)v10, &thisa->m_scheduler_identifier);
  }
  for ( i = 0; i < thisa->m_influences_count; ++i )
  {
    infl = &thisa->m_influences[i];
    if ( thisa->m_active )
    {
      v25 = survarium::inventory::holder((survarium::inventory *)thisa->m_active, (int)thisa->m_inventory);
      p_protector = &thisa->m_influences[i].protector;
      body_part_name = infl->body_part_name;
      v11 = (int)v25->damage_model(v25);
      v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, v11);
      survarium::damage_model::register_body_part_damage_protector(
        (survarium::damage_model *)v13,
        body_part_name,
        p_protector);
    }
    else
    {
      v24 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
      v22 = &thisa->m_influences[i].protector;
      v20 = infl->body_part_name;
      v14 = (int)v24->damage_model(v24);
      v16 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v15, v14);
      survarium::damage_model::unregister_body_part_damage_protector((survarium::damage_model *)v16, v20, v22);
    }
    v7 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(i + 1);
  }
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", info),
        (v7 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)has_passed_filters) != 0) )
  {
    if ( bactive )
      v23 = "ON";
    else
      v23 = "OFF";
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v7);
    v27 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\oxygen_tank.cpp",
      0x54u,
      "void __thiscall survarium::oxygen_tank::set_active(bool)",
      "game_core:",
      info,
      "Oxygen Tank switched to [%s]. amount= %dms",
      v23,
      thisa->m_amount_ms);
  }
  if ( (v27 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v7,
      (int *)&log_callback);
}
