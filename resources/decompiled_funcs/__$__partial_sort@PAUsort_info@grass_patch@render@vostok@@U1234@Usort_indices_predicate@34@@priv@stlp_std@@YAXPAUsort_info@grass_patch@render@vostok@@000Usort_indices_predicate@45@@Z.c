void __usercall stlp_std::priv::__partial_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        int *a2@<edi>,
        vostok::render::grass_patch::sort_info *__middle,
        vostok::render::grass_patch::sort_info *__last,
        __int64 __formal,
        __int64 __comp_8)
{
  vostok::render::grass_patch::sort_info *v7; // esi
  float v8; // xmm6_4
  vostok::render::sort_indices_predicate v9; // [esp-20h] [ebp-30h]
  vostok::render::sort_indices_predicate v10; // [esp-20h] [ebp-30h]
  int *v11; // [esp-10h] [ebp-20h]

  v11 = a2;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate,vostok::render::grass_patch::sort_info,int>(
      __first,
      __middle);
  v7 = __middle;
  if ( __middle < __last )
  {
    v8 = *((float *)&__comp_8 + 1);
    do
    {
      if ( (float)((float)((float)((float)(__first->position.x - *((float *)&__formal + 1))
                                 * (float)(__first->position.x - *((float *)&__formal + 1)))
                         + (float)((float)(__first->position.z - v8) * (float)(__first->position.z - v8)))
                 + (float)((float)(__first->position.y - *(float *)&__comp_8)
                         * (float)(__first->position.y - *(float *)&__comp_8))) > (float)((float)((float)((float)(v7->position.x - *((float *)&__formal + 1)) * (float)(v7->position.x - *((float *)&__formal + 1)))
                                                                                                + (float)((float)(v7->position.z - v8) * (float)(v7->position.z - v8)))
                                                                                        + (float)((float)(v7->position.y - *(float *)&__comp_8)
                                                                                                * (float)(v7->position.y - *(float *)&__comp_8))) )
      {
        *(_QWORD *)&v9.m_patch = __formal;
        *(_QWORD *)&v9.m_view_pos.elements[1] = __comp_8;
        stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
          __first,
          __middle,
          v7,
          *v7,
          v9,
          v11);
        v8 = *((float *)&__comp_8 + 1);
      }
      ++v7;
    }
    while ( v7 < __last );
  }
  *(_QWORD *)&v10.m_patch = __formal;
  *(_QWORD *)&v10.m_view_pos.elements[1] = __comp_8;
  stlp_std::sort_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
    __first,
    __middle,
    v10);
}
