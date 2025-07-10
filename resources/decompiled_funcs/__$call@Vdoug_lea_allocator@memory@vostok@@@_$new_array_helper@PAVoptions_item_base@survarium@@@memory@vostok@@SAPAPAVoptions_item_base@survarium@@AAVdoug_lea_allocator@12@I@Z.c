vostok::render::grass_layer_desc **__usercall vostok::memory::new_array_helper<survarium::options_item_base *>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  vostok::render::grass_layer_desc **result; // eax
  vostok::render::grass_layer_desc **v4; // edx
  vostok::render::grass_layer_desc **i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *(_DWORD *)v2 = count;
  result = (vostok::render::grass_layer_desc **)(v2 + 8);
  *(result - 1) = (vostok::render::grass_layer_desc *)4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}
