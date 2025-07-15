void __thiscall vostok::render::engine::world::set_view_matrix(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view,
        const vostok::math::float4x4 *view_and_culling_matrix)
{
  vostok::render::camera::set_view_transform(
    (vostok::render::camera *)&scene_view->m_object[3].m_fat_it.m_type,
    view_and_culling_matrix);
}
