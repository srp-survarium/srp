char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        __m128i *name,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::AmpStats *v8; // esi
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // eax
  bool v15; // bl
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v17; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS2::ObjectInterface *v19; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v20; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v21; // eax
  Scaleform::AmpStats *v22; // esi
  Scaleform::AmpStats_vtbl *v23; // edi
  unsigned __int64 v24; // rax
  Scaleform::GFx::Value_AS2ObjectData v25; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+14h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v27; // [esp+24h] [ebp-10h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v27,
    v6,
    "ObjectInterface::GetMember",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetMember);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v25, this, pdata, (bool)isdobj);
  pObject = v25.pObject;
  if ( v25.pObject )
  {
    pEnv = v25.pEnv;
    value.T.Type = 0;
    isdobj = Scaleform::GFx::ASStringManager::CreateStringNode(
               (Scaleform::GFx::ASStringManager *)v25.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
               name);
    ++isdobj->RefCount;
    v13 = !pObject->GetMember(pObject, pEnv, (const Scaleform::GFx::ASString *)&isdobj, &value);
    v14 = isdobj;
    v15 = v13;
    --isdobj->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    if ( v15 )
    {
      if ( pval )
      {
        if ( (pval->Type & 0x40) != 0 )
        {
          ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
            pval,
            pval->mValue.IValue);
          pval->pObjectInterface = 0;
        }
        pval->Type = VT_Undefined;
      }
      if ( value.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&value);
      Stats = v27.Stats;
      if ( v27.Stats )
      {
        v17 = v27.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v17->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v27.StartTicks),
          (ProfileTicks - v27.StartTicks) >> 32);
      }
      return 0;
    }
    else
    {
      if ( value.T.Type == 9 )
      {
        v19 = 0;
        if ( (unsigned int)(pObject->GetObjectType(pObject) - 6) <= 0x26 )
        {
          v20 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(pObject);
          if ( v20 )
            v19 = (Scaleform::GFx::AS2::ObjectInterface *)&v20[4];
          else
            v19 = 0;
        }
        if ( (unsigned int)(pObject->GetObjectType(pObject) - 2) <= 3 )
        {
          v21 = Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter(pObject);
          if ( v21 )
            v19 = (Scaleform::GFx::AS2::ObjectInterface *)&v21[1];
        }
        Scaleform::GFx::AS2::Value::GetPropertyValue(&value, pEnv, v19, &value);
      }
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v25.pRoot, pEnv, &value, pval);
      if ( value.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&value);
      v22 = v27.Stats;
      if ( v27.Stats )
      {
        v23 = v27.Stats->__vftable;
        v24 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v23->NativePopCallstack)(
          v22,
          v24 - LODWORD(v27.StartTicks),
          (v24 - v27.StartTicks) >> 32);
      }
      return 1;
    }
  }
  else
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(
          pval,
          pval->mValue.IValue);
        pval->pObjectInterface = 0;
      }
      pval->Type = VT_Undefined;
    }
    v8 = v27.Stats;
    if ( v27.Stats )
    {
      v9 = v27.Stats->__vftable;
      v10 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
        v8,
        v10 - LODWORD(v27.StartTicks),
        (v10 - v27.StartTicks) >> 32);
    }
    return 0;
  }
}
