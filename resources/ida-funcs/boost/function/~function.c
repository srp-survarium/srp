void __thiscall boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *this)
{
  boost::detail::function::vtable_base *vtable; // eax
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax

  vtable = this->vtable;
  if ( this->vtable )
  {
    if ( ((unsigned __int8)vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&this->functor, &this->functor, 2);
    }
    this->vtable = 0;
  }
}


void __usercall boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  void (__cdecl *v3)(int *, int *, int); // eax

  v2 = *a2;
  if ( *a2 )
  {
    if ( (v2 & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(int *, int *, int))(v2 & 0xFFFFFFFE);
      if ( v3 )
        v3(a2 + 2, a2 + 2, 2);
    }
    *a2 = 0;
  }
}
