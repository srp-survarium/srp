void __usercall stlp_std::priv::__insertion_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__last,
        int a3)
{
  vostok::render::grass_patch **i; // esi
  vostok::render::sort_grass_patch_predicate v5; // [esp-Ch] [ebp-1Ch]

  for ( i = __first + 1; i != __last; ++i )
  {
    *(_QWORD *)&v5.m_view_pos.x = *(_QWORD *)a3;
    v5.m_view_pos.z = *(float *)(a3 + 8);
    stlp_std::priv::__linear_insert<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      i,
      *i,
      v5);
  }
}
