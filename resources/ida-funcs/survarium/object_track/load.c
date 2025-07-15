void __thiscall survarium::object_track::load(
        survarium::object_track *this,
        const vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::animation::anm_track *v9; // ecx
  vostok::animation::anm_track *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v14; // ecx
  float v15; // xmm1_4
  vostok::animation::anm_track *m_track; // eax
  int m_channels_count; // esi
  vostok::animation::EtCurve **v18; // ecx
  vostok::animation::EtCurve *v19; // ecx
  float *p_time; // edx
  float v21; // xmm2_4
  int v22; // esi
  float v23; // xmm0_4
  unsigned __int8 v24; // dl
  vostok::animation::EtCurve **m_channels; // eax
  vostok::animation::EtCurve **v26; // ecx
  vostok::animation::EtCurve *v27; // ecx
  float time; // xmm1_4
  const char *v29; // [esp+0h] [ebp-10h]
  const char *v30; // [esp+4h] [ebp-Ch]
  unsigned int v31; // [esp+8h] [ebp-8h]
  unsigned __int8 i; // [esp+Fh] [ebp-1h]

  v4 = survarium::g_allocator;
  v6 = type_info::raw_name(&vostok::animation::anm_track `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v4, 0x14u, v6, v29, v30, v31);
  if ( v8 )
    vostok::animation::anm_track::anm_track(v9, (unsigned __int8 **)v8);
  else
    v10 = 0;
  this->m_track = v10;
  vostok::animation::anm_track::initialize_empty(v9, (int)v10);
  survarium::load_transform(t, &this->m_transform);
  v11 = vostok::configs::binary_config_value::operator[](t, "path");
  vostok::animation::anm_track::load(v11, this->m_track);
  v12 = vostok::configs::binary_config_value::operator[](t, "cyclic");
  v13 = infinity_28;
  v14 = 0;
  v15 = infinity_28;
  this->m_cyclic = v12->data.pointer != 0;
  m_track = this->m_track;
  m_channels_count = m_track->m_channels_count;
  for ( i = 0;
        i < m_channels_count;
        v14 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)i )
  {
    v18 = &m_track->m_channels[(_DWORD)v14];
    if ( *v18 )
    {
      v19 = *v18;
      p_time = &v19->keyList._M_impl._M_start->time;
      v21 = p_time == (float *)v19->keyList._M_impl._M_finish ? 0.0 : *p_time;
      if ( v21 <= v15 )
        v15 = v21;
    }
    ++i;
  }
  this->m_min_time = v15;
  v22 = m_track->m_channels_count;
  LODWORD(v23) = LODWORD(v13) ^ _mask__NegFloat_;
  v24 = 0;
  if ( v22 > 0 )
  {
    m_channels = m_track->m_channels;
    v14 = 0;
    do
    {
      v26 = &m_channels[(_DWORD)v14];
      if ( *v26 )
      {
        v27 = *v26;
        if ( v27->keyList._M_impl._M_start == v27->keyList._M_impl._M_finish )
          time = 0.0;
        else
          time = v27->keyList._M_impl._M_finish[-1].time;
        if ( v23 <= time )
          v23 = time;
      }
      v14 = (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)++v24;
    }
    while ( v24 < v22 );
  }
  this->m_max_time = v23;
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v14,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
