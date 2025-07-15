void __cdecl survarium::setup_damage_model_from_profile(
        survarium::damage_model *damage_model,
        const survarium::player_profile *profile,
        const survarium::items_dictionary *dict)
{
  vostok::configs::binary_config_value *m_root; // esi
  vostok::configs::binary_config_value *v4; // ecx
  char **pointer; // ebx
  const vostok::configs::binary_config_value *v6; // eax
  survarium::damage_model *v7; // ecx
  int v8; // esi
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm1_4
  vostok::configs::binary_config_value *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  char **v16; // esi
  const vostok::configs::binary_config_value *v17; // eax
  vostok::configs::binary_config_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  survarium::hit_type_parameters *k; // eax
  survarium::hit_type_parameters *v21; // esi
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  float v26; // xmm0_4
  char *v27; // [esp-4h] [ebp-2Ch]
  int v28; // [esp+Ch] [ebp-1Ch]
  float v29; // [esp+10h] [ebp-18h]
  float v30; // [esp+14h] [ebp-14h]
  vostok::configs::binary_config_value *v31; // [esp+18h] [ebp-10h]
  survarium::body_part_parameters *body_part; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  unsigned int j; // [esp+24h] [ebp-4h]

  for ( i = 0; i < 7; ++i )
  {
    if ( profile->slots[clothes_slots[i]].id )
    {
      m_root = survarium::items_dictionary::item_by_id(
                 dict,
                 (survarium::items_dictionary_vtbl *)profile->slots[clothes_slots[i]].dict_id)->item_cfg.m_object->m_root;
      if ( vostok::configs::binary_config_value::value_exists(v4, (int)m_root, (unsigned int)"hit_params") )
      {
        pointer = (char **)vostok::configs::binary_config_value::operator[](m_root, "hit_params")->data.pointer;
        v6 = vostok::configs::binary_config_value::operator[](m_root, "hit_params");
        v8 = (int)v6->data.pointer + 24 * v6->count;
        v28 = v8;
        while ( pointer != (char **)v8 )
        {
          body_part = survarium::damage_model::get_body_part(v7, (int)damage_model, pointer[2]);
          if ( vostok::configs::binary_config_value::value_exists(v9, (int)pointer, (unsigned int)"health") )
          {
            v11 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)pointer,
                    "health");
            if ( v11->type == 2 )
              v12 = *(float *)&v11->data.pointer;
            else
              v12 = (float)(int)v11->data.pointer;
          }
          else
          {
            v12 = 0.0;
          }
          v29 = body_part->m_max_health + v12;
          if ( vostok::configs::binary_config_value::value_exists(v10, (int)pointer, (unsigned int)"regeneration_speed") )
          {
            v14 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)pointer,
                    "regeneration_speed");
            if ( v14->type == 2 )
              v15 = *(float *)&v14->data.pointer;
            else
              v15 = (float)(int)v14->data.pointer;
          }
          else
          {
            v15 = 0.0;
          }
          body_part->m_max_health = v29;
          body_part->m_regeneration_speed = body_part->m_regeneration_speed + v15;
          if ( vostok::configs::binary_config_value::value_exists(v13, (int)pointer, (unsigned int)"hit_types") )
          {
            for ( j = 0; j < 8; ++j )
            {
              v16 = (char **)&hit_type_names_93[j];
              v27 = *v16;
              v17 = vostok::configs::binary_config_value::operator[](
                      (vostok::configs::binary_config_value *)pointer,
                      "hit_types");
              if ( vostok::configs::binary_config_value::value_exists(v18, (int)v17, (unsigned int)v27) )
              {
                v19 = vostok::configs::binary_config_value::operator[](
                        (vostok::configs::binary_config_value *)pointer,
                        "hit_types");
                v31 = vostok::configs::binary_config_value::operator[](v19, *v16);
                for ( k = body_part->m_hit_types.m_first; ; k = k->next )
                {
                  if ( !k )
                  {
                    v21 = 0;
                    goto LABEL_23;
                  }
                  if ( k->m_type == j )
                    break;
                }
                v21 = k;
LABEL_23:
                v22 = vostok::configs::binary_config_value::operator[](v31, "armor");
                if ( v22->type == 2 )
                  v23 = *(float *)&v22->data.pointer;
                else
                  v23 = (float)(int)v22->data.pointer;
                v30 = v23;
                v24 = vostok::configs::binary_config_value::operator[](v31, "reduce");
                if ( v24->type == 2 )
                  v25 = *(float *)&v24->data.pointer;
                else
                  v25 = (float)(int)v24->data.pointer;
                v26 = v25 + v21->m_reduce;
                v21->m_armor = v21->m_armor + v30;
                v21->m_reduce = v26;
              }
            }
            v8 = v28;
          }
          pointer += 6;
        }
      }
    }
  }
}
