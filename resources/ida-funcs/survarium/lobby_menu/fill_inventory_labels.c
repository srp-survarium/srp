void __thiscall survarium::lobby_menu::fill_inventory_labels(survarium::lobby_menu *this, int a2)
{
  survarium::text_translator *v2; // ecx
  survarium::ui_label *v3; // ebx
  survarium::flash_value *v4; // ecx
  char value[516]; // [esp+10h] [ebp-23Ch] BYREF
  survarium::flash_value v6; // [esp+214h] [ebp-38h] BYREF
  Scaleform::GFx::Value pargs; // [esp+22Ch] [ebp-20h] BYREF
  int v8; // [esp+244h] [ebp-8h]

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(
    (survarium::flash_movie *)this,
    *(survarium::flash_value **)(*(_DWORD *)(a2 + 1600) + 264),
    &pargs);
  v3 = survarium::lobby_labels;
  v8 = 216;
  do
  {
    *(_DWORD *)v6.body = 0;
    *(_DWORD *)&v6.body[4] = 0;
    survarium::text_translator::translate_text(v2, *(_DWORD *)(a2 + 160) + 13944, (char *)v3->label, value);
    survarium::flash_value::SetString(&v6, value);
    survarium::flash_value::SetMember(v4, &pargs, v3->name, &v6);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v6);
    ++v3;
    --v8;
  }
  while ( v8 );
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_localization_data",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
