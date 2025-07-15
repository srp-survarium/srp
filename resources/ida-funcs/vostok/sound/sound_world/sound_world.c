void __userpurge vostok::sound::sound_world::sound_world(
        vostok::sound::sound_world *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *a3@<edi>,
        const char *a4@<esi>,
        vostok::sound::sound_world *engine,
        vostok::sound::engine *logic_allocator,
        vostok::memory::base_allocator *editor_allocator)
{
  vostok::sound::panning_lut *v7; // ecx
  __int32 v8; // xmm0_4
  const char *v9; // esi
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // ecx
  void *v12; // eax
  vostok::sound::world_user *v13; // ecx
  vostok::sound::world_user *v14; // eax
  char *v15; // eax
  vostok::memory::pthreads3_allocator *v16; // ecx
  vostok::sound::sound_order *v17; // eax
  vostok::sound::sound_world *v18; // ecx
  char v19; // al
  int v20; // ecx
  unsigned int v21; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v22; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v23; // ecx
  vostok::resources::unmanaged_allocation_resource *m_object; // ecx
  vostok::memory::doug_lea_allocator *v25; // esi
  char *v26; // eax
  vostok::memory::doug_lea_allocator *v27; // ecx
  void *v28; // eax
  vostok::sound::voice_factory *v29; // eax
  vostok::memory::doug_lea_allocator *v30; // esi
  char *v31; // eax
  vostok::memory::doug_lea_allocator *v32; // ecx
  void *v33; // eax
  vostok::sound::sound_buffer_factory *v34; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1> > > v35; // [esp-20h] [ebp-A0h]
  vostok::sound::sound_buffer_factory *v36; // [esp-18h] [ebp-98h]
  const char *v37; // [esp-Ch] [ebp-8Ch]
  const char *v38; // [esp-Ch] [ebp-8Ch]
  const char *v39; // [esp-8h] [ebp-88h]
  const char *v40; // [esp-8h] [ebp-88h]
  const char *v41; // [esp-8h] [ebp-88h]
  unsigned int v43; // [esp-4h] [ebp-84h]
  unsigned int v44; // [esp-4h] [ebp-84h]
  unsigned int v45; // [esp-4h] [ebp-84h]
  unsigned int arena_size; // [esp+0h] [ebp-80h]
  char v47; // [esp+4h] [ebp-7Ch]
  unsigned int buffer_size; // [esp+8h] [ebp-78h]
  unsigned int max_buffers; // [esp+Ch] [ebp-74h]
  unsigned int size; // [esp+10h] [ebp-70h]
  vostok::sound::pool_parametrs params; // [esp+14h] [ebp-6Ch] BYREF
  vostok::resources::creation_request requests; // [esp+1Ch] [ebp-64h] BYREF
  void (__thiscall *v53)(vostok::sound::sound_world *, vostok::resources::queries_result *); // [esp+2Ch] [ebp-54h]
  int v54; // [esp+30h] [ebp-50h]
  vostok::sound::sound_world *v55; // [esp+34h] [ebp-4Ch]
  int v56; // [esp+38h] [ebp-48h]
  int f[8]; // [esp+3Ch] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy> const &)> on_out_of_memory; // [esp+5Ch] [ebp-24h] BYREF
  int savedregs; // [esp+80h] [ebp+0h] BYREF

  engine->m_speed_of_sound = FLOAT_343_20001;
  engine->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::sound_world::`vftable';
  vostok::timing::timer::timer((vostok::timing::timer *)this, (LARGE_INTEGER *)&engine->m_timer);
  engine->m_xaudio_callback_orders.m_head = 0;
  engine->m_xaudio_callback_orders.m_push_thread_id = -1;
  engine->m_xaudio_callback_orders.m_pop_thread_id = -1;
  engine->m_xaudio_callback_orders.m_tail = 0;
  engine->m_unmanaged_resources_ptr.m_object = 0;
  engine->m_sound_voices_count = 64;
  engine->m_sound_voices_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy> *)&engine->m_sound_voices_allocator;
  engine->m_sound_voices_allocator.m_initialized = 0;
  engine->m_sound_voices_allocator.m_construction_started = 0;
  engine->m_logic_world_user = 0;
  engine->m_editor_world_user = 0;
  engine->m_engine = logic_allocator;
  engine->m_master_voice = 0;
  vostok::sound::panning_lut::panning_lut(v7, (unsigned int)engine, 0, &engine->m_panning_lut.__vftable);
  v8 = LODWORD(s_bm_current_air_resistance);
  engine->m_last_current_time_in_ms = 0;
  engine->m_is_destroying = 0;
  engine->m_is_audio_device_exist = 0;
  engine->m_active_scenes.m_size = 0;
  engine->m_active_scenes.m_first = 0;
  engine->m_active_scenes.m_last = 0;
  engine->m_current_scene = 0;
  engine->m_base_volume = 100;
  _InterlockedExchange(&engine->m_time_factor.m_data.m_atomic, v8);
  v9 = (const char *)vostok::sound::g_allocator;
  v10 = type_info::raw_name(&vostok::sound::world_user `RTTI Type Descriptor');
  v12 = vostok::memory::doug_lea_allocator::malloc_impl(v11, (int)v9, 0x124u, v10, a3, a4, a2);
  if ( v12 )
    vostok::sound::world_user::world_user(v13, (const char *)&savedregs, (int)v12, v9, engine, editor_allocator);
  else
    v14 = 0;
  engine->m_logic_world_user = v14;
  vostok::sound::sound_world::register_sound_cooks((vostok::sound::sound_world *)v13, engine);
  _InterlockedExchange(&engine->m_xaudio_callback_orders.m_pop_thread_id, GetCurrentThreadId());
  v15 = type_info::raw_name(&vostok::sound::sound_order `RTTI Type Descriptor');
  v17 = (vostok::sound::sound_order *)vostok::memory::pthreads3_allocator::malloc_impl(
                                        v16,
                                        (unsigned int)&vostok::memory::g_mt_allocator,
                                        (const char *const)0x10,
                                        v15,
                                        v39,
                                        v43);
  if ( v17 )
  {
    v17->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::sound_order::`vftable';
    v17->allocator = &vostok::memory::g_mt_allocator;
    v17->m_next_for_orders = 0;
    v17->m_next_for_postponed_orders = 0;
  }
  else
  {
    v17 = 0;
  }
  v17->m_next_for_orders = 0;
  engine->m_xaudio_callback_orders.m_tail = v17;
  engine->m_xaudio_callback_orders.m_head = v17;
  CoInitializeEx(0, 2u);
  v19 = vostok::sound::sound_world::initialize_xaudio(v18, (int)engine);
  engine->m_is_audio_device_exist = v19;
  if ( v19 )
  {
    v20 = 64;
    params.mono_voices_count = 64;
    params.stereo_voices_count = 64;
  }
  else
  {
    params.mono_voices_count = 0;
    params.stereo_voices_count = 0;
  }
  if ( v19 )
  {
    v21 = 40 * engine->m_sound_voices_count;
    max_buffers = 3 * (params.mono_voices_count + params.stereo_voices_count);
    size = 264864 * (params.mono_voices_count + params.stereo_voices_count);
    requests.m_data.m_data = 0;
    requests.m_data.m_size = v21 + 264928 * (params.mono_voices_count + params.stereo_voices_count);
    arena_size = v21;
    v53 = vostok::sound::sound_world::on_unmanaged_resources_allocated;
    v54 = 0;
    v55 = engine;
    HIDWORD(v35.f_.f_) = vostok::sound::sound_world::on_unmanaged_resources_allocated;
    *(_QWORD *)&v35.l_.a1_.t_ = __PAIR64__((unsigned int)engine, 0);
    LODWORD(v35.f_.f_) = f;
    buffer_size = (params.mono_voices_count + params.stereo_voices_count) << 6;
    requests.m_name = "unmanaged_sound_resources_allocation";
    requests.m_id = unmanaged_allocation_class;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      v35,
      v56);
    vostok::resources::query_create_resources_and_wait(&requests, 1u, vostok::sound::g_allocator, 0, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v22, f);
    if ( engine != (vostok::sound::sound_world *)-112 )
    {
      m_object = engine->m_unmanaged_resources_ptr.m_object;
      on_out_of_memory.vtable = 0;
      v47 = 1;
      vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>(
        &on_out_of_memory,
        (vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy> *)&engine->m_sound_voices_allocator,
        (vostok::memory::single_size_buffer_allocator<40,vostok::threading::single_threading_policy>::node *)m_object->buffer,
        arena_size);
    }
    _InterlockedExchange(&engine->m_sound_voices_allocator.m_initialized, 1);
    if ( (v47 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v23,
        (int *)&on_out_of_memory);
    v25 = vostok::sound::g_allocator;
    v26 = type_info::raw_name(&vostok::sound::voice_factory `RTTI Type Descriptor');
    v28 = vostok::memory::doug_lea_allocator::malloc_impl(v27, (int)v25, 0x440u, v26, v37, v40, v44);
    if ( v28 )
      vostok::sound::voice_factory::voice_factory(
        (vostok::sound::voice_factory *)&engine->m_unmanaged_resources_ptr.m_object->buffer[arena_size],
        (int)v28,
        &engine->m_unmanaged_resources_ptr.m_object->buffer[arena_size],
        buffer_size,
        engine,
        &params);
    else
      v29 = 0;
    v30 = vostok::sound::g_allocator;
    engine->m_voice_factory = v29;
    v31 = type_info::raw_name(&vostok::sound::sound_buffer_factory `RTTI Type Descriptor');
    v33 = vostok::memory::doug_lea_allocator::malloc_impl(v32, (int)v30, 0x58u, v31, v38, v41, v45);
    if ( v33 )
    {
      v36 = (vostok::sound::sound_buffer_factory *)&engine->m_unmanaged_resources_ptr.m_object->buffer[buffer_size + arena_size];
      vostok::sound::sound_buffer_factory::sound_buffer_factory(
        v36,
        (int)v33,
        (unsigned __int8 *)v36,
        size,
        max_buffers);
    }
    else
    {
      v34 = 0;
    }
    engine->m_sound_buffer_factory = v34;
  }
  vostok::timing::timer::start((vostok::timing::timer *)v20, (LARGE_INTEGER *)&engine->m_timer);
}
