Opcode::AABBCollisionNode *__usercall vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  Opcode::AABBCollisionNode *result; // eax
  Opcode::AABBCollisionNode *i; // ecx

  v2 = (char *)allocator->call_malloc(allocator, 28 * count + 8);
  *(_DWORD *)v2 = count;
  result = (Opcode::AABBCollisionNode *)(v2 + 8);
  result[-1].mData = 28;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      i->mData = 0;
  }
  return result;
}
