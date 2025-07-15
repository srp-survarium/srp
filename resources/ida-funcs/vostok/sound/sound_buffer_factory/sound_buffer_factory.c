void __userpurge vostok::sound::sound_buffer_factory::sound_buffer_factory(
        vostok::sound::sound_buffer_factory *this@<ecx>,
        int a2@<edi>,
        vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node *buffer,
        unsigned int size,
        unsigned int max_buffers)
{
  unsigned int v5; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node>::free_list_type *v7; // esi
  int v8; // ecx
  const std::exception *v9; // eax
  vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node *v10; // eax
  bool v11; // zf
  int v12; // ecx
  stlp_std::out_of_range v13; // [esp+8h] [ebp-134h] BYREF
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy> const &)> on_out_of_memory; // [esp+118h] [ebp-24h] BYREF
  unsigned int arena_size; // [esp+148h] [ebp+Ch]

  v5 = 0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = a2 + 20;
  *(_DWORD *)(a2 + 28) = a2 + 20;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  on_out_of_memory.vtable = 0;
  vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>(
    &on_out_of_memory,
    (vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy> *)(a2 + 40),
    buffer,
    size);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&on_out_of_memory);
  if ( max_buffers != 1 )
  {
    arena_size = max_buffers - 1;
    do
    {
      v7 = (vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node>::free_list_type *)(a2 + 40);
      if ( *(_DWORD *)(a2 + 76) >= *(_DWORD *)(a2 + 80) )
      {
        v8 = -(v7->pointer != 0);
        if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v8) != 0 )
        {
          if ( !v7->pointer )
          {
            boost::bad_function_call::bad_function_call((boost::bad_function_call *)v8, (stlp_std::runtime_error *)&v13);
            boost::throw_exception(v9);
            stlp_std::__Named_exception::~__Named_exception(&v13);
          }
          v7 = (vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node>::free_list_type *)(a2 + 40);
          (*(void (__cdecl **)(int, int))((*(_DWORD *)(a2 + 40) & 0xFFFFFFFE) + 4))(a2 + 48, a2 + 40);
        }
      }
      v10 = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<88288,vostok::threading::single_threading_policy>::node>::allocate(v7 + 8);
      ++v7[9].pointer;
      if ( v10 )
      {
        v10->next = 0;
        *(_DWORD *)&v10->data[4] = 0;
        *(_DWORD *)&v10->data[8] = 0;
        *(_DWORD *)&v10->data[20] = 0;
        *(_DWORD *)&v10->data[24] = 0;
        *(_DWORD *)&v10->data[28] = 0;
        *(_DWORD *)&v10->data[72] = 0;
        *(_DWORD *)&v10->data[76] = 0;
        *(_DWORD *)&v10->data[80] = 0;
        *(_DWORD *)&v10->data[84] = 0;
      }
      *(_DWORD *)&v10->data[16] = 0;
      ++*(_DWORD *)a2;
      if ( *(_DWORD *)(a2 + 8) )
        *(_DWORD *)(*(_DWORD *)(a2 + 12) + 16) = v10;
      else
        *(_DWORD *)(a2 + 8) = v10;
      v11 = arena_size-- == 1;
      *(_DWORD *)(a2 + 12) = v10;
    }
    while ( !v11 );
  }
  v12 = 0;
  do
  {
    v12 = 134775813 * v12 + 1;
    garbage_buffer[v5++] = (255 * (unsigned __int64)(unsigned int)v12) >> 32;
  }
  while ( v5 < (unsigned int)&loc_15887 + 1 );
}
