void __userpurge survarium::game_world_ui::show_parametrized_message(
        survarium::game_world_ui *this@<ecx>,
        const char *message_id,
        char *font_size,
        unsigned __int8 y_pos_in_percents,
        unsigned int timeout_in_ms)
{
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  char *v11; // esi
  int i; // edi
  survarium::flash_value v13; // [esp+10h] [ebp-260h] BYREF
  _BYTE v14[24]; // [esp+28h] [ebp-248h] BYREF
  _BYTE v15[24]; // [esp+40h] [ebp-230h] BYREF
  _BYTE v16[24]; // [esp+58h] [ebp-218h] BYREF
  char value[512]; // [esp+70h] [ebp-200h] BYREF

  survarium::text_translator::translate_text(
    (survarium::text_translator *)this,
    *(_DWORD *)(*((_DWORD *)message_id + 5) + 160) + 13944,
    font_size,
    value);
  v5 = &v13;
  do
  {
    survarium::flash_value::flash_value(v5);
    v5 = v6 + 1;
  }
  while ( v7 - 1 >= 0 );
  survarium::flash_value::SetString(&v13, value);
  survarium::flash_value::SetUInt(v8, (int)v14, 0x21u);
  survarium::flash_value::SetUInt(v9, (int)v15, 0x14u);
  survarium::flash_value::SetUInt(v10, (int)v16, 0xBB8u);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*((_DWORD *)message_id + 2) + 264) + 4),
    "root.set_parameterized_message",
    0,
    (const Scaleform::GFx::Value *)&v13,
    4u);
  v11 = value;
  for ( i = 3; i >= 0; --i )
  {
    v11 -= 24;
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)v11);
  }
}
