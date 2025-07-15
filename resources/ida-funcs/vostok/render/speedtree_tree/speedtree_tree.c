void __userpurge vostok::render::speedtree_tree::speedtree_tree(
        vostok::render::speedtree_tree *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 *data,
        unsigned int size)
{
  __int64 v5; // xmm0_8
  __int64 v6; // [esp+Ch] [ebp-10h]
  float v7; // [esp+14h] [ebp-8h]

  vostok::render::speedtree_tree_base::speedtree_tree_base(this, a2);
  SpeedTree::CCore::CCore((SpeedTree::CCore *)(a2 + 288));
  *(_DWORD *)(a2 + 3908) = 0;
  *(_DWORD *)(a2 + 3912) = 0;
  *(_DWORD *)(a2 + 3916) = 0;
  *(_DWORD *)(a2 + 3920) = 0;
  *(_DWORD *)(a2 + 3924) = 0;
  *(_DWORD *)a2 = &stru_962594.m_parent_task.m_next_task_in_full_queue;
  *(_DWORD *)(a2 + 288) = &(&stru_962594.m_parent_task.m_function.vtable)[1];
  `vector constructor iterator'(
    (char *)(a2 + 3928),
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  *(_QWORD *)(a2 + 264) = 0xBF000000BF000000uLL;
  v7 = FLOAT_0_5;
  *(float *)&v6 = FLOAT_0_5;
  *((float *)&v6 + 1) = FLOAT_0_5;
  v5 = v6;
  *(_DWORD *)(a2 + 272) = -1090519040;
  *(_QWORD *)(a2 + 276) = v5;
  *(float *)(a2 + 284) = FLOAT_0_5;
  vostok::render::speedtree_tree::load((vostok::render::speedtree_tree *)a2, data, size);
}
