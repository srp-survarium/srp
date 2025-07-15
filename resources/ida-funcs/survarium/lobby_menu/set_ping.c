void __usercall survarium::lobby_menu::set_ping(survarium::lobby_menu *this@<edx>, unsigned int ping_val@<eax>)
{
  survarium::flash_movie_resource *m_object; // eax
  survarium::flash_value args; // [esp+0h] [ebp-1Ch] BYREF

  *(_DWORD *)&args.body[8] = ping_val;
  m_object = this->m_lobby_menu_ui.m_object;
  *(_DWORD *)args.body = 0;
  *(_DWORD *)&args.body[4] = 4;
  Scaleform::GFx::Movie::Invoke(m_object->movie->m_movie, "root.set_ping", 0, (const Scaleform::GFx::Value *)&args, 1u);
  if ( (args.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)args.body + 8))(
      *(_DWORD *)args.body,
      &args,
      *(_DWORD *)&args.body[8]);
}
