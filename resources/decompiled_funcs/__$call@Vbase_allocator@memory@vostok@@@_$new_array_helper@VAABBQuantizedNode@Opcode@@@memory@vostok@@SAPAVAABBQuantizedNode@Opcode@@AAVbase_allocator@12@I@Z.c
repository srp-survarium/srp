Opcode::AABBQuantizedNode *__usercall vostok::memory::new_array_helper<Opcode::AABBQuantizedNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBQuantizedNode *result; // eax
  Opcode::AABBQuantizedNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 16 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBQuantizedNode *)(v2 + 8);
  result[-1].mData = 16;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->mData = 0;
  }
  return result;
}
