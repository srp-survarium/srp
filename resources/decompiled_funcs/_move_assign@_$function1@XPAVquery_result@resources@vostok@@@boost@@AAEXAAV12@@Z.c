void __usercall boost::function1<void,vostok::resources::query_result *>::move_assign(
        boost::function2<void,unsigned int,unsigned int> *this@<eax>,
        boost::function2<void,unsigned int,unsigned int> *f@<edi>,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *a3@<ecx>)
{
  boost::detail::function::vtable_base *vtable; // eax

  if ( f != this )
  {
    vtable = f->vtable;
    if ( f->vtable )
    {
      this->vtable = vtable;
      if ( ((unsigned __int8)vtable & 1) != 0 )
        this->functor = f->functor;
      else
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE))(
          &f->functor,
          &this->functor,
          1);
      f->vtable = 0;
    }
    else
    {
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(a3);
    }
  }
}
