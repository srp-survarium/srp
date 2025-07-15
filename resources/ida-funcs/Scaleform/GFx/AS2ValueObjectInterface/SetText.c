bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const __m128i *ptext,
        char reqHtml)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // eax
  Scaleform::GFx::TextField *v7; // edi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
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
  Scaleform::AmpFunctionTimer v22; // [esp+18h] [ebp-28h] BYREF
  int v23; // [esp+28h] [ebp-18h] BYREF
  int v24; // [esp+2Ch] [ebp-14h]
  const __m128i *v25; // [esp+30h] [ebp-10h]

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v22,
    v5,
    "ObjectInterface::SetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetText);
  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v7 = (Scaleform::GFx::TextField *)v6;
  if ( !v6 )
  {
    Stats = v22.Stats;
    if ( v22.Stats )
    {
      v9 = v22.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v22.StartTicks),
        (ProfileTicks - v22.StartTicks) >> 32);
    }
    return 0;
  }
  if ( v6->GetType(v6) != MouseWheel )
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
    v14 = v22.Stats;
    v24 = 0;
    if ( v22.Stats )
    {
      v15 = v22.Stats->__vftable;
      v16 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
        v14,
        v16 - LODWORD(v22.StartTicks),
        (v16 - v22.StartTicks) >> 32);
    }
    return v13;
  }
  Flags = v7->Flags;
  if ( reqHtml )
  {
    if ( (v7->Flags & 2) == 0 )
    {
      v18 = Flags | 2;
LABEL_18:
      v7->Flags = v18;
    }
  }
  else if ( (v7->Flags & 2) != 0 )
  {
    v18 = Flags & 0xFFFFFFFD;
    goto LABEL_18;
  }
  Scaleform::GFx::TextField::SetTextValue(v7, ptext, reqHtml, 1);
  v19 = v22.Stats;
  if ( v22.Stats )
  {
    v20 = v22.Stats->__vftable;
    v21 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v20->NativePopCallstack)(
      v19,
      v21 - LODWORD(v22.StartTicks),
      (v21 - v22.StartTicks) >> 32);
  }
  return 1;
}


bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        __int64 ptext)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::TextField *v6; // edi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  const char *v11; // eax
  bool v12; // bl
  Scaleform::AmpStats *v13; // esi
  Scaleform::AmpStats_vtbl *v14; // edi
  unsigned __int64 v15; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v17; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v19; // [esp+18h] [ebp-28h] BYREF
  int v20; // [esp+28h] [ebp-18h] BYREF
  int v21; // [esp+2Ch] [ebp-14h]
  int v22; // [esp+30h] [ebp-10h]

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v19,
    v4,
    "ObjectInterface::SetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetText);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v6 = (Scaleform::GFx::TextField *)v5;
  if ( v5 )
  {
    if ( v5->GetType(v5) == MouseWheel )
    {
      Scaleform::GFx::TextField::SetText(v6, (wchar_t *)ptext, SBYTE4(ptext));
      Stats = v19.Stats;
      if ( v19.Stats )
      {
        v17 = v19.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v17->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v19.StartTicks),
          (ProfileTicks - v19.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v20 = 0;
      v21 = 7;
      v22 = ptext;
      v11 = "htmlText";
      if ( !BYTE4(ptext) )
        v11 = "text";
      v12 = this->SetMember(this, pdata, v11, (const Scaleform::GFx::Value *)&v20, 1);
      if ( (v21 & 0x40) != 0 )
      {
        (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)v20 + 8))(v20, &v20, v22);
        v20 = 0;
      }
      v13 = v19.Stats;
      v21 = 0;
      if ( v19.Stats )
      {
        v14 = v19.Stats->__vftable;
        v15 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v14->NativePopCallstack)(
          v13,
          v15 - LODWORD(v19.StartTicks),
          (v15 - v19.StartTicks) >> 32);
      }
      return v12;
    }
  }
  else
  {
    v7 = v19.Stats;
    if ( v19.Stats )
    {
      v8 = v19.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v19.StartTicks),
        (v9 - v19.StartTicks) >> 32);
    }
    return 0;
  }
}
