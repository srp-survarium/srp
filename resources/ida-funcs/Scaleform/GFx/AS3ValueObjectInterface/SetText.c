char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        const __m128i *ptext,
        char reqHtml)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  int v6; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::TextField *v11; // esi
  const char *v12; // eax
  bool v13; // bl
  Scaleform::AmpStats *v14; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 v16; // rax
  unsigned int Flags; // ecx
  unsigned int v18; // ecx
  Scaleform::AmpStats *v19; // esi
  Scaleform::AmpStats_vtbl *v20; // edi
  unsigned __int64 v21; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText; // [esp+18h] [ebp-28h] BYREF
  int v23; // [esp+28h] [ebp-18h] BYREF
  int v24; // [esp+2Ch] [ebp-14h]
  const __m128i *v25; // [esp+30h] [ebp-10h]

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText,
    v5,
    "ObjectInterface::SetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetText);
  v6 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v6 + 60) - 17) >= 0xC || (*(_DWORD *)(v6 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
    {
      v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
    }
    return 0;
  }
  v11 = (Scaleform::GFx::TextField *)pdata[12];
  if ( v11->GetType(v11) != MouseWheel )
  {
    v23 = 0;
    v24 = 6;
    v25 = ptext;
    v12 = "htmlText";
    if ( !reqHtml )
      v12 = "text";
    v13 = this->SetMember(this, pdata, v12, (const Scaleform::GFx::Value *)&v23, 1);
    if ( (v24 & 0x40) != 0 )
    {
      (*(void (__thiscall **)(int, int *, const __m128i *))(*(_DWORD *)v23 + 8))(v23, &v23, v25);
      v23 = 0;
    }
    v14 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
    v24 = 0;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
    {
      v15 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
      v16 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
        v14,
        v16 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
        (v16 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
    }
    return v13;
  }
  Flags = v11->Flags;
  if ( reqHtml )
  {
    if ( (v11->Flags & 2) == 0 )
    {
      v18 = Flags | 2;
LABEL_19:
      v11->Flags = v18;
    }
  }
  else if ( (v11->Flags & 2) != 0 )
  {
    v18 = Flags & 0xFFFFFFFD;
    goto LABEL_19;
  }
  Scaleform::GFx::TextField::SetTextValue(v11, ptext, reqHtml, 1);
  v19 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
  {
    v20 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
    v21 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v20->NativePopCallstack)(
      v19,
      v21 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
      (v21 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
  }
  return 1;
}


char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        wchar_t *ptext,
        char reqHtml)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  int v6; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::TextField *v11; // edi
  const char *v12; // eax
  bool v13; // bl
  Scaleform::AmpStats *v14; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 v16; // rax
  Scaleform::AmpStats *v17; // esi
  Scaleform::AmpStats_vtbl *v18; // edi
  unsigned __int64 v19; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText; // [esp+18h] [ebp-28h] BYREF
  int v21; // [esp+28h] [ebp-18h] BYREF
  int v22; // [esp+2Ch] [ebp-14h]
  wchar_t *v23; // [esp+30h] [ebp-10h]

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText,
    v5,
    "ObjectInterface::SetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetText);
  v6 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v6 + 60) - 17) >= 0xC || (*(_DWORD *)(v6 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
    {
      v8 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v11 = (Scaleform::GFx::TextField *)pdata[12];
    if ( v11->GetType(v11) == MouseWheel )
    {
      Scaleform::GFx::TextField::SetText(v11, ptext, reqHtml);
      v17 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
      {
        v18 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
        v19 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v18->NativePopCallstack)(
          v17,
          v19 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
          (v19 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v21 = 0;
      v22 = 7;
      v23 = ptext;
      v12 = "htmlText";
      if ( !reqHtml )
        v12 = "text";
      v13 = this->SetMember(this, pdata, v12, (const Scaleform::GFx::Value *)&v21, 1);
      if ( (v22 & 0x40) != 0 )
      {
        (*(void (__thiscall **)(int, int *, wchar_t *))(*(_DWORD *)v21 + 8))(v21, &v21, v23);
        v21 = 0;
      }
      v14 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats;
      v22 = 0;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats )
      {
        v15 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.Stats->__vftable;
        v16 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
          v14,
          v16 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks),
          (v16 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_SetText.StartTicks) >> 32);
      }
      return v13;
    }
  }
}
