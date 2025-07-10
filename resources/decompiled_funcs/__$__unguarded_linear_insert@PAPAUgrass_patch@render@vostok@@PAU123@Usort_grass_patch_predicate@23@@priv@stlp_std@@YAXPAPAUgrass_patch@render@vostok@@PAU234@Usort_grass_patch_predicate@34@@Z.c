void __usercall stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__last@<edx>,
        vostok::render::grass_patch *__val@<esi>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v3; // ecx
  float v4; // xmm3_4

  v3 = __last - 1;
  v4 = (float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z)
                     * (float)(__val->m_origin.z - __comp.m_view_pos.z))
             + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x)
                     * (float)(__val->m_origin.x - __comp.m_view_pos.x)))
     + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y) * (float)(__val->m_origin.y - __comp.m_view_pos.y));
  while ( (float)((float)((float)((float)((*v3)->m_origin.z - __comp.m_view_pos.z)
                                * (float)((*v3)->m_origin.z - __comp.m_view_pos.z))
                        + (float)((float)((*v3)->m_origin.y - __comp.m_view_pos.y)
                                * (float)((*v3)->m_origin.y - __comp.m_view_pos.y)))
                + (float)((float)((*v3)->m_origin.x - __comp.m_view_pos.x)
                        * (float)((*v3)->m_origin.x - __comp.m_view_pos.x))) > v4 )
  {
    *__last = *v3;
    __last = v3--;
  }
  *__last = __val;
}
