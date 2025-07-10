char __thiscall vostok::console_impl::on_text_commit(vostok::console_impl *this, vostok::ui::window *w, int p1, int p2)
{
  vostok::console_impl *v4; // edi
  char v5; // bl
  vostok::ui::text *v6; // eax
  char *v7; // ebp
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const char **M_finish; // ebx
  vostok::vectora<char const *> *p_m_executed_history; // esi
  const char **v12; // eax
  unsigned __int8 *M_start; // edx
  const char *v14; // ecx
  vostok::memory::base_allocator *m_allocator; // ecx
  unsigned int v16; // kr00_4
  unsigned __int8 *v17; // edi
  unsigned __int8 **v18; // eax
  int v19; // eax
  const stlp_std::__true_type *v21; // [esp+0h] [ebp-38h]
  unsigned int v22; // [esp+4h] [ebp-34h]
  bool v23; // [esp+8h] [ebp-30h]
  unsigned int __x; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v4 = this;
  v5 = 0;
  __x = 0;
  v6 = this->m_text_edit->text(this->m_text_edit);
  v7 = (char *)v6->get_text(v6);
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "engine:", info) )
  {
    v8 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v8 )
    {
      log_callback.functor.obj_ptr = v8;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v5 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\console_impl.cpp",
      0x132u,
      "bool __thiscall vostok::console_impl::on_text_commit(struct vostok::ui::window *,int,int)",
      "engine:",
      info,
      "~%s",
      v7);
  }
  if ( (v5 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  vostok::console_commands::execute(v7, execution_filter_all);
  M_finish = (const char **)v4->m_executed_history._M_impl._M_finish;
  p_m_executed_history = &v4->m_executed_history;
  v12 = stlp_std::priv::__find_if<char const * *,vostok::compare_pcstr_pred>(
          (const char **)v4->m_executed_history._M_impl._M_start,
          M_finish,
          (vostok::compare_pcstr_pred)v7);
  if ( v12 == M_finish )
  {
    m_allocator = v4->m_allocator;
    v16 = strlen(v7);
    v17 = (unsigned __int8 *)m_allocator->call_malloc(m_allocator, v16 + 1);
    memcpy(v17, (unsigned __int8 *)v7, v16 + 1);
    v18 = (unsigned __int8 **)p_m_executed_history->_M_impl._M_finish;
    __x = (unsigned int)v17;
    if ( v18 == (unsigned __int8 **)p_m_executed_history->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&__x,
        (unsigned __int8 **)p_m_executed_history,
        (int)v18,
        &__x,
        v21,
        v22,
        v23);
    }
    else
    {
      *v18 = v17;
      ++p_m_executed_history->_M_impl._M_finish;
    }
    v4 = this;
  }
  else
  {
    M_start = (unsigned __int8 *)p_m_executed_history->_M_impl._M_start;
    v14 = *v12;
    *v12 = (const char *)*p_m_executed_history->_M_impl._M_start;
    *(_DWORD *)M_start = v14;
  }
  v19 = (int)v4->m_text_edit->text(v4->m_text_edit);
  (*(void (__thiscall **)(int, const survarium::flash_text *))(*(_DWORD *)v19 + 8))(v19, &buf);
  return 1;
}
