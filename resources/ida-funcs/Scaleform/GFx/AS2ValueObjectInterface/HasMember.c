char __thiscall Scaleform::GFx::AS2ValueObjectInterface::HasMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        char *name,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // bl
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v15; // esi
  Scaleform::AmpStats_vtbl *v16; // edi
  unsigned __int64 v17; // rax
  Scaleform::GFx::Value_AS2ObjectData v18; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::AmpFunctionTimer v19; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+24h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v19,
    v5,
    "ObjectInterface::HasMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_HasMember);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v18, this, pdata, (bool)isdobj);
  pObject = v18.pObject;
  if ( !v18.pObject )
  {
LABEL_7:
    Stats = v19.Stats;
    if ( v19.Stats )
    {
      v12 = v19.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v19.StartTicks),
        (ProfileTicks - v19.StartTicks) >> 32);
    }
    return 0;
  }
  pEnv = v18.pEnv;
  v20.T.Type = 0;
  isdobj = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)v18.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             name,
             strlen(name),
             0);
  ++isdobj->RefCount;
  v8 = !pObject->GetMember(pObject, pEnv, (const Scaleform::GFx::ASString *)&isdobj, &v20);
  v9 = isdobj;
  v10 = v8;
  --isdobj->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v10 )
  {
    if ( v20.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v20);
    goto LABEL_7;
  }
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  v15 = v19.Stats;
  if ( v19.Stats )
  {
    v16 = v19.Stats->__vftable;
    v17 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v16->NativePopCallstack)(
      v15,
      v17 - LODWORD(v19.StartTicks),
      (v17 - v19.StartTicks) >> 32);
  }
  return 1;
}
