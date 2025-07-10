void __usercall boost::function1<void,vostok::resources::queries_result &>::move_assign(
        boost::function1<void,vostok::resources::queries_result &> *this@<ecx>,
        boost::function1<void,vostok::resources::queries_result &> *f@<esi>)
{
  boost::detail::function::vtable_base *vtable; // eax

  if ( f != this )
  {
    vtable = f->vtable;
    if ( f->vtable )
    {
      this->vtable = vtable;
      if ( ((unsigned __int8)vtable & 1) != 0 )
      {
        this->functor = f->functor;
        f->vtable = 0;
      }
      else
      {
        (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE))(
          &f->functor,
          &this->functor,
          1);
        f->vtable = 0;
      }
    }
    else
    {
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)this);
    }
  }
}
