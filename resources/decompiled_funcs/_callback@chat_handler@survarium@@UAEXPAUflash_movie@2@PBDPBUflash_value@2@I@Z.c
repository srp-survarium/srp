void __thiscall survarium::chat_handler::callback(
        survarium::chat_handler *this,
        survarium::flash_movie *__formal,
        const char *methodName,
        const survarium::flash_value *args,
        unsigned int a5)
{
  bool *p_m_focused; // esi
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-18h] BYREF

  if ( !strcmp(methodName, "chat_enter_start") )
  {
    p_m_focused = &this[-1].m_focused;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)this->survarium::flash_external_handler::__vftable[119].~survarium::flash_external_handler
                                                   + 20))(this->survarium::flash_external_handler::__vftable[119].~survarium::flash_external_handler)
      && !p_m_focused[20] )
    {
      if ( p_m_focused[22] )
      {
        v6 = *((_DWORD *)p_m_focused + 7);
        pargs.pObjectInterface = 0;
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = 1;
        Scaleform::GFx::Movie::Invoke(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(v6 + 264) + 4),
          "root.focus_chat",
          0,
          &pargs,
          1u);
        if ( (pargs.Type & 0x40) != 0 )
          pargs.pObjectInterface->ObjectRelease(pargs.pObjectInterface, &pargs, (void *)pargs.mValue.IValue);
      }
      v7 = *((_DWORD *)p_m_focused + 6);
      p_m_focused[20] = 1;
      v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 40))(v7);
      (*(void (__thiscall **)(int, bool *))(*(_DWORD *)v8 + 16))(v8, p_m_focused);
    }
  }
  else if ( !strcmp(methodName, "chat_enter_cancel") )
  {
    survarium::chat_handler::focus(this, (int)&this[-1].m_focused, 0);
  }
  else if ( !strcmp(methodName, "set_mouse_cursor") && !BYTE2(this->survarium::flash_function_handler::impl) )
  {
    survarium::lobby_menu::set_cursor(
      (survarium::lobby_menu *)this->survarium::flash_external_handler::__vftable[110].callback,
      args->body[8]);
  }
}
