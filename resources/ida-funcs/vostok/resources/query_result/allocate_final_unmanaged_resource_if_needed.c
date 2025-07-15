vostok::resources::allocation_result_enum __usercall vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::allocation_result_enum result; // eax
  vostok::const_buffer *v4; // eax
  const char *m_data; // ecx
  unsigned int m_size; // eax
  int v7; // edi
  bool resource_if_no_file; // al
  int *v9; // eax
  int v10; // edx
  int v11; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v12; // ecx
  vostok::resources::query_result *v13; // ecx
  vostok::resources::query_result *v14; // [esp-4h] [ebp-5Ch]
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v15; // [esp-4h] [ebp-5Ch]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v16; // [esp+10h] [ebp-48h] BYREF
  _BYTE v17[8]; // [esp+34h] [ebp-24h] BYREF
  const char *v18; // [esp+3Ch] [ebp-1Ch] BYREF
  _DWORD v19[2]; // [esp+44h] [ebp-14h] BYREF
  vostok::const_buffer pinned_raw_buffer; // [esp+4Ch] [ebp-Ch] BYREF
  int *v21; // [esp+54h] [ebp-4h]

  result = (vostok::resources::allocation_result_enum)vostok::resources::cook_base::find_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v21 = (int *)result;
  if ( result )
  {
    if ( vostok::resources::query_result::need_create_resource_if_no_file(v14, (_DWORD *)a2) )
    {
      v19[0] = 0;
      v19[1] = 0;
      v4 = (vostok::const_buffer *)v19;
    }
    else
    {
      v4 = vostok::resources::query_result::pin_raw_buffer((vostok::resources::query_result *)a2, &v18);
    }
    m_data = v4->m_data;
    m_size = v4->m_size;
    pinned_raw_buffer.m_data = m_data;
    pinned_raw_buffer.m_size = m_size;
    _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFFFEFFFF);
    v7 = *v21;
    resource_if_no_file = vostok::resources::query_result::need_create_resource_if_no_file(
                            (vostok::resources::query_result *)(a2 + 704),
                            (_DWORD *)a2);
    v9 = (int *)(*(int (__thiscall **)(int *, _BYTE *, int, const char *, unsigned int, bool))(v7 + 32))(
                  v21,
                  v17,
                  a2,
                  pinned_raw_buffer.m_data,
                  pinned_raw_buffer.m_size,
                  !resource_if_no_file);
    v10 = *v9;
    *(_DWORD *)(a2 + 660) = *v9;
    v11 = 0;
    *(_DWORD *)(a2 + 664) = v9[1];
    if ( v10 || ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a2 + 704)) != 0 )
    {
      if ( !vostok::resources::query_result::need_create_resource_if_no_file(
              (vostok::resources::query_result *)(a2 + 660),
              (_DWORD *)a2) )
        vostok::resources::query_result::unpin_raw_buffer(v13, &pinned_raw_buffer);
      return 1;
    }
    else
    {
      *(_DWORD *)(a2 + 320) = 4;
      *(_DWORD *)(a2 + 256) = 7;
      vostok::resources::get_out_of_memory_callback(&v16);
      v12 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v15;
      if ( (v16.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      {
        boost::function1<void,vostok::collision::object const &>::operator()(
          v15,
          &v16,
          (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
        v11 = 2;
      }
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v12,
        (int *)&v16);
      return v11;
    }
  }
  return result;
}
