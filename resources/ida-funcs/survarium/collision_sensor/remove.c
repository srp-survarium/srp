void __usercall survarium::collision_sensor::remove(survarium::collision_sensor *this@<ecx>, int a2@<edi>)
{
  unsigned int v2; // ebx

  v2 = 0;
  for ( *(_BYTE *)(a2 + 28) = 0; v2 < *(_DWORD *)(a2 + 24); ++v2 )
    survarium::collision_geometry::unsubscribe(
      *(survarium::collision_geometry **)(*(_DWORD *)(a2 + 20) + 4 * v2),
      (survarium::collision_geometry_subscriber *)a2);
  stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>>::erase(
    (stlp_std::priv::_Impl_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *)this,
    (const stlp_std::__false_type *)a2,
    a2 + 8,
    *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(a2 + 8),
    *(vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> **)(a2 + 12));
}
