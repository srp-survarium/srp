vostok::render::lod_entry *__usercall vostok::memory::new_array_helper<vostok::render::lod_entry>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  vostok::render::lod_entry *v3; // eax
  vostok::render::lod_entry *result; // eax
  vostok::render::lod_entry *v5; // edx
  vostok::render::lod_entry *i; // ecx

  v3 = (vostok::render::lod_entry *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 8 * count + 8);
  v3->start_index = count;
  result = v3 + 1;
  result[-1].num_indices = 8;
  v5 = &result[count];
  for ( i = result; i != v5; ++i )
  {
    if ( i )
    {
      i->start_index = 0;
      i->num_indices = 0;
    }
  }
  return result;
}
