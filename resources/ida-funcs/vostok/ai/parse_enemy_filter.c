void __cdecl vostok::ai::parse_enemy_filter(
        vostok::configs::binary_config_value *filter_options,
        survarium::weapon_core_animation_end_aware_state *world,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *filter)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp-14h] [ebp-2A4h]
  boost::function1<unsigned int,char const *> v7; // [esp+140h] [ebp-150h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v8; // [esp+160h] [ebp-130h]
  boost::function1<unsigned int,char const *> v9; // [esp+170h] [ebp-120h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v10; // [esp+190h] [ebp-100h]
  boost::function1<unsigned int,char const *> v11; // [esp+1A0h] [ebp-F0h] BYREF
  boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > v12; // [esp+1C0h] [ebp-D0h]
  boost::function1<unsigned int,char const *> v13; // [esp+1D0h] [ebp-C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v14; // [esp+1F0h] [ebp-A0h] BYREF
  void (__thiscall *v15)(vostok::ai::ai_world *, const char *); // [esp+200h] [ebp-90h]
  int v16; // [esp+204h] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v17; // [esp+208h] [ebp-88h] BYREF
  void (__thiscall *v18)(vostok::ai::ai_world *, const char *); // [esp+218h] [ebp-78h]
  int v19; // [esp+21Ch] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v20; // [esp+220h] [ebp-70h] BYREF
  unsigned int (__thiscall *v21)(vostok::ai::ai_world *, const char *); // [esp+230h] [ebp-60h]
  int v22; // [esp+234h] [ebp-5Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+238h] [ebp-58h] BYREF
  void (__thiscall *f)(vostok::ai::ai_world *, const char *); // [esp+248h] [ebp-48h]
  int f_4; // [esp+24Ch] [ebp-44h]
  const char *name; // [esp+250h] [ebp-40h]
  const vostok::configs::binary_config_value *value; // [esp+254h] [ebp-3Ch]
  unsigned int id; // [esp+258h] [ebp-38h]
  vostok::ai::enemy_filter_types_enum subfilter_type; // [esp+25Ch] [ebp-34h]
  boost::function<unsigned int __cdecl(char const *)> selector; // [esp+260h] [ebp-30h] BYREF
  const vostok::configs::binary_config_value *it_end; // [esp+280h] [ebp-10h]
  const vostok::configs::binary_config_value *values; // [esp+284h] [ebp-Ch]
  unsigned int subfilter_id; // [esp+288h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+28Ch] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](filter_options, "subtype");
  subfilter_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v4,
                                 (int)v3);
  subfilter_type = subfilter_id;
  (&filter[1].vtable)[1] = (boost::detail::function::vtable_base *)subfilter_id;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(filter, &selector);
  switch ( subfilter_type )
  {
    case enemy_filter_type_group:
      f = vostok::ai::ai_world::get_group_id_by_name;
      f_4 = 0;
      v12 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_group_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v13, v12, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v13,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v13);
      break;
    case enemy_filter_type_character:
      v21 = vostok::ai::ai_world::get_character_id_by_name;
      v22 = 0;
      v10 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v20, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_character_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v11, v10, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v11,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v11);
      break;
    case enemy_filter_type_class:
      v18 = vostok::ai::ai_world::get_class_id_by_name;
      v19 = 0;
      v8 = *(boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v17, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_class_id_by_name, world);
      boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(&v9, v8, 0);
      boost::function1<unsigned int,char const *>::swap(
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v9,
        (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v9);
      break;
    case enemy_filter_type_outfit:
      v15 = vostok::ai::ai_world::get_outfit_id_by_name;
      v16 = 0;
      v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v14,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_outfit_id_by_name,
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
  }
  values = vostok::configs::binary_config_value::operator[](filter_options, "names");
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
      vostok::ai::planning::enemy_filter::add_filtered_id((vostok::ai::planning::enemy_filter *)filter, id);
    v5 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&it[1];
    ++it;
  }
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&selector);
}
