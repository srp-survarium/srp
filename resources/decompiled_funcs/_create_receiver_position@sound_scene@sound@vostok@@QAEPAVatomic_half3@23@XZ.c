vostok::sound::atomic_half3 *__thiscall vostok::sound::sound_scene::create_receiver_position(
        vostok::sound::sound_scene *this)
{
  int v2; // eax
  char v4; // [esp+68h] [ebp-30h]
  vostok::sound::atomic_half3 *v5; // [esp+6Ch] [ebp-2Ch]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v6; // [esp+70h] [ebp-28h] BYREF

  v4 = 0;
  if ( 8 * this->m_receiver_positions_allocator.m_variable->m_max_count == 8
                                                                         * this->m_receiver_positions_allocator.m_variable->m_allocated_count )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      v6.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v6,
        vostok::core::g_log_callback);
      v4 = 1;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v6,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene.cpp",
        0x41Fu,
        "class vostok::sound::atomic_half3 *__thiscall vostok::sound::sound_scene::create_receiver_position(void)",
        "sound:",
        error,
        "can't allocate receiver_position, memory is full");
    }
    if ( (v4 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v6);
    return 0;
  }
  else
  {
    v5 = (vostok::sound::atomic_half3 *)vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::malloc_impl(
                                          this->m_receiver_positions_allocator.m_variable,
                                          8u);
    if ( !v5 )
      return 0;
    vostok::sound::atomic_half3::atomic_half3(v5);
    return (vostok::sound::atomic_half3 *)v2;
  }
}
