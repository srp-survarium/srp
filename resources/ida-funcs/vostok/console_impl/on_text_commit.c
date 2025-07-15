char __thiscall vostok::console_impl::on_text_commit(vostok::console_impl *this, vostok::ui::window *w, int p1, int p2)
{
  vostok::ui::text *v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  const void **M_start; // esi
  const void **v9; // eax
  const void *v10; // ecx
  vostok::ui::text *v11; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v13; // [esp-4h] [ebp-3Ch]
  const char *const *v14; // [esp+0h] [ebp-38h]
  char *command_to_execute; // [esp+10h] [ebp-28h]
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > v16; // [esp+14h] [ebp-24h] BYREF

  v16._M_impl._M_start = 0;
  v5 = this->m_text_edit->text(this->m_text_edit);
  command_to_execute = (char *)v5->get_text(v5);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&initiator_raw,
                               (const char *)4),
        v6 = v13,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v6,
      &v16._M_impl._M_finish);
    v16._M_impl._M_start = (const void **)1;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v16._M_impl._M_finish,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\console_impl.cpp",
      0x132u,
      "bool __thiscall vostok::console_impl::on_text_commit(struct vostok::ui::window *,int,int)",
      (char *)&initiator_raw,
      info,
      "~%s",
      command_to_execute);
  }
  if ( ((int)v16._M_impl._M_start & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
      (int *)&v16._M_impl._M_finish);
  vostok::console_commands::execute(command_to_execute, execution_filter_all, 2u);
  M_start = this->m_executed_history._M_impl._M_start;
  v9 = (const void **)stlp_std::priv::__find_if<char const * *,vostok::compare_pcstr_pred>(
                        (const char **)M_start,
                        (const char **)this->m_executed_history._M_impl._M_finish,
                        command_to_execute);
  if ( v9 == this->m_executed_history._M_impl._M_finish )
  {
    v16._M_impl._M_start = (const void **)vostok::strings::duplicate<vostok::memory::base_allocator>(command_to_execute);
    stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(&v16, v14);
  }
  else
  {
    v10 = *v9;
    *v9 = *M_start;
    *M_start = v10;
  }
  v11 = this->m_text_edit->text(this->m_text_edit);
  v11->set_text(v11, uri);
  return 1;
}
