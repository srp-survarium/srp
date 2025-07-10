void __thiscall vostok::logging::logging_filters_console_command::save_to(
        vostok::logging::logging_filters_console_command *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *a)
{
  vostok::memory::base_allocator **v3; // eax
  void *m_filter_tree; // ecx
  vostok::logging::initiator_filter *v5; // ecx
  unsigned int v6; // esi
  const char *v7; // eax
  unsigned int v8; // eax
  void *v9; // esp
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  char *v11; // eax
  vostok::logging::verbosity verbosity; // ecx
  survarium::game_camera *v13; // ecx
  vostok::console_commands::save_storage *v14; // ecx
  _DWORD v15[2]; // [esp+0h] [ebp-120h] BYREF
  const vostok::logging::logging_filters_console_command *thisa; // [esp+8h] [ebp-118h]
  char v17; // [esp+6Fh] [ebp-B1h]
  vostok::strings::detail::tuples v18; // [esp+70h] [ebp-B0h] BYREF
  vostok::logging::initiator_filter *v19; // [esp+A8h] [ebp-78h]
  vostok::logging::initiator_filter *M_start; // [esp+ACh] [ebp-74h]
  vostok::logging::initiator_filter *M_finish; // [esp+B0h] [ebp-70h]
  vostok::logging::initiator_filter *__first; // [esp+B4h] [ebp-6Ch]
  vostok::logging::initiator_filter *__last; // [esp+B8h] [ebp-68h]
  vostok::logging::filter_name_eq v24; // [esp+BCh] [ebp-64h]
  vostok::memory::base_allocator **v25; // [esp+C0h] [ebp-60h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v26; // [esp+C4h] [ebp-5Ch] BYREF
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+C8h] [ebp-58h] BYREF
  char *p0; // [esp+CCh] [ebp-54h]
  vostok::logging::filter_name_eq __pred; // [esp+D0h] [ebp-50h]
  char *p2; // [esp+D4h] [ebp-4Ch]
  char *p4; // [esp+D8h] [ebp-48h]
  const vostok::logging::initiator_filter *i; // [esp+DCh] [ebp-44h]
  const char *filter_str; // [esp+E0h] [ebp-40h]
  unsigned int length_to_test; // [esp+E4h] [ebp-3Ch]
  const char *verbosity_str; // [esp+E8h] [ebp-38h]
  const vostok::logging::initiator_filter *uit; // [esp+ECh] [ebp-34h]
  vostok::logging::initiator_filter *filter; // [esp+F0h] [ebp-30h]
  vostok::logging::initiator_filter *found; // [esp+F4h] [ebp-2Ch]
  vostok::logging::initiator_filter *it; // [esp+F8h] [ebp-28h]
  char *out_str; // [esp+FCh] [ebp-24h]
  unsigned int buffer_size; // [esp+100h] [ebp-20h]
  unsigned int max_length; // [esp+104h] [ebp-1Ch]
  vostok::vectora<vostok::logging::initiator_filter> uniq; // [esp+108h] [ebp-18h] BYREF
  const vostok::logging::initiator_filter *uit_e; // [esp+118h] [ebp-8h]
  const vostok::logging::initiator_filter *uit_b; // [esp+11Ch] [ebp-4h]

  thisa = this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)a,
    &v26);
  v25 = v3;
  __a.m_allocator = *v3;
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&uniq,
    &__a);
  m_filter_tree = thisa->m_filter_tree;
  for ( it = (vostok::logging::initiator_filter *)*((_DWORD *)m_filter_tree + 5); it; it = it->next )
  {
    v24.name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                               (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)m_filter_tree,
                               (int)&it->initiator);
    __pred.name = v24.name;
    __last = uniq._M_impl._M_finish;
    __first = uniq._M_impl._M_start;
    found = stlp_std::find_if<vostok::logging::initiator_filter *,vostok::logging::filter_name_eq>(
              uniq._M_impl._M_start,
              uniq._M_impl._M_finish,
              v24);
    M_finish = uniq._M_impl._M_finish;
    if ( found == uniq._M_impl._M_finish )
    {
      stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::push_back(
        &uniq._M_impl,
        it);
    }
    else
    {
      filter = found;
      found->verbosity = it->verbosity;
    }
    m_filter_tree = it->next;
  }
  max_length = 0;
  M_start = uniq._M_impl._M_start;
  uit_b = uniq._M_impl._M_start;
  v19 = uniq._M_impl._M_finish;
  uit_e = uniq._M_impl._M_finish;
  v5 = uniq._M_impl._M_start;
  for ( uit = uniq._M_impl._M_start; uit != uit_e; ++uit )
  {
    filter_str = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                 (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v5,
                                 (int)&uit->initiator);
    verbosity_str = vostok::logging::verbosity_to_str[uit->verbosity];
    v6 = vostok::strings::length(filter_str);
    length_to_test = vostok::strings::length(verbosity_str) + v6;
    v5 = (vostok::logging::initiator_filter *)length_to_test;
    if ( length_to_test > max_length )
      max_length = length_to_test;
  }
  v7 = vostok::console_commands::console_command::name((vostok::console_commands::console_command *)v5, (int)thisa);
  v8 = vostok::strings::length(v7);
  buffer_size = max_length + v8 + 3;
  v9 = alloca(buffer_size);
  v15[1] = v15;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)max_length);
  out_str = v11;
  for ( i = uit_b; i != uit_e; ++i )
  {
    p2 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                   v10,
                   (int)&i->initiator);
    verbosity = i->verbosity;
    p4 = (char *)vostok::logging::verbosity_to_str[verbosity];
    p0 = (char *)vostok::console_commands::console_command::name(
                   (vostok::console_commands::console_command *)verbosity,
                   (int)thisa);
    vostok::strings::detail::tuples::tuples(&v18, p0, (const char *)&stru_95AF78, p2, (const char *)&stru_95AF78, p4);
    v17 = 0;
    survarium::weapon_user_dead_state::finalize(v13);
    vostok::strings::detail::tuples::concat(out_str, &v18);
    vostok::console_commands::save_storage::add_line(v14, out_str);
    v10 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&i[1];
  }
  stlp_std::priv::_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>::~_Impl_vector<vostok::logging::initiator_filter,vostok::vectora_allocator<vostok::logging::initiator_filter>>(&uniq._M_impl);
}
