void __usercall stlp_std::__push_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        int __holeIndex@<ecx>,
        int __topIndex@<edi>,
        vostok::render::grass_patch *__val,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v5; // eax
  float v6; // xmm3_4
  vostok::render::grass_patch *v7; // edx

  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    v6 = (float)((float)((float)(__val->m_origin.z - __comp.m_view_pos.z)
                       * (float)(__val->m_origin.z - __comp.m_view_pos.z))
               + (float)((float)(__val->m_origin.y - __comp.m_view_pos.y)
                       * (float)(__val->m_origin.y - __comp.m_view_pos.y)))
       + (float)((float)(__val->m_origin.x - __comp.m_view_pos.x) * (float)(__val->m_origin.x - __comp.m_view_pos.x));
    do
    {
      v7 = __first[v5];
      if ( v6 <= (float)((float)((float)((float)(v7->m_origin.z - __comp.m_view_pos.z)
                                       * (float)(v7->m_origin.z - __comp.m_view_pos.z))
                               + (float)((float)(v7->m_origin.x - __comp.m_view_pos.x)
                                       * (float)(v7->m_origin.x - __comp.m_view_pos.x)))
                       + (float)((float)(v7->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v7->m_origin.y - __comp.m_view_pos.y))) )
        break;
      __first[__holeIndex] = v7;
      __holeIndex = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( __holeIndex > __topIndex );
  }
  __first[__holeIndex] = __val;
}
