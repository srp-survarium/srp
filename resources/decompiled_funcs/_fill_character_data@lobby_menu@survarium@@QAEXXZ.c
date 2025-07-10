void __usercall survarium::lobby_menu::fill_character_data(survarium::lobby_menu *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  unsigned __int8 *v7; // edi
  int v8; // ebx
  int v9; // ebx
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  unsigned int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // edi
  int v17; // edi
  unsigned __int8 j; // bl
  int v19; // ecx
  unsigned __int8 i; // [esp+EAh] [ebp-66h]
  unsigned __int8 total_points_in_tree; // [esp+EBh] [ebp-65h]
  unsigned __int8 total_points_in_treea; // [esp+EBh] [ebp-65h]
  survarium::flash_value player_skills_value_prop; // [esp+ECh] [ebp-64h] BYREF
  survarium::flash_value player_skills_value; // [esp+104h] [ebp-4Ch] BYREF
  survarium::flash_value skill_value_prop; // [esp+11Ch] [ebp-34h] BYREF
  survarium::flash_value perk_value; // [esp+134h] [ebp-1Ch] BYREF

  v2 = a2[53];
  *(_DWORD *)player_skills_value.body = 0;
  *(_DWORD *)&player_skills_value.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v2 + 264) + 4),
    (Scaleform::GFx::Value *)&player_skills_value,
    0,
    0,
    0);
  v3 = a2[53];
  *(_DWORD *)player_skills_value_prop.body = 0;
  *(_DWORD *)&player_skills_value_prop.body[4] = 0;
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4),
    (Scaleform::GFx::Value *)&player_skills_value_prop);
  v4 = a2[42];
  *(_DWORD *)skill_value_prop.body = 0;
  *(_DWORD *)&skill_value_prop.body[4] = 0;
  total_points_in_tree = 0;
  i = 0;
  if ( *(_BYTE *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v4 + 952) + 60))(*(_DWORD *)(v4 + 952)) + 1948) )
  {
    do
    {
      v5 = *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952))
                     + 1944);
      v6 = a2[53];
      v7 = (unsigned __int8 *)(v5 + 2 * i);
      *(_DWORD *)perk_value.body = 0;
      *(_DWORD *)&perk_value.body[4] = 0;
      Scaleform::GFx::Movie::CreateObject(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(v6 + 264) + 4),
        (Scaleform::GFx::Value *)&perk_value,
        0,
        0,
        0);
      v8 = *v7;
      if ( (skill_value_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)skill_value_prop.body + 8))(
          *(_DWORD *)skill_value_prop.body,
          &skill_value_prop,
          *(_DWORD *)&skill_value_prop.body[8]);
        *(_DWORD *)skill_value_prop.body = 0;
      }
      *(_DWORD *)&skill_value_prop.body[4] = 4;
      *(_DWORD *)&skill_value_prop.body[8] = v8;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)perk_value.body
                                                                                           + 20))(
        *(_DWORD *)perk_value.body,
        *(_DWORD *)&perk_value.body[8],
        "id",
        &skill_value_prop,
        (perk_value.body[4] & 0x8F) == 10);
      v9 = v7[1];
      if ( (skill_value_prop.body[4] & 0x40) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)skill_value_prop.body + 8))(
          *(_DWORD *)skill_value_prop.body,
          &skill_value_prop,
          *(_DWORD *)&skill_value_prop.body[8]);
        *(_DWORD *)skill_value_prop.body = 0;
      }
      *(_DWORD *)&skill_value_prop.body[4] = 4;
      *(_DWORD *)&skill_value_prop.body[8] = v9;
      (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)perk_value.body
                                                                                           + 20))(
        *(_DWORD *)perk_value.body,
        *(_DWORD *)&perk_value.body[8],
        "points",
        &skill_value_prop,
        (perk_value.body[4] & 0x8F) == 10);
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)player_skills_value_prop.body
                                                                               + 52))(
        *(_DWORD *)player_skills_value_prop.body,
        *(_DWORD *)&player_skills_value_prop.body[8],
        i,
        &perk_value);
      total_points_in_tree += v7[1];
      if ( (perk_value.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)perk_value.body + 8))(
          *(_DWORD *)perk_value.body,
          &perk_value,
          *(_DWORD *)&perk_value.body[8]);
      ++i;
    }
    while ( i < *(_BYTE *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952))
                         + 1948) );
  }
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "trees",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  v10 = *(unsigned __int8 *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952))
                           + 2100)
      - total_points_in_tree;
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 4;
  *(_DWORD *)&player_skills_value_prop.body[8] = v10;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "points_available",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  v11 = *(unsigned __int8 *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952))
                           + 2100);
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 4;
  *(_DWORD *)&player_skills_value_prop.body[8] = v11;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "points_unlocked",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952));
  v13 = *(_DWORD *)(v12 + 2104)
      - *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952)) + 2108);
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 4;
  *(_DWORD *)&player_skills_value_prop.body[8] = v13;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "experience_current",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  v14 = *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952)) + 2112);
  v15 = *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952)) + 2108);
  if ( v14 <= v15 )
    v16 = 0;
  else
    v16 = v14 - v15;
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 4;
  *(_DWORD *)&player_skills_value_prop.body[8] = v16;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "experience_next_level",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  v17 = a2[68];
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 4;
  *(_DWORD *)&player_skills_value_prop.body[8] = v17;
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "experience_delta",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(a2[53] + 264) + 4),
    (Scaleform::GFx::Value *)&player_skills_value_prop);
  for ( j = 0;
        j < *(_BYTE *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2[42] + 952) + 60))(*(_DWORD *)(a2[42] + 952))
                     + 2120);
        ++j )
  {
    v19 = a2[42];
    *(_DWORD *)perk_value.body = 0;
    *(_DWORD *)&perk_value.body[4] = 0;
    total_points_in_treea = *(_BYTE *)(j
                                     + *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v19 + 952) + 60))(*(_DWORD *)(v19 + 952))
                                                 + 2116));
    if ( (perk_value.body[4] & 0x40) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)perk_value.body + 8))(
        *(_DWORD *)perk_value.body,
        &perk_value,
        *(_DWORD *)&perk_value.body[8]);
      *(_DWORD *)perk_value.body = 0;
    }
    *(_DWORD *)&perk_value.body[8] = total_points_in_treea;
    *(_DWORD *)&perk_value.body[4] = 4;
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, survarium::flash_value *))(**(_DWORD **)player_skills_value_prop.body
                                                                             + 52))(
      *(_DWORD *)player_skills_value_prop.body,
      *(_DWORD *)&player_skills_value_prop.body[8],
      j,
      &perk_value);
    if ( (perk_value.body[4] & 0x40) != 0 )
      (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)perk_value.body + 8))(
        *(_DWORD *)perk_value.body,
        &perk_value,
        *(_DWORD *)&perk_value.body[8]);
  }
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)player_skills_value.body
                                                                                       + 20))(
    *(_DWORD *)player_skills_value.body,
    *(_DWORD *)&player_skills_value.body[8],
    "perks",
    &player_skills_value_prop,
    (player_skills_value.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(a2[53] + 264) + 4),
    "root.fill_char_info",
    0,
    (const Scaleform::GFx::Value *)&player_skills_value,
    1u);
  if ( (skill_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)skill_value_prop.body + 8))(
      *(_DWORD *)skill_value_prop.body,
      &skill_value_prop,
      *(_DWORD *)&skill_value_prop.body[8]);
    *(_DWORD *)skill_value_prop.body = 0;
  }
  *(_DWORD *)&skill_value_prop.body[4] = 0;
  if ( (player_skills_value_prop.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value_prop.body + 8))(
      *(_DWORD *)player_skills_value_prop.body,
      &player_skills_value_prop,
      *(_DWORD *)&player_skills_value_prop.body[8]);
    *(_DWORD *)player_skills_value_prop.body = 0;
  }
  *(_DWORD *)&player_skills_value_prop.body[4] = 0;
  if ( (player_skills_value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)player_skills_value.body + 8))(
      *(_DWORD *)player_skills_value.body,
      &player_skills_value,
      *(_DWORD *)&player_skills_value.body[8]);
}
