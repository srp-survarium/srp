bool __thiscall vostok::collision::triangle_mesh_resource::aabb_query(
        vostok::collision::triangle_mesh_resource *this,
        const vostok::collision::object *object,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  int v5; // eax
  char v6; // bl
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp-8h] [ebp-78h] BYREF
  Opcode::MeshInterface *m_mesh; // [esp-4h] [ebp-74h]
  vostok::collision::resource_guard guard; // [esp+Ch] [ebp-64h] BYREF
  vostok::collision::colliders::aabb_geometry v11; // [esp+20h] [ebp-50h] BYREF

  m_mesh = this->m_mesh;
  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    &this->m_resource);
  vostok::collision::resource_guard::resource_guard(
    &guard,
    &this->m_indices,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v8.m_object,
    m_mesh);
  vostok::collision::colliders::aabb_geometry::aabb_geometry(&v11, aabb, triangles, this, object);
  v6 = *(_BYTE *)(v5 + 4);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&guard.pinned_data);
  return v6;
}
