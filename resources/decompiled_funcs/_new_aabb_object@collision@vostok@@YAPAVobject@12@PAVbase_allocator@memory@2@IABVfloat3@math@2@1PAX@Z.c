vostok::collision::object *__cdecl vostok::collision::new_aabb_object(
        vostok::memory::base_allocator *allocator,
        unsigned int object_type,
        const vostok::math::float3 *position,
        const vostok::math::float3 *epsilon,
        void *user_data)
{
  char *v5; // esi
  float y; // xmm4_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  __int64 v10; // xmm6_8
  __int64 v12; // [esp+4h] [ebp-24h]
  __int128 v13; // [esp+18h] [ebp-10h]

  v5 = (char *)allocator->call_malloc(allocator, 48);
  if ( !v5 )
    return 0;
  y = position->y;
  z = position->z;
  *(float *)&v12 = position->x - epsilon->x;
  v8 = epsilon->y;
  *((float *)&v12 + 1) = y - v8;
  v9 = epsilon->z;
  v10 = v12;
  *(float *)&v13 = z - v9;
  *(float *)&v12 = epsilon->x + position->x;
  *((float *)&v12 + 1) = v8 + y;
  *(_QWORD *)((char *)&v13 + 4) = v12;
  *((float *)&v13 + 3) = v9 + z;
  vostok::collision::object::object(COERCE_VOSTOK_COLLISION_OBJECT_(v9 + z), (int)v5);
  *(_QWORD *)(v5 + 4) = v10;
  *(_QWORD *)(v5 + 12) = v13;
  *((_DWORD *)v5 + 9) = user_data;
  *(_DWORD *)v5 = &vostok::collision::aabb_object::`vftable';
  *((_DWORD *)v5 + 10) = object_type;
  *(_QWORD *)(v5 + 20) = *((_QWORD *)&v13 + 1);
  return (vostok::collision::object *)v5;
}
