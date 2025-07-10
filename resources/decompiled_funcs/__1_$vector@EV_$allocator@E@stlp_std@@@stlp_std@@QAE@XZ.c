void __usercall stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char>>::~vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::vector<unsigned char,stlp_std::allocator<unsigned char> > *this@<ecx>,
        int a2@<eax>)
{
  void *v2; // ecx
  unsigned int v3; // eax

  v2 = *(void **)a2;
  if ( *(_DWORD *)a2 )
  {
    v3 = *(_DWORD *)(a2 + 8) - (_DWORD)v2;
    if ( v3 <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(v2, v3);
    else
      operator delete(v2);
  }
}
