char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::ASString reqHtml)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebp
  int v7; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::TextField *v12; // edi
  const char *v13; // eax
  bool v14; // al
  Scaleform::AmpStats *v15; // esi
  bool v16; // bl
  Scaleform::AmpStats_vtbl *v17; // edi
  unsigned __int64 v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::AmpStats *v20; // esi
  Scaleform::AmpStats_vtbl *v21; // edi
  unsigned __int64 v22; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+20h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText,
    v5,
    "ObjectInterface::GetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetText);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v7 + 60) - 17) >= 0xC || (*(_DWORD *)(v7 + 56) & 0x20) != 0 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats )
    {
      v9 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    v12 = (Scaleform::GFx::TextField *)pdata[12];
    if ( v12->GetType(v12) == MouseWheel )
    {
      Scaleform::GFx::TextField::GetText(v12, &reqHtml, (Scaleform::String)reqHtml.pNode);
      Scaleform::GFx::AS3::Value::Value(&value, &reqHtml);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, (Scaleform::GFx::ASStringNode *)pval);
      Scaleform::GFx::AS3::Value::~Value(&value);
      pNode = reqHtml.pNode;
      --reqHtml.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v20 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats )
      {
        v21 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats->__vftable;
        v22 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v21->NativePopCallstack)(
          v20,
          v22 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks),
          (v22 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v13 = "htmlText";
      if ( !LOBYTE(reqHtml.pNode) )
        v13 = "text";
      v14 = this->GetMember(this, pdata, v13, pval, 1);
      v15 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats;
      v16 = v14;
      if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats )
      {
        v17 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.Stats->__vftable;
        v18 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v17->NativePopCallstack)(
          v15,
          v18 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks),
          (v18 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GetText.StartTicks) >> 32);
      }
      return v16;
    }
  }
}
