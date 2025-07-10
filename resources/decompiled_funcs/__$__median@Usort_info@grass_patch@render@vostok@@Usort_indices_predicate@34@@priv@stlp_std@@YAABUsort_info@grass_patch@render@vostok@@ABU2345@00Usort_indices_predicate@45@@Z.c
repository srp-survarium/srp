const vostok::render::grass_patch::sort_info *__fastcall stlp_std::priv::__median<vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        const vostok::render::grass_patch::sort_info *__b,
        const vostok::render::grass_patch::sort_info *__c,
        const vostok::render::grass_patch::sort_info *__a,
        vostok::render::sort_indices_predicate __comp)
{
  const vostok::render::grass_patch::sort_info *result; // eax
  float y; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // [esp+0h] [ebp-10h]
  float __aa; // [esp+14h] [ebp+4h]

  result = __a;
  y = __a->position.y;
  v6 = __a->position.x - __comp.m_view_pos.x;
  v7 = __b->position.x - __comp.m_view_pos.x;
  v8 = __a->position.z - __comp.m_view_pos.z;
  __aa = __b->position.y - __comp.m_view_pos.y;
  v9 = y - __comp.m_view_pos.y;
  v10 = __c->position.x - __comp.m_view_pos.x;
  if ( (float)((float)((float)(v7 * v7)
                     + (float)((float)(__b->position.z - __comp.m_view_pos.z)
                             * (float)(__b->position.z - __comp.m_view_pos.z)))
             + (float)(__aa * __aa)) > (float)((float)((float)(v6 * v6) + (float)(v9 * v9)) + (float)(v8 * v8)) )
  {
    v13 = __c->position.z - __comp.m_view_pos.z;
    if ( (float)((float)((float)(v10 * v10) + (float)(v13 * v13))
               + (float)((float)(__c->position.y - __comp.m_view_pos.y) * (float)(__c->position.y - __comp.m_view_pos.y))) <= (float)((float)((float)(v7 * v7) + (float)((float)(__b->position.z - __comp.m_view_pos.z) * (float)(__b->position.z - __comp.m_view_pos.z))) + (float)(__aa * __aa)) )
    {
      if ( (float)((float)((float)(v10 * v10) + (float)(v13 * v13))
                 + (float)((float)(__c->position.y - __comp.m_view_pos.y)
                         * (float)(__c->position.y - __comp.m_view_pos.y))) > (float)((float)((float)(v6 * v6)
                                                                                            + (float)(v8 * v8))
                                                                                    + (float)(v9 * v9)) )
        return __c;
      return result;
    }
    return __b;
  }
  v11 = __c->position.z - __comp.m_view_pos.z;
  v12 = __c->position.y - __comp.m_view_pos.y;
  if ( (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v12 * v12)) <= (float)((float)((float)(v6 * v6) + (float)(v8 * v8))
                                                                                               + (float)(v9 * v9)) )
  {
    result = __c;
    if ( (float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v10 * v10)) <= (float)((float)((float)((float)(__b->position.z - __comp.m_view_pos.z) * (float)(__b->position.z - __comp.m_view_pos.z)) + (float)(__aa * __aa))
                                                                                                 + (float)(v7 * v7)) )
      return __b;
  }
  return result;
}
