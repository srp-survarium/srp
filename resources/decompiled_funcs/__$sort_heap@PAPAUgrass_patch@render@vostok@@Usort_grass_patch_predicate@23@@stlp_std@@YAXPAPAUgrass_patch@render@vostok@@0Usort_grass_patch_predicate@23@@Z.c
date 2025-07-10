void __usercall stlp_std::sort_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<esi>,
        vostok::render::grass_patch **__last@<eax>,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v3; // eax
  vostok::render::grass_patch *v4; // ecx
  __int64 v5; // xmm0_8
  int v6; // edi
  vostok::render::sort_grass_patch_predicate v7; // [esp-Ch] [ebp-10h]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::grass_patch **)((char *)__first + v3 - 4);
      v5 = *(_QWORD *)&__comp.m_view_pos.x;
      *(vostok::render::grass_patch **)((char *)__first + v3 - 4) = *__first;
      v6 = v3 - 4;
      *(_QWORD *)&v7.m_view_pos.x = v5;
      v7.m_view_pos.z = __comp.m_view_pos.z;
      stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        v7);
      v3 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}
