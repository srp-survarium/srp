void __userpurge vostok::collision::collision_object::collision_object(
        vostok::collision::collision_object *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::memory::base_allocator *allocator,
        vostok::collision::geometry_instance *type_object,
        vostok::collision::geometry_instance *geometry,
        void *const user_data)
{
  vostok::collision::object::object(this, (int)a2);
  a2[12] = type_object;
  *a2 = &vostok::collision::collision_object::`vftable';
  a2[9] = geometry;
  a2[10] = allocator;
}
