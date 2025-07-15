void __thiscall survarium::lobby_menu::switch_to_level_loading(
        survarium::lobby_menu *this,
        _DWORD *level_id,
        unsigned __int8 a3)
{
  int v3; // eax
  survarium::flash_value *v4; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-18h] BYREF

  v3 = level_id[40];
  level_id[413] = 0;
  survarium::lobby_menu::show_match_making(this, *(_DWORD *)(v3 + 13840), 1);
  LOBYTE(v4) = 0;
  if ( a3 > 0x14u )
  {
    switch ( a3 )
    {
      case 0x15u:
        LOBYTE(v4) = 8;
        break;
      case 0x16u:
        LOBYTE(v4) = 9;
        break;
      case 0x17u:
        LOBYTE(v4) = 10;
        break;
      case 0x18u:
        LOBYTE(v4) = 11;
        break;
      case 0x19u:
        LOBYTE(v4) = 12;
        break;
      case 0x1Au:
        LOBYTE(v4) = 14;
        break;
      case 0x1Bu:
        LOBYTE(v4) = 13;
        break;
    }
  }
  else
  {
    switch ( a3 )
    {
      case 0x14u:
        LOBYTE(v4) = 7;
        break;
      case 1u:
        LOBYTE(v4) = 0;
        break;
      case 3u:
        LOBYTE(v4) = 1;
        break;
      case 5u:
        LOBYTE(v4) = 2;
        break;
      case 8u:
        LOBYTE(v4) = 3;
        break;
      case 9u:
        LOBYTE(v4) = 4;
        break;
      case 0xAu:
        LOBYTE(v4) = 5;
        break;
      case 0x13u:
        LOBYTE(v4) = 6;
        break;
    }
  }
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v4, (int)&pargs, (unsigned __int8)v4);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(level_id[400] + 264) + 4),
    "root.set_loading_level",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
