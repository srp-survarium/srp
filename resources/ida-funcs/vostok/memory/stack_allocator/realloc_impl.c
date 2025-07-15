unsigned __int8 *__userpurge vostok::memory::stack_allocator::realloc_impl@<eax>(
        vostok::memory::stack_allocator *this@<eax>,
        unsigned int new_size@<edx>,
        unsigned __int8 *pointer,
        const char *const description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  unsigned __int8 *m_arena_current_position; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-34h]
  char v12; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  m_arena_current_position = (unsigned __int8 *)this->m_arena_current_position;
  v8 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&m_arena_current_position[new_size];
  v12 = 0;
  this->m_arena_current_position = &m_arena_current_position[new_size];
  if ( pointer )
    memcpy(m_arena_current_position, pointer, new_size);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_802D94,
                               (const char *)3),
        v8 = v11,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v8,
      &log_callback);
    v12 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\memory_stack_allocator.cpp",
      0x59u,
      "void *__thiscall vostok::memory::stack_allocator::realloc_impl(void *,unsigned int,const char *const ,const char *"
      "const ,const char *const ,const unsigned int)",
      (char *)&stru_802D94,
      warning,
      "realloc has been called on stack allocator, is it intended behavior?");
  }
  if ( (v12 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v8,
      (int *)&log_callback);
  return m_arena_current_position;
}
