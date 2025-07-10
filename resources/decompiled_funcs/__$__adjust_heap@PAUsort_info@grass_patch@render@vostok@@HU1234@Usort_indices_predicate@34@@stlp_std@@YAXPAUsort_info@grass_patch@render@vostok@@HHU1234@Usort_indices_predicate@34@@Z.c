void __usercall stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<ecx>,
        int __holeIndex@<eax>,
        int __len@<esi>,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  int v6; // ecx
  bool v7; // zf
  int v8; // ebx
  float z; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  vostok::render::grass_patch::sort_info *v13; // edx
  vostok::render::grass_patch::sort_info *v14; // eax
  vostok::render::grass_patch::sort_info *v15; // edx
  vostok::render::grass_patch::sort_info *v16; // eax

  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  v8 = __holeIndex;
  if ( v6 < __len )
  {
    z = __comp.m_view_pos.z;
    do
    {
      v10 = __first[v6].position.z - z;
      v11 = __first[v6 - 1].position.x - __comp.m_view_pos.x;
      v12 = __first[v6].position.y - __comp.m_view_pos.y;
      if ( (float)((float)((float)((float)(__first[v6 - 1].position.z - z) * (float)(__first[v6 - 1].position.z - z))
                         + (float)(v11 * v11))
                 + (float)((float)(__first[v6 - 1].position.y - __comp.m_view_pos.y)
                         * (float)(__first[v6 - 1].position.y - __comp.m_view_pos.y))) > (float)((float)((float)(v10 * v10) + (float)((float)(__first[v6].position.x - __comp.m_view_pos.x) * (float)(__first[v6].position.x - __comp.m_view_pos.x)))
                                                                                               + (float)(v12 * v12)) )
        --v6;
      v13 = &__first[v6];
      v14 = &__first[__holeIndex];
      *(_QWORD *)&v14->position.x = *(_QWORD *)&v13->position.x;
      *(_QWORD *)&v14->position.elements[2] = *(_QWORD *)&v13->position.elements[2];
      v14->num_indices = v13->num_indices;
      __holeIndex = v6;
      v6 = 2 * v6 + 2;
      v7 = v6 == __len;
    }
    while ( v6 < __len );
  }
  if ( v7 )
  {
    v15 = &__first[v6 - 1];
    v16 = &__first[__holeIndex];
    *(_QWORD *)&v16->position.x = *(_QWORD *)&v15->position.x;
    *(_QWORD *)&v16->position.elements[2] = *(_QWORD *)&v15->position.elements[2];
    v16->num_indices = v15->num_indices;
    __holeIndex = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    __holeIndex,
    v8,
    __val,
    __comp);
}
