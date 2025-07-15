vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *__cdecl vostok::render::merge_effect_options(
        vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> *result,
        const vostok::render::custom_config_value *effect_config,
        vostok::render::effect_options_descriptor *desc,
        unsigned int *out_crc)
{
  int num_fields; // edi
  unsigned int v5; // edi
  void *v6; // esp
  _QWORD *v7; // ecx
  _QWORD *v8; // eax
  vostok::render::custom_config *m_object; // esi
  vostok::render::grass_render_model *v10; // ecx
  _QWORD v12[2]; // [esp+0h] [ebp-20h] BYREF
  const vostok::render::custom_config_value *values; // [esp+10h] [ebp-10h] BYREF
  const vostok::render::custom_config_value *values2; // [esp+14h] [ebp-Ch] BYREF
  unsigned int crc; // [esp+18h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> C; // [esp+1Ch] [ebp-4h] BYREF

  crc = 0;
  vostok::render::create_custom_config_impl_vostok::render::effect_options_descriptor__0(desc, (unsigned int *)&C, &crc);
  num_fields = vostok::render::get_num_fields(&C.m_object->m_root);
  v5 = vostok::render::get_num_fields(effect_config) + num_fields;
  v6 = alloca(100 * v5);
  values = (const vostok::render::custom_config_value *)v12;
  v7 = v12;
  if ( v5 )
  {
    crc = v5;
    do
    {
      v8 = v7;
      v7 = (_QWORD *)((char *)v7 + 20);
      if ( v8 )
      {
        v5 = 0;
        *(_DWORD *)v8 = 0;
        *((_DWORD *)v8 + 1) = 0;
        *((_DWORD *)v8 + 2) = 0;
        *((_WORD *)v8 + 6) = 0;
        *((_WORD *)v8 + 7) = 0;
        *((_DWORD *)v8 + 4) = 0;
      }
      --crc;
    }
    while ( crc );
  }
  v12[0] = *(_QWORD *)&effect_config->id;
  v12[1] = *(_QWORD *)&effect_config->id_crc;
  values = (const vostok::render::custom_config_value *)effect_config->destroyer;
  values2 = (const vostok::render::custom_config_value *)&values2;
  vostok::render::merge_configs(
    (const char *)effect_config,
    (const char *)v5,
    &values,
    &values2,
    effect_config,
    &C.m_object->m_root);
  vostok::render::create_custom_config_impl_vostok::render::custom_config_value__0(
    (const vostok::render::custom_config_value *)v12,
    &result->m_object,
    out_crc);
  m_object = C.m_object;
  if ( C.m_object && !_InterlockedExchangeAdd(&C.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( m_object->call_destructors )
      vostok::render::custom_config_value::call_data_destructor(&m_object->m_root);
    if ( m_object->own_buffer )
    {
      v10 = vostok::render::g_allocator.m_object;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(v10->m_reconstruction_info_actuality_tick), m_object);
    }
  }
  return result;
}
