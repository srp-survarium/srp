vostok::physics::bt_collision_shape *__usercall vostok::physics::collision_shape_cook::create_primitives_shape@<eax>(
        const vostok::configs::binary_config_value *primitives_t@<ecx>,
        vostok::physics::collision_shape_cook::cook_data *cd@<eax>,
        float a3@<xmm4>,
        vostok::physics::collision_shape_cook *this)
{
  const void *pointer; // eax
  const char *v7; // ecx
  const void *v9; // esi
  const vostok::configs::binary_config_value *v10; // eax
  unsigned __int64 v11; // xmm0_8
  const char *v12; // eax
  vostok::math::float3_pod other; // [esp+10h] [ebp-28h] BYREF
  vostok::configs::binary_config_value cfg; // [esp+1Ch] [ebp-1Ch] BYREF

  if ( 24 * primitives_t->count / 24 != 1 )
    return vostok::physics::create_compound_shape(primitives_t, a3, &cd->scale_);
  pointer = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)primitives_t->data.pointer,
              "position")->data.pointer;
  v7 = (const char *)*((_DWORD *)pointer + 2);
  cfg.data.max_storage = *(_QWORD *)pointer;
  cfg.id.pointer = v7;
  memset(&other, 0, sizeof(other));
  if ( !vostok::math::float3_pod::is_similar((vostok::math::float3_pod *)&cfg, &other, 0.0000099999997) )
    return vostok::physics::create_compound_shape(primitives_t, a3, &cd->scale_);
  cfg = *(vostok::configs::binary_config_value *)primitives_t->data.pointer;
  v9 = vostok::configs::binary_config_value::operator[](&cfg, "type")->data.pointer;
  v10 = vostok::configs::binary_config_value::operator[](&cfg, "scale");
  v11 = *(_QWORD *)v10->data.pointer;
  v12 = (const char *)*((_DWORD *)v10->data.pointer + 2);
  cfg.data.max_storage = v11;
  cfg.id.pointer = v12;
  return vostok::physics::create_primitive_shape(
           (vostok::collision::primitive_type)v9,
           (const vostok::math::float3 *)&cfg,
           a3,
           &cd->scale_);
}
