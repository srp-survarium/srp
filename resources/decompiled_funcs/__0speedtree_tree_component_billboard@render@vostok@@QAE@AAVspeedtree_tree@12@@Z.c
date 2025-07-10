void __userpurge vostok::render::speedtree_tree_component_billboard::speedtree_tree_component_billboard(
        vostok::render::speedtree_tree_component_billboard *this@<ecx>,
        int a2@<eax>,
        vostok::render::speedtree_tree *parent)
{
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 32) = a2 + 44;
  *(_DWORD *)(a2 + 36) = a2 + 44;
  *(_BYTE *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 40) = a2 + 108;
  *(_DWORD *)(a2 + 108) = 0;
  *(_DWORD *)(a2 + 4) = parent;
  *(_DWORD *)a2 = &vostok::render::speedtree_tree_component_billboard::`vftable';
  *(_BYTE *)(a2 + 112) = 0;
}
