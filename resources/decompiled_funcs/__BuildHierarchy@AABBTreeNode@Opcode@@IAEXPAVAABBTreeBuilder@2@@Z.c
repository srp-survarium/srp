void __thiscall Opcode::AABBTreeNode::_BuildHierarchy(Opcode::AABBTreeNode *this, Opcode::AABBTreeBuilder *builder)
{
  Opcode::AABBTreeNode *v3; // ecx

  do
  {
    builder->ComputeGlobalBox(builder, this->mNodePrimitives, this->mNbPrimitives, (IceMaths::AABB *)this);
    Opcode::AABBTreeNode::Subdivide(this, builder);
    v3 = (Opcode::AABBTreeNode *)(this->mPos & 0xFFFFFFFE);
    if ( v3 )
      this = v3 + 1;
    else
      this = 0;
    if ( v3 )
      Opcode::AABBTreeNode::_BuildHierarchy(v3, builder);
  }
  while ( this );
}
