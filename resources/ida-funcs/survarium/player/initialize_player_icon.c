void __usercall survarium::player::initialize_player_icon(survarium::player *this@<ecx>, int a2@<esi>)
{
  int v2; // edi
  survarium::game_world_ui *v3; // ecx
  survarium::game_world_ui *v4; // ecx
  survarium::game_world_ui *v5; // ecx
  survarium::game_world_ui *v6; // ecx
  unsigned __int8 v7; // [esp+8h] [ebp-4h]

  v7 = survarium::calculate_profile_icon(
         *(const survarium::player_profile **)((char *)&loc_11066 + a2 + 2),
         *(const survarium::items_dictionary **)(*(int *)((char *)&dword_11414 + a2) + 13908));
  v2 = *(int *)((char *)&dword_11414 + a2) + 708;
  survarium::game_world_ui::create_hud_icon(v3, v2, *(_BYTE *)(a2 + 304), 0.0, s_player_icon_size);
  survarium::game_world_ui::set_hud_icon_type(v4, v2, *(_BYTE *)(a2 + 304), v7);
  survarium::game_world_ui::set_hud_icon_name(
    v5,
    v2,
    (const char *)*(unsigned __int8 *)(a2 + 304),
    (char *)&loc_1143B + a2 + 1);
  survarium::game_world_ui::set_hud_icon_color(v6, v2, *(_BYTE *)(a2 + 304), 0, 0xFFu, 0);
}
