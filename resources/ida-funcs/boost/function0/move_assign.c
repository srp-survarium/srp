void __thiscall boost::function0<void>::move_assign(boost::function0<void> *this, boost::function0<void> *f)
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
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)this);
    }
  }
}


void __thiscall boost::function0<bool>::move_assign(boost::function0<bool> *this, boost::function0<bool> *f)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function4<void,unsigned int,float,float,char const *> *v3; // ecx
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax

  if ( f != this )
  {
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)f) )
    {
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v2,
        (int *)this);
    }
    else
    {
      this->vtable = f->vtable;
      if ( (unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(f, this) )
      {
        this->functor = f->functor;
      }
      else
      {
        vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
                   v3,
                   this);
        vtable->base.manager(&f->functor, &this->functor, move_functor_tag);
      }
      f->vtable = 0;
    }
  }
}
