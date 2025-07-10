void __cdecl vostok::ai::parse_cover_filter(
        vostok::configs::binary_config_value *filter_options,
        survarium::weapon_core_animation_end_aware_state *world,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *filter)
{
  const vostok::configs::binary_config_value *v3; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp-14h] [ebp-210h]
  boost::function1<unsigned int,char const *> v7; // [esp+184h] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+1A4h] [ebp-58h] BYREF
  unsigned int (__thiscall *f)(vostok::ai::ai_world *, const char *); // [esp+1B4h] [ebp-48h]
  int f_4; // [esp+1B8h] [ebp-44h]
  const char *name; // [esp+1BCh] [ebp-40h]
  const vostok::configs::binary_config_value *value; // [esp+1C0h] [ebp-3Ch]
  unsigned int id; // [esp+1C4h] [ebp-38h]
  vostok::ai::cover_filter_types_enum subfilter_type; // [esp+1C8h] [ebp-34h]
  boost::function<unsigned int __cdecl(char const *)> selector; // [esp+1CCh] [ebp-30h] BYREF
  const vostok::configs::binary_config_value *it_end; // [esp+1ECh] [ebp-10h]
  const vostok::configs::binary_config_value *values; // [esp+1F0h] [ebp-Ch]
  unsigned int subfilter_id; // [esp+1F4h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+1F8h] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](filter_options, "subtype");
  subfilter_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 v4,
                                 (int)v3);
  subfilter_type = subfilter_id;
  (&filter[1].vtable)[1] = (boost::detail::function::vtable_base *)subfilter_id;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(filter, &selector);
  f = vostok::ai::ai_world::get_node_id_by_name;
  f_4 = 0;
  v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::ai_world::get_node_id_by_name,
          world);
  boost::function1<unsigned int,char const *>::function1<unsigned int,char const *>(
    &v7,
    (boost::_bi::bind_t<unsigned int,boost::_mfi::cmf1<unsigned int,vostok::ai::ai_world,char const *>,boost::_bi::list2<boost::_bi::value<vostok::ai::ai_world *>,boost::arg<1> > >)v6,
    0);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v7,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&selector);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v7);
  values = vostok::configs::binary_config_value::operator[](filter_options, "nodes");
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
      vostok::ai::planning::cover_filter::add_filtered_id((vostok::ai::planning::cover_filter *)filter, id);
    v5 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&it[1];
    ++it;
  }
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&selector);
}
