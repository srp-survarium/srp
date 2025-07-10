void __userpurge vostok::render::scene::select_models_via_sectors(
        vostok::render::scene *this@<eax>,
        vostok::render::vector<vostok::render::render_surface_instance *> *selection@<ecx>,
        const vostok::math::float4x4 *mat_vp,
        vostok::render::culling::portal_sector_system *view_point)
{
  vostok::render::culling::portal_sector_system::select_models(
    view_point,
    this->m_portal_system,
    this->m_models_tree,
    (vostok::math::float3 *)view_point,
    mat_vp,
    selection);
}
