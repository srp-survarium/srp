char *__thiscall stlp_std::allocator<char>::_M_allocate(
        stlp_std::allocator<char> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  char *result; // eax

  if ( !__n )
    return 0;
  if ( __n <= 0x80 )
    result = (char *)stlp_std::__node_alloc::_M_allocate(&__n);
  else
    result = (char *)operator new(__n);
  *__allocated_n = __n;
  return result;
}


unsigned __int8 *__userpurge stlp_std::allocator<unsigned char>::_M_allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int a2@<ecx>,
        stlp_std::allocator<unsigned char> *this,
        unsigned int *__allocated_n)
{
  unsigned __int8 *result; // eax
  unsigned int __buf_size; // [esp+0h] [ebp-4h] BYREF

  __buf_size = a2;
  if ( !__n )
    return 0;
  __buf_size = __n;
  if ( __n <= 0x80 )
    result = (unsigned __int8 *)stlp_std::__node_alloc::_M_allocate(&__buf_size);
  else
    result = (unsigned __int8 *)operator new(__n);
  *(_DWORD *)&this->stlp_std::__stlport_class<stlp_std::allocator<unsigned char> > = __buf_size;
  return result;
}


void **__thiscall stlp_std::allocator<void *>::_M_allocate(
        stlp_std::allocator<void *> *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  void **result; // eax
  unsigned int __buf_size; // [esp+8h] [ebp-4h] BYREF

  if ( __n > 0x3FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  __buf_size = 4 * __n;
  result = (void **)stlp_std::__node_alloc::allocate(&__buf_size);
  *__allocated_n = __buf_size >> 2;
  return result;
}


Wm4::ConvexHull1<float>::SortedVertex *__userpurge stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex>::_M_allocate@<eax>(
        unsigned int __n@<eax>,
        unsigned int a2@<ecx>,
        stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> *this,
        unsigned int *__allocated_n)
{
  unsigned int v4; // eax
  Wm4::ConvexHull1<float>::SortedVertex *result; // eax
  unsigned int __buf_size; // [esp+0h] [ebp-4h] BYREF

  __buf_size = a2;
  if ( __n > 0x1FFFFFFF )
  {
    puts("out of memory\n");
    exit(1);
  }
  if ( !__n )
    return 0;
  v4 = 8 * __n;
  __buf_size = v4;
  if ( v4 <= 0x80 )
    result = (Wm4::ConvexHull1<float>::SortedVertex *)stlp_std::__node_alloc::_M_allocate(&__buf_size);
  else
    result = (Wm4::ConvexHull1<float>::SortedVertex *)operator new(v4);
  *(_DWORD *)&this->stlp_std::__stlport_class<stlp_std::allocator<Wm4::ConvexHull1<float>::SortedVertex> > = __buf_size >> 3;
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
    std::exception::exception(&pExceptionObject, &bad_alloc_Message_6, 1);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, &_TI2_AVbad_alloc_std__);
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
