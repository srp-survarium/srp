void __thiscall vostok::sound::sound_scene::init_allocators(
        vostok::sound::sound_scene *this,
        vostok::resources::query_result_for_cook *parent,
        const vostok::variant<32> **parenta)
{
  int v3; // edx
  __int32 v4; // ecx
  int v5; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  volatile int m_pending_tasks_count; // ecx
  unsigned int v8; // edi
  volatile int v9; // ecx
  unsigned int v10; // edi
  volatile int v11; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  volatile int v13; // ecx
  char v14; // [esp+Ch] [ebp-64h]
  unsigned int arena_size; // [esp+10h] [ebp-60h]
  unsigned int v16; // [esp+14h] [ebp-5Ch]
  int v17; // [esp+18h] [ebp-58h]
  vostok::resources::creation_request requests; // [esp+20h] [ebp-50h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+30h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<144,vostok::threading::multi_threading_policy> const &)> on_out_of_memory; // [esp+50h] [ebp-20h] BYREF

  v3 = 76 * *(_DWORD *)&parent->m_request_path_default_storage[52];
  v4 = 144 * parent->m_out_of_memory_type;
  v5 = *(_DWORD *)&parent->m_request_path_default_storage[124];
  v14 = 0;
  requests.m_data.m_data = 0;
  v17 = 8 * v5;
  requests.m_data.m_size = v4 + v3 + 24 * v5;
  arena_size = v4;
  callback.vtable = (boost::detail::function::vtable_base *)vostok::sound::sound_scene::on_unmanaged_resources_allocated;
  (&callback.vtable)[1] = 0;
  callback.functor.obj_ptr = parent;
  on_out_of_memory.vtable = (boost::detail::function::vtable_base *)vostok::sound::sound_scene::on_unmanaged_resources_allocated;
  (&on_out_of_memory.vtable)[1] = 0;
  *(_QWORD *)&on_out_of_memory.functor.obj_ptr = __PAIR64__(
                                                   (unsigned int)callback.functor.vostok_pointer_size_alignment[1],
                                                   (unsigned int)parent);
  v16 = v3;
  requests.m_name = "unmanaged_sound_resources_allocation";
  requests.m_id = unmanaged_allocation_class;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    callback.vtable = 0;
  }
  else
  {
    *(_QWORD *)&callback.functor.obj_ptr = *(_QWORD *)&on_out_of_memory.vtable;
    *((_QWORD *)&callback.functor.data + 1) = *(_QWORD *)&on_out_of_memory.functor.obj_ptr;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_create_resources_and_wait(&requests, 1u, vostok::sound::g_allocator, 0, parenta);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)&callback);
  if ( parent == (vostok::resources::query_result_for_cook *)-328 )
  {
    v8 = arena_size;
  }
  else
  {
    m_pending_tasks_count = parent->m_pending_tasks_count;
    on_out_of_memory.vtable = 0;
    v14 = 1;
    v8 = arena_size;
    vostok::memory::single_size_buffer_allocator<144,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<144,vostok::threading::multi_threading_policy>(
      &on_out_of_memory,
      (vostok::memory::single_size_buffer_allocator<144,vostok::threading::multi_threading_policy> *)&parent->m_out_of_memory.size,
      (vostok::memory::single_size_buffer_allocator<144,vostok::threading::multi_threading_policy>::node *)(m_pending_tasks_count + 268),
      arena_size);
  }
  _InterlockedExchange((volatile __int32 *)&parent->m_request_path_default_storage[40], 1);
  if ( (v14 & 1) != 0 )
  {
    v14 &= ~1u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&parent->m_request_path_default_storage[40],
      (int *)&on_out_of_memory);
  }
  if ( parent != (vostok::resources::query_result_for_cook *)-408 )
  {
    v9 = parent->m_pending_tasks_count;
    on_out_of_memory.vtable = 0;
    v14 |= 2u;
    vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>(
      (const boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &)> *)&on_out_of_memory,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)&parent->m_request_path_default_storage[60],
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *)(v9 + v8 + 268),
      v16);
  }
  _InterlockedExchange((volatile __int32 *)&parent->m_request_path_default_storage[112], 1);
  if ( (v14 & 2) != 0 )
  {
    v14 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&parent->m_request_path_default_storage[112],
      (int *)&on_out_of_memory);
  }
  v10 = v16 + v8;
  if ( parent != (vostok::resources::query_result_for_cook *)-480 )
  {
    v11 = parent->m_pending_tasks_count;
    on_out_of_memory.vtable = 0;
    v14 |= 4u;
    vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>(
      (const boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> const &)> *)&on_out_of_memory,
      (vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> *)&parent->m_request_path_default_storage[132],
      (vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *)(v11 + v10 + 268),
      v17);
  }
  v12 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&parent->m_request_path_default_storage[184];
  _InterlockedExchange((volatile __int32 *)&parent->m_request_path_default_storage[184], 1);
  if ( (v14 & 4) != 0 )
  {
    v14 &= ~4u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v12,
      (int *)&on_out_of_memory);
  }
  if ( parent != (vostok::resources::query_result_for_cook *)-544 )
  {
    v13 = parent->m_pending_tasks_count;
    on_out_of_memory.vtable = 0;
    v14 |= 8u;
    vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>(
      (const boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &)> *)&on_out_of_memory,
      (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)&parent->m_request_path_default_storage[196],
      (vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *)(v10 + v13 + v17 + 268),
      16 * v5);
  }
  _InterlockedExchange((volatile __int32 *)&parent->m_request_path_default_storage[248], 1);
  if ( (v14 & 8) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v12,
      (int *)&on_out_of_memory);
}
