_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<char>::_M_allocate(
        stlp_std::allocator<char> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  _STLP_atomic_freelist::item *result; // eax

  if ( !__n )
    return 0;
  result = stlp_std::__node_alloc::allocate(&__n);
  *__allocated_n = __n;
  return result;
}


_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<void *>::_M_allocate(
        stlp_std::allocator<void *> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  _STLP_atomic_freelist::item *result; // eax

  if ( __n > 0x3FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  __n *= 4;
  result = stlp_std::__node_alloc::allocate(&__n);
  *__allocated_n = __n >> 2;
  return result;
}


_STLP_atomic_freelist::item *__thiscall stlp_std::allocator<wchar_t>::_M_allocate(
        stlp_std::allocator<wchar_t> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  unsigned int v3; // eax
  _STLP_atomic_freelist::item *result; // eax
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
    result = stlp_std::__node_alloc::_M_allocate(&__n);
  else
    result = (_STLP_atomic_freelist::item *)operator new(v3);
  *__allocated_n = __n >> 1;
  return result;
}
