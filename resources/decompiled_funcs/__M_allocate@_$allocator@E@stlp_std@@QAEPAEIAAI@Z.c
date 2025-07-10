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
