void __userpurge vostok::render::culling::portal_sector_system::render(
        const vostok::math::float3 *view_pos@<eax>,
        vostok::render::culling::portal_sector_system *this,
        int r,
        const vostok::math::float4x4 *__formal)
{
  vostok::render::system_renderer *v4; // ebp
  unsigned int sector_id; // eax
  vostok::render::culling::sector_double_query_preventer *v6; // ecx
  unsigned int v7; // edi
  vostok::render::culling::spatial_sector *v8; // esi

  v4 = (vostok::render::system_renderer *)r;
  sector_id = vostok::render::culling::portal_sector_structure::get_sector_id(
                this->m_structure.m_object,
                (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
                view_pos);
  v7 = sector_id;
  if ( sector_id )
  {
    v8 = &this->m_structure.m_object->m_sectors.m_begin[sector_id];
    r = -16776961;
    vostok::render::system_renderer::draw_aabb(v4, &v8->m_aabb, (const vostok::math::color *)&r);
  }
  if ( s_draw_draw_frustum_images_value )
    vostok::render::culling::sector_double_query_preventer::render(v6, (int)this->m_preventer, v4);
  if ( s_draw_portals_value )
    vostok::render::culling::portal_sector_system::draw_portals(v7, this, v4);
}
