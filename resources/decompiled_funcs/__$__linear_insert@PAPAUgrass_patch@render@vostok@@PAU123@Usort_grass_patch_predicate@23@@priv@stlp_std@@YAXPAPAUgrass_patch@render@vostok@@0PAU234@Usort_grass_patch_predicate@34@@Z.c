void __usercall stlp_std::priv::__linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<edi>,
        vostok::render::grass_patch **__last@<edx>,
        vostok::render::grass_patch *__val@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  if ( (float)((float)((float)((float)((*__first)->m_origin.z - __comp.m_view_pos.z)
                             * (float)((*__first)->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)((*__first)->m_origin.y - __comp.m_view_pos.y)
                             * (float)((*__first)->m_origin.y - __comp.m_view_pos.y)))
             + (float)((float)((*__first)->m_origin.x - __comp.m_view_pos.x)
                     * (float)((*__first)->m_origin.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z) * (float)(__val->m_origin.z - __comp.m_view_pos.z))
                                                                                                + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y) * (float)(__val->m_origin.y - __comp.m_view_pos.y)))
                                                                                        + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x)
                                                                                                * (float)(__val->m_origin.x - __comp.m_view_pos.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}
