Opcode::AABBTreeNode *__usercall vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  unsigned int v3; // esi
  char *v4; // eax
  Opcode::AABBTreeNode *result; // eax
  unsigned int **p_mNodePrimitives; // ecx

  v3 = count;
  v4 = (char *)allocator->call_malloc(allocator, 36 * count + 8);
  *(_DWORD *)v4 = count;
  v4 += 4;
  *(_DWORD *)v4 = 36;
  result = (Opcode::AABBTreeNode *)(v4 + 4);
  if ( result != &result[v3] )
  {
    p_mNodePrimitives = &result->mNodePrimitives;
    do
    {
      if ( p_mNodePrimitives != (unsigned int **)28 )
      {
        *(p_mNodePrimitives - 1) = 0;
        *p_mNodePrimitives = 0;
        p_mNodePrimitives[1] = 0;
      }
      p_mNodePrimitives += 9;
    }
    while ( p_mNodePrimitives - 7 != (unsigned int **)&result[v3] );
  }
  return result;
}
