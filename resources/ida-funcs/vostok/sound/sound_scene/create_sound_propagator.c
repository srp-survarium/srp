void __userpurge vostok::sound::sound_scene::create_sound_propagator(
        vostok::sound::sound_scene *this@<ecx>,
        int a2@<eax>,
        const vostok::sound::sound_propagator_emitter *owner,
        vostok::sound::sound_instance_proxy_internal *proxy,
        unsigned int playback_id)
{
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v5; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v8; // ecx
  vostok::sound::new_sound_propagator *v9; // eax
  int v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-34h]
  char v12; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF

  v12 = 0;
  v5 = *(vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> **)(a2 + 456);
  v6 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(76 * v5->m_allocated_count);
  if ( (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)(76 * v5->m_max_count) == v6 )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                                 (const char *)2),
          v6 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &log_callback);
      v12 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene_propagators.cpp",
        0x61u,
        "class vostok::sound::new_sound_propagator *__thiscall vostok::sound::sound_scene::create_sound_propagator(const "
        "class vostok::sound::sound_propagator_emitter &,class vostok::sound::sound_instance_proxy_internal &,unsigned int)",
        (char *)&initiator_raw.filter_stack.m_last,
        error,
        "can't allocate sound_propagator, memory pool is empty :(");
    }
    if ( (v12 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&log_callback);
  }
  else
  {
    type_info::raw_name(&vostok::sound::new_sound_propagator `RTTI Type Descriptor');
    if ( v5->m_allocated_count >= v5->m_max_count
      && (v5->m_on_out_of_memory.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      boost::function1<void,vostok::collision::object const &>::operator()(v8, v5, v5);
    }
    v9 = (vostok::sound::new_sound_propagator *)vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node>::allocate(&v5->m_free_list_head);
    ++v5->m_allocated_count;
    if ( v9 )
      vostok::sound::new_sound_propagator::new_sound_propagator(v9, proxy, owner, playback_id);
    else
      v10 = 0;
    *(_BYTE *)(v10 + 48) = 1;
  }
}
