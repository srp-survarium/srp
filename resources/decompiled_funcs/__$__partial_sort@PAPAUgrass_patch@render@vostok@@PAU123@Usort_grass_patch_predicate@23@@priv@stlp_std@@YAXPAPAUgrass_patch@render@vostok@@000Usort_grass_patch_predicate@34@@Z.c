void __usercall stlp_std::priv::__partial_sort<vostok::render::grass_patch * *,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first@<eax>,
        vostok::render::grass_patch **__middle,
        vostok::render::grass_patch **__last,
        __int64 __formal,
        float __comp_8)
{
  vostok::render::grass_patch **v5; // ebx
  int v7; // ebp
  float v8; // xmm6_4
  vostok::render::grass_patch *v9; // eax
  vostok::render::sort_grass_patch_predicate v10; // [esp-1Ch] [ebp-28h]
  vostok::render::sort_grass_patch_predicate v11; // [esp-1Ch] [ebp-28h]

  v5 = __middle;
  v7 = __middle - __first;
  if ( v7 >= 2 )
    stlp_std::__make_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate,vostok::render::grass_patch *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    v8 = __comp_8;
    do
    {
      v9 = *v5;
      if ( (float)((float)((float)((float)((*__first)->m_origin.z - v8) * (float)((*__first)->m_origin.z - v8))
                         + (float)((float)((*__first)->m_origin.y - *((float *)&__formal + 1))
                                 * (float)((*__first)->m_origin.y - *((float *)&__formal + 1))))
                 + (float)((float)((*__first)->m_origin.x - *(float *)&__formal)
                         * (float)((*__first)->m_origin.x - *(float *)&__formal))) > (float)((float)((float)((float)((*v5)->m_origin.z - v8) * (float)((*v5)->m_origin.z - v8)) + (float)((float)((*v5)->m_origin.y - *((float *)&__formal + 1)) * (float)((*v5)->m_origin.y - *((float *)&__formal + 1))))
                                                                                           + (float)((float)((*v5)->m_origin.x - *(float *)&__formal) * (float)((*v5)->m_origin.x - *(float *)&__formal))) )
      {
        *v5 = *__first;
        *(_QWORD *)&v10.m_view_pos.x = __formal;
        v10.m_view_pos.z = __comp_8;
        stlp_std::__adjust_heap<vostok::render::grass_patch * *,int,vostok::render::grass_patch *,vostok::render::sort_grass_patch_predicate>(
          __first,
          0,
          v7,
          v9,
          v10);
        v8 = __comp_8;
      }
      ++v5;
    }
    while ( v5 < __last );
  }
  *(_QWORD *)&v11.m_view_pos.x = __formal;
  v11.m_view_pos.z = __comp_8;
  stlp_std::sort_heap<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
    __first,
    __middle,
    v11);
}
