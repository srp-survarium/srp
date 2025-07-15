void __usercall survarium::get_profile_faction_affinity(
        const survarium::player_profile *profile@<edx>,
        const survarium::items_dictionary *dict,
        survarium::factions_enum *faction,
        float *faction_factor)
{
  survarium::inventory_item_descr *slots; // esi
  survarium::game_team_id *p_team; // ebx
  unsigned int v6; // edi
  unsigned __int16 dict_id; // ax
  survarium::dictionary_item *v8; // eax
  survarium::factions_enum v9; // ecx
  unsigned int *v10; // eax
  unsigned int *v11; // ecx
  survarium::factions_enum v12; // eax
  double v13; // st7
  _DWORD v14[7]; // [esp+Ch] [ebp-20h] BYREF
  unsigned int v15; // [esp+28h] [ebp-4h] BYREF

  memset(v14, 0, sizeof(v14));
  slots = profile->slots;
  p_team = &profile->team;
  v6 = 0;
  if ( profile->slots == (survarium::inventory_item_descr *)&profile->team )
    goto LABEL_11;
  do
  {
    dict_id = slots->dict_id;
    if ( dict_id )
    {
      v8 = survarium::items_dictionary::item_by_id(dict, (survarium::items_dictionary_vtbl *)dict_id);
      v9 = v8->faction;
      v8 = (survarium::dictionary_item *)((char *)v8 + 372);
      v14[v9] += v8->item_id;
      v6 += v8->item_id;
    }
    ++slots;
  }
  while ( slots != (survarium::inventory_item_descr *)p_team );
  if ( !v6 )
  {
LABEL_11:
    *faction = faction_neutral;
    *faction_factor = 0.0;
  }
  else
  {
    v10 = v14;
    v11 = &v14[1];
    do
    {
      if ( *v10 < *v11 )
        v10 = v11;
      ++v11;
    }
    while ( v11 != &v15 );
    v12 = v10 - v14;
    *faction = v12;
    v15 = v14[v12];
    v13 = (double)v15;
    v15 = v6;
    *faction_factor = v13 / (double)v6;
  }
}
