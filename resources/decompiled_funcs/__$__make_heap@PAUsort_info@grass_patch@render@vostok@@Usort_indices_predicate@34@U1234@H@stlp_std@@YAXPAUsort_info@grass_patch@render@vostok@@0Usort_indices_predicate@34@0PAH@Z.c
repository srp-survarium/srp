void __usercall stlp_std::__make_heap<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate,vostok::render::grass_patch::sort_info,int>(
        vostok::render::grass_patch::sort_info *__last@<eax>,
        vostok::render::grass_patch::sort_info *__first,
        _QWORD *a3)
{
  int v3; // esi
  int v4; // edi
  vostok::render::grass_patch::sort_info *v5; // ebx
  unsigned int num_indices; // ecx
  __int64 v7; // xmm0_8
  vostok::render::grass_patch::sort_info v8; // [esp-2Ch] [ebp-34h]
  vostok::render::sort_indices_predicate v9; // [esp-18h] [ebp-20h]
  vostok::render::sort_indices_predicate v10; // [esp-18h] [ebp-20h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  *(_QWORD *)&v9.m_patch = *a3;
  *(_QWORD *)&v9.m_view_pos.elements[1] = a3[1];
  stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
    __first,
    v4,
    v3,
    *v5,
    v9);
  while ( v4 )
  {
    num_indices = v5[-1].num_indices;
    *(_QWORD *)&v10.m_patch = *a3;
    *(_QWORD *)&v10.m_view_pos.elements[1] = a3[1];
    v7 = *(_QWORD *)&v5[-1].position.x;
    --v5;
    *(_QWORD *)&v8.position.x = v7;
    *(_QWORD *)&v8.position.elements[2] = *(_QWORD *)&v5->position.elements[2];
    v8.num_indices = num_indices;
    stlp_std::__adjust_heap<vostok::render::grass_patch::sort_info *,int,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __first,
      --v4,
      v3,
      v8,
      v10);
  }
}
