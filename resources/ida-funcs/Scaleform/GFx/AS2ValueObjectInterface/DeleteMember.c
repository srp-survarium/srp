bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        char *name,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  bool v12; // bl
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::Value_AS2ObjectData v17; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::AmpFunctionTimer v18; // [esp+14h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v18,
    v5,
    "ObjectInterface::DeleteMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_DeleteMember);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v17, this, pdata, (bool)isdobj);
  pObject = v17.pObject;
  if ( v17.pObject )
  {
    p_StringContext = &v17.pEnv->StringContext;
    isdobj = Scaleform::GFx::ASStringManager::CreateConstStringNode(
               (Scaleform::GFx::ASStringManager *)v17.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
               name,
               strlen(name),
               0);
    ++isdobj->RefCount;
    v12 = pObject->DeleteMember(pObject, p_StringContext, (const Scaleform::GFx::ASString *)&isdobj);
    v13 = isdobj;
    --isdobj->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
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
    return v12;
  }
  else
  {
    v7 = v18.Stats;
    if ( v18.Stats )
    {
      v8 = v18.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v18.StartTicks),
        (v9 - v18.StartTicks) >> 32);
    }
    return 0;
  }
}
