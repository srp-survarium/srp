void __thiscall survarium::lobby_menu::create_player_params(
        survarium::lobby_menu *this,
        survarium::flash_value *player_characteristics_value,
        Scaleform::GFx::Value *params_container,
        int a4)
{
  survarium::flash_movie *v5; // ecx
  survarium::player_params_modifiers_enum v6; // edi
  int v7; // eax
  double v8; // st7
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  char **v15; // eax
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  vostok::configs::binary_config_value *v19; // eax
  vostok::configs::binary_config_value *i; // esi
  const vostok::configs::binary_config_value *v21; // eax
  survarium::text_translator *v22; // ecx
  const vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  survarium::flash_value *v28; // ecx
  survarium::text_translator v29[128]; // [esp+14h] [ebp-2D4h] BYREF
  char _Dest[128]; // [esp+214h] [ebp-D4h] BYREF
  survarium::flash_value v31; // [esp+298h] [ebp-50h] BYREF
  survarium::flash_value v32; // [esp+2B0h] [ebp-38h] BYREF
  int v33; // [esp+2C8h] [ebp-20h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v34; // [esp+2CCh] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v35; // [esp+2D0h] [ebp-18h] BYREF
  char *v36; // [esp+2D4h] [ebp-14h]
  survarium::player_params_modifiers_enum *v37; // [esp+2D8h] [ebp-10h]
  unsigned int value; // [esp+2DCh] [ebp-Ch]
  char pointer; // [esp+2E3h] [ebp-5h]
  float v40; // [esp+2F0h] [ebp+8h]
  unsigned __int8 v41; // [esp+2F3h] [ebp+Bh]

  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[66].body[16] + 264) + 4),
    params_container);
  value = 0;
  v37 = survarium::player_chars_to_show;
  v33 = 10;
  do
  {
    v6 = *v37;
    v7 = *(_DWORD *)&player_characteristics_value[66].body[16];
    *(_DWORD *)v31.body = 0;
    *(_DWORD *)&v31.body[4] = 0;
    survarium::flash_movie::CreateObject(v5, *(survarium::flash_value **)(v7 + 264), (Scaleform::GFx::Value *)&v31);
    v8 = *(float *)(a4 + 4 * v6);
    *(_DWORD *)v32.body = 0;
    v40 = v8;
    *(_DWORD *)&v32.body[4] = 0;
    survarium::flash_value::SetUInt(v9, (int)&v32, value);
    survarium::flash_value::SetMember(v10, &v31, "id", &v32);
    sprintf_s<128>((char (*)[128])_Dest, "booster_%d", v6 + 1);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v35,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[6].body[16] + 13908) + 268));
    v11 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v35.m_object->m_lods[0].m_template.m_object,
            "boosters_dict");
    v12 = vostok::configs::binary_config_value::operator[](v11, _Dest);
    pointer = (char)vostok::configs::binary_config_value::operator[](v12, "booster_icon")->data.pointer;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v34,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(*(_DWORD *)&player_characteristics_value[6].body[16] + 13908) + 268));
    v13 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v34.m_object->m_lods[0].m_template.m_object,
            "boosters_dict");
    v14 = vostok::configs::binary_config_value::operator[](v13, _Dest);
    v15 = (char **)vostok::configs::binary_config_value::operator[](v14, "booster_name");
    survarium::text_translator::translate_text(
      v29,
      *(_DWORD *)&player_characteristics_value[6].body[16] + 13944,
      *v15,
      (char *)v29);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
    survarium::flash_value::SetString(&v32, (const char *)v29);
    survarium::flash_value::SetMember(v16, &v31, "name", &v32);
    survarium::flash_value::SetNumber(v17, (int)&v32, v40);
    survarium::flash_value::SetMember(v18, &v31, "value", &v32);
    v19 = *(vostok::configs::binary_config_value **)(*(_DWORD *)&player_characteristics_value[71].body[12] + 264);
    v36 = (char *)uri;
    v41 = 1;
    for ( i = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                        v19,
                                                        "max_prop_vals")->data.pointer; ; ++i )
    {
      v21 = vostok::configs::binary_config_value::operator[](
              *(vostok::configs::binary_config_value **)(*(_DWORD *)&player_characteristics_value[71].body[12] + 264),
              "max_prop_vals");
      v22 = (survarium::text_translator *)((char *)v21->data.pointer + 24 * v21->count);
      if ( i == (vostok::configs::binary_config_value *)v22 )
        break;
      v23 = vostok::configs::binary_config_value::operator[](i, "id");
      LOBYTE(v24) = pointer;
      if ( LOBYTE(v23->data.pointer) == pointer )
      {
        if ( vostok::configs::binary_config_value::value_exists(v24, (int)i, (unsigned int)"postfix") )
          v36 = (char *)vostok::configs::binary_config_value::operator[](i, "postfix")->data.pointer;
        v41 = (unsigned __int8)vostok::configs::binary_config_value::operator[](i, "direction")->data.pointer;
        break;
      }
    }
    survarium::text_translator::translate_text(
      v22,
      *(_DWORD *)&player_characteristics_value[6].body[16] + 13944,
      v36,
      (char *)v29);
    survarium::flash_value::SetString(&v32, (const char *)v29);
    survarium::flash_value::SetMember(v25, &v31, "postfix", &v32);
    survarium::flash_value::SetUInt(v26, (int)&v32, v41);
    survarium::flash_value::SetMember(v27, &v31, "direction", &v32);
    survarium::flash_value::PushBack(v28, params_container, &v31);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v32);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v31);
    ++value;
    ++v37;
    --v33;
  }
  while ( v33 );
}
