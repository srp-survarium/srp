void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::render::grass_patch **i; // edi
  vostok::render::sort_grass_patch_predicate v5; // [esp-Ch] [ebp-18h]

  for ( i = __first; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_view_pos.x = __formal;
    v5.m_view_pos.z = __comp_8;
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      i,
      *i,
      v5);
  }
}
