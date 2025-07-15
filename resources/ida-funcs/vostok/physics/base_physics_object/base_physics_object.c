void __userpurge vostok::physics::base_physics_object::base_physics_object(
        vostok::physics::base_physics_object *this@<ecx>,
        _DWORD *a2@<edi>,
        vostok::memory::base_allocator *allocator)
{
  _DWORD *v3; // esi
  char *v4; // eax
  _DWORD *v5; // eax

  v3 = a2 + 1;
  v4 = type_info::raw_name(&vostok::physics::loose_ptr_data `RTTI Type Descriptor');
  v5 = allocator->call_malloc(
         allocator,
         8,
         v4,
         "vostok::physics::loose_ptr_base::loose_ptr_base",
         "c:\\survarium.deploy\\sources\\vostok/loose_ptr_base_inline.h",
         18);
  if ( v5 )
  {
    *v5 = v3;
    v5[1] = 0;
  }
  else
  {
    v5 = 0;
  }
  *v3 = v5;
  *(_DWORD *)(*v3 + 4) = v5[1] + 1;
  a2[2] = allocator;
  a2[3] = 0;
  *a2 = &vostok::physics::base_physics_object::`vftable';
}
