void __userpurge survarium::chat_handler::focus(survarium::chat_handler *this@<ecx>, int a2@<edi>, bool b_focused)
{
  survarium::flash_value *v3; // ecx
  int v4; // ecx
  int *v5; // eax
  int v6; // edx
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-1Ch] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 16) + 13912) + 32))(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 13912))
    && *(_BYTE *)(a2 + 12) != b_focused )
  {
    if ( *(_BYTE *)(a2 + 14) || !b_focused )
    {
      pargs.pObjectInterface = 0;
      pargs.Type = VT_Undefined;
      survarium::flash_value::SetBoolean(v3, (int)&pargs, b_focused);
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 264) + 4),
        "root.focus_chat",
        0,
        &pargs,
        1u);
      Scaleform::GFx::Value::~Value(&pargs);
    }
    v4 = *(_DWORD *)(a2 + 16);
    *(_BYTE *)(a2 + 12) = b_focused;
    v5 = (int *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4);
    v6 = *v5;
    if ( b_focused )
      (*(void (__thiscall **)(int *, int))(v6 + 16))(v5, a2);
    else
      (*(void (__thiscall **)(int *, int))(v6 + 20))(v5, a2);
  }
}
