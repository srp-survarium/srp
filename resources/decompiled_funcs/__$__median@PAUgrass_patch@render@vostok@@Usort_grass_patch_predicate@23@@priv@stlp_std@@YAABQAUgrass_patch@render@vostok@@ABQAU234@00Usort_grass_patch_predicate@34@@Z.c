const vostok::render::grass_patch **__usercall stlp_std::priv::__median<vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>@<eax>(
        const vostok::render::grass_patch **__b@<edi>,
        vostok::render::grass_patch **__c@<esi>,
        const vostok::render::grass_patch **__a,
        vostok::render::sort_grass_patch_predicate __comp)
{
  const vostok::render::grass_patch *v4; // edx
  vostok::render::grass_patch *v5; // eax
  const vostok::render::grass_patch *v6; // ecx
  float v7; // xmm6_4
  const vostok::render::grass_patch **result; // eax
  bool v9; // zf

  v4 = *__b;
  v5 = *__c;
  v6 = *__a;
  v7 = (*__c)->m_origin.x - __comp.m_view_pos.x;
  if ( (float)((float)((float)((float)((*__b)->m_origin.z - __comp.m_view_pos.z)
                             * (float)((*__b)->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)((*__b)->m_origin.y - __comp.m_view_pos.y)
                             * (float)((*__b)->m_origin.y - __comp.m_view_pos.y)))
             + (float)((float)((*__b)->m_origin.x - __comp.m_view_pos.x)
                     * (float)((*__b)->m_origin.x - __comp.m_view_pos.x))) > (float)((float)((float)((float)((*__a)->m_origin.z - __comp.m_view_pos.z) * (float)((*__a)->m_origin.z - __comp.m_view_pos.z))
                                                                                           + (float)((float)((*__a)->m_origin.y - __comp.m_view_pos.y) * (float)((*__a)->m_origin.y - __comp.m_view_pos.y)))
                                                                                   + (float)((float)((*__a)->m_origin.x - __comp.m_view_pos.x)
                                                                                           * (float)((*__a)->m_origin.x - __comp.m_view_pos.x))) )
  {
    if ( (float)((float)((float)((float)(v5->m_origin.z - __comp.m_view_pos.z)
                               * (float)(v5->m_origin.z - __comp.m_view_pos.z))
                       + (float)((float)(v5->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v5->m_origin.y - __comp.m_view_pos.y)))
               + (float)(v7 * v7)) <= (float)((float)((float)((float)(v4->m_origin.z - __comp.m_view_pos.z)
                                                            * (float)(v4->m_origin.z - __comp.m_view_pos.z))
                                                    + (float)((float)(v4->m_origin.y - __comp.m_view_pos.y)
                                                            * (float)(v4->m_origin.y - __comp.m_view_pos.y)))
                                            + (float)((float)(v4->m_origin.x - __comp.m_view_pos.x)
                                                    * (float)(v4->m_origin.x - __comp.m_view_pos.x))) )
    {
      if ( vostok::render::sort_grass_patch_predicate::operator()(v6, v5, &__comp) )
        return (const vostok::render::grass_patch **)__c;
      return __a;
    }
    return __b;
  }
  if ( (float)((float)((float)((float)(v5->m_origin.z - __comp.m_view_pos.z)
                             * (float)(v5->m_origin.z - __comp.m_view_pos.z))
                     + (float)((float)(v5->m_origin.y - __comp.m_view_pos.y)
                             * (float)(v5->m_origin.y - __comp.m_view_pos.y)))
             + (float)(v7 * v7)) > (float)((float)((float)((float)(v6->m_origin.z - __comp.m_view_pos.z)
                                                         * (float)(v6->m_origin.z - __comp.m_view_pos.z))
                                                 + (float)((float)(v6->m_origin.y - __comp.m_view_pos.y)
                                                         * (float)(v6->m_origin.y - __comp.m_view_pos.y)))
                                         + (float)((float)(v6->m_origin.x - __comp.m_view_pos.x)
                                                 * (float)(v6->m_origin.x - __comp.m_view_pos.x))) )
    return __a;
  v9 = !vostok::render::sort_grass_patch_predicate::operator()(v4, v5, &__comp);
  result = (const vostok::render::grass_patch **)__c;
  if ( v9 )
    return __b;
  return result;
}
