void __thiscall vostok::network_core::http_client::on_error(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  bool has_passed_filters; // al
  vostok::network_core::http_client *thisa; // [esp+4h] [ebp-174h]
  char v4; // [esp+13Ch] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+140h] [ebp-38h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v6; // [esp+160h] [ebp-18h] BYREF

  thisa = this;
  v4 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               vostok::core::g_log_filter_tree,
                               "network_core:",
                               error),
        (this = (vostok::network_core::http_client *)has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v4 = 3;
    err->m_cat->message(err->m_cat, &v6, err->m_val);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\http_client.cpp",
      0x3Au,
      "void __thiscall vostok::network_core::http_client::on_error(const class boost::system::error_code &)",
      "network_core:",
      error,
      "http_client error: %s",
      v6._M_start_of_storage._M_data);
  }
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v6);
  }
  if ( (v4 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)this,
      (int *)&log_callback);
  vostok::network_core::http_client::close_connection(thisa);
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_on_error)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&thisa->m_on_error,
      (const char *)err->m_val,
      (const vostok::network_core::udp_match_packet *)err->m_cat);
}
