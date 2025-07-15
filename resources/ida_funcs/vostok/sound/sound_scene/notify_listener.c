void __thiscall vostok::sound::sound_scene::notify_listener(
        vostok::sound::sound_scene *this,
        const vostok::sound::sound_world *world)
{
  unsigned int v2; // eax
  float v3; // [esp+14h] [ebp-204h]
  float v4; // [esp+18h] [ebp-200h]
  vostok::sound::sound_instance_proxy_internal *v6; // [esp+100h] [ebp-118h]
  vostok::sound::propagator_info *graph_position; // [esp+108h] [ebp-110h]
  vostok::sound::sound_spl **v8; // [esp+118h] [ebp-100h]
  vostok::sound::sound_instance_proxy_internal *m_proxy; // [esp+124h] [ebp-F4h]
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > __a; // [esp+13Ch] [ebp-DCh] BYREF
  vostok::sound::propagator_info *__first; // [esp+140h] [ebp-D8h]
  vostok::sound::propagator_info *__last; // [esp+144h] [ebp-D4h]
  stlp_std::pair<float,vostok::math::float3> *v13; // [esp+148h] [ebp-D0h]
  stlp_std::pair<float,vostok::math::float3> *v14; // [esp+14Ch] [ebp-CCh]
  vostok::resources::unmanaged_resource *v15; // [esp+150h] [ebp-C8h]
  vostok::vectora_allocator<void *> v16; // [esp+154h] [ebp-C4h] BYREF
  vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > v17; // [esp+158h] [ebp-C0h] BYREF
  vostok::resources::unmanaged_resource *m_object; // [esp+15Ch] [ebp-BCh]
  vostok::vectora_allocator<void *> allocator; // [esp+160h] [ebp-B8h] BYREF
  vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > v20; // [esp+164h] [ebp-B4h] BYREF
  vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base> panning_lut; // [esp+168h] [ebp-B0h] BYREF
  char v22; // [esp+16Fh] [ebp-A9h]
  vostok::math::float3 result; // [esp+170h] [ebp-A8h] BYREF
  vostok::sound::unique_propagator_info __x; // [esp+17Ch] [ebp-9Ch] BYREF
  float attenuation; // [esp+190h] [ebp-88h]
  float distance_to_listener; // [esp+194h] [ebp-84h]
  float distance; // [esp+198h] [ebp-80h]
  vostok::sound::compare_by_propagator predicate; // [esp+19Ch] [ebp-7Ch]
  vostok::sound::sound_voice_params params; // [esp+1A0h] [ebp-78h] BYREF
  stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *v30; // [esp+1ACh] [ebp-6Ch]
  unsigned int j; // [esp+1B0h] [ebp-68h]
  vostok::sound::propagator_info info; // [esp+1B4h] [ebp-64h] BYREF
  unsigned int i; // [esp+1C8h] [ebp-50h]
  vostok::sound::new_sound_propagator *propagator; // [esp+1CCh] [ebp-4Ch]
  vostok::vectora<stlp_std::pair<float,vostok::math::float3> > results; // [esp+1D0h] [ebp-48h] BYREF
  vostok::vectora<vostok::sound::propagator_info> props; // [esp+1E0h] [ebp-38h] BYREF
  vostok::math::float3 listener; // [esp+1F0h] [ebp-28h] BYREF
  vostok::vectora<vostok::sound::unique_propagator_info> unique; // [esp+1FCh] [ebp-1Ch] BYREF
  vostok::sound::sound_instance_proxy_internal *proxy; // [esp+20Ch] [ebp-Ch]
  vostok::sound::unique_propagator_info *end; // [esp+210h] [ebp-8h]
  vostok::sound::unique_propagator_info *it; // [esp+214h] [ebp-4h]

  vostok::math::half3_pod::operator vostok::math::float3(&this->m_list_position.m_data.m_val, &result);
  listener = result;
  m_object = vostok::sound::g_allocator.m_object;
  allocator.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
    &v20,
    &allocator);
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&props,
    (const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *)&v20);
  proxy = this->m_active_proxies.m_first;
  while ( proxy )
  {
    v15 = vostok::sound::g_allocator.m_object;
    v16.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
    vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
      &v17,
      &v16);
    stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
      (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&results,
      (const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *)&v17);
    vostok::sound::sound_instance_proxy_internal::calculate_graph_position(proxy, &listener, &results);
    v22 = 0;
    for ( propagator = proxy->m_propagators.m_first; propagator; propagator = propagator->m_next_for_proxies )
    {
      for ( i = 0; ; ++i )
      {
        v2 = stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::size(&results._M_impl);
        if ( i >= v2 )
          break;
        info.prop = propagator;
        v14 = &results._M_impl._M_start[i];
        *(_QWORD *)&info.in_graph_position.x = *(_QWORD *)&v14->second.x;
        info.in_graph_position.z = v14->second.z;
        v13 = v14;
        info.distance_to_listener = v14->first;
        stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::push_back(
          &props._M_impl,
          &info);
      }
    }
    proxy = proxy->m_next_for_sound_world;
    stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::~_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>(&results._M_impl);
  }
  __last = props._M_impl._M_finish;
  __first = props._M_impl._M_start;
  stlp_std::sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
    props._M_impl._M_start,
    props._M_impl._M_finish,
    vostok::sound::compare_propagator_info_by_distance);
  __a.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
  stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
    (stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *)&unique,
    &__a);
  for ( j = 0; j < props._M_impl._M_finish - props._M_impl._M_start && j < 0x14; ++j )
  {
    distance_to_listener = props._M_impl._M_start[j].distance_to_listener;
    if ( distance_to_listener <= 1.0 )
      v4 = FLOAT_1_0;
    else
      v4 = distance_to_listener;
    distance = v4;
    if ( float_max_18 <= v4 )
      v3 = float_max_18;
    else
      v3 = distance;
    distance = v3;
    m_proxy = props._M_impl._M_start[j].prop->m_proxy;
    v8 = (vostok::sound::sound_spl **)((int (__thiscall *)(const vostok::sound::sound_propagator_emitter *, const vostok::sound::sound_propagator_emitter *))m_proxy->m_propagator_emitter->get_sound_spl)(
                                        m_proxy->m_propagator_emitter,
                                        m_proxy->m_propagator_emitter);
    attenuation = vostok::sound::sound_spl::get_loudness(*v8, distance);
    graph_position = &props._M_impl._M_start[j];
    v6 = graph_position->prop->m_proxy;
    vostok::resources::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base>(
      &panning_lut,
      &world->m_panning_lut);
    vostok::sound::sound_scene::calculate_channel_matrix(
      this,
      &panning_lut,
      v6,
      &graph_position->in_graph_position,
      distance,
      attenuation,
      params.channel_matrix,
      &params.lp_filter_coeff);
    vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&panning_lut);
    predicate.prop = props._M_impl._M_start[j].prop;
    v30 = (stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *)stlp_std::find_if<vostok::sound::unique_propagator_info *,vostok::sound::compare_by_propagator>(unique._M_impl._M_start, unique._M_impl._M_finish, predicate);
    if ( v30 == (stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *)unique._M_impl._M_finish )
    {
      vostok::sound::unique_propagator_info::unique_propagator_info(&__x);
      stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::push_back(
        &__x.voice_params._M_impl,
        &params);
      __x.prop = props._M_impl._M_start[j].prop;
      stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::push_back(
        &unique._M_impl,
        &__x);
      stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::~_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(&__x.voice_params._M_impl);
    }
    else
    {
      stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::push_back(
        v30,
        &params);
    }
  }
  it = unique._M_impl._M_start;
  end = unique._M_impl._M_finish;
  while ( it != end )
  {
    vostok::sound::new_sound_propagator::distribute_voices(
      it->prop,
      it->voice_params._M_impl._M_finish - it->voice_params._M_impl._M_start,
      &it->voice_params);
    ++it;
  }
  stlp_std::priv::_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>::~_Impl_vector<vostok::sound::unique_propagator_info,vostok::vectora_allocator<vostok::sound::unique_propagator_info>>(&unique._M_impl);
  stlp_std::priv::_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>::~_Impl_vector<vostok::sound::propagator_info,vostok::vectora_allocator<vostok::sound::propagator_info>>(&props._M_impl);
}
