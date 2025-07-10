void __userpurge vostok::render::debug::renderer::draw_line_ellipsoid(
        const vostok::math::float4x4 *matrix@<edi>,
        const vostok::math::color *color@<esi>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        bool use_depth)
{
  vostok::render::debug::renderer::draw_lines(
    vostok::geometry_utils::line_ellipsoid::pairs,
    0x20u,
    this,
    scene,
    matrix,
    vostok::geometry_utils::line_ellipsoid::vertices_xy,
    (vostok::buffer_vector<vostok::render::vertex_colored> *)0x20,
    color,
    1);
  vostok::render::debug::renderer::draw_lines(
    vostok::geometry_utils::line_ellipsoid::pairs,
    0x20u,
    this,
    scene,
    matrix,
    vostok::geometry_utils::line_ellipsoid::vertices_yz,
    (vostok::buffer_vector<vostok::render::vertex_colored> *)0x20,
    color,
    1);
  vostok::render::debug::renderer::draw_lines(
    vostok::geometry_utils::line_ellipsoid::pairs,
    0x20u,
    this,
    scene,
    matrix,
    vostok::geometry_utils::line_ellipsoid::vertices_xz,
    (vostok::buffer_vector<vostok::render::vertex_colored> *)0x20,
    color,
    1);
}
