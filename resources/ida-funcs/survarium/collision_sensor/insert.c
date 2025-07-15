void __userpurge survarium::collision_sensor::insert(
        survarium::collision_sensor *this@<ecx>,
        int a2@<esi>,
        vostok::physics::world *world)
{
  unsigned int v3; // edi

  v3 = 0;
  for ( *(_BYTE *)(a2 + 28) = 1; v3 < *(_DWORD *)(a2 + 24); ++v3 )
    survarium::collision_geometry::subscribe(
      (survarium::collision_geometry *)this,
      *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v3),
      world,
      (survarium::collision_geometry_subscriber *)a2);
}
