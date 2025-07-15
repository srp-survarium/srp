void __userpurge survarium::lobby_menu::player_parameters_ready(
        survarium::lobby_menu *this@<ecx>,
        int a2@<eax>,
        const survarium::lobby_player_profile *profile)
{
  survarium::player_params_modifiers_container *v5; // ecx
  float v6; // xmm0_4
  survarium::player_params_modifiers_container *v7; // ecx
  float v8; // xmm0_4
  survarium::player_params_modifiers_container *v9; // ecx
  int v10; // eax
  survarium::player_params_modifiers_container *v11; // ecx
  survarium::flash_value *condition_or_stack; // ecx
  survarium::inventory_item_descr *slots; // esi
  survarium::dictionary_item *v14; // eax
  float weight; // xmm0_4
  unsigned int v16; // eax
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  int v20; // edx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::lobby_menu *v24; // ecx
  Scaleform::GFx::Value *p_pargs; // esi
  int i; // edi
  float value; // [esp+0h] [ebp-74h]
  survarium::flash_value v28; // [esp+14h] [ebp-60h] BYREF
  _BYTE v29[24]; // [esp+2Ch] [ebp-48h] BYREF
  Scaleform::GFx::Value pargs; // [esp+44h] [ebp-30h] BYREF
  float v31; // [esp+5Ch] [ebp-18h]
  survarium::items_dictionary *v32; // [esp+60h] [ebp-14h]
  int v33; // [esp+64h] [ebp-10h]
  float v34; // [esp+68h] [ebp-Ch]
  unsigned __int8 v35; // [esp+6Fh] [ebp-5h]
  unsigned __int8 v36; // [esp+7Fh] [ebp+Bh]

  *(_BYTE *)(a2 + 1638) = (int)survarium::player_params_modifiers_container::apply_modifier(
                                 &profile->modifiers,
                                 ammo_bags_modifier,
                                 (float)*(unsigned __int8 *)(a2 + 1636),
                                 (float)*(unsigned __int8 *)(a2 + 1636),
                                 1.0);
  v6 = survarium::player_params_modifiers_container::apply_modifier(
         v5,
         quick_slot_size_modifier,
         (float)*(unsigned __int8 *)(a2 + 1637),
         (float)*(unsigned __int8 *)(a2 + 1637),
         1.0);
  *(_BYTE *)(a2 + 1639) = (int)v6;
  v8 = survarium::player_params_modifiers_container::apply_modifier(v7, device_slots_modifier, v6, 0.0, 1.0);
  *(_BYTE *)(a2 + 1640) = (int)v8;
  v10 = (int)survarium::player_params_modifiers_container::apply_modifier(v9, artefact_slots_modifier, v8, 0.0, 1.0);
  value = *(float *)(a2 + 1632);
  v36 = v10;
  v34 = 0.0;
  v35 = (int)survarium::player_params_modifiers_container::apply_modifier(
               v11,
               max_carried_weight_modifier,
               0.0,
               value,
               1.0);
  v32 = *(survarium::items_dictionary **)(*(_DWORD *)(a2 + 160) + 13908);
  slots = profile->slots;
  v33 = 23;
  do
  {
    if ( slots->dict_id )
    {
      v14 = survarium::items_dictionary::item_by_id(v32, (survarium::items_dictionary_vtbl *)slots->dict_id);
      if ( v14->is_stack )
      {
        condition_or_stack = (survarium::flash_value *)slots->condition_or_stack;
        v31 = (double)slots->condition_or_stack * v14->weight;
        weight = v31;
      }
      else
      {
        weight = v14->weight;
      }
      v34 = weight + v34;
    }
    ++slots;
    --v33;
  }
  while ( v33 );
  v16 = *(unsigned __int8 *)(a2 + 1638);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(condition_or_stack, (int)&pargs, v16);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_ammo_bags_count",
    0,
    &pargs,
    1u);
  survarium::flash_value::SetUInt(v17, (int)&pargs, *(unsigned __int8 *)(a2 + 1639));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_quick_slot_size",
    0,
    &pargs,
    1u);
  v18 = &v28;
  do
  {
    survarium::flash_value::flash_value(v18);
    v18 = v19 + 1;
  }
  while ( v20 - 1 >= 0 );
  survarium::flash_value::SetUInt(v18, (int)&v28, v36);
  survarium::flash_value::SetUInt(v21, (int)v29, *(unsigned __int8 *)(a2 + 1640));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.update_profile_slots_count",
    0,
    (const Scaleform::GFx::Value *)&v28,
    2u);
  survarium::flash_value::SetNumber(v22, (int)&v28, v34);
  survarium::flash_value::SetNumber(v23, (int)v29, (float)v35);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.update_player_items_weight",
    0,
    (const Scaleform::GFx::Value *)&v28,
    2u);
  survarium::lobby_menu::set_autobuy_checkbox(v24, a2, profile->profile_id, profile->autobuy_items);
  p_pargs = &pargs;
  for ( i = 1; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--p_pargs);
  Scaleform::GFx::Value::~Value(&pargs);
}
