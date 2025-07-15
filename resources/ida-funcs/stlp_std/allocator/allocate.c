_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<char>::allocate(
        stlp_std::allocator<char> *this,
        unsigned int __n,
        const void *__formal)
{
  if ( !__n )
    return 0;
  if ( __n <= 0x80 )
    return stlp_std::__node_alloc::_M_allocate(&__n);
  return (_STLP_atomic_freelist::item *)operator new(__n);
}


_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<wchar_t>::allocate(
        stlp_std::allocator<wchar_t> *this,
        unsigned int __n,
        const void *__formal)
{
  unsigned int v3; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  if ( __n > 0x7FFFFFFF )
  {
    std::exception::exception(&pExceptionObject, &bad_alloc_Message_3, 1);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException((DWORD)&pExceptionObject, &_TI2_AVbad_alloc_std__);
  }
  if ( !__n )
    return 0;
  v3 = 2 * __n;
  __n = v3;
  if ( v3 <= 0x80 )
    return stlp_std::__node_alloc::_M_allocate(&__n);
  else
    return (_STLP_atomic_freelist::item *)operator new(v3);
}
