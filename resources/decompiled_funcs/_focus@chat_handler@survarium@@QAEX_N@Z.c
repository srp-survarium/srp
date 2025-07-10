void __userpurge survarium::chat_handler::focus(survarium::chat_handler *this@<ecx>, int a2@<edi>, bool b_focused)
{
  survarium::flash_value *v3; // ecx
  int v4; // ecx
  int v5; // eax
  survarium::flash_value argument; // [esp+8h] [ebp-18h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 24) + 952) + 20))(*(_DWORD *)(*(_DWORD *)(a2 + 24) + 952))
    && *(_BYTE *)(a2 + 20) != b_focused )
  {
    if ( *(_BYTE *)(a2 + 22) || !b_focused )
    {
      *(_DWORD *)argument.body = 0;
      *(_DWORD *)&argument.body[4] = 0;
      survarium::flash_value::SetBoolean(v3, &argument, b_focused);
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 28) + 264) + 4),
        "root.focus_chat",
        0,
        (const Scaleform::GFx::Value *)&argument,
        1u);
      if ( (argument.body[4] & 0x40) != 0 )
        (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)argument.body + 8))(
          *(_DWORD *)argument.body,
          &argument,
          *(_DWORD *)&argument.body[8]);
    }
    v4 = *(_DWORD *)(a2 + 24);
    *(_BYTE *)(a2 + 20) = b_focused;
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 40))(v4);
    if ( b_focused )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 16))(v5, a2);
    else
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 20))(v5, a2);
  }
}
