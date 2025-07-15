void __userpurge vostok::render::culling::portal_sector_system::sort_portals_and_calculate_rects_in_screen_space(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        vostok::render::culling::portal_sector_system *a2@<esi>,
        vostok::render::culling::portal_sector_system *mat_vp,
        float min_z,
        vostok::buffer_vector<vostok::render::culling::aab_rect> *rects)
{
  void *v5; // esp
  vostok::render::culling::portal_sector_structure *v6; // ecx
  vostok::buffer_vector<float> distances; // [esp+Ch] [ebp-Ch] BYREF

  v5 = alloca(4 * (a2->m_structure.m_object->m_portals.m_end - a2->m_structure.m_object->m_portals.m_begin));
  distances.m_begin = (float *)&distances;
  distances.m_end = (float *)&distances;
  vostok::render::culling::portal_sector_system::calculate_portal_rects_in_screen_space(
    mat_vp,
    a2,
    min_z,
    rects,
    &distances);
  vostok::render::culling::portal_sector_structure::sort_portal_ids(v6, distances.m_begin);
}
