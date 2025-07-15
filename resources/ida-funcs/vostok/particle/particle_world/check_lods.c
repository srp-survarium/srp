void __userpurge vostok::particle::particle_world::check_lods(
        vostok::particle::particle_world *this@<ecx>,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        const vostok::math::float3 *view_location)
{
  const vostok::math::float3 *v3; // ebx
  const vostok::math::float3 *v4; // eax
  int p_z; // ecx
  float v6; // xmm2_4
  float *v7; // edx
  float x; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *next_of_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+10h] [ebp-4h] BYREF

  v3 = view_location;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&view_location,
    a2 + 101);
  while ( 1 )
  {
    v4 = view_location;
    if ( !view_location )
      break;
    p_z = (int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      break;
    if ( BYTE1(view_location[63].x) )
    {
      p_z = LODWORD(view_location[61].z) - 1;
      if ( p_z >= 0 )
      {
        v7 = &view_location[23].z + 8 * p_z;
        while ( 1 )
        {
          v6 = v3->z - view_location[54].x;
          if ( (float)((float)((float)((float)(v3->y - view_location[53].z) * (float)(v3->y - view_location[53].z))
                             + (float)((float)(v3->x - view_location[53].y) * (float)(v3->x - view_location[53].y)))
                     + (float)(v6 * v6)) >= (float)(*v7 * *v7) )
            break;
          --p_z;
          v7 -= 8;
          if ( p_z < 0 )
            goto LABEL_12;
        }
        x = view_location[61].x;
        if ( p_z != LODWORD(x) )
        {
          v9 = s_bm_current_air_resistance;
          LODWORD(view_location[61].x) = p_z;
          p_z = (int)&v4[62].z;
          v10 = v9 - v4[62].z;
          v4[61].y = x;
          v4[62].z = v10;
          LOBYTE(v4[63].x) = 0;
        }
      }
    }
LABEL_12:
    v12.m_object = (vostok::particle::particle_system_instance_impl *)p_z;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v12,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&view_location);
    next_of_object = vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(
                       &v13,
                       (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v12.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      next_of_object,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&view_location);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&view_location);
}
