void __thiscall vostok::physics::collision_shape_cook::create_primitives_shape(
        vostok::physics::collision_shape_cook *this,
        const vostok::configs::binary_config_value *primitives_t,
        vostok::physics::collision_shape_cook::cook_data *cd)
{
  const vostok::configs::binary_config_value *v4; // eax
  unsigned int *v5; // esi
  const void *pointer; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  unsigned int *v8; // esi
  vostok::configs::binary_config_value v9; // [esp+14h] [ebp-28h] BYREF
  vostok::math::float3_pod other; // [esp+30h] [ebp-Ch] BYREF

  if ( 24 * primitives_t->count / 24 == 1
    && (v4 = vostok::configs::binary_config_value::operator[](
               (vostok::configs::binary_config_value *)primitives_t->data.pointer,
               "position"),
        v5 = (unsigned int *)v4->data.pointer,
        HIDWORD(v9.id.max_storage) = *(_DWORD *)v4->data.pointer,
        ++v5,
        v9.id_crc = *v5,
        *(_DWORD *)&v9.type = v5[1],
        memset(&other, 0, sizeof(other)),
        vostok::math::float3_pod::is_similar(
          (vostok::math::float3_pod *)((char *)&v9.id.max_storage + 4),
          &other,
          0.0000099999997)) )
  {
    qmemcpy((void *)&v9, primitives_t->data.pointer, sizeof(v9));
    pointer = vostok::configs::binary_config_value::operator[](&v9, "type")->data.pointer;
    v7 = vostok::configs::binary_config_value::operator[](&v9, "scale");
    v8 = (unsigned int *)v7->data.pointer;
    HIDWORD(v9.id.max_storage) = *(_DWORD *)v7->data.pointer;
    v9.id_crc = *++v8;
    *(_DWORD *)&v9.type = v8[1];
    vostok::physics::create_primitive_shape(
      (const vostok::math::float3 *)((char *)&v9.id.max_storage + 4),
      (vostok::collision::primitive_type)pointer,
      &cd->scale_);
  }
  else
  {
    vostok::physics::create_compound_shape(primitives_t, &cd->scale_);
  }
}
