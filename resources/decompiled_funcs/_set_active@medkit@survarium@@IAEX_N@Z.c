void __thiscall survarium::medkit::set_active(survarium::medkit *this, bool bactive)
{
  survarium::medkit *v2; // eax
  survarium::inventory_holder *v3; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  survarium::base_project::resolve_link_object *v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  survarium::inventory_holder *v7; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v8; // ecx
  survarium::base_project::resolve_link_object *v9; // eax
  int v10; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v11; // ecx
  const vostok::variant<32> **v12; // eax
  int v13; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::variant<32> **v15; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v16; // [esp-10h] [ebp-9Ch]
  char *body_part_name; // [esp-4h] [ebp-90h]
  char *v18; // [esp-4h] [ebp-90h]
  survarium::medkit::damage_protection *new_regeneration_speed; // [esp+0h] [ebp-8Ch]
  survarium::medkit::damage_protection *new_regeneration_speeda; // [esp+0h] [ebp-8Ch]
  survarium::inventory_holder *v21; // [esp+8h] [ebp-84h]
  survarium::inventory_holder *v22; // [esp+Ch] [ebp-80h]
  int v23; // [esp+10h] [ebp-7Ch]
  survarium::inventory_holder *v24; // [esp+14h] [ebp-78h]
  survarium::medkit *thisa; // [esp+18h] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+44h] [ebp-48h] BYREF
  void (__thiscall *f)(survarium::medkit *, const unsigned int); // [esp+54h] [ebp-38h]
  int f_4; // [esp+58h] [ebp-34h]
  boost::function2<void,unsigned int,unsigned int> v29; // [esp+5Ch] [ebp-30h] BYREF
  survarium::medkit::damage_protection *dmgp; // [esp+80h] [ebp-Ch]
  unsigned int i; // [esp+84h] [ebp-8h]
  survarium::player_stamina *stamina; // [esp+88h] [ebp-4h]

  thisa = this;
  v2 = this;
  LOBYTE(this) = bactive;
  v2->m_active = bactive;
  if ( thisa->m_active )
  {
    thisa->m_activity_time_ms = thisa->m_config_activity_time_ms;
    thisa->m_delay_ms = thisa->m_config_delay_ms;
    f = survarium::medkit::active_tick;
    f_4 = 0;
    v16 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::medkit::active_tick,
             (survarium::weapon_core_animation_end_aware_state *)thisa);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      &v29,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::medkit,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::medkit *>,boost::arg<1> > >)v16,
      0);
    v3 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v4,
           (int)v3);
    survarium::scheduler::register_for_update(
      (survarium::scheduler *)&v29,
      1,
      (survarium::scheduler *)v5,
      &thisa->m_scheduler_identifier,
      0x12Cu,
      1u,
      0);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v6,
      (int *)&v29);
  }
  else
  {
    v24 = survarium::inventory::holder((survarium::inventory *)this, (int)thisa->m_inventory);
    v23 = (int)v24->cast_to_base_player(v24);
    stamina = (survarium::player_stamina *)(*(int (__thiscall **)(int))(*(_DWORD *)v23 + 52))(v23);
    survarium::player_stamina::set_regeneration_speed(
      stamina,
      stamina->m_regeneration_speed - thisa->m_add_stamina_regen);
    v7 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
    v9 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v8,
           (int)v7);
    survarium::scheduler::unregister((survarium::scheduler *)v9, &thisa->m_scheduler_identifier);
  }
  for ( i = 0; i < thisa->m_damage_protect_count; ++i )
  {
    dmgp = &thisa->m_damage_protect[i];
    if ( thisa->m_active )
    {
      v22 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
      new_regeneration_speed = dmgp;
      body_part_name = dmgp->body_part_name;
      v10 = (int)v22->damage_model(v22);
      v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v11, v10);
      survarium::damage_model::register_body_part_damage_protector(
        (survarium::damage_model *)v12,
        body_part_name,
        &new_regeneration_speed->protector);
    }
    else
    {
      v21 = survarium::inventory::holder((survarium::inventory *)thisa, (int)thisa->m_inventory);
      new_regeneration_speeda = dmgp;
      v18 = dmgp->body_part_name;
      v13 = (int)v21->damage_model(v21);
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v14, v13);
      survarium::damage_model::unregister_body_part_damage_protector(
        (survarium::damage_model *)v15,
        v18,
        &new_regeneration_speeda->protector);
    }
  }
}
