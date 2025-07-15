char __usercall survarium::load_quest_descriptor@<al>(
        survarium::quest_descriptor *quest@<esi>,
        vostok::configs::binary_config_value v)
{
  vostok::configs::binary_config_value *v2; // eax
  vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  float pointer; // xmm0_4
  unsigned int v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  unsigned int *v15; // eax
  unsigned int v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  const vostok::configs::binary_config_value *v20; // eax
  _DWORD *v21; // ecx
  vostok::configs::binary_config_value *v22; // eax
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // ecx
  vostok::configs::binary_config_value *v27; // eax
  vostok::configs::binary_config_value *v28; // eax
  vostok::configs::binary_config_value *v29; // eax
  const vostok::configs::binary_config_value *v30; // eax
  int v31; // ecx
  const char **v32; // eax
  unsigned __int8 v33; // dl
  const char *v34; // ebx
  vostok::configs::binary_config_value *v35; // eax
  unsigned int v37; // [esp+8h] [ebp-Ch]
  unsigned int v38; // [esp+8h] [ebp-Ch]
  const char **v39; // [esp+8h] [ebp-Ch]
  int v40; // [esp+Ch] [ebp-8h]
  unsigned int *p_param; // [esp+Ch] [ebp-8h]
  unsigned int *p_X_param; // [esp+10h] [ebp-4h]
  int v43; // [esp+10h] [ebp-4h]

  quest->id = (unsigned int)vostok::configs::binary_config_value::operator[](&v, "id")->data.pointer;
  quest->type = (survarium::quest_type_enum)vostok::configs::binary_config_value::operator[](&v, "type")->data.pointer;
  quest->is_daily = vostok::configs::binary_config_value::operator[](&v, "daily")->data.pointer != 0;
  quest->faction = (survarium::factions_enum)vostok::configs::binary_config_value::operator[](&v, "faction")->data.pointer;
  quest->faction_representative = (survarium::factions_enum)vostok::configs::binary_config_value::operator[](
                                                              &v,
                                                              "faction_representative")->data.pointer;
  quest->priority = (int)vostok::configs::binary_config_value::operator[](&v, "priority")->data.pointer;
  quest->ttl_minutes = (unsigned int)vostok::configs::binary_config_value::operator[](&v, "ttl_minutes")->data.pointer;
  v2 = vostok::configs::binary_config_value::operator[](&v, "params");
  quest->max_games_count = (unsigned int)vostok::configs::binary_config_value::operator[](v2, "max_games_count")->data.pointer;
  v3 = vostok::configs::binary_config_value::operator[](&v, "params");
  quest->N_param = (unsigned int)vostok::configs::binary_config_value::operator[](v3, "n")->data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](&v, "params");
  quest->X_param = (unsigned int)vostok::configs::binary_config_value::operator[](v4, "x")->data.pointer;
  v5 = vostok::configs::binary_config_value::operator[](&v, "params");
  v6 = vostok::configs::binary_config_value::operator[](v5, "y");
  if ( v6->type == 2 )
    pointer = *(float *)&v6->data.pointer;
  else
    pointer = (float)(int)v6->data.pointer;
  quest->Y_param = pointer;
  v8 = 24 * vostok::configs::binary_config_value::operator[](&v, "preconditions")->count / 24;
  v37 = 0;
  quest->preconditions_count = v8;
  if ( v8 )
  {
    v40 = 0;
    p_X_param = &quest->preconditions[0].X_param;
    do
    {
      v9 = vostok::configs::binary_config_value::operator[](&v, "preconditions");
      p_X_param[2] = (unsigned int)vostok::configs::binary_config_value::operator[](
                                     (vostok::configs::binary_config_value *)((char *)v9->data.pointer + v40),
                                     "type")->data.pointer;
      v10 = vostok::configs::binary_config_value::operator[](&v, "preconditions");
      *(p_X_param - 1) = (unsigned int)vostok::configs::binary_config_value::operator[](
                                         (vostok::configs::binary_config_value *)((char *)v10->data.pointer + v40),
                                         "n")->data.pointer;
      v11 = vostok::configs::binary_config_value::operator[](&v, "preconditions");
      *p_X_param = (unsigned int)vostok::configs::binary_config_value::operator[](
                                   (vostok::configs::binary_config_value *)((char *)v11->data.pointer + v40),
                                   "x")->data.pointer;
      v12 = vostok::configs::binary_config_value::operator[](&v, "preconditions");
      v13 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)((char *)v12->data.pointer + v40),
              "y");
      if ( v13->type == 2 )
        v14 = *(float *)&v13->data.pointer;
      else
        v14 = (float)(int)v13->data.pointer;
      v15 = p_X_param;
      ++v37;
      p_X_param += 4;
      v40 += 24;
      *((float *)v15 + 1) = v14;
    }
    while ( v37 < quest->preconditions_count );
  }
  v16 = 24 * vostok::configs::binary_config_value::operator[](&v, "awards")->count / 24;
  v38 = 0;
  quest->awards_count = v16;
  if ( v16 )
  {
    v43 = 0;
    p_param = &quest->awards[0].param;
    do
    {
      v17 = vostok::configs::binary_config_value::operator[](&v, "awards");
      p_param[1] = (unsigned int)vostok::configs::binary_config_value::operator[](
                                   (vostok::configs::binary_config_value *)((char *)v17->data.pointer + v43),
                                   "type")->data.pointer;
      v18 = vostok::configs::binary_config_value::operator[](&v, "awards");
      *(p_param - 1) = (unsigned int)vostok::configs::binary_config_value::operator[](
                                       (vostok::configs::binary_config_value *)((char *)v18->data.pointer + v43),
                                       "amount")->data.pointer;
      v19 = vostok::configs::binary_config_value::operator[](&v, "awards");
      v20 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)((char *)v19->data.pointer + v43),
              "param");
      v21 = p_param;
      ++v38;
      p_param += 3;
      v43 += 24;
      *v21 = v20->data.pointer;
    }
    while ( v38 < quest->awards_count );
  }
  v22 = vostok::configs::binary_config_value::operator[](&v, "ui");
  quest->name = (const char *)vostok::configs::binary_config_value::operator[](v22, "name")->data.pointer;
  v23 = vostok::configs::binary_config_value::operator[](&v, "ui");
  quest->description = (const char *)vostok::configs::binary_config_value::operator[](v23, "description")->data.pointer;
  v24 = vostok::configs::binary_config_value::operator[](&v, "ui");
  quest->icon = (unsigned __int8)vostok::configs::binary_config_value::operator[](v24, "icon")->data.pointer;
  v25 = vostok::configs::binary_config_value::operator[](&v, "ui");
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)v25, (unsigned int)"task_descriptions") )
  {
    v27 = vostok::configs::binary_config_value::operator[](&v, "ui");
    quest->task_descriptions_count = 24
                                   * vostok::configs::binary_config_value::operator[](v27, "task_descriptions")->count
                                   / 24;
    v28 = vostok::configs::binary_config_value::operator[](&v, "ui");
    v39 = (const char **)vostok::configs::binary_config_value::operator[](v28, "task_descriptions")->data.pointer;
    v29 = vostok::configs::binary_config_value::operator[](&v, "ui");
    v30 = vostok::configs::binary_config_value::operator[](v29, "task_descriptions");
    v31 = (int)v30->data.pointer + 24 * v30->count;
    v32 = v39;
    v33 = 0;
    while ( v32 != (const char **)v31 )
    {
      v34 = *v32;
      v32 += 6;
      quest->task_descriptions[v33++] = v34;
    }
  }
  else
  {
    quest->task_descriptions_count = 1;
    v35 = vostok::configs::binary_config_value::operator[](&v, "ui");
    quest->task_descriptions[0] = (const char *)vostok::configs::binary_config_value::operator[](
                                                  v35,
                                                  "task_description")->data.pointer;
  }
  return 1;
}
