void __userpurge vostok::render::speedtree_tree_component::speedtree_tree_component(
        vostok::render::speedtree_tree_component *this@<ecx>,
        int a2@<eax>,
        vostok::render::speedtree_tree *parent)
{
  *(_DWORD *)a2 = &stru_962594.m_parent_task.m_function.functor.vostok_pointer_size_alignment[1];
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 32) = a2 + 44;
  *(_DWORD *)(a2 + 36) = a2 + 44;
  *(_BYTE *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 40) = a2 + 108;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 4) = parent;
}
