char __thiscall vostok::resources::device_manager::pre_allocate(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        vostok::fs_new::asynchronous_device_interface *a3)
{
  int v4; // eax
  boost::function<void __cdecl(bool)> *v6; // ecx
  boost::function<bool __cdecl(vostok::fs_new::synchronous_device_interface &)> *v7; // ecx
  vostok::fs_new::query_custom_operation_args *v8; // ecx
  vostok::resources::query_result *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::resources::device_manager,vostok::resources::query_result *,vostok::fs_new::synchronous_device_interface const &>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1> > > v12; // [esp-54h] [ebp-D4h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v13; // [esp-44h] [ebp-C4h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v14; // [esp-24h] [ebp-A4h] BYREF
  vostok::threading::event *p_m_resources_wakeup_event; // [esp-4h] [ebp-84h]
  vostok::fs_new::query_custom_operation_args args; // [esp+10h] [ebp-70h] BYREF
  boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1> > v17; // [esp+60h] [ebp-20h]
  vostok::fs_new::asynchronous_device_interface *v18; // [esp+68h] [ebp-18h]
  void (__thiscall *v19)(vostok::resources::device_manager *, vostok::resources::query_result *, bool); // [esp+6Ch] [ebp-14h]
  vostok::resources::query_result *v20; // [esp+70h] [ebp-10h]
  vostok::fs_new::asynchronous_device_interface *v21; // [esp+74h] [ebp-Ch]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+78h] [ebp-8h]
  vostok::resources::device_manager *v23; // [esp+7Ch] [ebp-4h]
  vostok::fs_new::asynchronous_device_interface *m_hdd; // [esp+8Ch] [ebp+Ch]

  if ( (*(_DWORD *)&a3[3].m_high_priority_queries.m_forward_queue.m_static_memory[16] & 2) != 0 )
  {
    v4 = *(_DWORD *)&a3[3].m_queries.m_forward_queue.m_static_memory[52];
    this = *(vostok::resources::device_manager **)&a3[3].m_queries.m_forward_queue.m_static_memory[56];
    v23 = this;
    if ( !v4
      && !*(_DWORD *)&a3[3].m_queries.m_forward_queue.m_static_memory[48]
      && !vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
            (vostok::resources::query_result *)this,
            (int)a3) )
    {
      *(_DWORD *)&a3[3].m_queries.m_forward_queue.m_static_memory[24] = 0;
      ++query->m_quality_levels_count;
      if ( LODWORD(query->m_target_satisfaction) )
        *(_DWORD *)(LODWORD(query->m_last_fail_of_increasing_quality) + 624) = a3;
      else
        LODWORD(query->m_target_satisfaction) = a3;
      LODWORD(query->m_last_fail_of_increasing_quality) = a3;
      return 0;
    }
  }
  if ( *(_DWORD *)&a3[1].m_queries.m_forward_queue.m_static_memory[56] == 7 )
    return 0;
  lpCriticalSection = (LPCRITICAL_SECTION)&query->vostok::resources::resource_reconstruction_info;
  vostok::threading::mutex::lock(
    (vostok::threading::mutex *)this,
    (_RTL_CRITICAL_SECTION *)&query->vostok::resources::resource_reconstruction_info);
  p_m_resources_wakeup_event = &s_resources_manager_buffer.m_resources_wakeup_event;
  m_hdd = s_resources_manager_buffer.m_hdd;
  v20 = query;
  v17.a2_.t_ = query;
  v19 = vostok::resources::device_manager::on_query_processed;
  v21 = a3;
  v13.functor.vostok_pointer_size_alignment[3] = vostok::resources::device_manager::on_query_processed;
  v13.functor.bound_memfunc_ptr.obj_ptr = query;
  v13.functor.vostok_pointer_size_alignment[2] = &v14;
  v17.a1_.t_ = (vostok::resources::device_manager *)vostok::resources::device_manager::process_query;
  v18 = a3;
  boost::function<void __cdecl (bool)>::function<void __cdecl (bool)>(
    v6,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1> > > *)(&v13.functor.data + 8),
    (int)a3);
  v12.l_ = v17;
  v12.f_.f_ = (bool (__thiscall *)(vostok::resources::device_manager *, vostok::resources::query_result *, const vostok::fs_new::synchronous_device_interface *))&v13;
  boost::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>(
    v7,
    v12,
    (int)v18);
  vostok::fs_new::query_custom_operation_args::query_custom_operation_args(
    v8,
    (int)&args,
    v13,
    v14,
    p_m_resources_wakeup_event);
  if ( (*(_DWORD *)&a3[3].m_high_priority_queries.m_forward_queue.m_static_memory[16] & 2) != 0 )
    query->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags += vostok::resources::query_result::raw_buffer_size(v9, (vostok::resources::query_result *)a3);
  vostok::fs_new::asynchronous_device_interface::query_custom_operation(
    &vostok::memory::g_resources_helper_allocator,
    m_hdd,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&args);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&args.callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&args);
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}
