bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetText(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        Scaleform::GFx::Value *pval,
        Scaleform::String reqHtml)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::TextField *v8; // ebx
  Scaleform::AmpStats *v9; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 v11; // rax
  const char *v13; // eax
  bool v14; // al
  Scaleform::AmpStats *v15; // esi
  bool v16; // bl
  Scaleform::AmpStats_vtbl *v17; // edi
  unsigned __int64 v18; // rax
  Scaleform::GFx::AS2::MovieRoot *pObject; // esi
  Scaleform::GFx::AS2::Environment *v20; // edi
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v24; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v26; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+20h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v26,
    v5,
    "ObjectInterface::GetText",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetText);
  v6 = pdata;
  v7 = Scaleform::GFx::CharacterHandle::ResolveCharacter((Scaleform::GFx::CharacterHandle *)pdata, this->pMovieRoot);
  v8 = (Scaleform::GFx::TextField *)v7;
  if ( v7 )
  {
    if ( v7->GetType(v7) == MouseWheel )
    {
      pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
      v20 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->pMovieImpl->pMainMovie->__vftable
                                                                             + pObject->pMovieImpl->pMainMovie->AvmObjOffset)
                                                                           + 124))(
                                                  (int)pObject->pMovieImpl->pMainMovie
                                                + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset);
      Scaleform::GFx::TextField::GetText(v8, (Scaleform::GFx::ASString *)&pdata, reqHtml);
      v21 = pdata;
      ++pdata->RefCount;
      value.NV.Int32Value = (int)v21;
      value.T.Type = 5;
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, v20, &value, pval);
      Scaleform::GFx::AS2::Value::DropRefs(&value);
      v22 = pdata;
      --pdata->RefCount;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      Stats = v26.Stats;
      if ( v26.Stats )
      {
        v24 = v26.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v24->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v26.StartTicks),
          (ProfileTicks - v26.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v13 = "htmlText";
      if ( !LOBYTE(reqHtml.pData) )
        v13 = "text";
      v14 = this->GetMember(this, v6, v13, pval, 1);
      v15 = v26.Stats;
      v16 = v14;
      if ( v26.Stats )
      {
        v17 = v26.Stats->__vftable;
        v18 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v17->NativePopCallstack)(
          v15,
          v18 - LODWORD(v26.StartTicks),
          (v18 - v26.StartTicks) >> 32);
      }
      return v16;
    }
  }
  else
  {
    v9 = v26.Stats;
    if ( v26.Stats )
    {
      v10 = v26.Stats->__vftable;
      v11 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        v9,
        v11 - LODWORD(v26.StartTicks),
        (v11 - v26.StartTicks) >> 32);
    }
    return 0;
  }
}
