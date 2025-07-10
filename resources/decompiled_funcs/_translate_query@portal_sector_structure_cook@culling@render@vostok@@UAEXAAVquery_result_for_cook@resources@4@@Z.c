void __thiscall vostok::render::culling::portal_sector_structure_cook::translate_query(
        vostok::render::culling::portal_sector_structure_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char v2; // al
  vostok::resources::query_result_for_cook *v3; // ecx
  vostok::configs::binary_config *m_object; // ebx
  unsigned int v5; // esi
  int v6; // edi
  int *v7; // ecx
  vostok::render::culling::portal_sector_structure *v8; // eax
  vostok::render::culling::portal_sector_structure *v9; // esi
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-Ch] [ebp-34h] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-30h]
  unsigned int v13; // [esp-4h] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> game_progect_cfg_ptr; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::configs::binary_config_value portal_system_cfg; // [esp+10h] [ebp-18h] BYREF

  game_progect_cfg_ptr.m_object = 0;
  v2 = vostok::variant<32>::try_get<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
         (vostok::variant<32> *)&game_progect_cfg_ptr,
         (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)parent->m_user_data,
         &game_progect_cfg_ptr);
  m_object = game_progect_cfg_ptr.m_object;
  if ( v2 && vostok::configs::binary_config_value::value_exists(game_progect_cfg_ptr.m_object->m_root, "portal_system") )
  {
    portal_system_cfg = *vostok::configs::binary_config_value::operator[](m_object->m_root, "portal_system");
    v5 = 24 * vostok::configs::binary_config_value::operator[](&portal_system_cfg, "sectors")->count / 24;
    v6 = 24 * vostok::configs::binary_config_value::operator[](&portal_system_cfg, "portals")->count / 24;
    v7 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x138u);
    if ( v7 )
    {
      vostok::render::culling::portal_sector_structure::portal_sector_structure(
        (vostok::render::culling::portal_sector_structure *)v7,
        v5,
        (vostok::memory::base_allocator *)v6);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    vostok::render::culling::portal_sector_structure::load(&portal_system_cfg, v9);
    v13 = 312;
    v12 = &vostok::resources::nocache_memory;
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      (vostok::configs::binary_config *)v9);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v11.m_object,
      v12,
      v13);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v10,
      (int)parent,
      result_success,
      assert_on_fail_true,
      0);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v3,
      (int)parent,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
    if ( !m_object )
      return;
  }
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
}
