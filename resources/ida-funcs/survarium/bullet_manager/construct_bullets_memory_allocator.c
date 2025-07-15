void __userpurge survarium::bullet_manager::construct_bullets_memory_allocator(
        survarium::bullet_manager *this@<ecx>,
        int a2@<edi>,
        vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node *pointer,
        const unsigned int __formal)
{
  int v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // ecx
  char v8; // [esp+Ch] [ebp-34h]
  survarium::bullet_manager::bullet_functor_mt_allocator v9; // [esp+10h] [ebp-30h] BYREF
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock> const &)> on_out_of_memory; // [esp+20h] [ebp-20h] BYREF

  v8 = 0;
  if ( *(_DWORD *)(a2 + 124) )
  {
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      *(int **)(a2 + 120));
    *(_DWORD *)(a2 + 124) = 0;
  }
  if ( a2 != -64 )
  {
    v4 = *(_DWORD *)(a2 + 152);
    on_out_of_memory.vtable = 0;
    v8 = 1;
    vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::single_size_buffer_allocator<140,vostok::threading::simple_lock>(
      &on_out_of_memory,
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock> *)(a2 + 64),
      pointer,
      140 * v4);
  }
  v5 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)_InterlockedExchange(
                                                                                         (volatile __int32 *)(a2 + 124),
                                                                                         1);
  if ( (v8 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&on_out_of_memory);
  v6 = (unsigned __int8 *)&pointer[*(_DWORD *)(a2 + 152)];
  v7 = &v6[4 * *(_DWORD *)(a2 + 152)];
  *(_DWORD *)(a2 + 8) = v6;
  *(_DWORD *)(a2 + 12) = v6;
  *(_DWORD *)(a2 + 16) = v7;
  survarium::bullet_manager::bullet_functor_mt_allocator::bullet_functor_mt_allocator(
    (survarium::bullet_manager::bullet_functor *)&v6[4 * *(_DWORD *)(a2 + 152)],
    576 * *(_DWORD *)(a2 + 152),
    &v9);
  *(survarium::bullet_manager::bullet_functor_mt_allocator *)(a2 + 32) = v9;
}
