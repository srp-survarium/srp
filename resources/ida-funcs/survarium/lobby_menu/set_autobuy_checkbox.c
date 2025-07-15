void __userpurge survarium::lobby_menu::set_autobuy_checkbox(
        survarium::lobby_menu *this@<ecx>,
        int a2@<edi>,
        const unsigned int profile_id,
        const unsigned __int8 autobuy)
{
  unsigned __int8 v4; // bl
  survarium::lobby_client *v5; // eax
  survarium::flash_value *v6; // ecx
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  v4 = *(_BYTE *)(a2 + 1604);
  v5 = survarium::lobby_menu::lobby_client(this, a2);
  v6 = (survarium::flash_value *)(1512 * v4);
  if ( *(unsigned int *)((char *)&v5->m_profiles[0].profile_id + (_DWORD)v6) == profile_id )
  {
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_value::SetUInt(v6, (int)&pargs, autobuy);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
      "root.set_autobuy",
      0,
      &pargs,
      1u);
    Scaleform::GFx::Value::~Value(&pargs);
  }
}
