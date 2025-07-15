void __cdecl vostok::ai::parse_position_filter(
        vostok::configs::binary_config_value *filter_options,
        vostok::ai::planning::position_filter *filter)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::configs::binary_config_value *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::math::float3 *velocity; // [esp+3Ch] [ebp-28h]
  const char *animation_name; // [esp+40h] [ebp-24h]
  const vostok::math::float3 *direction; // [esp+44h] [ebp-20h]
  const vostok::math::float3 *position; // [esp+48h] [ebp-1Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+54h] [ebp-10h]
  vostok::configs::binary_config_value *values; // [esp+58h] [ebp-Ch]
  vostok::configs::binary_config_value *it; // [esp+60h] [ebp-4h]

  v2 = vostok::configs::binary_config_value::operator[](filter_options, "subtype");
  filter->m_filter_type = (vostok::ai::position_filter_types_enum)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                    v3,
                                                                    (int)v2);
  values = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                     filter_options,
                                                     "positions");
  it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)values);
  it_end = vostok::configs::binary_config_value::end(values);
  while ( it != it_end )
  {
    v4 = vostok::configs::binary_config_value::operator[](it, "target_point");
    position = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                               v5,
                                               (int)v4);
    v6 = vostok::configs::binary_config_value::operator[](it, (char *)&stru_96A440.m_inverted_view.lines[2].elements[2]);
    direction = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                v7,
                                                (int)v6);
    v8 = vostok::configs::binary_config_value::operator[](it, "velocity");
    velocity = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                               v9,
                                               (int)v8);
    v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](it, "animation");
    v11 = vostok::configs::binary_config_value::operator[](v10, "name");
    animation_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     v12,
                                     (int)v11);
    vostok::ai::planning::position_filter::add_filtered_item(filter, position, direction, velocity, animation_name);
    ++it;
  }
}
