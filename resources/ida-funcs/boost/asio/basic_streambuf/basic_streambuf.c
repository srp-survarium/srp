void __userpurge boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this@<ecx>,
        int a2@<esi>,
        unsigned int maximum_size,
        const stlp_std::allocator<char> *allocator)
{
  unsigned int v4; // ecx
  unsigned int *p_maximum_size; // eax
  int *v6; // edi
  unsigned int v7; // ebx
  unsigned int *v8; // eax
  int v9; // eax
  unsigned int v10; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::basic_streambuf<char,stlp_std::char_traits<char>>((stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *)a2);
  v4 = maximum_size;
  *(_DWORD *)a2 = &boost::asio::basic_streambuf<stlp_std::allocator<char>>::`vftable';
  p_maximum_size = (unsigned int *)(a2 + 32);
  *(_DWORD *)(a2 + 32) = v4;
  v6 = (int *)(a2 + 36);
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  maximum_size = 128;
  if ( *(_DWORD *)(a2 + 32) > 0x80u )
    p_maximum_size = &maximum_size;
  v7 = *p_maximum_size;
  v11 = 1;
  v10 = v7;
  HIBYTE(maximum_size) = 0;
  v8 = (unsigned int *)&v11;
  if ( v7 )
    v8 = &v10;
  stlp_std::vector<char,stlp_std::allocator<char>>::resize(
    (stlp_std::vector<char,stlp_std::allocator<char> > *)(a2 + 36),
    *v8,
    (const char *)&maximum_size + 3);
  v9 = *v6;
  *(_DWORD *)(a2 + 4) = *v6;
  *(_DWORD *)(a2 + 8) = v9;
  *(_DWORD *)(a2 + 12) = v9;
  *(_DWORD *)(a2 + 16) = v9;
  *(_DWORD *)(a2 + 20) = v9;
  *(_DWORD *)(a2 + 24) = v7 + v9;
}
