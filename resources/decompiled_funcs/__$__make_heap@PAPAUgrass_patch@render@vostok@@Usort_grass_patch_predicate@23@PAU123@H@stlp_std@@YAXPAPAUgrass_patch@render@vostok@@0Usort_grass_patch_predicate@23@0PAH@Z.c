void __usercall stlp_std::__make_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate,vostok::render::grass_patch *,int>(
        vostok::render::grass_patch **__first@<edi>,
        vostok::render::grass_patch **__last,
        int a3)
{
  int v3; // ebp
  int v4; // esi
  vostok::render::grass_patch *v5; // edx
  vostok::render::sort_grass_patch_predicate v6; // [esp-14h] [ebp-18h]
  vostok::render::sort_grass_patch_predicate v7; // [esp-14h] [ebp-18h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  *(_QWORD *)&v6.m_view_pos.x = *(_QWORD *)a3;
  v6.m_view_pos.z = *(float *)(a3 + 8);
  stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    v6);
  while ( v4 )
  {
    v5 = __first[--v4];
    *(_QWORD *)&v7.m_view_pos.x = *(_QWORD *)a3;
    v7.m_view_pos.z = *(float *)(a3 + 8);
    stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
      __first,
      v4,
      v3,
      v5,
      v7);
  }
}
