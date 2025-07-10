void __thiscall boost::function0<bool>::assign_to_own(
        boost::function0<bool> *this,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *f)
{
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax

  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(f) )
  {
    this->vtable = (boost::detail::function::vtable_base *)f->m_object;
    if ( (unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(this, this) )
    {
      this->functor = *(boost::detail::function::function_buffer *)&f[2].m_object;
    }
    else
    {
      vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
                 (boost::function4<void,unsigned int,float,float,char const *> *)&f[2],
                 this);
      vtable->base.manager((boost::detail::function::function_buffer *)&f[2], &this->functor, clone_functor_tag);
    }
  }
}
