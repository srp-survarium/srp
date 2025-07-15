void __cdecl survarium::read_transform(vostok::configs::binary_config_value *cfg, vostok::math::float4x4 *result)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::configs::binary_config_value *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  vostok::math::float4x4 *v8; // eax
  const vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // [esp-8h] [ebp-2F4h]
  const vostok::math::float4x4 *v11; // [esp-4h] [ebp-2F0h]
  vostok::math::float4x4 v12; // [esp+1A0h] [ebp-14Ch] BYREF
  vostok::math::float4x4 v13; // [esp+1E0h] [ebp-10Ch] BYREF
  _BYTE v14[64]; // [esp+220h] [ebp-CCh] BYREF
  vostok::math::float4x4 v15; // [esp+260h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v16; // [esp+2A0h] [ebp-4Ch] BYREF
  const vostok::math::float3 *rotation; // [esp+2E0h] [ebp-Ch]
  const vostok::math::float3 *scale; // [esp+2E4h] [ebp-8h]
  const vostok::math::float3 *position; // [esp+2E8h] [ebp-4h]

  v2 = vostok::configs::binary_config_value::operator[](cfg, "scale");
  scale = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                          v3,
                                          (int)v2);
  v4 = vostok::configs::binary_config_value::operator[](cfg, "rotation");
  rotation = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v5,
                                             (int)v4);
  v6 = vostok::configs::binary_config_value::operator[](cfg, "position");
  position = (const vostok::math::float3 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                             v7,
                                             (int)v6);
  v11 = vostok::math::create_translation(&v16, position);
  v10 = vostok::math::create_rotation(&v15, rotation);
  v8 = vostok::math::create_scale(scale, (int)v14);
  v9 = vostok::math::operator*(&v13, v8, v10);
  qmemcpy((void *)result, vostok::math::operator*(&v12, v9, v11), sizeof(vostok::math::float4x4));
}
