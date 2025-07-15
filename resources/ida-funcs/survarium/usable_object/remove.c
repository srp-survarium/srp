void __usercall survarium::usable_object::remove(
        survarium::usable_object *this@<ecx>,
        survarium::collision_geometry_subscriber *a2@<edi>)
{
  survarium::collision_geometry_subscriber_vtbl *i; // ebx

  for ( i = 0; i < a2[15].__vftable; i = (survarium::collision_geometry_subscriber_vtbl *)((char *)i + 1) )
    survarium::collision_geometry::unsubscribe(
      *((survarium::collision_geometry **)&a2[14].~survarium::collision_geometry_subscriber + (_DWORD)i),
      a2);
}
