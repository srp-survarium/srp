void __thiscall boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>(
        boost::function0<bool> *this,
        boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> f)
{
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)f,
         &this->functor) )
  {
    this->vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable.base.manager
                                                          + 1);
  }
  else
  {
    this->vtable = 0;
  }
}
