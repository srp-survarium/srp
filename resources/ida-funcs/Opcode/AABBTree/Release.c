void __usercall Opcode::AABBTree::Release(Opcode::AABBTree *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  int v5; // eax
  int v6; // eax

  Opcode::AABBTreeNode::Release(*(Opcode::AABBTreeNode **)(a2 + 52), (_DWORD *)a2);
  v2 = *(_DWORD *)(a2 + 40);
  if ( v2 )
  {
    v3 = *(_DWORD **)(a2 + 40);
    v4 = (_DWORD *)(v2 + 36 * *(_DWORD *)(a2 + 44));
    while ( v3 != v4 )
    {
      Opcode::AABBTreeNode::Release(*(Opcode::AABBTreeNode **)(a2 + 52), v3);
      v3 += 9;
    }
    if ( *(_DWORD *)(a2 + 40) )
    {
      v5 = *(_DWORD *)(a2 + 40);
      if ( v5 )
        (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 52) + 24))(
          *(_DWORD *)(a2 + 52),
          v5 - 8,
          "Opcode::AABBTree::Release",
          ".\\OPC_AABBTree.cpp",
          412);
      *(_DWORD *)(a2 + 40) = 0;
    }
  }
  if ( *(_DWORD *)(a2 + 36) )
  {
    v6 = *(_DWORD *)(a2 + 36);
    if ( v6 )
      (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 52) + 24))(
        *(_DWORD *)(a2 + 52),
        v6 - 8,
        "Opcode::AABBTree::Release",
        ".\\OPC_AABBTree.cpp",
        414);
    *(_DWORD *)(a2 + 36) = 0;
  }
}
