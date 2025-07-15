vostok::collision::object *__usercall vostok::collision::new_collision_object@<eax>(
        vostok::memory::base_allocator *allocator@<eax>,
        unsigned int object_type,
        vostok::collision::geometry_instance *geometry)
{
  char *v4; // eax
  vostok::collision::object *v5; // ecx
  _DWORD *v6; // esi

  v4 = type_info::raw_name(&vostok::collision::collision_object `RTTI Type Descriptor');
  v6 = allocator->call_malloc(allocator, 52, v4, "vostok::collision::new_collision_object", ".\\api.cpp", 246);
  if ( !v6 )
    return 0;
  vostok::collision::object::object(v5, (int)v6);
  v6[12] = object_type;
  v6[9] = geometry;
  *v6 = &vostok::collision::collision_object::`vftable';
  v6[10] = 1;
  return (vostok::collision::object *)v6;
}
