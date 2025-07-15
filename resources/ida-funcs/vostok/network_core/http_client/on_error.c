void __userpurge vostok::network_core::http_client::on_error(
        const boost::system::error_code *err@<edi>,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *a2@<ecx>,
        vostok::network_core::http_client *this)
{
  bool has_passed_filters; // al
  const boost::system::error_category *m_cat; // ecx
  boost::system::error_category_vtbl *v5; // eax
  int v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-50h]
  int m_val; // [esp-4h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+8h] [ebp-44h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v10; // [esp+2Ch] [ebp-20h] BYREF
  int v11; // [esp+44h] [ebp-8h]

  v11 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"network_core",
                               (const char *)2),
        a2 = v7,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      a2,
      &v9);
    m_val = err->m_val;
    m_cat = err->m_cat;
    v5 = m_cat->__vftable;
    v11 = 3;
    v5->message(
      m_cat,
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v10,
      m_val);
    vostok::logging::append(
      &v9,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\http_client.cpp",
      0x48u,
      "void __thiscall vostok::network_core::http_client::on_error(const class boost::system::error_code &)",
      "network_core",
      error,
      "http_client error: %s",
      v10._M_start_of_storage._M_data);
  }
  if ( (v11 & 2) != 0 )
  {
    v11 &= ~2u;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v10);
  }
  if ( (v11 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)a2,
      (int *)&v9);
  vostok::network_core::http_client::close_connection((vostok::network_core::http_client *)a2, (int)this);
  v6 = -(this->m_on_error.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v6) != 0 )
    boost::function1<void,boost::system::error_code>::operator()(
      (boost::function2<void,vostok::math::float4x4 *,unsigned int> *)v6,
      &this->m_on_error.vtable,
      (vostok::math::float4x4 *)err->m_val,
      (unsigned int)err->m_cat);
}
