void __userpurge vostok::sound::voice_factory::voice_factory(
        vostok::sound::voice_factory *this@<ecx>,
        int a2@<edi>,
        vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>::node *buffer,
        unsigned int buffer_size,
        vostok::sound::sound_world *world,
        const vostok::sound::pool_parametrs *params)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  bool v8; // zf
  vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>::node *v9; // eax
  int v10; // eax
  _DWORD *v11; // ecx
  vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>::node *v12; // eax
  int v13; // eax
  _DWORD *v14; // ecx
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy> const &)> on_out_of_memory; // [esp+8h] [ebp-28h] BYREF
  vostok::sound::voice_bridge::creation_parametrs v16; // [esp+28h] [ebp-8h] BYREF
  unsigned int arena_size; // [esp+3Ch] [ebp+Ch]
  unsigned int arena_sizea; // [esp+3Ch] [ebp+Ch]
  unsigned int v19; // [esp+44h] [ebp+14h]
  unsigned int v20; // [esp+44h] [ebp+14h]

  *(vostok::sound::pool_parametrs *)a2 = *params;
  *(_DWORD *)(a2 + 1032) = 0;
  *(_DWORD *)(a2 + 1036) = 0;
  on_out_of_memory.vtable = 0;
  vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>(
    &on_out_of_memory,
    (vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy> *)(a2 + 1040),
    buffer,
    buffer_size);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)&on_out_of_memory);
  v19 = 0;
  v8 = params->mono_voices_count == 0;
  v16.world = world;
  v16.channels_num = 1;
  v16.enable_filter = 1;
  if ( !v8 )
  {
    arena_size = a2 + 8;
    do
    {
      v9 = vostok::memory::new_helper<vostok::sound::voice_bridge>::call<vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>>((const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)(a2 + 1040));
      if ( v9 )
        vostok::sound::voice_bridge::voice_bridge((vostok::sound::voice_bridge *)&v16, (int)v9, &v16, v19);
      else
        v10 = 0;
      v11 = (_DWORD *)arena_size;
      ++v19;
      arena_size += 4;
      *v11 = v10;
    }
    while ( v19 < params->mono_voices_count );
  }
  v20 = 0;
  v8 = params->stereo_voices_count == 0;
  v16.channels_num = 2;
  v16.enable_filter = 0;
  if ( !v8 )
  {
    arena_sizea = a2 + 520;
    do
    {
      v12 = vostok::memory::new_helper<vostok::sound::voice_bridge>::call<vostok::memory::single_size_buffer_allocator<64,vostok::threading::single_threading_policy>>((const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)(a2 + 1040));
      if ( v12 )
        vostok::sound::voice_bridge::voice_bridge(
          (vostok::sound::voice_bridge *)&v16,
          (int)v12,
          &v16,
          v20 + params->mono_voices_count);
      else
        v13 = 0;
      v14 = (_DWORD *)arena_sizea;
      ++v20;
      arena_sizea += 4;
      *v14 = v13;
    }
    while ( v20 < params->stereo_voices_count );
  }
}
