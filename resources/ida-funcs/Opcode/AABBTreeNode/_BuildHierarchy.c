void __thiscall Opcode::AABBTreeNode::_BuildHierarchy(Opcode::AABBTreeNode *this, Opcode::AABBTreeBuilder *builder)
{
  Opcode::AABBTreeNode *v3; // ecx
  Opcode::AABBTreeNode *v4; // ecx

  do
  {
    builder->ComputeGlobalBox(builder, this->mNodePrimitives, this->mNbPrimitives, (IceMaths::AABB *)this);
    Opcode::AABBTreeNode::Subdivide(v3, this, builder);
    v4 = (Opcode::AABBTreeNode *)(this->mPos & 0xFFFFFFFE);
    this = v4 != 0 ? &v4[1] : 0;
    if ( v4 )
      Opcode::AABBTreeNode::_BuildHierarchy(v4, builder);
  }
  while ( this );
}
