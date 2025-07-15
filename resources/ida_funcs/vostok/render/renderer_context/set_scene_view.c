void __userpurge vostok::render::renderer_context::set_scene_view(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> view_ptr)
{
  vostok::render::base_scene_view *m_object; // edi
  vostok::render::renderer_context *v4; // ecx
  vostok::render::renderer_context *v5; // ecx

  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)(a2 + 12392),
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&view_ptr);
  m_object = view_ptr.m_object;
  vostok::render::renderer_context::set_v(
    v4,
    (vostok::render::renderer_context *)a2,
    (const vostok::math::float4x4 *)&view_ptr.m_object[3].m_fat_it.m_type);
  vostok::render::renderer_context::set_p(
    v5,
    (vostok::render::renderer_context *)a2,
    (const vostok::math::float4x4 *)((char *)&m_object[4].m_reconstruction_info_actuality_tick + 4));
  if ( view_ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&view_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &view_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        view_ptr.m_object);
  }
}
