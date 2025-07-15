survarium::artefact_spring_core::config *__cdecl survarium::artefact_spring_core::load_config(
        survarium::artefact_spring_core::config *result,
        vostok::configs::binary_config_value *config)
{
  vostok::configs::binary_config_value *v3; // eax
  const vostok::configs::binary_config_value *v4; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  _BYTE v22[20]; // [esp+0h] [ebp-14h] BYREF

  result->passive.movement_speed_mod.value = 0.0;
  result->passive.movement_speed_mod.next = 0;
  result->passive.max_carried_weight_mod.value = 0.0;
  result->passive.max_carried_weight_mod.next = 0;
  result->active.movement_speed_mod.value = 0.0;
  result->active.movement_speed_mod.next = 0;
  result->active.stamina_regen_mod.value = 0.0;
  result->active.stamina_regen_mod.next = 0;
  result->active.stamina_spend_mod.value = 0.0;
  result->active.stamina_spend_mod.next = 0;
  qmemcpy(result, survarium::artefact_base::load_config((int)v22, config), 0x14u);
  v3 = vostok::configs::binary_config_value::operator[](config, "passive");
  v4 = vostok::configs::binary_config_value::operator[](v3, "movement_speed_mod");
  if ( v4->type == 2 )
    pointer = *(float *)&v4->data.pointer;
  else
    pointer = (float)(int)v4->data.pointer;
  result->passive.movement_speed_mod.value = pointer;
  v6 = vostok::configs::binary_config_value::operator[](config, "passive");
  v7 = vostok::configs::binary_config_value::operator[](v6, "max_carried_weight_mod");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  result->passive.max_carried_weight_mod.value = v8;
  v9 = vostok::configs::binary_config_value::operator[](config, "active");
  v10 = vostok::configs::binary_config_value::operator[](v9, "movement_speed_mod");
  if ( v10->type == 2 )
    v11 = *(float *)&v10->data.pointer;
  else
    v11 = (float)(int)v10->data.pointer;
  result->active.movement_speed_mod.value = v11;
  v12 = vostok::configs::binary_config_value::operator[](config, "active");
  v13 = vostok::configs::binary_config_value::operator[](v12, "stamina_regen_mod");
  if ( v13->type == 2 )
    v14 = *(float *)&v13->data.pointer;
  else
    v14 = (float)(int)v13->data.pointer;
  result->active.stamina_regen_mod.value = v14;
  v15 = vostok::configs::binary_config_value::operator[](config, "active");
  v16 = vostok::configs::binary_config_value::operator[](v15, "stamina_spend_mod");
  if ( v16->type == 2 )
    v17 = *(float *)&v16->data.pointer;
  else
    v17 = (float)(int)v16->data.pointer;
  result->active.stamina_spend_mod.value = v17;
  v18 = vostok::configs::binary_config_value::operator[](config, "active");
  v19 = vostok::configs::binary_config_value::operator[](v18, "duration");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  result->active.duration_ms = (unsigned __int64)(v20 * 1000.0);
  return result;
}
