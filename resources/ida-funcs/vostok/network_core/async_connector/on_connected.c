void __thiscall vostok::network_core::async_connector::on_connected(
        vostok::network_core::async_connector *this,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *error_code,
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> iterator)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  char v5; // [esp+26Ch] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+270h] [ebp-28h] BYREF
  char v7; // [esp+297h] [ebp-1h]

  v5 = 0;
  v7 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = error_code;
  if ( (error_code->vtable != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
  {
    this->m_connection_state = host_name_is_unresolved;
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error)
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
        (boost::function3<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum> *)&this->m_on_error,
        (const char *)3,
        (survarium::hit_affects_type_enum)error_code->vtable,
        (survarium::affect_event_type_enum)(&error_code->vtable)[1]);
    if ( iterator.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iterator.values_.pn.pi_);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", info) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[5].m_store[452],
        0x21u,
        &stru_984D24.m_working_macro_list.m_buffer[5].m_store[268],
        "network_core:",
        info,
        &stru_984D24.m_working_macro_list.m_buffer[5].m_store[228]);
    }
    if ( (v5 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v3,
        (int *)&log_callback);
    this->m_connection_state = connection_has_been_established;
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_connected)
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function0<void>::operator()(&this->m_on_connected);
    if ( iterator.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iterator.values_.pn.pi_);
  }
}
