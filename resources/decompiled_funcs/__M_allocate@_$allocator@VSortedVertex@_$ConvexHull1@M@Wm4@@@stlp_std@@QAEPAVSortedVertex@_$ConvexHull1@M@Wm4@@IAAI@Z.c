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
