void __userpurge boost::function1<void,vostok::resources::queries_result &>::swap(
        boost::function1<void,vostok::resources::queries_result &> *other@<edi>,
        boost::function1<void,vostok::resources::queries_result &> *this)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function1<void,vostok::resources::queries_result &> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::move_assign(&tmp, this);
    boost::function1<void,vostok::resources::queries_result &>::move_assign(this, other);
    boost::function1<void,vostok::resources::queries_result &>::move_assign(other, &tmp);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}
