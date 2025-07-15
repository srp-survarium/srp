void __usercall boost::bad_function_call::bad_function_call(
        boost::bad_function_call *this@<ecx>,
        stlp_std::runtime_error *a2@<esi>)
{
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __s; // [esp+4h] [ebp-1Ch] BYREF
  stlp_std::allocator<char> v3; // [esp+1Fh] [ebp-1h] BYREF

  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &__s,
    "call to empty boost::function",
    &v3);
  stlp_std::runtime_error::runtime_error(a2, &__s);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__s);
  a2->__vftable = (stlp_std::runtime_error_vtbl *)&boost::bad_function_call::`vftable';
}
