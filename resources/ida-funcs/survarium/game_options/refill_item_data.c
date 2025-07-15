void __usercall survarium::game_options::refill_item_data(survarium::game_options *this@<ecx>, int a2@<eax>)
{
  survarium::flash_value *v3; // ecx
  survarium::flash_value *v4; // ecx
  int v5; // edx
  survarium::flash_value *v6; // ecx
  int v7; // ecx
  Scaleform::GFx::Value *v8; // esi
  int i; // edi
  survarium::flash_value v10; // [esp+8h] [ebp-48h] BYREF
  _BYTE v11[24]; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+38h] [ebp-18h] BYREF
  char vars0; // [esp+50h] [ebp+0h] BYREF

  v3 = &v10;
  do
  {
    survarium::flash_value::flash_value(v3);
    v3 = v4 + 1;
  }
  while ( v5 - 1 >= 0 );
  survarium::flash_value::SetUInt(v3, (int)&v10, 2u);
  survarium::flash_value::SetUInt(v6, (int)v11, 1u);
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4), &pvalue);
  v7 = *(_DWORD *)(**(_DWORD **)(a2 + 28) + 4);
  (*(void (__thiscall **)(int, Scaleform::GFx::Value *))(*(_DWORD *)v7 + 8))(v7, &pvalue);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 12) + 264) + 4),
    "root.set_data_provider",
    0,
    (const Scaleform::GFx::Value *)&v10,
    3u);
  v8 = (Scaleform::GFx::Value *)&vars0;
  for ( i = 2; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v8);
}
