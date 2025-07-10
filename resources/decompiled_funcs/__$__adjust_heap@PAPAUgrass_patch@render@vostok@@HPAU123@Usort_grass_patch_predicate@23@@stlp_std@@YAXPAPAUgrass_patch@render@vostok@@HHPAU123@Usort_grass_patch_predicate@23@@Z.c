void __usercall stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        int __holeIndex@<ecx>,
        int __len,
        vostok::render::grass_patch *__val,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v6; // eax
  bool v7; // zf
  int i; // edi
  vostok::render::grass_patch *v9; // edx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  vostok::render::grass_patch *v13; // edx

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  for ( i = __holeIndex; v6 < __len; v7 = v6 == __len )
  {
    v9 = __first[v6];
    x = v9->m_origin.x;
    y = v9->m_origin.y;
    z = v9->m_origin.z;
    v13 = __first[v6 - 1];
    if ( (float)((float)((float)((float)(v13->m_origin.z - __comp.m_view_pos.z)
                               * (float)(v13->m_origin.z - __comp.m_view_pos.z))
                       + (float)((float)(v13->m_origin.y - __comp.m_view_pos.y)
                               * (float)(v13->m_origin.y - __comp.m_view_pos.y)))
               + (float)((float)(v13->m_origin.x - __comp.m_view_pos.x) * (float)(v13->m_origin.x - __comp.m_view_pos.x))) > (float)((float)((float)((float)(z - __comp.m_view_pos.z) * (float)(z - __comp.m_view_pos.z)) + (float)((float)(y - __comp.m_view_pos.y) * (float)(y - __comp.m_view_pos.y))) + (float)((float)(x - __comp.m_view_pos.x) * (float)(x - __comp.m_view_pos.x))) )
      --v6;
    __first[__holeIndex] = __first[v6];
    __holeIndex = v6;
    v6 = 2 * v6 + 2;
  }
  if ( v7 )
  {
    __first[__holeIndex] = __first[v6 - 1];
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
    __first,
    __holeIndex,
    i,
    __val,
    __comp);
}
