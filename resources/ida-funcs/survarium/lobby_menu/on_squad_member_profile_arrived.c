void __userpurge survarium::lobby_menu::on_squad_member_profile_arrived(
        survarium::lobby_menu *this@<ecx>,
        int a2@<eax>,
        survarium::lobby_player_profile *profile)
{
  BOOL v5; // esi
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  int v8; // edx
  survarium::flash_value *v9; // ecx
  Scaleform::GFx::Value *v10; // esi
  int i; // edi
  survarium::flash_value v12; // [esp+10h] [ebp-34h] BYREF
  _BYTE v13[24]; // [esp+28h] [ebp-1Ch] BYREF
  char v14; // [esp+40h] [ebp-4h] BYREF
  unsigned __int8 profile_3; // [esp+4Fh] [ebp+Bh]

  profile_3 = survarium::calculate_profile_icon(
                profile,
                *(const survarium::items_dictionary **)(*(_DWORD *)(a2 + 160) + 13908));
  v5 = **(_DWORD **)(a2 + 1612) != profile->profile_id;
  survarium::lobby_character::setup_profile(*(survarium::lobby_character **)(a2 + 4 * v5 + 1612), profile);
  v6 = &v12;
  do
  {
    survarium::flash_value::flash_value(v6);
    v6 = v7 + 1;
  }
  while ( v8 - 1 >= 0 );
  survarium::flash_value::SetUInt(v6, (int)&v12, v5 + 1);
  survarium::flash_value::SetUInt(v9, (int)v13, profile_3);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_squad_player_type",
    0,
    (const Scaleform::GFx::Value *)&v12,
    2u);
  v10 = (Scaleform::GFx::Value *)&v14;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v10);
}
