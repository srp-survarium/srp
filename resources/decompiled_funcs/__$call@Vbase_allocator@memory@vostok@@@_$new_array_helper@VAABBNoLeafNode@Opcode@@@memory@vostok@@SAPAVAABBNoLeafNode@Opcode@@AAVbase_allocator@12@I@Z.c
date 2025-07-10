Opcode::AABBNoLeafNode *__usercall vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBNoLeafNode *result; // eax
  Opcode::AABBNoLeafNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 32 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBNoLeafNode *)(v2 + 8);
  result[-1].mNegData = 32;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
    {
      i->mPosData = 0;
      i->mNegData = 0;
    }
  }
  return result;
}
