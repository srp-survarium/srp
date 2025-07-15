int __fastcall stlp_std::_dynamic_initializer_for___Nameless__(int a1)
{
  stlp_std::allocator<char> v2; // [esp+1h] [ebp-1h] BYREF

  v2.stlp_std::__stlport_class<stlp_std::allocator<char> > = (stlp_std::__stlport_class<stlp_std::allocator<char> >)HIBYTE(a1);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &Nameless,
    "*",
    &v2);
  return atexit(stlp_std::_dynamic_atexit_destructor_for___Nameless__);
}
