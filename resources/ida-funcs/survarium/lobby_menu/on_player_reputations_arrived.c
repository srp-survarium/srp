void __thiscall survarium::lobby_menu::on_player_reputations_arrived(survarium::lobby_menu *this, int a2)
{
  survarium::lobby_menu *v3; // ecx
  survarium::lobby_menu *v4; // ecx
  survarium::player_reputation *v5; // edi
  int faction; // ecx
  int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned int i; // esi
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  int v13; // edx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  unsigned int v16; // edi
  survarium::text_translator *v17; // ecx
  char *v18; // edi
  Scaleform::GFx::Value *v19; // esi
  int j; // edi
  survarium::lobby_client *v21; // eax
  char v22[512]; // [esp+10h] [ebp-274h] BYREF
  survarium::flash_value v23; // [esp+210h] [ebp-74h] BYREF
  _BYTE v24[24]; // [esp+228h] [ebp-5Ch] BYREF
  _BYTE v25[24]; // [esp+240h] [ebp-44h] BYREF
  survarium::flash_value v26; // [esp+258h] [ebp-2Ch] BYREF
  char v27; // [esp+270h] [ebp-14h] BYREF
  unsigned int value; // [esp+274h] [ebp-10h]
  unsigned int reputation_value; // [esp+278h] [ebp-Ch]
  unsigned __int8 m_unlocked_factions_mask; // [esp+27Fh] [ebp-5h]
  unsigned __int8 v31; // [esp+28Fh] [ebp+Bh]

  m_unlocked_factions_mask = survarium::lobby_menu::lobby_client(this, a2)->m_unlocked_factions_mask;
  v31 = 0;
  if ( survarium::lobby_menu::lobby_client(v3, a2)->m_player_reputations_count )
  {
    do
    {
      v5 = &survarium::lobby_menu::lobby_client(v4, a2)->m_player_reputations[v31];
      faction = v5->faction;
      reputation_value = v5->reputation_value;
      if ( faction && faction <= 4 )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(a2 + 160) + 13908);
        value = 0;
        v8 = (faction << 6) + v7 + 248;
        v9 = *(_DWORD *)(v7 + 4 * faction + 756);
        for ( i = 0; i < v9; value = i++ )
        {
          if ( *(_DWORD *)(v8 + 4 * i) > reputation_value )
            break;
        }
        v11 = &v23;
        do
        {
          survarium::flash_value::flash_value(v11);
          v11 = v12 + 1;
        }
        while ( v13 - 1 >= 0 );
        survarium::flash_value::SetUInt(v11, (int)&v23, v5->faction);
        survarium::flash_value::SetUInt(v14, (int)v24, value);
        survarium::flash_value::SetUInt(v15, (int)v25, reputation_value);
        v16 = v5->faction;
        v17 = (survarium::text_translator *)(v16 - 1);
        LOBYTE(v17) = m_unlocked_factions_mask;
        if ( ((unsigned __int8)(1 << (v16 - 1)) & m_unlocked_factions_mask) != 0 )
          v18 = (char *)uri;
        else
          v18 = (char *)survarium::blocked_factions_text[v16];
        survarium::text_translator::translate_text(v17, *(_DWORD *)(a2 + 160) + 13944, v18, v22);
        survarium::flash_value::SetString(&v26, v22);
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
          "root.setup_player_progress",
          0,
          (const Scaleform::GFx::Value *)&v23,
          4u);
        v19 = (Scaleform::GFx::Value *)&v27;
        for ( j = 3; j >= 0; --j )
          Scaleform::GFx::Value::~Value(--v19);
      }
      ++v31;
      v21 = survarium::lobby_menu::lobby_client((survarium::lobby_menu *)faction, a2);
      LOBYTE(v4) = v31;
    }
    while ( v31 < v21->m_player_reputations_count );
  }
}
