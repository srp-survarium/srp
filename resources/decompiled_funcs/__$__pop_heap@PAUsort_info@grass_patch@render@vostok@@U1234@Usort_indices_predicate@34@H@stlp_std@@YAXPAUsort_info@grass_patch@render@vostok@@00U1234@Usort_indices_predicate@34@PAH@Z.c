void __usercall stlp_std::__pop_heap<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate,int>(
        vostok::render::grass_patch::sort_info *__last@<edx>,
        vostok::render::grass_patch::sort_info *__result@<eax>,
        vostok::render::grass_patch::sort_info *__first,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  __int64 v5; // xmm0_8
  unsigned int v6; // edx
  vostok::render::sort_indices_predicate v7; // [esp-14h] [ebp-14h]

  *(_QWORD *)&__result->position.x = *(_QWORD *)&__first->position.x;
  *(_QWORD *)&__result->position.elements[2] = *(_QWORD *)&__first->position.elements[2];
  v5 = *(_QWORD *)&__comp.m_patch;
  __result->num_indices = __first->num_indices;
  *(_QWORD *)&v7.m_patch = v5;
  *(_QWORD *)&v7.m_view_pos.elements[1] = *(_QWORD *)&__comp.m_view_pos.elements[1];
  v6 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 3;
  stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    0,
    v6 + (v6 >> 31),
    __val,
    v7);
}
