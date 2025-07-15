void __cdecl vostok::ai::parse_sound_filter(
        vostok::configs::binary_config_value *filter_options,
        vostok::ai::planning::sound_filter *filter)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const char *name; // [esp+24h] [ebp-1Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+30h] [ebp-10h]
  vostok::configs::binary_config_value *values; // [esp+34h] [ebp-Ch]
  vostok::configs::binary_config_value *it; // [esp+3Ch] [ebp-4h]

  v2 = vostok::configs::binary_config_value::operator[](filter_options, "subtype");
  filter->m_filter_type = (vostok::ai::sound_filter_types_enum)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                 v3,
                                                                 (int)v2);
  values = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                     filter_options,
                                                     "filenames");
  it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)values);
  it_end = vostok::configs::binary_config_value::end(values);
  while ( it != it_end )
  {
    v4 = vostok::configs::binary_config_value::operator[](it, "name");
    name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v5,
                           (int)v4);
    vostok::ai::planning::sound_filter::add_filtered_item(filter, name);
    ++it;
  }
}
