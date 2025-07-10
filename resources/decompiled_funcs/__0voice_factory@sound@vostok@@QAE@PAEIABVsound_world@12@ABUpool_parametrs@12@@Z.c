void __thiscall vostok::sound::voice_factory::voice_factory(
        vostok::sound::voice_factory *this,
        unsigned __int8 *buffer,
        unsigned int buffer_size,
        vostok::sound::sound_world *world,
        const vostok::sound::pool_parametrs *params)
{
  unsigned int stereo_voices_count; // edx
  vostok::sound::voice_bridge *v6; // eax
  vostok::sound::voice_bridge *v7; // eax
  vostok::sound::voice_bridge *v8; // [esp+0h] [ebp-74h]
  vostok::sound::voice_bridge *v9; // [esp+4h] [ebp-70h]
  int v11; // [esp+48h] [ebp-2Ch]
  boost::array<vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>,2> *j; // [esp+4Ch] [ebp-28h]
  vostok::sound::voice_bridge *v13; // [esp+50h] [ebp-24h]
  vostok::sound::voice_bridge *v14; // [esp+54h] [ebp-20h]
  unsigned int k; // [esp+5Ch] [ebp-18h]
  unsigned int i; // [esp+64h] [ebp-10h]
  vostok::sound::voice_bridge::creation_parametrs voice_params; // [esp+68h] [ebp-Ch] BYREF

  stereo_voices_count = params->stereo_voices_count;
  this->m_pool_params.mono_voices_count = params->mono_voices_count;
  this->m_pool_params.stereo_voices_count = stereo_voices_count;
  v11 = 2;
  for ( j = &this->m_voices_pool;
        --v11 >= 0;
        j = (boost::array<vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>,2> *)((char *)j + 16) )
  {
    vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(j->elems);
  }
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>(
    &this->m_voices_allocator,
    buffer,
    buffer_size);
  this->m_min_frequency_ratio = 0.0009765625;
  this->m_max_frequency_ratio = FLOAT_2_0;
  voice_params.xaudio_engine = world->m_xaudio;
  voice_params.master_channels_num = vostok::sound::sound_world::master_channels_num(world);
  voice_params.max_frequency_ratio = this->m_max_frequency_ratio;
  voice_params.channels_num = 1;
  for ( i = 0; i < params->mono_voices_count; ++i )
  {
    v14 = (vostok::sound::voice_bridge *)vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::allocate(&this->m_voices_allocator);
    if ( v14 )
    {
      vostok::sound::voice_bridge::voice_bridge(v14, &voice_params);
      v9 = v6;
    }
    else
    {
      v9 = 0;
    }
    vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_voices_pool.elems[voice_params.channels_num - 1],
      v9,
      0);
  }
  voice_params.channels_num = 2;
  for ( k = 0; k < params->stereo_voices_count; ++k )
  {
    v13 = (vostok::sound::voice_bridge *)vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::allocate(&this->m_voices_allocator);
    if ( v13 )
    {
      vostok::sound::voice_bridge::voice_bridge(v13, &voice_params);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    vostok::intrusive_list<vostok::sound::voice_bridge,vostok::sound::voice_bridge *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_voices_pool.elems[voice_params.channels_num - 1],
      v8,
      0);
  }
}
