int __userpurge Opcode::AABBTreeNode::Split@<eax>(
        Opcode::AABBTreeNode *this@<esi>,
        Opcode::AABBTreeBuilder *builder@<edi>,
        unsigned int axis)
{
  unsigned int *mNodePrimitives; // eax
  unsigned int *v4; // ecx
  unsigned int v5; // edx
  int v6; // ebx
  unsigned int v7; // eax
  float v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  v9 = builder->GetSplittingValue(
         builder,
         this->mNodePrimitives,
         this->mNbPrimitives,
         (const IceMaths::AABB *)this,
         axis);
  v10 = 0;
  for ( i = 0; i < this->mNbPrimitives; ++i )
  {
    if ( ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, unsigned int))builder->GetSplittingValue)(
           builder,
           this->mNodePrimitives[i],
           axis) > v9 )
    {
      mNodePrimitives = this->mNodePrimitives;
      v4 = &mNodePrimitives[i];
      v5 = *v4;
      v6 = v10;
      v7 = mNodePrimitives[v10++];
      *v4 = v7;
      this->mNodePrimitives[v6] = v5;
    }
  }
  return v10;
}
