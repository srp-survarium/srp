void __cdecl add_bone(
        const vostok::animation::skeleton_bone *parent,
        vostok::configs::binary_config_value *bones_begin,
        unsigned int index,
        unsigned int *last_index,
        const vostok::configs::binary_config_value *const *config,
        char **bones_ids_buffer,
        unsigned int *bones_ids_buffer_size)
{
  _DWORD *v7; // edx
  const vostok::configs::binary_config_value *pointer; // esi
  const vostok::configs::binary_config_value *v9; // ecx
  char *v10; // edx
  unsigned int v11; // edi
  const vostok::animation::skeleton_bone *v12; // esi
  unsigned int *v13; // edx
  const vostok::animation::skeleton_bone *v14; // ecx
  const vostok::animation::skeleton_bone *v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  int v18; // edi
  const vostok::configs::binary_config_value *v19; // edi
  unsigned int *v20; // edx
  unsigned int v21; // ecx
  char *v22; // [esp-Ch] [ebp-3Ch]
  const vostok::configs::binary_config_value *configa; // [esp+Ch] [ebp-24h] BYREF
  int v24; // [esp+10h] [ebp-20h]
  unsigned int v25; // [esp+14h] [ebp-1Ch]
  vostok::configs::binary_config_value v26; // [esp+18h] [ebp-18h] BYREF

  v7 = *config;
  configa = 0;
  qmemcpy((void *)&v26, v7, sizeof(v26));
  pointer = (const vostok::configs::binary_config_value *)v26.data.pointer;
  v9 = (const vostok::configs::binary_config_value *)((char *)v26.data.pointer + 24 * HIWORD(*(_DWORD *)&v26.type));
  while ( pointer != v9 )
  {
    if ( is_table(pointer) )
      configa = (const vostok::configs::binary_config_value *)((char *)configa + 1);
    ++pointer;
  }
  v10 = (char *)v7[2];
  v11 = strlen(v10) + 1;
  v22 = *bones_ids_buffer;
  v25 = v11;
  memcpy((unsigned __int8 *)v22, (unsigned __int8 *)v10, v11);
  v12 = (const vostok::animation::skeleton_bone *)((char *)bones_begin + 28 * index);
  if ( v12 )
  {
    if ( vostok::configs::binary_config_value::value_exists(bones_begin, (int)&v26, (unsigned int)"mask") )
      v24 = (int)vostok::configs::binary_config_value::operator[](&v26, "mask")->data.pointer;
    else
      v24 = -1;
    v13 = last_index;
    v14 = 0;
    if ( configa )
      v15 = (const vostok::animation::skeleton_bone *)((char *)bones_begin + 28 * ((_DWORD)configa + *last_index));
    else
      v15 = 0;
    if ( configa )
      v14 = (const vostok::animation::skeleton_bone *)((char *)bones_begin + 28 * *last_index);
    v12->m_id = *bones_ids_buffer;
    v12->m_children_end = v15;
    v16 = v24;
    v12->m_parent = parent;
    v11 = v25;
    v12->m_children_begin = v14;
    v12->m_mask = v16;
    v12->m_calc_mask = 1;
  }
  else
  {
    v13 = last_index;
  }
  *bones_ids_buffer += v11;
  *bones_ids_buffer_size -= v11;
  if ( configa )
  {
    v17 = *v13;
    v18 = 24 * v26.count;
    *v13 += (unsigned int)configa;
    v19 = (const vostok::configs::binary_config_value *)((char *)v26.data.pointer + v18);
    v24 = v17;
    for ( configa = (const vostok::configs::binary_config_value *)v26.data.pointer; configa != v19; ++configa )
    {
      if ( is_table(configa) )
      {
        add_bone(v12, bones_begin, v21, v20, &configa, bones_ids_buffer, bones_ids_buffer_size);
        ++v24;
      }
    }
  }
}
