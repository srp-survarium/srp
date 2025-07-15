void __thiscall survarium::ai_sound_player::on_active_sound_serialized(
        survarium::ai_sound_player *this,
        vostok::memory::writer *sound_thread_writer,
        vostok::memory::writer *current_thread_writer)
{
  void (__cdecl *v3)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::sound::sound_world *v5; // edi
  _BYTE *v6; // esi
  void *v7; // eax
  void *m_start_time_high; // esi
  const char *v9; // [esp+0h] [ebp-30h]
  bool v10; // [esp+4h] [ebp-2Ch]
  char v11; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v11 = 0;
  current_thread_writer->write(current_thread_writer, sound_thread_writer->m_data, sound_thread_writer->m_file_size);
  if ( !vostok::memory::writer::save_to((vostok::memory::writer *)&stru_97341C, v9, v10) )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
    {
      v3 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v3 )
      {
        log_callback.functor.obj_ptr = v3;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v11 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\ai_sound_player.cpp",
        0x197u,
        "void __thiscall survarium::ai_sound_player::on_active_sound_serialized(class vostok::memory::writer *,class vost"
        "ok::memory::writer *)",
        "game:",
        error,
        (const char *)&stru_97341C.external_data);
    }
    if ( (v11 & 1) != 0 && log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v4 )
          v4(&log_callback.functor, &log_callback.functor, 2);
      }
      log_callback.vtable = 0;
    }
  }
  v5 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v6 = __RTCastToVoid((void **)&current_thread_writer->__vftable);
  ((void (__thiscall *)(vostok::memory::writer *, _DWORD))current_thread_writer->~vostok::memory::writer)(
    current_thread_writer,
    0);
  if ( v6 )
  {
    v7 = v6;
    m_start_time_high = (void *)HIDWORD(v5->m_timer.m_start_time);
    BYTE2(v5->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v7);
  }
}
