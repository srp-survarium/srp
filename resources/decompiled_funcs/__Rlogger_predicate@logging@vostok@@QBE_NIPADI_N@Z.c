char __thiscall vostok::logging::logger_predicate::operator()(
        vostok::logging::logger_predicate *this,
        const unsigned int index,
        char *string,
        const unsigned int length,
        const bool is_last)
{
  void *v5; // esp
  char *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const std::exception *v8; // eax
  boost::detail::function::basic_vtable4<void,unsigned int,float,float,char const *> *vtable; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp-28h] [ebp-19Ch]
  void *v12; // [esp-24h] [ebp-198h]
  boost::function4<void,unsigned int,float,float,char const *> *v13; // [esp-20h] [ebp-194h]
  unsigned int v14; // [esp-1Ch] [ebp-190h]
  const char *v15; // [esp-18h] [ebp-18Ch]
  const char *v16; // [esp-14h] [ebp-188h]
  vostok::logging::verbosity v17; // [esp-10h] [ebp-184h]
  const vostok::variant<32> **v18; // [esp-Ch] [ebp-180h]
  int v19; // [esp-8h] [ebp-17Ch]
  int v20; // [esp-4h] [ebp-178h]
  int v21; // [esp+0h] [ebp-174h] BYREF
  vostok::logging::logger_predicate *v22; // [esp+4h] [ebp-170h]
  int v23; // [esp+8h] [ebp-16Ch]
  int v24; // [esp+Ch] [ebp-168h]
  const vostok::variant<32> **v25; // [esp+10h] [ebp-164h]
  vostok::logging::verbosity m_verbosity; // [esp+14h] [ebp-160h]
  const char *m_initiator; // [esp+18h] [ebp-15Ch]
  const char *m_function_signature; // [esp+1Ch] [ebp-158h]
  unsigned int m_line; // [esp+20h] [ebp-154h]
  boost::function4<void,unsigned int,float,float,char const *> *m_file; // [esp+24h] [ebp-150h]
  void *m_user_data; // [esp+28h] [ebp-14Ch]
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v32; // [esp+2Ch] [ebp-148h]
  boost::bad_function_call v33; // [esp+4Ch] [ebp-128h] BYREF
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_log_callback; // [esp+15Ch] [ebp-18h]
  unsigned int max_count; // [esp+164h] [ebp-10h] BYREF
  vostok::buffer_string dest; // [esp+168h] [ebp-Ch] BYREF

  v22 = this;
  max_count = length + 129;
  v5 = alloca(length + 129);
  v21 = (int)&v21;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&max_count);
  vostok::buffer_string::buffer_string(&dest, v6, &max_count);
  fill_log_string(&dest, string, &string[length], v22->m_path, v22->m_helper->m_verbosity, &v22->m_helper->m_log_format);
  m_log_callback = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_helper->m_log_callback;
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(m_log_callback)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    if ( index )
      v23 = is_last ? 2 : 0;
    else
      v23 = 1;
    v24 = vostok::fs_new::path_string_impl::length((vostok::fs_new::path_string_impl *)&dest);
    v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&dest);
    m_verbosity = v22->m_helper->m_verbosity;
    m_initiator = v22->m_helper->m_initiator;
    m_function_signature = v22->m_helper->m_function_signature;
    m_line = v22->m_helper->m_line;
    m_file = (boost::function4<void,unsigned int,float,float,char const *> *)v22->m_helper->m_file;
    m_user_data = v22->m_helper->m_user_data;
    v32 = (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22->m_helper->m_log_callback;
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(v32) )
    {
      boost::bad_function_call::bad_function_call(&v33);
      boost::throw_exception(v8);
      boost::bad_function_call::~bad_function_call(&v33);
    }
    v20 = v23;
    v19 = v24;
    v18 = v25;
    v17 = m_verbosity;
    v16 = m_initiator;
    v15 = m_function_signature;
    v14 = m_line;
    v13 = m_file;
    v12 = m_user_data;
    v11 = v32 + 2;
    vtable = boost::function5<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum,vostok::sign_up_info const &>::get_vtable(m_file);
    ((void (__cdecl *)(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, void *, boost::function4<void,unsigned int,float,float,char const *> *, unsigned int, const char *, const char *, vostok::logging::verbosity, const vostok::variant<32> **, int, int))vtable->invoker)(
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20);
  }
  return 1;
}
