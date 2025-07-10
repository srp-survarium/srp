vostok::math::float2 *__thiscall vostok::memory::new_array_helper<vostok::math::float2>::call<vostok::memory::doug_lea_allocator>(
        vostok::memory::doug_lea_allocator *allocator)
{
  char *v1; // eax
  vostok::math::float2 *result; // eax
  vostok::math::float2 *v3; // ecx
  float v4; // xmm0_4

  v1 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 0x328u);
  *(_DWORD *)v1 = 100;
  result = (vostok::math::float2 *)(v1 + 8);
  LODWORD(result[-1].y) = 8;
  v3 = result;
  v4 = SNaN;
  do
  {
    if ( v3 )
    {
      v3->x = v4;
      v3->y = v4;
    }
    ++v3;
  }
  while ( v3 != &result[100] );
  return result;
}
