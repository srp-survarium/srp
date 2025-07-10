Opcode::AABBQuantizedNoLeafNode *__usercall vostok::memory::new_array_helper<Opcode::AABBQuantizedNoLeafNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBQuantizedNoLeafNode *result; // eax
  Opcode::AABBQuantizedNoLeafNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 20 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBQuantizedNoLeafNode *)(v2 + 8);
  result[-1].mNegData = 20;
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
