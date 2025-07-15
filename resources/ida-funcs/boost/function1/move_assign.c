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


void __usercall boost::function1<void,vostok::vfs::base_node<1> *>::move_assign(
        boost::function1<void,vostok::vfs::vfs_iterator &> *this@<eax>,
        boost::function1<void,vostok::vfs::vfs_iterator &> *f@<edi>)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::detail::function::basic_vtable1<void,vostok::vfs::base_node<1> *> *v4; // eax

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
        v4 = boost::function1<void,vostok::vfs::vfs_association * &>::get_vtable((boost::function1<void,vostok::vfs::base_node<1> *> *)this);
        v4->base.manager(&f->functor, &this->functor, move_functor_tag);
        f->vtable = 0;
      }
    }
    else
    {
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)this);
    }
  }
}
