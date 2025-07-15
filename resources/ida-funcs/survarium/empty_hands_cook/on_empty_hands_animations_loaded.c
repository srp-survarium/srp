void __thiscall survarium::empty_hands_cook::on_empty_hands_animations_loaded(
        survarium::empty_hands_cook *this,
        survarium::pure_game_effect_emitter_base *data)
{
  vostok::resources::resource_link *m_last; // edi
  vostok::resources::unmanaged_resource *v3; // ecx
  char *v4; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v5; // esi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  char *v7; // eax
  vostok::math::float4x4 *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_uid; // ebx
  survarium::pure_game_effect_emitter_base *v10; // edi
  survarium::pure_game_effect_emitter_base *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v13[4]; // [esp-4h] [ebp-30h] BYREF
  unsigned int v14; // [esp+Ch] [ebp-20h]
  vostok::resources::memory_usage_type v15; // [esp+10h] [ebp-1Ch] BYREF
  vostok::resources::resource_link *v16; // [esp+18h] [ebp-14h]
  vostok::resources::resource_link *v17; // [esp+1Ch] [ebp-10h]
  vostok::resources::resource_link **p_m_last; // [esp+20h] [ebp-Ch]
  int v19; // [esp+24h] [ebp-8h]

  v19 = 0;
  m_last = data->m_children_resources.m_last;
  v16 = m_last;
  v14 = 4 * (_DWORD)m_last + 360;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)this,
         (int)survarium::g_allocator,
         v14,
         "empty_hands",
         (const char *const)v13[1].m_object,
         (const char *const)v13[2].m_object,
         (const unsigned int)v13[3].m_object);
  if ( m_last )
  {
    v5 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(v4 + 360);
    p_m_last = &data->m_parent_resources.m_last;
    v17 = m_last;
    do
    {
      if ( v5 )
      {
        v19 |= 1u;
        managed_resource = vostok::resources::query_result_for_user::get_managed_resource(
                             (vostok::resources::query_result_for_user *)p_m_last,
                             (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v15.size);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
          v5,
          managed_resource->m_object);
        m_last = v16;
      }
      if ( (v19 & 1) != 0 )
      {
        v19 &= ~1u;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v15.size);
      }
      p_m_last += 184;
      ++v5;
      v17 = (vostok::resources::resource_link *)((char *)v17 - 1);
    }
    while ( v17 );
  }
  v7 = 0;
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 0;
    v4[13] = 0;
    v13[0].m_object = (survarium::pure_game_effect_emitter_base *)1;
    *(_DWORD *)v4 = &survarium::interactive_object::`vftable';
    v4[12] = -1;
    v4[14] = 1;
    vostok::resources::unmanaged_resource::unmanaged_resource(
      v3,
      (_DWORD *)v4 + 4,
      (vostok::resources::class_id_enum)v13[0].m_object);
    *((_DWORD *)v4 + 86) = 0;
    *((_DWORD *)v4 + 87) = v4 + 360;
    *(_DWORD *)v4 = &survarium::empty_hands::`vftable'{for `survarium::interactive_object'};
    *((_DWORD *)v4 + 4) = &survarium::empty_hands::`vftable'{for `vostok::resources::unmanaged_resource'};
    *((_DWORD *)v4 + 88) = m_last;
    *((_DWORD *)v4 + 89) = 0;
    vostok::math::float4x4::identity(v8, (vostok::math::float4x4 *)(v4 + 280));
    v7 = v4;
  }
  m_uid = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_uid;
  if ( v7 )
    v10 = (survarium::pure_game_effect_emitter_base *)(v7 + 16);
  else
    v10 = 0;
  v13[0].m_object = data;
  v15.type = &vostok::resources::nocache_memory;
  v15.size = v14;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    v13,
    v10);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(&v15, v11, m_uid, v13[0]);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v12,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_uid,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
