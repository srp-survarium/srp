vostok::sound::sound_voice *__userpurge vostok::sound::sound_world::create_sound_voice@<eax>(
        vostok::sound::sound_world *this@<ecx>,
        int a2@<eax>,
        vostok::sound::sound_scene *scene,
        vostok::sound::new_sound_propagator *propagator,
        const vostok::sound::sound_propagator_emitter *emitter)
{
  bool has_passed_filters; // al
  int v7; // edi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v8; // ecx
  vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>::node *v9; // eax
  vostok::threading::mutex *v10; // ecx
  vostok::sound::sound_voice *v11; // eax
  vostok::sound::sound_voice *v12; // edi
  vostok::sound::sound_world *v13; // [esp-4h] [ebp-38h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-2Ch] BYREF
  int v15; // [esp+2Ch] [ebp-8h]

  v15 = 0;
  if ( !*(_BYTE *)(a2 + 18649) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                                 (const char *)2),
          this = v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &log_callback);
      v15 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_world.cpp",
        0x211u,
        "class vostok::sound::sound_voice *__thiscall vostok::sound::sound_world::create_sound_voice(class vostok::sound:"
        ":sound_scene &,class vostok::sound::new_sound_propagator *,const class vostok::sound::sound_propagator_emitter &)",
        (char *)&initiator_raw.filter_stack.m_last,
        error,
        "can't allocate sound_voice, audio device do not exist:(");
    }
    if ( (v15 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&log_callback);
    return 0;
  }
  v7 = *(_DWORD *)(a2 + 160);
  if ( 40 * *(_DWORD *)(v7 + 40) == 40 * *(_DWORD *)(v7 + 36) )
    return 0;
  type_info::raw_name(&vostok::sound::sound_voice `RTTI Type Descriptor');
  if ( *(_DWORD *)(v7 + 36) >= *(_DWORD *)(v7 + 40)
    && (*(_DWORD *)v7 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      v8,
      (_DWORD *)v7,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v7);
  }
  v9 = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>::node>::allocate((vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>::node>::free_list_type *)(v7 + 32));
  ++*(_DWORD *)(v7 + 36);
  if ( v9 )
  {
    vostok::sound::sound_voice::sound_voice((vostok::sound::sound_voice *)v9, propagator, emitter);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  vostok::sound::sound_scene::add_active_voice(scene, v12, v10);
  return v12;
}
