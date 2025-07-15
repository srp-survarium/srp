void __thiscall survarium::respawn_point_core::load(
        survarium::respawn_point_core *this,
        const vostok::configs::binary_config_value *config,
        vostok::configs::binary_config_value *a3)
{
  const char ***v4; // eax
  const char **v5; // esi
  float **v6; // eax
  float *v7; // esi
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // eax
  int v11; // esi
  const vostok::configs::binary_config_value *v12; // eax
  vostok::math::float4x4 *v13; // [esp-4h] [ebp-5Ch]
  vostok::math::float3 *v14; // [esp+0h] [ebp-58h]
  vostok::math::axis_rotation_order v15; // [esp+4h] [ebp-54h]
  _BYTE v16[64]; // [esp+Ch] [ebp-4Ch] BYREF
  vostok::math::float3 v17; // [esp+4Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF
  int v19; // [esp+60h] [ebp+8h]

  HIDWORD(config->data.max_storage) = vostok::configs::binary_config_value::operator[](a3, "point_id")->data.pointer;
  config[1].data.pointer = vostok::configs::binary_config_value::operator[](a3, "priority")->data.pointer;
  v4 = (const char ***)vostok::configs::binary_config_value::operator[](a3, "position");
  v5 = *v4;
  config->id.pointer = **v4;
  HIDWORD(config->id.max_storage) = *++v5;
  config->id_crc = (unsigned int)v5[1];
  v6 = (float **)vostok::configs::binary_config_value::operator[](a3, "rotation");
  v7 = *v6;
  v17.x = **v6;
  *(_QWORD *)&v17.elements[1] = *(_QWORD *)(v7 + 1);
  vostok::math::create_rotation(&v17, (int)&savedregs, (int)v16);
  *(float *)&config->type = vostok::math::float4x4::get_angles(v13, v14, v15)->y;
  HIDWORD(config[1].data.max_storage) = vostok::configs::binary_config_value::operator[](a3, "team")->data.pointer;
  v8 = vostok::configs::binary_config_value::operator[](a3, "ally_zones");
  if ( 24 * vostok::configs::binary_config_value::operator[](v8, "collision_geometries")->count / 24 )
  {
    v19 = *(_DWORD *)HIDWORD(config[1].id.max_storage);
    v9 = vostok::configs::binary_config_value::operator[](a3, "ally_zones");
    (*(void (__thiscall **)(_DWORD, const vostok::configs::binary_config_value *))(v19 + 24))(
      HIDWORD(config[1].id.max_storage),
      v9);
  }
  v10 = vostok::configs::binary_config_value::operator[](a3, "enemy_zones");
  if ( 24 * vostok::configs::binary_config_value::operator[](v10, "collision_geometries")->count / 24 )
  {
    v11 = *(_DWORD *)config[1].id_crc;
    v12 = vostok::configs::binary_config_value::operator[](a3, "enemy_zones");
    (*(void (__thiscall **)(unsigned int, const vostok::configs::binary_config_value *))(v11 + 24))(
      config[1].id_crc,
      v12);
  }
  *(_DWORD *)(HIDWORD(config[1].id.max_storage) + 36) = HIDWORD(config[1].data.max_storage);
  *(_DWORD *)(config[1].id_crc + 36) = HIDWORD(config[1].data.max_storage) == 0;
}
