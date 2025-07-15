void __usercall boost::asio::basic_streambuf<stlp_std::allocator<char>>::~basic_streambuf<stlp_std::allocator<char>>(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this@<ecx>,
        int a2@<esi>)
{
  _STLP_atomic_freelist::item *v2; // eax

  v2 = *(_STLP_atomic_freelist::item **)(a2 + 36);
  if ( v2 )
    stlp_std::allocator<char>::deallocate((stlp_std::allocator<char> *)(a2 + 44), v2, *(_DWORD *)(a2 + 44) - (_DWORD)v2);
  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::~basic_streambuf<char,stlp_std::char_traits<char>>((stlp_std::basic_streambuf<char,stlp_std::char_traits<char> > *)a2);
}
