void __usercall stlp_std::__push_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<edi>,
        int __holeIndex@<eax>,
        int __topIndex,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  int v5; // esi
  int i; // eax
  vostok::render::grass_patch::sort_info *v7; // ecx
  vostok::render::grass_patch::sort_info *v8; // edx

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    v7 = &__first[i];
    if ( (float)((float)((float)((float)(__val.position.z - __comp.m_view_pos.z)
                               * (float)(__val.position.z - __comp.m_view_pos.z))
                       + (float)((float)(__val.position.y - __comp.m_view_pos.y)
                               * (float)(__val.position.y - __comp.m_view_pos.y)))
               + (float)((float)(__val.position.x - __comp.m_view_pos.x)
                       * (float)(__val.position.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(v7->position.x - __comp.m_view_pos.x) * (float)(v7->position.x - __comp.m_view_pos.x))
                                                                                            + (float)((float)(v7->position.y - __comp.m_view_pos.y) * (float)(v7->position.y - __comp.m_view_pos.y)))
                                                                                    + (float)((float)(v7->position.z - __comp.m_view_pos.z)
                                                                                            * (float)(v7->position.z - __comp.m_view_pos.z))) )
      break;
    v8 = &__first[v5];
    *(_QWORD *)&v8->position.x = *(_QWORD *)&v7->position.x;
    v5 = i;
    *(_QWORD *)&v8->position.elements[2] = *(_QWORD *)&v7->position.elements[2];
    v8->num_indices = v7->num_indices;
  }
  __first[v5] = __val;
}
