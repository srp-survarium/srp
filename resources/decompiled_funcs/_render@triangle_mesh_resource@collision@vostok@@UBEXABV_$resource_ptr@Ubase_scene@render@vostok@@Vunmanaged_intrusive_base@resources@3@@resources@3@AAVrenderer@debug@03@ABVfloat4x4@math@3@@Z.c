void __thiscall vostok::collision::triangle_mesh_resource::render(
        vostok::collision::triangle_mesh_resource *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer,
        const vostok::math::float4x4 *matrix)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp-8h] [ebp-24h] BYREF
  Opcode::MeshInterface *m_mesh; // [esp-4h] [ebp-20h]
  vostok::collision::resource_guard guard; // [esp+8h] [ebp-14h] BYREF

  m_mesh = this->m_mesh;
  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    &this->m_resource);
  vostok::collision::resource_guard::resource_guard(
    &guard,
    &this->m_indices,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v5.m_object,
    m_mesh);
  vostok::collision::triangle_mesh_geometry::render(this, scene, renderer, matrix);
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&guard.pinned_data);
}
