void __usercall boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
        boost::function4<void,unsigned int,float,float,char const *> *this@<ecx>,
        int a2@<esi>)
{
  boost::detail::function::vtable_base *vtable; // eax

  *(_DWORD *)a2 = 0;
  vtable = this->vtable;
  if ( this->vtable )
  {
    *(_DWORD *)a2 = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      *(boost::detail::function::function_buffer *)(a2 + 8) = this->functor;
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, int, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->functor,
        a2 + 8,
        0);
  }
}
