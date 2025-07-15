int __usercall vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::inplace_unmanaged_cook *inplace_unmanaged_cook; // edi
  int v4; // ebx
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::mutable_buffer *v9; // eax
  unsigned int raw_file_size; // eax
  char *m_data; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v13; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v14; // [esp+10h] [ebp-30h] BYREF
  vostok::mutable_buffer v15; // [esp+30h] [ebp-10h] BYREF
  char v16; // [esp+38h] [ebp-8h] BYREF
  DWORD CurrentThreadId; // [esp+3Ch] [ebp-4h]

  inplace_unmanaged_cook = vostok::resources::cook_base::find_inplace_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v4 = 0;
  if ( !inplace_unmanaged_cook )
    return 0;
  CurrentThreadId = GetCurrentThreadId();
  if ( vostok::resources::query_result::allocate_thread_id(v6, a2) != CurrentThreadId
    || vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(v7, a2) )
  {
    return 0;
  }
  _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFFEFFFF);
  if ( vostok::resources::query_result::need_create_resource_if_no_file(
         (vostok::resources::query_result *)0xFFFEFFFF,
         (_DWORD *)a2) )
  {
    v9 = inplace_unmanaged_cook->allocate_resource(
           inplace_unmanaged_cook,
           (vostok::mutable_buffer *)&v16,
           (vostok::resources::query_result_for_cook *)a2,
           0,
           (unsigned int *)(a2 + 688),
           0);
  }
  else
  {
    raw_file_size = vostok::resources::query_result_for_cook::get_raw_file_size(v8, (_DWORD *)a2);
    *(_DWORD *)(a2 + 688) = 0;
    v9 = inplace_unmanaged_cook->allocate_resource(
           inplace_unmanaged_cook,
           &v15,
           (vostok::resources::query_result_for_cook *)a2,
           raw_file_size,
           (unsigned int *)(a2 + 688),
           1);
  }
  m_data = v9->m_data;
  *(_DWORD *)(a2 + 652) = v9->m_data;
  *(_DWORD *)(a2 + 656) = v9->m_size;
  if ( m_data || ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a2 + 704)) != 0 )
    return 1;
  *(_DWORD *)(a2 + 320) = 3;
  *(_DWORD *)(a2 + 256) = 7;
  vostok::resources::get_out_of_memory_callback(&v14);
  v12 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v13;
  if ( (v14.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      v13,
      &v14,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
    v4 = 2;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v12,
    (int *)&v14);
  return v4;
}
