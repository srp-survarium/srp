void __thiscall survarium::respawn_point_core::load(
        survarium::respawn_point_core *this,
        vostok::configs::binary_config_value *config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::configs::binary_config_value *v8; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v9; // ecx
  vostok::math::float4x4 *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  vostok::math::float3 *v13; // [esp+0h] [ebp-160h]
  vostok::math::axis_rotation_order v14; // [esp+4h] [ebp-15Ch]
  vostok::math::float4x4 result; // [esp+114h] [ebp-4Ch] BYREF
  vostok::math::float3 angles; // [esp+154h] [ebp-Ch] BYREF

  v2 = vostok::configs::binary_config_value::operator[](config, "point_id");
  this->point_id = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                   v3,
                                   (int)v2);
  v4 = vostok::configs::binary_config_value::operator[](config, "priority");
  this->point_priority = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                         v5,
                                         (int)v4);
  v6 = vostok::configs::binary_config_value::operator[](config, "position");
  this->position = *(vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                              v7,
                                              (int)v6);
  v8 = vostok::configs::binary_config_value::operator[](config, "rotation");
  angles = *(vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                      v9,
                                      (int)v8);
  vostok::math::create_rotation(&result, &angles);
  this->orientation = vostok::math::float4x4::get_angles(v10, v13, v14)->y;
  v11 = vostok::configs::binary_config_value::operator[](config, "team");
  this->team_owner = (survarium::game_team_id)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                v12,
                                                (int)v11);
}
