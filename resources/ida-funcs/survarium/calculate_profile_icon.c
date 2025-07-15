unsigned __int8 __cdecl survarium::calculate_profile_icon(
        const survarium::player_profile *profile,
        const survarium::items_dictionary *dictionary)
{
  vostok::configs::binary_config_value *m_root; // ebx
  vostok::configs::binary_config_value *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // ebx
  const vostok::configs::binary_config_value *v6; // edi
  int v7; // eax
  char *v8; // ecx
  unsigned __int8 v9; // cl
  vostok::configs::binary_config_value *v10; // ebx
  vostok::configs::binary_config_value *v11; // ecx
  const vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // ebx
  const vostok::configs::binary_config_value *v14; // edi
  int v15; // eax
  char *v16; // ecx
  unsigned __int8 v17; // cl
  unsigned __int8 v19; // [esp+13h] [ebp-1Dh]
  unsigned __int8 v20; // [esp+13h] [ebp-1Dh]
  char v21; // [esp+14h] [ebp-1Ch] BYREF
  __int16 v22; // [esp+15h] [ebp-1Bh]
  vostok::configs::binary_config_value *pointer; // [esp+18h] [ebp-18h]
  const survarium::profile_slot_enum *v24; // [esp+1Ch] [ebp-14h]
  int v25; // [esp+20h] [ebp-10h]
  int v26; // [esp+24h] [ebp-Ch]
  int max_storage_low; // [esp+28h] [ebp-8h]
  int v28; // [esp+2Ch] [ebp-4h]

  v26 = 0;
  v21 = 0;
  v19 = 0;
  v22 = 0;
  v24 = weapon_slots_3;
  v25 = 2;
  do
  {
    if ( profile->slots[*v24].dict_id )
    {
      m_root = survarium::items_dictionary::item_by_id(
                 dictionary,
                 (survarium::items_dictionary_vtbl *)profile->slots[*v24].dict_id)->item_cfg.m_object->m_root;
      if ( vostok::configs::binary_config_value::value_exists(v3, (int)m_root, (unsigned int)"item_affinities") )
      {
        pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            m_root,
                                                            "item_affinities")->data.pointer;
        v4 = vostok::configs::binary_config_value::operator[](m_root, "item_affinities");
        v5 = (vostok::configs::binary_config_value *)((char *)v4->data.pointer + 24 * v4->count);
        while ( pointer != v5 )
        {
          max_storage_low = LOBYTE(vostok::configs::binary_config_value::operator[](pointer, "affinity_type")->data.max_storage);
          v6 = vostok::configs::binary_config_value::operator[](pointer, "affinity_value");
          v7 = max_storage_low;
          v8 = &v21 + max_storage_low;
          *v8 += LOBYTE(v6->data.pointer);
          v9 = *v8;
          if ( v9 > v19 )
          {
            v19 = v9;
            v26 = v7;
          }
          ++pointer;
        }
      }
    }
    ++v24;
    --v25;
  }
  while ( v25 );
  max_storage_low = 0;
  v21 = 0;
  v20 = 0;
  v22 = 0;
  v24 = clothes_slots_1;
  v25 = 7;
  do
  {
    if ( profile->slots[*v24].dict_id )
    {
      v10 = survarium::items_dictionary::item_by_id(
              dictionary,
              (survarium::items_dictionary_vtbl *)profile->slots[*v24].dict_id)->item_cfg.m_object->m_root;
      if ( vostok::configs::binary_config_value::value_exists(v11, (int)v10, (unsigned int)"item_affinities") )
      {
        pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                            v10,
                                                            "item_affinities")->data.pointer;
        v12 = vostok::configs::binary_config_value::operator[](v10, "item_affinities");
        v13 = (vostok::configs::binary_config_value *)((char *)v12->data.pointer + 24 * v12->count);
        while ( pointer != v13 )
        {
          v28 = LOBYTE(vostok::configs::binary_config_value::operator[](pointer, "affinity_type")->data.max_storage);
          v14 = vostok::configs::binary_config_value::operator[](pointer, "affinity_value");
          v15 = v28;
          v16 = &v21 + v28;
          *v16 += LOBYTE(v14->data.pointer);
          v17 = *v16;
          if ( v17 > v20 )
          {
            v20 = v17;
            max_storage_low = v15;
          }
          ++pointer;
        }
      }
    }
    ++v24;
    --v25;
  }
  while ( v25 );
  return survarium::player_icons_array[v26][max_storage_low];
}
