void __userpurge survarium::usable_object::insert(
        survarium::usable_object *this@<ecx>,
        survarium::collision_geometry_subscriber *a2@<esi>,
        vostok::physics::world *world)
{
  survarium::collision_geometry_subscriber_vtbl *i; // edi

  for ( i = 0; i < a2[15].__vftable; i = (survarium::collision_geometry_subscriber_vtbl *)((char *)i + 1) )
    survarium::collision_geometry::subscribe(
      (survarium::collision_geometry *)this,
      *((_DWORD *)&a2[14].~survarium::collision_geometry_subscriber + (_DWORD)i),
      world,
      a2);
}
