void __thiscall survarium::lobby_menu::player_parameters_ready(
        survarium::lobby_menu *this,
        vostok::resources::queries_result *data,
        survarium::player_parameters_cooker_data *cook_data)
{
  vostok::configs::binary_config *v3; // ebx
  malloc_state *v5; // esi
  vostok::configs::binary_config *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  survarium::flash_value *v8; // eax
  int i; // ecx
  int m_thread_id_low; // esi
  int v11; // esi
  float v12; // esi
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // ecx
  char *v16; // esi
  int j; // edi
  int v18; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+1Ch] [ebp-3Ch] BYREF
  float v20; // [esp+20h] [ebp-38h]
  survarium::flash_value args[2]; // [esp+24h] [ebp-34h] BYREF
  char v22; // [esp+54h] [ebp-4h] BYREF

  v3 = 0;
  v20 = *(float *)&this;
  if ( cook_data )
  {
    v5 = *(malloc_state **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v5, (char *)cook_data);
  }
  v19.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v19,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v19.m_object;
  if ( v19.m_object )
  {
    v7 = &v19.m_object->vostok::resources::unmanaged_intrusive_base;
    v3 = v19.m_object;
    _InterlockedExchangeAdd(&v19.m_object->m_reference_count, 1u);
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, m_object);
  }
  v8 = args;
  this->m_player_total_items_weight = *((float *)&v3[1].m_reconstruction_info_actuality_tick + 1);
  for ( i = 1; i >= 0; --i )
  {
    if ( v8 )
    {
      *(_DWORD *)v8->body = 0;
      *(_DWORD *)&v8->body[4] = 0;
    }
    ++v8;
  }
  m_thread_id_low = LOBYTE(v3[1].m_parent_resources.m_thread_id);
  if ( (args[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  *(_DWORD *)&args[0].body[4] = 4;
  *(_DWORD *)&args[0].body[8] = m_thread_id_low;
  v11 = BYTE1(v3[1].m_parent_resources.m_thread_id);
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  *(_DWORD *)&args[1].body[8] = v11;
  v12 = v20;
  v13 = *(_DWORD *)(LODWORD(v20) + 212);
  *(_DWORD *)&args[1].body[4] = 4;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v13 + 264) + 4),
    "root.player_profile.updateSlots",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v20 = *((float *)&v3[1].m_reconstruction_info_actuality_tick + 1);
  if ( (args[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[0].body + 8))(
      *(_DWORD *)args[0].body,
      args,
      *(_DWORD *)&args[0].body[8]);
    *(_DWORD *)args[0].body = 0;
  }
  *(double *)&args[0].body[8] = v20;
  v14 = *(float *)(LODWORD(v12) + 252);
  *(_DWORD *)&args[0].body[4] = 5;
  v20 = v14;
  if ( (args[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args[1].body + 8))(
      *(_DWORD *)args[1].body,
      &args[1],
      *(_DWORD *)&args[1].body[8]);
    *(_DWORD *)args[1].body = 0;
  }
  v15 = *(_DWORD *)(LODWORD(v12) + 212);
  *(_DWORD *)&args[1].body[4] = 5;
  *(double *)&args[1].body[8] = v20;
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v15 + 264) + 4),
    "root.player_profile.updateWeight",
    0,
    (const Scaleform::GFx::Value *)args,
    2u);
  v16 = &v22;
  for ( j = 1; j >= 0; --j )
  {
    v18 = *((_DWORD *)v16 - 5);
    v16 -= 24;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v16 + 8))(v16, *((_DWORD *)v16 + 2));
      *(_DWORD *)v16 = 0;
    }
    *((_DWORD *)v16 + 1) = 0;
  }
  if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
}
