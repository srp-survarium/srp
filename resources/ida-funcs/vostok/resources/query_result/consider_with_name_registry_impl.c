int __userpurge vostok::resources::query_result::consider_with_name_registry_impl@<eax>(
        const char *name@<eax>,
        vostok::resources::query_result *this,
        vostok::resources::query_result::only_try_to_get_associated_resource_bool only_try_to_get_associated_resource)
{
  vostok::resources::resources_manager *m_variable; // edi
  vostok::resources::class_id_enum m_class_id; // eax
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *v5; // ecx
  vostok::resources::query_result *v6; // ecx
  vostok::resources::resource_base **p_associated; // esi
  vostok::resources::resource_base *associated; // eax
  vostok::configs::binary_config *v10; // edx
  unsigned int v11; // eax
  const char *requested_path; // eax
  vostok::resources::resource_base *v13; // eax
  const vostok::resources::memory_usage_type *p_m_memory_usage_self; // esi
  vostok::resources::managed_resource *v15; // eax
  vostok::resources::query_result *v16; // [esp-8h] [ebp-30h]
  vostok::configs::binary_config *v17; // [esp-8h] [ebp-30h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-2Ch] BYREF
  bool do_debug_break; // [esp+Fh] [ebp-19h] BYREF
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *name_registry; // [esp+10h] [ebp-18h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+14h] [ebp-14h] BYREF
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator it; // [esp+1Ch] [ebp-Ch] BYREF

  m_variable = vostok::resources::g_resources_manager.m_variable;
  this->m_name_registry_entry.name = name;
  m_class_id = this->m_class_id;
  this->m_name_registry_entry.associated = this;
  this->m_name_registry_entry.class_id = m_class_id;
  do_debug_break = only_try_to_get_associated_resource == only_try_to_get_associated_resource_true;
  name_registry = &m_variable->m_name_registry;
  raii.m_lock = (const vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable];
  vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable]);
  raii.m_locked = 1;
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::find(
    v5,
    (int)&it,
    &m_variable->m_name_registry,
    &this->m_name_registry_entry);
  if ( !it.m_value )
  {
    if ( !do_debug_break )
    {
      vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::insert(
        name_registry,
        &this->m_name_registry_entry);
      vostok::threading::interlocked_or(&this->m_flags, (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
      LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
      return 3;
    }
    goto $LN197_1;
  }
  p_associated = &it.m_value->associated;
  associated = it.m_value->associated;
  if ( (associated->m_flags.m_flags & 2) == 0 || !associated )
  {
    v13 = *p_associated;
    if ( ((*p_associated)->m_flags.m_flags & 4) != 0 && v13 )
    {
      v17 = (vostok::configs::binary_config *)*p_associated;
      p_m_memory_usage_self = &v13->m_memory_usage_self;
      v18.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v18,
        v17);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        p_m_memory_usage_self,
        this,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v18.m_object);
    }
    else
    {
      v15 = (vostok::resources::managed_resource *)*p_associated;
      if ( ((*p_associated)->m_flags.m_flags & 1) == 0 || !v15 )
      {
        this->m_error_type = error_type_name_registry_error;
        goto $LN197_1;
      }
      vostok::resources::query_result_for_cook::set_managed_resource(this, v15);
    }
    vostok::threading::interlocked_or(&this->m_flags, 0x40000u);
    LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
    return 4;
  }
  if ( associated == this )
  {
$LN197_1:
    LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
    return 1;
  }
  if ( debug_macro_helper_ignore_always_17
    || (v6 = (vostok::resources::query_result *)associated->m_class_id,
        v10 = (vostok::configs::binary_config *)this->m_class_id,
        v6 == (vostok::resources::query_result *)v10) )
  {
    vostok::resources::query_result::add_referrer(this, v6, (vostok::resources::query_result *)associated, 1);
    LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
    return 2;
  }
  else
  {
    v11 = occurances_left_17;
    if ( occurances_left_17 == -1 )
      v11 = 10;
    occurances_left_17 = v11 - 1;
    if ( v11 )
    {
      v18.m_object = v10;
      v16 = v6;
      do_debug_break = 0;
      requested_path = vostok::resources::query_result_for_user::get_requested_path(this);
      vostok::debug::on_error(
        (unsigned int)this,
        &do_debug_break,
        process_error_false,
        &debug_macro_helper_ignore_always_17,
        assert_untyped,
        "assertion_failed",
        "active_query->get_class_id() == m_class_id",
        ".\\resources_query_result_cache.cpp",
        "vostok::resources::query_result::consider_with_name_registry_impl",
        0xFEu,
        "active_query associated with path '%s' has different class id: '%d', self class id: '%d'",
        requested_path,
        v16,
        v18.m_object);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v6,
      (int)&raii);
    return 0;
  }
}
