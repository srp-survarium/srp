int __userpurge Opcode::AABBTreeNode::Split@<eax>(
        Opcode::AABBTreeNode *this@<ecx>,
        int a2@<esi>,
        unsigned int axis,
        Opcode::AABBTreeBuilder *builder)
{
  int v5; // ebx
  unsigned int i; // edi
  int v7; // eax
  int v8; // ecx
  float SplitValue; // [esp+18h] [ebp+8h]

  SplitValue = builder->GetSplittingValue(
                 builder,
                 *(const unsigned int **)(a2 + 28),
                 *(_DWORD *)(a2 + 32),
                 (const IceMaths::AABB *)a2,
                 axis);
  v5 = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 32); ++i )
  {
    if ( ((double (__thiscall *)(Opcode::AABBTreeBuilder *, _DWORD, unsigned int))builder->GetSplittingValue)(
           builder,
           *(_DWORD *)(*(_DWORD *)(a2 + 28) + 4 * i),
           axis) > SplitValue )
    {
      v7 = *(_DWORD *)(a2 + 28);
      v8 = *(_DWORD *)(v7 + 4 * i);
      *(_DWORD *)(v7 + 4 * i) = *(_DWORD *)(v7 + 4 * v5);
      *(_DWORD *)(*(_DWORD *)(a2 + 28) + 4 * v5++) = v8;
    }
  }
  return v5;
}
