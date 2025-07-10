void __thiscall survarium::player_cook::on_hit_params_loaded(
        survarium::player_cook *this,
        vostok::resources::unmanaged_resource *data,
        survarium::player_creation_params *params)
{
  vostok::resources::query_result_for_cook *m_uid; // ebp
  vostok::resources::unmanaged_resource *v4; // edi
  vostok::resources::unmanaged_resource *v5; // ebx
  survarium::player_creation_params *v6; // esi
  vostok::resources::unmanaged_resource *v7; // eax
  survarium::damage_model *v8; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  survarium::player *v10; // ecx
  survarium::player_creation_params *v11; // ecx
  int v12; // eax
  int v13; // edi
  int f; // ebx
  survarium::player_creation_params *v15; // eax
  void *v16; // esi
  vostok::resources::query_result_for_cook *v17; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp-Ch] [ebp-20h] BYREF
  assert_on_fail_bool v19; // [esp-8h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-18h]
  int v21; // [esp+10h] [ebp-4h]

  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  v4 = 0;
  p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
  v21 = 0;
  data = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
  v5 = data;
  if ( data )
  {
    v4 = data;
    _InterlockedExchangeAdd(&data->m_reference_count, 1u);
  }
  v6 = params;
  v7 = 0;
  if ( v4 )
  {
    v7 = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  v8 = (survarium::damage_model *)v7;
  m_object = v6->damage_model.m_object;
  v6->damage_model.m_object = v8;
  if ( m_object )
  {
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v5 = data;
  }
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         (unsigned int)&unk_10F88)
    && (survarium::player::player(v10, v6), (v13 = v12) != 0) )
  {
    f = (int)survarium::g_allocator.f_.f_;
    if ( v6 )
    {
      survarium::player_creation_params::~player_creation_params(v11, (vostok::resources::unmanaged_resource **)v6);
      v15 = v6;
      v16 = *(void **)(f + 20);
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(v16, v15);
    }
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&unk_10F88;
    v19 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v18.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v18,
      (vostok::configs::binary_config *)(v13 + 288));
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      m_uid,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v18.m_object,
      (const vostok::resources::memory_type *)v19,
      (unsigned int)p_m_children_resources);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v17,
      result_success,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    p_m_children_resources = 0;
    v19 = assert_on_fail_true;
    v18.m_object = (vostok::configs::binary_config *)5;
    m_uid->m_out_of_memory.type = &vostok::resources::unmanaged_memory;
    m_uid->m_out_of_memory.size = (unsigned int)&unk_10F88;
    vostok::resources::query_result_for_cook::finish_query_impl(
      &unk_10F88,
      (vostok::resources::cook_base::result_enum)v18.m_object,
      v19,
      (vostok::resources::query_result_for_user::error_type_enum)p_m_children_resources);
  }
}
