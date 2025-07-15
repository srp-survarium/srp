void __thiscall survarium::game_world_ui::set_broken_connection_message(
        survarium::game_world_ui *this,
        const char *str)
{
  survarium::flash_value *v2; // ecx
  survarium::flash_value *v3; // ecx
  int v4; // edx
  survarium::flash_value *v5; // ecx
  Scaleform::GFx::Value *v6; // esi
  int i; // edi
  char value[512]; // [esp+10h] [ebp-234h] BYREF
  survarium::flash_value v9; // [esp+210h] [ebp-34h] BYREF
  _BYTE v10[24]; // [esp+228h] [ebp-1Ch] BYREF
  char v11; // [esp+240h] [ebp-4h] BYREF

  if ( *((_DWORD *)str + 2) )
  {
    survarium::text_translator::translate_text(
      (survarium::text_translator *)this,
      *(_DWORD *)(*((_DWORD *)str + 5) + 160) + 13944,
      "match server connection lost",
      value);
    v2 = &v9;
    do
    {
      survarium::flash_value::flash_value(v2);
      v2 = v3 + 1;
    }
    while ( v4 - 1 >= 0 );
    survarium::flash_value::SetString(&v9, value);
    survarium::flash_value::SetInt(v5, (int)v10, 1000);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*((_DWORD *)str + 2) + 264) + 4),
      "root.set_warning_message",
      0,
      (const Scaleform::GFx::Value *)&v9,
      2u);
    v6 = (Scaleform::GFx::Value *)&v11;
    for ( i = 1; i >= 0; --i )
      Scaleform::GFx::Value::~Value(--v6);
  }
}
