void __thiscall survarium::game_options::apply_default_graphic(survarium::game_options *this, int a2)
{
  survarium::graphic_preset *v2; // edi
  int v3; // ebx
  survarium::flash_value *v4; // ecx
  survarium::flash_value *v5; // ecx
  int v6; // edx
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  Scaleform::GFx::Value *v10; // esi
  survarium::flash_value v11; // [esp+Ch] [ebp-64h] BYREF
  _BYTE v12[24]; // [esp+24h] [ebp-4Ch] BYREF
  _BYTE v13[24]; // [esp+3Ch] [ebp-34h] BYREF
  _BYTE v14[24]; // [esp+54h] [ebp-1Ch] BYREF
  int v15; // [esp+6Ch] [ebp-4h] BYREF

  v2 = survarium::default_graphic_preset;
  v15 = 10;
  do
  {
    v3 = 3;
    v4 = &v11;
    do
    {
      survarium::flash_value::flash_value(v4);
      v4 = v5 + 1;
    }
    while ( v6 - 1 >= 0 );
    survarium::flash_value::SetUInt(v4, (int)&v11, 2u);
    survarium::flash_value::SetUInt(v7, (int)v12, v2->option_id);
    survarium::flash_value::SetUInt(v8, (int)v13, v2->option_value);
    survarium::flash_value::SetUInt(v9, (int)v14, 0);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
      "root.set_value",
      0,
      (const Scaleform::GFx::Value *)&v11,
      4u);
    v10 = (Scaleform::GFx::Value *)&v15;
    do
    {
      Scaleform::GFx::Value::~Value(--v10);
      --v3;
    }
    while ( v3 >= 0 );
    ++v2;
    --v15;
  }
  while ( v15 );
}
