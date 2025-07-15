void __thiscall survarium::lobby_menu::fill_character_data(
        survarium::lobby_menu *this,
        survarium::flash_value *player_characteristics_value)
{
  survarium::lobby_client *v3; // eax
  survarium::flash_movie *v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  survarium::player_params_modifiers_container *v8; // ecx
  survarium::lobby_menu *v9; // ecx
  survarium::lobby_menu *v10; // ecx
  survarium::player_skill *m_player_skills; // eax
  unsigned __int8 *p_skill_id; // edi
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  vostok::configs::binary_config_value *v17; // esi
  bool v18; // cf
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *v20; // esi
  const vostok::configs::binary_config_value *v21; // eax
  vostok::configs::binary_config_value *v22; // esi
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  survarium::lobby_menu *v25; // ecx
  survarium::lobby_client *v26; // eax
  survarium::lobby_menu *v27; // ecx
  survarium::flash_value *v28; // ecx
  survarium::flash_value *v29; // ecx
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  survarium::flash_value *v32; // ecx
  unsigned int v33; // eax
  survarium::flash_value *v34; // ecx
  unsigned int v35; // eax
  survarium::flash_value *v36; // ecx
  survarium::flash_value *v37; // ecx
  survarium::flash_value *v38; // ecx
  survarium::lobby_menu *v39; // ecx
  survarium::lobby_menu *v40; // ecx
  survarium::lobby_client *v41; // eax
  survarium::flash_value *v42; // ecx
  survarium::lobby_menu *v43; // ecx
  survarium::lobby_client *v44; // eax
  survarium::lobby_menu *v45; // ecx
  survarium::lobby_client *v46; // eax
  survarium::flash_value *v47; // ecx
  survarium::flash_value *v48; // [esp-8h] [ebp-4DCh]
  survarium::flash_value *v49; // [esp-8h] [ebp-4DCh]
  survarium::flash_value *v50; // [esp-4h] [ebp-4D8h]
  float v51[20]; // [esp+10h] [ebp-4C4h] BYREF
  char v52[960]; // [esp+60h] [ebp-474h] BYREF
  char v53[16]; // [esp+420h] [ebp-B4h] BYREF
  char _Dest[16]; // [esp+430h] [ebp-A4h] BYREF
  Scaleform::GFx::Value pargs; // [esp+440h] [ebp-94h] BYREF
  survarium::flash_value value; // [esp+458h] [ebp-7Ch] BYREF
  Scaleform::GFx::Value v57; // [esp+470h] [ebp-64h] BYREF
  vostok::configs::binary_config_value *v58; // [esp+488h] [ebp-4Ch]
  int v59; // [esp+48Ch] [ebp-48h]
  int v60; // [esp+490h] [ebp-44h]
  Scaleform::GFx::Value v61; // [esp+494h] [ebp-40h] BYREF
  unsigned __int8 *v62; // [esp+4ACh] [ebp-28h]
  Scaleform::GFx::Value pvalue; // [esp+4B0h] [ebp-24h] BYREF
  vostok::configs::binary_config_value *pointer; // [esp+4C8h] [ebp-Ch]
  unsigned __int8 v65; // [esp+4CEh] [ebp-6h]
  unsigned __int8 v66; // [esp+4CFh] [ebp-5h]
  unsigned __int8 player_characteristics_value_3b; // [esp+4DFh] [ebp+Bh]
  unsigned __int8 player_characteristics_value_3; // [esp+4DFh] [ebp+Bh]
  unsigned __int8 player_characteristics_value_3a; // [esp+4DFh] [ebp+Bh]
  unsigned __int8 player_characteristics_value_3c; // [esp+4DFh] [ebp+Bh]

  player_characteristics_value_3b = player_characteristics_value[66].body[20];
  v3 = survarium::lobby_menu::lobby_client(this, (int)player_characteristics_value);
  v4 = (survarium::flash_movie *)(1512 * player_characteristics_value_3b);
  v5 = (int)&v4[22] + (_DWORD)v3;
  v6 = *(_DWORD *)&player_characteristics_value[66].body[16];
  v61.pObjectInterface = 0;
  v61.Type = VT_Undefined;
  v48 = *(survarium::flash_value **)(v6 + 264);
  v59 = v5;
  survarium::flash_movie::CreateObject(v4, v48, &v61);
  v7 = *(_DWORD *)&player_characteristics_value[66].body[16];
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v7 + 264) + 4), &pvalue);
  v65 = 0;
  survarium::player_params_modifiers_container::player_params_modifiers_container(v8, (char *)v51);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  player_characteristics_value_3 = 0;
  if ( survarium::lobby_menu::lobby_client(v9, (int)player_characteristics_value)->m_player_skills_count )
  {
    do
    {
      m_player_skills = survarium::lobby_menu::lobby_client(v10, (int)player_characteristics_value)->m_player_skills;
      v57.pObjectInterface = 0;
      v57.Type = VT_Undefined;
      p_skill_id = &m_player_skills[player_characteristics_value_3].skill_id;
      v49 = *(survarium::flash_value **)(*(_DWORD *)&player_characteristics_value[66].body[16] + 264);
      v62 = p_skill_id;
      survarium::flash_movie::CreateObject((survarium::flash_movie *)player_characteristics_value_3, v49, &v57);
      survarium::flash_value::SetUInt(v13, (int)&value, *p_skill_id);
      survarium::flash_value::SetMember(v14, &v57, "id", &value);
      survarium::flash_value::SetUInt(v15, (int)&value, p_skill_id[1]);
      survarium::flash_value::SetMember(v16, &v57, "points", &value);
      pvalue.pObjectInterface->SetElement(
        pvalue.pObjectInterface,
        (void *)pvalue.mValue.IValue,
        player_characteristics_value_3,
        &v57);
      v65 += p_skill_id[1];
      v17 = *(vostok::configs::binary_config_value **)(*(_DWORD *)&player_characteristics_value[71].body[16] + 264);
      sprintf_s<16>((char (*)[16])_Dest, "skill_%d", *p_skill_id);
      v58 = vostok::configs::binary_config_value::operator[](v17, _Dest);
      v18 = v62[1] == 0;
      v66 = 1;
      if ( !v18 )
      {
        do
        {
          sprintf_s<16>((char (*)[16])v53, "skill_level_%d", v66);
          v19 = vostok::configs::binary_config_value::operator[](v58, "levels");
          v20 = vostok::configs::binary_config_value::operator[](v19, v53);
          pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              v20,
                                                              "boosters")->data.pointer;
          v21 = vostok::configs::binary_config_value::operator[](v20, "boosters");
          v22 = (vostok::configs::binary_config_value *)((char *)v21->data.pointer + 24 * v21->count);
          while ( pointer != v22 )
          {
            v60 = LOBYTE(vostok::configs::binary_config_value::operator[](pointer, "id")->data.max_storage) - 1;
            v23 = vostok::configs::binary_config_value::operator[](pointer, "value");
            if ( v23->type == 2 )
              v24 = *(float *)&v23->data.pointer;
            else
              v24 = (float)(int)v23->data.pointer;
            ++pointer;
            v51[v60] = v51[v60] + v24;
          }
          ++v66;
        }
        while ( v66 <= v62[1] );
      }
      Scaleform::GFx::Value::~Value(&v57);
      ++player_characteristics_value_3;
      v26 = survarium::lobby_menu::lobby_client(v25, (int)player_characteristics_value);
      LOBYTE(v10) = player_characteristics_value_3;
    }
    while ( player_characteristics_value_3 < v26->m_player_skills_count );
    v5 = v59;
  }
  survarium::flash_value::SetMember((survarium::flash_value *)v10, &v61, "trees", (survarium::flash_value *)&pvalue);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::lobby_menu::create_player_params(v27, player_characteristics_value, &pargs, (int)v51);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[66].body[16] + 264) + 4),
    "root.set_char_stats",
    0,
    &pargs,
    1u);
  v50 = (survarium::flash_value *)(*(unsigned __int8 *)(v5 + 1507) - v65);
  survarium::flash_value::SetUInt(v50, (int)&pvalue, (unsigned int)v50);
  survarium::flash_value::SetMember(v28, &v61, "points_available", (survarium::flash_value *)&pvalue);
  survarium::flash_value::SetUInt(v29, (int)&pvalue, *(unsigned __int8 *)(v5 + 1507));
  survarium::flash_value::SetMember(v30, &v61, "points_unlocked", (survarium::flash_value *)&pvalue);
  survarium::flash_value::SetUInt(v31, (int)&pvalue, *(_DWORD *)(v5 + 1488) - *(_DWORD *)(v5 + 1496));
  survarium::flash_value::SetMember(v32, &v61, "experience_current", (survarium::flash_value *)&pvalue);
  v33 = *(_DWORD *)(v5 + 1492);
  v34 = *(survarium::flash_value **)(v5 + 1496);
  if ( v33 < (unsigned int)v34 )
    v35 = 0;
  else
    v35 = v33 - (_DWORD)v34;
  survarium::flash_value::SetUInt(v34, (int)&pvalue, v35);
  survarium::flash_value::SetMember(v36, &v61, "experience_next_level", (survarium::flash_value *)&pvalue);
  survarium::flash_value::SetUInt(v37, (int)&pvalue, *(unsigned __int16 *)(v5 + 1504));
  survarium::flash_value::SetMember(v38, &v61, "experience_delta", (survarium::flash_value *)&pvalue);
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[66].body[16] + 264) + 4),
    &pvalue);
  player_characteristics_value_3a = 0;
  if ( survarium::lobby_menu::lobby_client(v39, (int)player_characteristics_value)->m_player_perks_count )
  {
    do
    {
      v57.pObjectInterface = 0;
      v57.Type = VT_Undefined;
      v41 = survarium::lobby_menu::lobby_client(v40, (int)player_characteristics_value);
      survarium::flash_value::SetUInt(v42, (int)&v57, v41->m_player_perks[player_characteristics_value_3a]);
      pvalue.pObjectInterface->SetElement(
        pvalue.pObjectInterface,
        (void *)pvalue.mValue.IValue,
        player_characteristics_value_3a,
        &v57);
      Scaleform::GFx::Value::~Value(&v57);
      ++player_characteristics_value_3a;
      v44 = survarium::lobby_menu::lobby_client(v43, (int)player_characteristics_value);
      LOBYTE(v40) = player_characteristics_value_3a;
    }
    while ( player_characteristics_value_3a < v44->m_player_perks_count );
  }
  survarium::flash_value::SetMember((survarium::flash_value *)v40, &v61, "perks", (survarium::flash_value *)&pvalue);
  player_characteristics_value_3c = player_characteristics_value[66].body[20];
  v46 = survarium::lobby_menu::lobby_client(v45, (int)player_characteristics_value);
  survarium::flash_value::SetString(
    (survarium::flash_value *)&pvalue,
    v46->m_profiles[player_characteristics_value_3c].profile_name);
  survarium::flash_value::SetMember(v47, &v61, "nickname", (survarium::flash_value *)&pvalue);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[66].body[16] + 264) + 4),
    "root.fill_char_info",
    0,
    &v61,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  `vector destructor iterator'(
    v52,
    0x30u,
    20,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  Scaleform::GFx::Value::~Value(&pvalue);
  Scaleform::GFx::Value::~Value(&v61);
}
