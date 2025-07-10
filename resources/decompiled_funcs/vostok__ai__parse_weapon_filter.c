void __cdecl vostok::ai::parse_weapon_filter(
        vostok::configs::binary_config_value *filter_options,
        survarium::weapon_core_animation_end_aware_state *world,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *filter)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp-14h] [ebp-2ECh]
  boost::function1<unsigned int,char const *> v7; // [esp+140h] [ebp-198h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v8; // [esp+160h] [ebp-178h]
  boost::function1<unsigned int,char const *> v9; // [esp+170h] [ebp-168h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v10; // [esp+190h] [ebp-148h]
  boost::function1<unsigned int,char const *> v11; // [esp+1A0h] [ebp-138h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v12; // [esp+1C0h] [ebp-118h]
  boost::function1<unsigned int,char const *> v13; // [esp+1D0h] [ebp-108h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v14; // [esp+1F0h] [ebp-E8h]
  boost::function1<unsigned int,char const *> v15; // [esp+200h] [ebp-D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v16; // [esp+220h] [ebp-B8h] BYREF
  void (__thiscall *v17)(vostok::ai::ai_world *, const char *); // [esp+230h] [ebp-A8h]
  int v18; // [esp+234h] [ebp-A4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v19; // [esp+238h] [ebp-A0h] BYREF
  void (__thiscall *v20)(vostok::ai::ai_world *, const char *); // [esp+248h] [ebp-90h]
  int v21; // [esp+24Ch] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v22; // [esp+250h] [ebp-88h] BYREF
  void (__thiscall *v23)(vostok::ai::ai_world *, const char *); // [esp+260h] [ebp-78h]
  int v24; // [esp+264h] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v25; // [esp+268h] [ebp-70h] BYREF
  void (__thiscall *v26)(vostok::ai::ai_world *, const char *); // [esp+278h] [ebp-60h]
  int v27; // [esp+27Ch] [ebp-5Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+280h] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::ai::ai_world *, const char *); // [esp+290h] [ebp-48h]
  int f_4; // [esp+294h] [ebp-44h]
  const char *name; // [esp+298h] [ebp-40h]
  const vostok::configs::binary_config_value *value; // [esp+29Ch] [ebp-3Ch]
  unsigned int id; // [esp+2A0h] [ebp-38h]
  vostok::ai::weapon_filter_types_enum subfilter_type; // [esp+2A4h] [ebp-34h]
  boost::function<unsigned int __cdecl(char const *)> selector; // [esp+2A8h] [ebp-30h] BYREF
  const vostok::configs::binary_config_value *it_end; // [esp+2C8h] [ebp-10h]
  const vostok::configs::binary_config_value *values; // [esp+2CCh] [ebp-Ch]
  unsigned int subfilter_id; // [esp+2D0h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+2D4h] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](filter_options, "subtype");
  subfilter_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v4,
                                 (int)v3);
  subfilter_type = subfilter_id;
  (&filter[1].vtable)[1] = (boost::detail::function::vtable_base *)subfilter_id;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(filter, &selector);
  switch ( subfilter_type )
  {
    case weapon_filter_type_melee:
      f = vostok::ai::ai_world::get_melee_weapon_id_by_name;
      f_4 = 0;
      v14 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_melee_weapon_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v15, v14, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v15,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v15);
      break;
    case weapon_filter_type_sniper:
      v26 = vostok::ai::ai_world::get_sniper_weapon_id_by_name;
      v27 = 0;
      v12 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v25, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_sniper_weapon_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v13, v12, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v13,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v13);
      break;
    case weapon_filter_type_heavy:
      v23 = vostok::ai::ai_world::get_heavy_weapon_id_by_name;
      v24 = 0;
      v10 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v22, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_heavy_weapon_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v11, v10, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v11,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v11);
      break;
    case weapon_filter_type_energy:
      v17 = vostok::ai::ai_world::get_energy_weapon_id_by_name;
      v18 = 0;
      v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v16,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_energy_weapon_id_by_name,
              world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(
        &v7,
        (boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > >)v6,
        0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v7,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v7);
      break;
    case weapon_filter_type_light:
      v20 = vostok::ai::ai_world::get_light_weapon_id_by_name;
      v21 = 0;
      v8 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v19, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_light_weapon_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v9, v8, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v9,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v9);
      break;
  }
  values = vostok::configs::binary_config_value::operator[](filter_options, "weapons");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)values);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)values);
  while ( it != it_end )
  {
    value = it;
    name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v5,
                           (int)it);
    id = boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(&selector, name);
    if ( id != -1 )
      vostok::ai::planning::weapon_filter::add_filtered_id((vostok::ai::planning::weapon_filter *)filter, id);
    v5 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&it[1];
    ++it;
  }
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&selector);
}
