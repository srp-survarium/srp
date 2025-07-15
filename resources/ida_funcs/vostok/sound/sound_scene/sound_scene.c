void __thiscall vostok::sound::sound_scene::sound_scene(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_world *world_,
        const vostok::sound::sound_scene_creation_params *creation_params,
        IXAudio2SubmixVoice *submix_voice,
        unsigned int dbg_id,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::sound::sound_environment *v6; // eax
  vostok::sound::effect_cross_fader *v7; // eax
  vostok::sound::effect_cross_fader *v8; // [esp+10h] [ebp-240h]
  vostok::sound::sound_environment *v9; // [esp+14h] [ebp-23Ch]
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *v11; // [esp+54h] [ebp-1FCh]
  vostok::fixed_string<64> v12; // [esp+58h] [ebp-1F8h] BYREF
  char *m_end; // [esp+A4h] [ebp-1ACh]
  unsigned int max_count; // [esp+A8h] [ebp-1A8h] BYREF
  char *begin_src; // [esp+ACh] [ebp-1A4h] BYREF
  char *end_src; // [esp+B0h] [ebp-1A0h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *v17; // [esp+C0h] [ebp-190h]
  vostok::memory::doug_lea_allocator *v18; // [esp+C4h] [ebp-18Ch]
  IID *v19; // [esp+C8h] [ebp-188h]
  IID *rclsid; // [esp+CCh] [ebp-184h]
  vostok::intrusive_list<vostok::sound::sound_voice,vostok::sound::sound_voice *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_active_voices; // [esp+D4h] [ebp-17Ch]
  vostok::threading::mutex_tasks_unaware *v23; // [esp+D8h] [ebp-178h]
  vostok::intrusive_list<vostok::sound::sound_instance_proxy_internal,vostok::sound::sound_instance_proxy_internal *,488,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_active_proxies; // [esp+DCh] [ebp-174h]
  vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_receivers; // [esp+E0h] [ebp-170h]
  vostok::threading::mutex_tasks_unaware *p_m_mutex; // [esp+E4h] [ebp-16Ch]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> > *p_m_receiver_collisions_allocator; // [esp+E8h] [ebp-168h]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> > *p_m_receiver_positions_allocator; // [esp+ECh] [ebp-164h]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> > *p_m_propagators_allocator; // [esp+F0h] [ebp-160h]
  vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> > *p_m_proxies_allocator; // [esp+F4h] [ebp-15Ch]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_graph; // [esp+F8h] [ebp-158h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_memory_arena_resources_ptr; // [esp+FCh] [ebp-154h]
  vostok::resources::unmanaged_resource *m_object; // [esp+124h] [ebp-12Ch]
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *p_m_environment_parameters; // [esp+128h] [ebp-128h]
  vostok::resources::unmanaged_resource *v35; // [esp+12Ch] [ebp-124h]
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+130h] [ebp-120h] BYREF
  vostok::sound::effect_cross_fader *v37; // [esp+138h] [ebp-118h]
  vostok::sound::sound_environment *v38; // [esp+13Ch] [ebp-114h]
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> v39; // [esp+140h] [ebp-110h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *v40; // [esp+194h] [ebp-BCh]
  char v41; // [esp+199h] [ebp-B7h]
  char v42; // [esp+19Ah] [ebp-B6h]
  char v43; // [esp+19Bh] [ebp-B5h]
  XAUDIO2_EFFECT_DESCRIPTOR effects_1[1]; // [esp+19Ch] [ebp-B4h] BYREF
  IUnknown *pReverbEffect_2; // [esp+1A8h] [ebp-A8h] BYREF
  XAUDIO2_SEND_DESCRIPTOR send_descriptor; // [esp+1ACh] [ebp-A4h] BYREF
  HRESULT hr; // [esp+1B4h] [ebp-9Ch]
  XAUDIO2_VOICE_SENDS sends; // [esp+1B8h] [ebp-98h] BYREF
  XAUDIO2_EFFECT_CHAIN effectChain_2; // [esp+1C0h] [ebp-90h] BYREF
  XAUDIO2FX_REVERB_PARAMETERS native; // [esp+1C8h] [ebp-88h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *default_params; // [esp+1FCh] [ebp-54h]
  unsigned int env_params_id; // [esp+200h] [ebp-50h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS i3dl2_params; // [esp+204h] [ebp-4Ch] BYREF
  IUnknown *pReverbEffect_1; // [esp+238h] [ebp-18h] BYREF
  XAUDIO2_EFFECT_CHAIN effectChain_1; // [esp+23Ch] [ebp-14h] BYREF
  XAUDIO2_EFFECT_DESCRIPTOR effects_2[1]; // [esp+244h] [ebp-Ch] BYREF

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::sound_scene_vtbl *)&vostok::sound::sound_scene::`vftable';
  this->m_next = 0;
  m_object = vostok::sound::g_allocator.m_object;
  p_m_environment_parameters = (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&this->m_environment_parameters;
  v35 = vostok::sound::g_allocator.m_object;
  __a.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&this->m_environment_parameters,
    &__a);
  this->m_world = world_;
  vostok::sound::atomic_half3::atomic_half3(&this->m_list_position);
  vostok::sound::atomic_half3::atomic_half3(&this->m_list_orient_front);
  vostok::sound::atomic_half3::atomic_half3(&this->m_list_orient_top);
  p_m_memory_arena_resources_ptr = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_memory_arena_resources_ptr;
  this->m_memory_arena_resources_ptr.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    p_m_memory_arena_resources_ptr,
    0);
  p_m_graph = (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_graph;
  this->m_graph.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    p_m_graph,
    0);
  this->m_proxies_count = creation_params->proxies_count;
  p_m_proxies_allocator = &this->m_proxies_allocator;
  this->m_proxies_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *)&this->m_proxies_allocator;
  p_m_proxies_allocator->m_initialized = 0;
  p_m_proxies_allocator->m_construction_started = 0;
  this->m_propagators_count = creation_params->propagators_count;
  p_m_propagators_allocator = &this->m_propagators_allocator;
  this->m_propagators_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> *)&this->m_propagators_allocator;
  p_m_propagators_allocator->m_initialized = 0;
  p_m_propagators_allocator->m_construction_started = 0;
  this->m_receivers_count = creation_params->receivers_count;
  p_m_receiver_positions_allocator = &this->m_receiver_positions_allocator;
  this->m_receiver_positions_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> *)&this->m_receiver_positions_allocator;
  p_m_receiver_positions_allocator->m_initialized = 0;
  p_m_receiver_positions_allocator->m_construction_started = 0;
  p_m_receiver_collisions_allocator = &this->m_receiver_collisions_allocator;
  this->m_receiver_collisions_allocator.m_variable = (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)&this->m_receiver_collisions_allocator;
  p_m_receiver_collisions_allocator->m_initialized = 0;
  p_m_receiver_collisions_allocator->m_construction_started = 0;
  this->m_spatial_tree = 0;
  this->m_environments_tree = 0;
  p_m_receivers = &this->m_receivers;
  this->m_receivers.m_size = 0;
  p_m_mutex = &p_m_receivers->m_mutex;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(&p_m_receivers->m_mutex);
  p_m_receivers->m_first = 0;
  p_m_receivers->m_last = 0;
  p_m_active_proxies = &this->m_active_proxies;
  this->m_active_proxies.m_size = 0;
  p_m_active_proxies->m_first = 0;
  p_m_active_proxies->m_last = 0;
  p_m_active_voices = &this->m_active_voices;
  this->m_active_voices.m_size = 0;
  v23 = &p_m_active_voices->m_mutex;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(&p_m_active_voices->m_mutex);
  p_m_active_voices->m_first = 0;
  p_m_active_voices->m_last = 0;
  this->m_submix_voice = submix_voice;
  this->m_fade_in_environment = 0;
  this->m_fade_out_environment = 0;
  this->m_fade_vol_per_msec = *(float *)&FLOAT_0_0;
  this->m_volume = *(float *)&FLOAT_0_0;
  this->m_fade_in_time = 0;
  this->m_fade_out_time = 0;
  this->m_dbg_id = dbg_id;
  this->m_is_paused = 0;
  this->m_is_active = 0;
  this->m_is_listener_position_set = 0;
  this->m_fade_state = none;
  vostok::sound::sound_scene::init_allocators(this, parent);
  v43 = 0;
  this->m_spatial_tree = vostok::collision::new_space_partitioning_tree(
                           (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
                           0.000099999997,
                           0x400u);
  v42 = 0;
  this->m_environments_tree = vostok::collision::new_space_partitioning_tree(
                                (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object,
                                0.000099999997,
                                0x40u);
  v41 = 0;
  if ( this->m_world->m_is_audio_device_exist )
  {
    this->m_fade_in_environment = vostok::sound::sound_world::create_submix_voice(this->m_world, 1u, 1u);
    this->m_fade_out_environment = vostok::sound::sound_world::create_submix_voice(this->m_world, 1u, 1u);
    pReverbEffect_1 = 0;
    rclsid = &_GUID_6a93130e_1d53_41d1_a9cf_e758800bb179;
    hr = CoCreateInstance(
           &_GUID_6a93130e_1d53_41d1_a9cf_e758800bb179,
           0,
           1u,
           &_GUID_00000000_0000_0000_c000_000000000046,
           (LPVOID *)&pReverbEffect_1);
    effects_1[0].pEffect = pReverbEffect_1;
    effects_1[0].InitialState = 1;
    effects_1[0].OutputChannels = 1;
    effectChain_1.EffectCount = 1;
    effectChain_1.pEffectDescriptors = effects_1;
    this->m_fade_in_environment->SetEffectChain(this->m_fade_in_environment, &effectChain_1);
    pReverbEffect_2 = 0;
    v19 = &_GUID_6a93130e_1d53_41d1_a9cf_e758800bb179;
    hr = CoCreateInstance(
           &_GUID_6a93130e_1d53_41d1_a9cf_e758800bb179,
           0,
           1u,
           &_GUID_00000000_0000_0000_c000_000000000046,
           (LPVOID *)&pReverbEffect_2);
    effects_2[0].pEffect = pReverbEffect_2;
    effects_2[0].InitialState = 1;
    effects_2[0].OutputChannels = 1;
    effectChain_2.EffectCount = 1;
    effectChain_2.pEffectDescriptors = effects_2;
    this->m_fade_out_environment->SetEffectChain(this->m_fade_out_environment, &effectChain_2);
    i3dl2_params.WetDryMix = 100.0;
    i3dl2_params.Room = -10000;
    i3dl2_params.RoomHF = 0;
    i3dl2_params.RoomRolloffFactor = *(float *)&FLOAT_0_0;
    i3dl2_params.DecayTime = FLOAT_1_0;
    i3dl2_params.DecayHFRatio = FLOAT_0_5;
    i3dl2_params.Reflections = -10000;
    i3dl2_params.ReflectionsDelay = 0.02;
    i3dl2_params.Reverb = -10000;
    i3dl2_params.ReverbDelay = 0.039999999;
    i3dl2_params.Diffusion = 100.0;
    i3dl2_params.Density = 100.0;
    i3dl2_params.HFReference = 5000.0;
    v18 = (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object;
    v17 = (XAUDIO2FX_REVERB_I3DL2_PARAMETERS *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                 0x34u);
    v40 = v17;
    default_params = v17;
    qmemcpy(v17, &i3dl2_params, sizeof(XAUDIO2FX_REVERB_I3DL2_PARAMETERS));
    vostok::fixed_string<64>::fixed_string<64>(&v12, (const char *)&buf);
    v11 = default_params;
    m_end = v12.m_end;
    end_src = v12.m_end;
    begin_src = v12.m_begin;
    max_count = 64;
    vostok::buffer_string::buffer_string(
      &v39.first,
      v39.first.m_buffer,
      &max_count,
      (const char *const *)&begin_src,
      (const char *const *)&end_src);
    v39.second = v11;
    stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>,vostok::vectora_allocator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>>>::push_back(
      &this->m_environment_parameters._M_impl,
      &v39);
    env_params_id = 0;
    vostok::sound::sound_scene::add_environment_params(this, (const char *)&buf, default_params, &env_params_id);
    v38 = (vostok::sound::sound_environment *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                0x110u);
    if ( v38 )
    {
      vostok::sound::sound_environment::sound_environment(v38, env_params_id);
      v9 = v6;
    }
    else
    {
      v9 = 0;
    }
    this->m_default_environment = v9;
    ReverbConvertI3DL2ToNative(&i3dl2_params, &native);
    hr = this->m_fade_in_environment->SetEffectParameters(this->m_fade_in_environment, 0, &native, 52u, 0);
    hr = this->m_fade_out_environment->SetEffectParameters(this->m_fade_out_environment, 0, &native, 52u, 0);
    send_descriptor.pOutputVoice = this->m_submix_voice;
    send_descriptor.Flags = 0;
    sends.pSends = &send_descriptor;
    sends.SendCount = 1;
    hr = this->m_fade_in_environment->SetOutputVoices(this->m_fade_in_environment, &sends);
    hr = this->m_fade_out_environment->SetOutputVoices(this->m_fade_out_environment, &sends);
    v37 = (vostok::sound::effect_cross_fader *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                                 0x1Cu);
    if ( v37 )
    {
      vostok::sound::effect_cross_fader::effect_cross_fader(
        v37,
        this,
        0x64u,
        this->m_fade_in_environment,
        this->m_fade_out_environment);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    this->m_environment_crossfader = v8;
  }
}
