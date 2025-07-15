char __userpurge Opcode::AABBTree::Build@<al>(
        Opcode::AABBTree *this@<ecx>,
        int a2@<eax>,
        Opcode::AABBTreeBuilder *builder)
{
  unsigned int mNbPrimitives; // esi
  unsigned int *v6; // eax
  unsigned int i; // eax
  unsigned int v8; // eax
  Opcode::AABBTreeNode *v9; // eax
  vostok::memory::base_allocator *v11; // [esp-Ch] [ebp-14h]

  if ( !builder )
    return 0;
  if ( !builder->mNbPrimitives )
    return 0;
  Opcode::AABBTree::Release(this, a2);
  builder->mNbInvalidSplits = 0;
  mNbPrimitives = builder->mNbPrimitives;
  builder->mCount = 1;
  v6 = vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::base_allocator>(
         *(vostok::memory::base_allocator **)(a2 + 52),
         mNbPrimitives);
  *(_DWORD *)(a2 + 36) = v6;
  if ( !v6 )
    return 0;
  for ( i = 0; i < builder->mNbPrimitives; ++i )
    *(_DWORD *)(*(_DWORD *)(a2 + 36) + 4 * i) = i;
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 32) = builder->mNbPrimitives;
  if ( builder->mSettings.mLimit == 1 )
  {
    v8 = 2 * builder->mNbPrimitives - 1;
    v11 = *(vostok::memory::base_allocator **)(a2 + 52);
    *(_DWORD *)(a2 + 44) = v8;
    v9 = vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>(
           v8,
           v11,
           "Opcode::AABBTree::Build",
           (const char *const)0x1C4);
    *(_DWORD *)(a2 + 40) = v9;
    builder->mNodeBase = v9;
  }
  Opcode::AABBTreeNode::_BuildHierarchy((Opcode::AABBTreeNode *)a2, builder);
  *(_DWORD *)(a2 + 48) = builder->mCount;
  return 1;
}
