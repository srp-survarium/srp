bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        __m128i *name,
        Scaleform::GFx::Value *value,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::AmpStats *v8; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::Value_AS2ObjectData v17; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::AmpFunctionTimer v18; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+24h] [ebp-10h] BYREF
  bool v20; // [esp+38h] [ebp+4h]

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v18,
    v6,
    "ObjectInterface::SetMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_SetMember);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v17, this, pdata, isdobj);
  pObject = v17.pObject;
  if ( v17.pObject )
  {
    pdestVal.T.Type = 0;
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v17.pRoot, value, &pdestVal);
    pEnv = v17.pEnv;
    isdobj = 0;
    value = (Scaleform::GFx::Value *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                       (Scaleform::GFx::ASStringManager *)v17.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                       name);
    ++*((_DWORD *)&value->mValue.BValue + 1);
    v20 = pObject->SetMember(
            pObject,
            pEnv,
            (const Scaleform::GFx::ASString *)&value,
            &pdestVal,
            (const Scaleform::GFx::AS2::PropFlags *)&isdobj);
    v13 = (Scaleform::GFx::ASStringNode *)value;
    --*((_DWORD *)&value->mValue.BValue + 1);
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( pdestVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
    Stats = v18.Stats;
    if ( v18.Stats )
    {
      v15 = v18.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v18.StartTicks),
        (ProfileTicks - v18.StartTicks) >> 32);
    }
    return v20;
  }
  else
  {
    v8 = v18.Stats;
    if ( v18.Stats )
    {
      v9 = v18.Stats->__vftable;
      v10 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
        v8,
        v10 - LODWORD(v18.StartTicks),
        (v10 - v18.StartTicks) >> 32);
    }
    return 0;
  }
}
