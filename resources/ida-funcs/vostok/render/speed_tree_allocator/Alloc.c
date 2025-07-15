void *__thiscall vostok::render::speed_tree_allocator::Alloc(
        vostok::render::speed_tree_allocator *this,
        unsigned int size)
{
  void *result; // eax
  std::exception pExceptionObject; // [esp+4h] [ebp-Ch] BYREF

  result = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
             size);
  num_speedtree_memory_used += size;
  if ( !result )
  {
    std::exception::exception(&pExceptionObject, &bad_alloc_Message_49, 1);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, &_TI2_AVbad_alloc_std__);
  }
  return result;
}
