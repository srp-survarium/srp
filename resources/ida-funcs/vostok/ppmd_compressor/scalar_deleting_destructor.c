vostok::ppmd_compressor *__thiscall vostok::ppmd_compressor::`scalar deleting destructor'(
        vostok::ppmd_compressor *this,
        char a2)
{
  vostok::ppmd_compressor::~ppmd_compressor(this, (ppmd_allocator *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
