vostok::collision::object *__cdecl vostok::collision::new_collision_object(
        vostok::memory::base_allocator *allocator,
        unsigned int object_type,
        vostok::collision::geometry_instance *geometry,
        void *user_data)
{
  _DWORD *v4; // eax
  vostok::collision::object *v5; // ecx
  _DWORD *v6; // esi

  v4 = allocator->call_malloc(allocator, 52);
  v6 = v4;
  if ( !v4 )
    return 0;
  vostok::collision::object::object(v5, (int)v4);
  v6[12] = geometry;
  *v6 = &vostok::collision::collision_object::`vftable';
  v6[9] = user_data;
  v6[10] = object_type;
  return (vostok::collision::object *)v6;
}
