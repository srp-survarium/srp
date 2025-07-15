int __thiscall vostok::physics::bt_static_rigid_body::get_triangle_material(
        vostok::physics::bt_static_rigid_body *this,
        int triangle_id,
        int is_shape_index)
{
  vostok::physics::bt_collision_shape *v3; // eax

  v3 = vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(&this->m_shape);
  return ((int (__thiscall *)(vostok::physics::bt_collision_shape *, int, int))v3->get_triangle_material)(
           v3,
           triangle_id,
           is_shape_index);
}
