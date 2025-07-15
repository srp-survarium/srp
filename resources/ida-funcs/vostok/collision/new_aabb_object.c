vostok::collision::object *__usercall vostok::collision::new_aabb_object@<eax>(
        vostok::memory::base_allocator *allocator@<eax>,
        unsigned int object_type,
        const vostok::math::float3 *position,
        const vostok::math::float3 *epsilon,
        void *user_data)
{
  char *v6; // eax
  _DWORD *v7; // ebx
  vostok::math::aabb *v8; // esi
  vostok::collision::object *v10; // [esp-4h] [ebp-2Ch]
  vostok::math::aabb v11; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::math::aabb *v12; // [esp+24h] [ebp-4h]

  v6 = type_info::raw_name(&vostok::collision::aabb_object `RTTI Type Descriptor');
  v7 = allocator->call_malloc(allocator, 48, v6, "vostok::collision::new_aabb_object", ".\\api.cpp", 257);
  if ( !v7 )
    return 0;
  v12 = vostok::math::create_aabb_center_radius(epsilon, position, &v11);
  vostok::collision::object::object(v10, (int)v7);
  v8 = v12;
  v7[10] = object_type;
  v7[9] = user_data;
  *v7 = &vostok::collision::aabb_object::`vftable';
  qmemcpy(v7 + 1, v8, 0x18u);
  return (vostok::collision::object *)v7;
}
