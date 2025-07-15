Scaleform::DefaultAcquireInterface *__thiscall Scaleform::SysAllocMalloc::Realloc(
        Scaleform::SysAllocMalloc *this,
        unsigned int oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        Scaleform::DefaultAcquireInterface *align)
{
  if ( newSize == oldSize )
    return (Scaleform::DefaultAcquireInterface *)oldPtr;
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  return Scaleform::DefaultAcquireInterface::`vector deleting destructor'(align, oldPtr);
}
