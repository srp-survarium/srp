void __usercall stlp_std::priv::__insertion_sort<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<eax>,
        vostok::render::grass_patch::sort_info *__last,
        _QWORD *a3)
{
  vostok::render::grass_patch::sort_info *i; // edi
  vostok::render::sort_indices_predicate v5; // [esp-10h] [ebp-20h]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_patch = *a3;
    *(_QWORD *)&v5.m_view_pos.elements[1] = a3[1];
    stlp_std::priv::__linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}
