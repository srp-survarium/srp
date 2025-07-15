void __userpurge vostok::resources::resources_manager::after_resource_deleted(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::cook_base *cook@<eax>,
        vostok::resources::query_result *const destruction_observer@<edi>,
        bool was_delay_delete,
        const vostok::resources::memory_usage_type *memory_usage,
        vostok::resources::class_id_enum class_id,
        const char *request_name)
{
  boost::detail::function::vtable_base *vtable; // eax
  int v8; // ecx
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> callback; // [esp+8h] [ebp-20h] BYREF

  if ( was_delay_delete )
    _InterlockedExchangeAdd((volatile signed __int32 *)((char *)&off_20378 + (_DWORD)this), 0xFFFFFFFF);
  if ( cook )
    _InterlockedExchangeAdd(&cook->m_cook_users_count.m_count, 0xFFFFFFFF);
  if ( destruction_observer )
    _InterlockedExchangeAdd(&destruction_observer->m_observed_resource_destructions_left, 0xFFFFFFFF);
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&s_resource_freed_callback,
    (int)&callback);
  vtable = callback.vtable;
  v8 = -(callback.vtable != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v8) != 0 )
  {
    boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::operator()(
      (boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *)v8,
      &callback,
      destruction_observer,
      memory_usage,
      class_id);
    vtable = callback.vtable;
  }
  if ( vtable && ((unsigned __int8)vtable & 1) == 0 )
  {
    v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((unsigned int)vtable & 0xFFFFFFFE);
    if ( v9 )
      v9(&callback.functor, &callback.functor, 2);
  }
}
