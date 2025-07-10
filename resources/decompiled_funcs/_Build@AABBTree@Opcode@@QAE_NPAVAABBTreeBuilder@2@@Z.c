char __userpurge Opcode::AABBTree::Build@<al>(
        Opcode::AABBTreeBuilder *builder@<edi>,
        Opcode::AABBTree *a2@<ecx>,
        Opcode::AABBTree *this)
{
  unsigned int mNbPrimitives; // esi
  unsigned int *v4; // eax
  unsigned int i; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  unsigned int v7; // eax
  Opcode::AABBTreeNode *v8; // eax

  if ( !builder )
    return 0;
  if ( !builder->mNbPrimitives )
    return 0;
  Opcode::AABBTree::Release(a2, (int)this);
  mNbPrimitives = builder->mNbPrimitives;
  builder->mCount = 1;
  builder->mNbInvalidSplits = 0;
  v4 = vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::base_allocator>(
         this->m_allocator,
         mNbPrimitives);
  this->mIndices = v4;
  if ( !v4 )
    return 0;
  for ( i = 0; i < builder->mNbPrimitives; ++i )
    this->mIndices[i] = i;
  this->mNodePrimitives = this->mIndices;
  this->mNbPrimitives = builder->mNbPrimitives;
  if ( builder->mSettings.mLimit == 1 )
  {
    m_allocator = this->m_allocator;
    v7 = 2 * builder->mNbPrimitives - 1;
    this->mPool_count = v7;
    v8 = vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>(m_allocator, v7);
    this->mPool = v8;
    builder->mNodeBase = v8;
  }
  Opcode::AABBTreeNode::_BuildHierarchy(this, builder);
  this->mTotalNbNodes = builder->mCount;
  return 1;
}
