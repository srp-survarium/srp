void __cdecl add_bone(
        const vostok::animation::skeleton_bone *parent,
        vostok::animation::skeleton_bone *bones_begin,
        unsigned int index,
        unsigned int *last_index,
        vostok::configs::binary_config_value **config,
        const char **bones_ids_buffer,
        unsigned int *bones_ids_buffer_size)
{
  vostok::configs::binary_config_value *v7; // ecx
  const vostok::configs::binary_config_value *v8; // edi
  char *v9; // eax
  _WORD *v10; // edx
  unsigned int v11; // edi
  unsigned __int8 *v12; // eax
  vostok::animation::skeleton_bone *v13; // esi
  const vostok::configs::binary_config_value *v14; // ecx
  vostok::animation::skeleton_bone *v15; // edx
  vostok::animation::skeleton_bone *v16; // eax
  const vostok::configs::binary_config_value *v17; // edx
  unsigned int v18; // edi
  const vostok::configs::binary_config_value *pointer; // eax
  const vostok::configs::binary_config_value *v20; // edx
  unsigned __int16 type; // cx
  const vostok::configs::binary_config_value *i; // [esp+4h] [ebp-24h] BYREF
  vostok::animation::skeleton_bone *v23; // [esp+8h] [ebp-20h]
  const vostok::configs::binary_config_value *e; // [esp+Ch] [ebp-1Ch]
  vostok::configs::binary_config_value value; // [esp+10h] [ebp-18h] BYREF

  v7 = *config;
  value = **config;
  v8 = 0;
  v9 = (char *)value.data.pointer + 24 * HIWORD(*(_DWORD *)&value.type);
  i = 0;
  if ( value.data.pointer != v9 )
  {
    v10 = (char *)value.data.pointer + 20;
    do
    {
      if ( *v10 == 3 || *v10 == 4 )
        v8 = (const vostok::configs::binary_config_value *)((char *)v8 + 1);
      v10 += 12;
    }
    while ( v10 - 10 != (_WORD *)v9 );
    i = v8;
  }
  v11 = strlen((const char *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7->id))
      + 1;
  v12 = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*config)->id);
  memcpy((unsigned __int8 *)*bones_ids_buffer, v12, v11);
  v13 = &bones_begin[index];
  if ( v13 )
  {
    if ( vostok::configs::binary_config_value::value_exists(&value, "mask") )
      e = (const vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&value, "mask")->data.pointer;
    else
      e = (const vostok::configs::binary_config_value *)-1;
    v14 = i;
    if ( i )
    {
      v15 = &bones_begin[(unsigned int)i + *last_index];
      v23 = &bones_begin[*last_index];
      v14 = i;
    }
    else
    {
      v15 = 0;
      v23 = 0;
    }
    v13->m_id = *bones_ids_buffer;
    v13->m_parent = parent;
    v16 = v23;
    v13->m_children_end = v15;
    v17 = e;
    v13->m_children_begin = v16;
    v13->m_mask = (unsigned int)v17;
  }
  else
  {
    v14 = i;
  }
  *bones_ids_buffer += v11;
  *bones_ids_buffer_size -= v11;
  if ( v14 )
  {
    v18 = *last_index;
    *last_index += (unsigned int)v14;
    pointer = (const vostok::configs::binary_config_value *)value.data.pointer;
    v20 = (const vostok::configs::binary_config_value *)((char *)value.data.pointer + 24 * value.count);
    i = (const vostok::configs::binary_config_value *)value.data.pointer;
    e = v20;
    if ( value.data.pointer != v20 )
    {
      do
      {
        type = pointer->type;
        if ( type == 3 || type == 4 )
        {
          add_bone(v13, bones_begin, v18, last_index, &i, (char **)bones_ids_buffer, bones_ids_buffer_size);
          pointer = i;
          v20 = e;
          ++v18;
        }
        i = ++pointer;
      }
      while ( pointer != v20 );
    }
  }
}
