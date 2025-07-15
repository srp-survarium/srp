void __userpurge survarium::lobby_menu::show_match_making(survarium::lobby_menu *this@<ecx>, int a2@<edi>, bool b_show)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-1Ch] BYREF

  if ( *(_BYTE *)(a2 + 1625) != b_show )
  {
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_value::SetBoolean((survarium::flash_value *)this, (int)&pargs, b_show);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
      "root.show_match_making",
      0,
      &pargs,
      1u);
    *(_BYTE *)(a2 + 1625) = b_show;
    Scaleform::GFx::Value::~Value(&pargs);
  }
}
