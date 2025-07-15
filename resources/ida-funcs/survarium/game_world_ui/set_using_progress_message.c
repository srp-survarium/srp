void __thiscall survarium::game_world_ui::set_using_progress_message(
        survarium::game_world_ui *this,
        unsigned int progress_value,
        int a3)
{
  survarium::flash_value *v3; // ecx
  survarium::flash_value *v4; // ecx
  int v5; // edx
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  Scaleform::GFx::Value *v8; // esi
  int i; // edi
  char value[512]; // [esp+10h] [ebp-248h] BYREF
  survarium::flash_value v11; // [esp+210h] [ebp-48h] BYREF
  _BYTE v12[24]; // [esp+228h] [ebp-30h] BYREF
  _BYTE v13[24]; // [esp+240h] [ebp-18h] BYREF
  char vars0; // [esp+258h] [ebp+0h] BYREF

  survarium::text_translator::translate_text(
    (survarium::text_translator *)this,
    *(_DWORD *)(*(_DWORD *)(progress_value + 20) + 160) + 13944,
    "st_using_progress_message",
    value);
  v3 = &v11;
  do
  {
    survarium::flash_value::flash_value(v3);
    v3 = v4 + 1;
  }
  while ( v5 - 1 >= 0 );
  survarium::flash_value::SetString(&v11, value);
  survarium::flash_value::SetInt(v6, (int)v12, a3);
  survarium::flash_value::SetInt(v7, (int)v13, 500);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(progress_value + 8) + 264) + 4),
    "root.set_context",
    0,
    (const Scaleform::GFx::Value *)&v11,
    3u);
  v8 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 2; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v8);
}
