void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last@<edi>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  vostok::render::grass_patch **v3; // esi
  vostok::render::sort_grass_patch_predicate v4; // [esp-8h] [ebp-18h]

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        __first,
        __last);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      __first + 16);
    *(_QWORD *)&v4.m_view_pos.x = *(_QWORD *)&__comp.m_view_pos.elements[1];
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      v3,
      __last,
      (vostok::render::grass_patch **)LODWORD(__comp.m_view_pos.x),
      v4);
  }
}
