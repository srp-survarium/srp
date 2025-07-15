void __userpurge survarium::booby_trap_core::remove_collision(
        survarium::booby_trap_core *this@<ecx>,
        survarium::collision_geometry_subscriber *a2@<esi>,
        bool forcefully)
{
  survarium::collision_sensor *v3; // ecx

  if ( forcefully )
  {
    a2[25].__vftable = 0;
    a2[26].__vftable = 0;
    a2[23].__vftable = 0;
  }
  else
  {
    while ( a2[25].__vftable )
      ((void (__thiscall *)(survarium::collision_geometry_subscriber *, survarium::collision_geometry_subscriber_vtbl *))a2[13].__vftable[2].cast_to_usable)(
        &a2[13],
        a2[26].__vftable);
  }
  survarium::usable_object::remove((survarium::usable_object *)this, a2 + 13);
  survarium::collision_sensor::remove(v3, (int)&a2[4]);
  if ( LOBYTE(a2[121].__vftable[21].~survarium::collision_geometry_subscriber) )
  {
    (*((void (__thiscall **)(survarium::collision_geometry_subscriber_vtbl *, survarium::collision_geometry_subscriber_vtbl *))a2[2].~survarium::collision_geometry_subscriber
     + 14))(
      a2[2].__vftable,
      a2[1].__vftable);
    a2[2].__vftable = 0;
  }
}
