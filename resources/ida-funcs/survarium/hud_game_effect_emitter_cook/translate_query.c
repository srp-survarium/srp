void __thiscall survarium::hud_game_effect_emitter_cook::translate_query(
        survarium::hud_game_effect_emitter_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::query_result_for_cook *v2; // ecx
  const vostok::configs::binary_config_value *v3; // edi
  int v4; // eax
  int v5; // ebx
  char *v6; // eax
  unsigned int size; // ecx
  vostok::configs::binary_config_value *v8; // esi
  const vostok::configs::binary_config_value *v9; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  char *v13; // eax
  unsigned int *v14; // eax
  unsigned int v15; // ebx
  survarium::pure_game_effect_emitter_base *v16; // esi
  survarium::pure_game_effect_emitter_base *v17; // ecx
  char v18; // al
  survarium::pure_game_effect_emitter_base *v19; // ecx
  vostok::resources::query_result_for_cook *v20; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21[4]; // [esp-4h] [ebp-38h] BYREF
  unsigned int v22; // [esp+Ch] [ebp-28h]
  vostok::resources::memory_usage_type v23; // [esp+10h] [ebp-24h] BYREF
  const vostok::configs::binary_config_value *v24; // [esp+18h] [ebp-1Ch]
  int v25; // [esp+1Ch] [ebp-18h]
  float v26; // [esp+20h] [ebp-14h]
  const vostok::configs::binary_config_value *v27; // [esp+24h] [ebp-10h] BYREF
  int v28; // [esp+28h] [ebp-Ch]
  char *v29; // [esp+2Ch] [ebp-8h]
  char v30; // [esp+33h] [ebp-1h]

  if ( vostok::variant<32>::try_get<vostok::configs::binary_config_value const *>(
         (vostok::variant<32> *)this,
         (int)parent[66].m_object,
         &v27) )
  {
    v3 = vostok::configs::binary_config_value::operator[](v27, "key_frames");
    v4 = 24 * v3->count / 24;
    v24 = v3;
    v5 = v4;
    v22 = 8 * v4 + 288;
    v6 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)0x18,
           (int)survarium::g_allocator,
           v22,
           "hud_game_effect_emitter",
           (const char *const)v21[1].m_object,
           (const char *const)v21[2].m_object,
           (const unsigned int)v21[3].m_object);
    size = (unsigned int)v6;
    v23.size = (unsigned int)v6;
    if ( v5 )
    {
      v28 = 0;
      v29 = v6;
      v25 = v5;
      do
      {
        v8 = (vostok::configs::binary_config_value *)((char *)v3->data.pointer + v28);
        if ( v29 )
        {
          v9 = vostok::configs::binary_config_value::operator[](v8, "frame");
          if ( v9->type == 2 )
            pointer = *(float *)&v9->data.pointer;
          else
            pointer = (float)(int)v9->data.pointer;
          v26 = pointer;
          v11 = vostok::configs::binary_config_value::operator[](v8, "time");
          if ( v11->type == 2 )
            v12 = *(float *)&v11->data.pointer;
          else
            v12 = (float)(int)v11->data.pointer;
          v13 = v29;
          v3 = v24;
          size = v23.size;
          *(float *)v29 = v26;
          *((float *)v13 + 1) = v12;
        }
        v28 += 24;
        v29 += 8;
        --v25;
      }
      while ( v25 );
    }
    v14 = (unsigned int *)(size + 8 * v5);
    if ( v14 )
    {
      v14[1] = v5;
      *v14 = size;
      v15 = size + 8 * v5;
    }
    else
    {
      v15 = 0;
    }
    v23.size = (unsigned int)vostok::configs::binary_config_value::operator[](v27, "hud_effect_type")->data.pointer;
    v16 = (survarium::pure_game_effect_emitter_base *)(v15 + 8);
    v30 = (char)vostok::configs::binary_config_value::operator[](v27, "priority")->data.pointer;
    if ( v15 == -8 )
    {
      v16 = 0;
    }
    else
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v17, (_DWORD *)(v15 + 8), fs_iterator_class);
      *(_DWORD *)(v15 + 272) = v23.size;
      v18 = v30;
      v16->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&survarium::hud_game_effect_emitter::`vftable';
      *(_BYTE *)(v15 + 276) = v18;
      *(_DWORD *)(v15 + 280) = v15;
    }
    v21[0].m_object = v17;
    v23.type = &vostok::resources::nocache_memory;
    v23.size = v22;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      v21,
      v16);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(&v23, v19, parent, v21[0]);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v20,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v2,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
