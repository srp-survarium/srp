void __thiscall vostok::console_commands::logging_filters_console_command::save_to(
        vostok::console_commands::logging_filters_console_command *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *allocator)
{
  vostok::console_commands::logging_filters_console_command *v3; // ebx
  vostok::logging::verbosity **v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  int v7; // edx
  const char *m_name; // eax
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *v9; // ecx
  void *v10; // esp
  vostok::logging::verbosity **v11; // ebx
  const char *v12; // eax
  int v13; // ecx
  vostok::strings::detail::tuples *v14; // ecx
  vostok::console_commands::save_storage *v15; // ecx
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > v16; // [esp-4h] [ebp-60h] BYREF
  vostok::strings::detail::tuples v17; // [esp+Ch] [ebp-50h] BYREF
  vostok::logging::verbosity **v18; // [esp+40h] [ebp-1Ch] BYREF
  vostok::logging::verbosity **v19; // [esp+44h] [ebp-18h]
  vostok::memory::base_allocator *v20; // [esp+48h] [ebp-14h]
  int v21; // [esp+4Ch] [ebp-10h]
  __int64 v22; // [esp+50h] [ebp-Ch] BYREF
  vostok::console_commands::logging_filters_console_command *v23; // [esp+58h] [ebp-4h]

  v20 = allocator;
  v3 = this;
  HIDWORD(v22) = &v18;
  v16._M_impl._M_start = (const void **)&v22;
  v23 = this;
  v18 = 0;
  v19 = 0;
  v21 = 0;
  LODWORD(v22) = vostok::console_commands::unique_filters_collector::operator();
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::console_commands::unique_filters_collector::operator()) )
  {
    v17.m_strings[2].second = 0;
  }
  else
  {
    *(_QWORD *)&v17.m_strings[3].second = v22;
    v17.m_strings[2].second = (unsigned int)&`boost::function1<void,vostok::logging::filter const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::console_commands::unique_filters_collector,vostok::logging::filter const &>,boost::_bi::list2<boost::_bi::value<vostok::console_commands::unique_filters_collector *>,boost::arg<1>>>>'::`2'::stored_vtable
                            + 1;
  }
  vostok::logging::enumerate_filters(
    v3->m_filter_tree,
    (boost::bad_function_call *)&v22,
    (const boost::function<void __cdecl(vostok::logging::filter const &)> *)&v17.m_strings[2].second);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v16._M_impl._M_start,
    (int *)&v17.m_strings[2].second);
  v4 = v18;
  v5 = 0;
  HIDWORD(v22) = v19;
  if ( v18 != v19 )
  {
    do
    {
      strlen((const char *)*v4 + 8);
      v6 = strlen(vostok::logging::verbosity_name(**v4++));
      v5 -= v5 < v7 + v6 ? v5 - (v7 + v6) : 0;
    }
    while ( v4 != v19 );
    v3 = v23;
  }
  m_name = v3->m_name;
  v9 = (stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *> > *)(m_name + 1);
  v10 = alloca(strlen(m_name) + v5 + 3);
  v11 = v18;
  if ( v18 != v19 )
  {
    do
    {
      v12 = vostok::logging::verbosity_name(**v11);
      vostok::strings::detail::tuples::tuples(
        (vostok::strings::detail::tuples *)(v13 + 8),
        &v17,
        v23->m_name,
        " ",
        (const char *)(v13 + 8),
        " ",
        v12);
      vostok::strings::detail::tuples::concat(v14, (int)&v17, (char *)&v16._M_impl._M_finish);
      v16._M_impl._M_start = (const void **)&v16._M_impl._M_finish;
      vostok::console_commands::save_storage::add_line(v15, v16);
      ++v11;
    }
    while ( v11 != (vostok::logging::verbosity **)HIDWORD(v22) );
  }
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    v9,
    (int)&v18);
}
