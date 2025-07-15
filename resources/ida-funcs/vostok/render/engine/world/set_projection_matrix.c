void __thiscall vostok::render::engine::world::set_projection_matrix(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view,
        const vostok::math::float4x4 *projection_matrix)
{
  qmemcpy((char *)&scene_view->m_object[4].m_reconstruction_info_actuality_tick + 4, projection_matrix, 0x40u);
}
