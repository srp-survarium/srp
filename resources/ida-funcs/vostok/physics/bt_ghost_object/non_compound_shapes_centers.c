void __userpurge vostok::physics::bt_ghost_object::non_compound_shapes_centers(
        vostok::physics::bt_ghost_object *this@<ecx>,
        vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        vostok::vectora<vostok::math::float3> *centres_results)
{
  const btTransform *v3; // esi
  vostok::physics::bt_collision_shape *v4; // eax

  v3 = (const btTransform *)&a2[4].m_object->vostok::resources::resource_reconstruction_info;
  v4 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(a2 + 3);
  vostok::physics::get_non_compound_shapes_centers(v4->m_bt_shape, v3, centres_results);
}
