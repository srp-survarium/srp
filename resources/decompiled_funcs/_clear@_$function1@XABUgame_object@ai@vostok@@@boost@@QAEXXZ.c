void __thiscall boost::function1<void,vostok::ai::game_object const &>::clear(
        boost::function1<void,vostok::ai::game_object const &> *this)
{
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // [esp+8h] [ebp-4h]

  if ( this->vtable )
  {
    if ( !(unsigned __int8)boost::function_base::has_trivial_copy_and_destroy(this, this) )
    {
      vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(
                 0,
                 this);
      if ( vtable->base.manager )
        vtable->base.manager(&this->functor, &this->functor, destroy_functor_tag);
    }
    this->vtable = 0;
  }
}
