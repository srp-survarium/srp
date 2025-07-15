void __thiscall vostok::sound::sound_world::sound_world(
        vostok::sound::sound_world *this,
        vostok::sound::engine *engine,
        vostok::memory::base_allocator *logic_allocator,
        vostok::memory::base_allocator *editor_allocator)
{
  vostok::sound::world_user *v4; // eax
  vostok::sound::sound_order *v5; // eax
  bool v6; // al
  vostok::sound::voice_factory *v7; // eax
  vostok::sound::sound_buffer_factory *v8; // eax
  unsigned __int64 performance_counter; // [esp+FE2h] [ebp-208h]
  vostok::timing::timer *p_m_timer; // [esp+FEAh] [ebp-200h]
  vostok::sound::sound_buffer_factory *v11; // [esp+FEEh] [ebp-1FCh]
  vostok::sound::sound_buffer_factory *v12; // [esp+FFAh] [ebp-1F0h]
  unsigned int v13; // [esp+1006h] [ebp-1E4h]
  vostok::sound::voice_factory *v14; // [esp+100Ah] [ebp-1E0h]
  vostok::sound::voice_factory *v15; // [esp+1016h] [ebp-1D4h]
  unsigned int v16; // [esp+1022h] [ebp-1C8h]
  boost::function1<void,vostok::resources::queries_result &> v17; // [esp+104Ah] [ebp-1A0h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v18; // [esp+106Ah] [ebp-180h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v19; // [esp+107Ah] [ebp-170h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1> > > v20; // [esp+108Eh] [ebp-15Ch] BYREF
  unsigned int buffer_size; // [esp+10A6h] [ebp-144h]
  unsigned int size; // [esp+10AAh] [ebp-140h]
  unsigned int max_buffers; // [esp+10AEh] [ebp-13Ch]
  unsigned int v24; // [esp+10B2h] [ebp-138h]
  unsigned int arena_size; // [esp+10B6h] [ebp-134h]
  boost::function1<void,vostok::resources::queries_result &> v26; // [esp+10BAh] [ebp-130h] BYREF
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v27; // [esp+10DAh] [ebp-110h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+10EAh] [ebp-100h] BYREF
  void (__thiscall *f)(vostok::sound::sound_world *, vostok::resources::queries_result *); // [esp+10FAh] [ebp-F0h]
  int f_4; // [esp+10FEh] [ebp-ECh]
  vostok::variant<32> v31; // [esp+1102h] [ebp-E8h] BYREF
  unsigned __int8 value; // [esp+1139h] [ebp-B1h] BYREF
  vostok::resources::creation_request v33; // [esp+113Ah] [ebp-B0h] BYREF
  __int64 v34; // [esp+114Ah] [ebp-A0h]
  int v35; // [esp+1156h] [ebp-94h]
  unsigned __int16 v36; // [esp+115Ch] [ebp-8Eh]
  float v37; // [esp+115Eh] [ebp-8Ch] BYREF
  vostok::sound::pool_parametrs v38; // [esp+1162h] [ebp-88h] BYREF
  __int64 v39; // [esp+116Ah] [ebp-80h]
  int v40; // [esp+1176h] [ebp-74h]
  unsigned __int16 v41; // [esp+117Ch] [ebp-6Eh]
  float v42; // [esp+117Eh] [ebp-6Ch] BYREF
  char v43; // [esp+1184h] [ebp-66h]
  char v44; // [esp+1185h] [ebp-65h]
  vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *v45; // [esp+1186h] [ebp-64h]
  vostok::sound::sound_order *v46; // [esp+118Ah] [ebp-60h]
  vostok::sound::sound_order *v47; // [esp+118Eh] [ebp-5Ch]
  vostok::sound::sound_order *v48; // [esp+1192h] [ebp-58h]
  DWORD v49; // [esp+1196h] [ebp-54h]
  __int64 v50; // [esp+119Ah] [ebp-50h]
  int v51; // [esp+11A2h] [ebp-48h]
  unsigned __int16 v52; // [esp+11A6h] [ebp-44h]
  char v53; // [esp+11A9h] [ebp-41h]
  float out_value; // [esp+11AAh] [ebp-40h] BYREF
  int v55; // [esp+11AEh] [ebp-3Ch]
  char v56; // [esp+11B5h] [ebp-35h]
  vostok::sound::world_user *v57; // [esp+11B6h] [ebp-34h]
  vostok::sound::world_user *v58; // [esp+11BAh] [ebp-30h]
  vostok::sound::world_user *v59; // [esp+11BEh] [ebp-2Ch]
  vostok::memory::doug_lea_allocator *m_object; // [esp+11C2h] [ebp-28h]
  float v61; // [esp+11C6h] [ebp-24h]
  float v62; // [esp+11CAh] [ebp-20h]
  vostok::intrusive_list<vostok::sound::sound_scene,vostok::sound::sound_scene *,264,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_active_scenes; // [esp+11CEh] [ebp-1Ch]
  vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_voices_to_delete; // [esp+11D2h] [ebp-18h]
  vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_panning_lut; // [esp+11D6h] [ebp-14h]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> > *p_m_sound_voices_allocator; // [esp+11DAh] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resources_ptr; // [esp+11DEh] [ebp-Ch]
  vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *p_m_xaudio_callback_orders; // [esp+11E2h] [ebp-8h]
  vostok::sound::sound_world *owner; // [esp+11E6h] [ebp-4h]

  owner = this;
  this->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::world::`vftable';
  owner->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::sound_world::`vftable';
  vostok::timing::timer::timer(&owner->m_timer);
  p_m_xaudio_callback_orders = &owner->m_xaudio_callback_orders;
  owner->m_xaudio_callback_orders.m_head = 0;
  p_m_xaudio_callback_orders->m_push_thread_id = -1;
  p_m_xaudio_callback_orders->m_pop_thread_id = -1;
  p_m_xaudio_callback_orders->m_tail = 0;
  p_m_unmanaged_resources_ptr = &owner->m_unmanaged_resources_ptr;
  owner->m_unmanaged_resources_ptr.m_object = 0;
  owner->m_sound_voices_count = 64;
  p_m_sound_voices_allocator = &owner->m_sound_voices_allocator;
  owner->m_sound_voices_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *)&owner->m_sound_voices_allocator;
  p_m_sound_voices_allocator->m_initialized = 0;
  p_m_sound_voices_allocator->m_construction_started = 0;
  owner->m_logic_world_user = 0;
  owner->m_editor_world_user = 0;
  owner->m_engine = engine;
  owner->m_master_voice = 0;
  p_m_panning_lut = (vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&owner->m_panning_lut;
  owner->m_panning_lut.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    p_m_panning_lut,
    0);
  p_m_voices_to_delete = &owner->m_voices_to_delete;
  owner->m_voices_to_delete.m_size = 0;
  vostok::threading::mutex::mutex(&p_m_voices_to_delete->vostok::threading::mutex);
  p_m_voices_to_delete->m_first = 0;
  p_m_voices_to_delete->m_last = 0;
  owner->m_last_current_time_in_ms = 0;
  owner->m_is_destroying = 0;
  owner->m_is_audio_device_exist = 0;
  owner->m_calc_type = 0;
  p_m_active_scenes = &owner->m_active_scenes;
  owner->m_active_scenes.m_size = 0;
  p_m_active_scenes->m_first = 0;
  p_m_active_scenes->m_last = 0;
  owner->m_current_scene = 0;
  v62 = FLOAT_1_0;
  v61 = FLOAT_1_0;
  _InterlockedExchange(&owner->m_time_factor.m_data.m_atomic, SLODWORD(FLOAT_1_0));
  m_object = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
  v59 = (vostok::sound::world_user *)vostok::memory::doug_lea_allocator::malloc_impl(
                                       (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                       0x12Cu);
  v58 = v59;
  if ( v59 )
  {
    vostok::sound::world_user::world_user(v58, owner, logic_allocator);
    v57 = v4;
  }
  else
  {
    v57 = 0;
  }
  owner->m_logic_world_user = v57;
  v56 = 0;
  vostok::sound::sound_world::register_sound_cooks(owner);
  v55 = 0;
  out_value = *(float *)&FLOAT_0_0;
  if ( vostok::command_line::key::is_set_as_number(&s_speed_of_sound, &out_value) )
  {
    v51 = v52 | 0xC00;
    v50 = (__int64)out_value;
    v55 = v50;
    v53 = 1;
  }
  else
  {
    v53 = 0;
  }
  if ( v53 )
    vostok::sound::world::m_speed_of_sound = vostok::sound::world::m_speed_of_sound / 1000.0;
  v49 = vostok::threading::current_thread_id();
  _InterlockedExchange(&owner->m_xaudio_callback_orders.m_pop_thread_id, v49);
  v48 = (vostok::sound::sound_order *)vostok::memory::pthreads3_allocator::malloc_impl(
                                        &vostok::memory::g_mt_allocator,
                                        0xCu);
  v47 = v48;
  if ( v48 )
  {
    vostok::sound::sound_order::sound_order(v47);
    v46 = v5;
  }
  else
  {
    v46 = 0;
  }
  v45 = &owner->m_xaudio_callback_orders;
  v44 = 0;
  v43 = 0;
  v46->m_next_for_orders = 0;
  v45->m_tail = v46;
  v45->m_head = v46;
  CoInitializeEx(0, 2u);
  v6 = vostok::sound::sound_world::initialize_xaudio(owner);
  owner->m_is_audio_device_exist = v6;
  if ( owner->m_is_audio_device_exist )
  {
    if ( vostok::command_line::key::is_set(&s_xaudio_mono_voices_count) )
    {
      v42 = *(float *)&FLOAT_0_0;
      if ( vostok::command_line::key::is_set_as_number(&s_xaudio_mono_voices_count, &v42) )
      {
        v40 = v41 | 0xC00;
        v39 = (__int64)v42;
        v38.mono_voices_count = v39;
      }
    }
    else
    {
      v38.mono_voices_count = 64;
    }
    if ( vostok::command_line::key::is_set(&s_xaudio_stereo_voices_count) )
    {
      v37 = *(float *)&FLOAT_0_0;
      if ( vostok::command_line::key::is_set_as_number(&s_xaudio_stereo_voices_count, &v37) )
      {
        v35 = v36 | 0xC00;
        v34 = (__int64)v37;
        v38.stereo_voices_count = v34;
      }
    }
    else
    {
      v38.stereo_voices_count = 64;
    }
  }
  else
  {
    v38.mono_voices_count = 0;
    v38.stereo_voices_count = 0;
  }
  vostok::resources::creation_request::creation_request(&v33, "panning_lut", 0x4908u, sound_panning_lut_class);
  value = 2;
  vostok::variant<32>::variant<32>(&v31);
  vostok::variant<32>::set<unsigned char>(&v31, &value);
  f = vostok::sound::sound_world::on_panning_lut_loaded;
  f_4 = 0;
  v27 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
           (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_world::on_panning_lut_loaded,
           (survarium::weapon_core_animation_end_aware_state *)owner);
  v26.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1>>>>(
    &v26,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1> > >)v27);
  vostok::resources::query_resource_and_wait(
    "panning_lut",
    sound_panning_lut_class,
    (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v26,
    (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
    &v31,
    0,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v26);
  if ( owner->m_is_audio_device_exist )
  {
    arena_size = 136 * owner->m_sound_voices_count;
    v24 = 28 * (v38.stereo_voices_count + v38.mono_voices_count);
    max_buffers = 3 * (v38.stereo_voices_count + v38.mono_voices_count);
    size = 132600 * (v38.stereo_voices_count + v38.mono_voices_count);
    buffer_size = size + v24 + arena_size;
    vostok::resources::creation_request::creation_request(
      (vostok::resources::creation_request *)&v20.l_,
      "unmanaged_sound_resources_allocation",
      buffer_size,
      unmanaged_allocation_class);
    LODWORD(v20.f_.f_) = vostok::sound::sound_world::on_unmanaged_resources_allocated;
    HIDWORD(v20.f_.f_) = 0;
    v18 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
             (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v19,
             (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::sound::sound_world::on_unmanaged_resources_allocated,
             (survarium::weapon_core_animation_end_aware_state *)owner);
    v17.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1>>>>(
      &v17,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::arg<1> > >)v18);
    vostok::resources::query_create_resources_and_wait(
      (const vostok::resources::creation_request *)&v20.l_,
      1u,
      (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&v17,
      (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
      0,
      0,
      assert_on_fail_true);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v17);
    if ( owner != (vostok::sound::sound_world *)-112 )
      vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>(
        (vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *)&owner->m_sound_voices_allocator,
        owner->m_unmanaged_resources_ptr.m_object->buffer,
        arena_size);
    _InterlockedExchange(&owner->m_sound_voices_allocator.m_initialized, 1);
    v16 = arena_size;
    v15 = (vostok::sound::voice_factory *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                            0x3Cu);
    if ( v15 )
    {
      vostok::sound::voice_factory::voice_factory(
        v15,
        &owner->m_unmanaged_resources_ptr.m_object->buffer[v16],
        v24,
        owner,
        &v38);
      v14 = v7;
    }
    else
    {
      v14 = 0;
    }
    owner->m_voice_factory = v14;
    v13 = v24 + v16;
    v12 = (vostok::sound::sound_buffer_factory *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                   0x44u);
    if ( v12 )
    {
      vostok::sound::sound_buffer_factory::sound_buffer_factory(
        v12,
        &owner->m_unmanaged_resources_ptr.m_object->buffer[v13],
        size,
        max_buffers);
      v11 = v8;
    }
    else
    {
      v11 = 0;
    }
    owner->m_sound_buffer_factory = v11;
  }
  p_m_timer = &owner->m_timer;
  if ( vostok::timing::g_cpu_supports_time_stamp )
    performance_counter = __rdtsc();
  else
    performance_counter = vostok::timing::query_performance_counter();
  p_m_timer->m_start_time = performance_counter;
  LODWORD(p_m_timer->m_current_time) = 0;
  HIDWORD(p_m_timer->m_current_time) = 0;
  vostok::variant<32>::~variant<32>(&v31);
}
