bool __thiscall vostok::collision::triangle_mesh_resource::cuboid_query(
        vostok::collision::triangle_mesh_resource *this,
        const vostok::collision::object *object,
        const vostok::math::cuboid *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  bool v5; // bl
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v7; // [esp-8h] [ebp-28h] BYREF
  Opcode::MeshInterface *m_mesh; // [esp-4h] [ebp-24h]
  vostok::collision::resource_guard guard; // [esp+Ch] [ebp-14h] BYREF

  m_mesh = this->m_mesh;
  v7.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v7,
    &this->m_resource);
  vostok::collision::resource_guard::resource_guard(
    &guard,
    &this->m_indices,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v7.m_object,
    m_mesh);
  v5 = vostok::collision::triangle_mesh_geometry::cuboid_query(this, object, cuboid, triangles);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&guard.pinned_data);
  return v5;
}
