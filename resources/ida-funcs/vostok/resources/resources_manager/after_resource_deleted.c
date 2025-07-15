void __userpurge vostok::resources::resources_manager::after_resource_deleted(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::cook_base *cook@<eax>,
        bool was_delay_delete,
        vostok::resources::query_result *const destruction_observer,
        const vostok::resources::memory_usage_type *memory_usage,
        vostok::resources::class_id_enum class_id,
        const char *request_name)
{
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *v7; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+8h] [ebp-20h] BYREF

  if ( was_delay_delete )
    _InterlockedExchangeAdd((volatile signed __int32 *)((char *)&dword_20380 + (_DWORD)this), 0xFFFFFFFF);
  if ( cook )
    _InterlockedExchangeAdd(&cook->m_cook_users_count.m_count, 0xFFFFFFFF);
  if ( destruction_observer )
    _InterlockedExchangeAdd(&destruction_observer->m_observed_resource_destructions_left, 0xFFFFFFFF);
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&s_resource_freed_callback,
    &f);
  if ( (f.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::function2<void,enum vostok::network_core::client_error_codes_enum,boost::system::error_code>::operator()(
      v7,
      &f,
      destruction_observer,
      memory_usage,
      class_id);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
    (int *)&f);
}
