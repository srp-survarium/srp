char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        char *name,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // bl
  Scaleform::GFx::AS2::ObjectInterface *v11; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v12; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v13; // eax
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value asval; // [esp+14h] [ebp-10h] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&o, this, pdata, (bool)isdobj);
  pObject = o.pObject;
  if ( o.pObject )
  {
    pEnv = o.pEnv;
    asval.T.Type = 0;
    isdobj = Scaleform::GFx::ASStringManager::CreateStringNode(
               (Scaleform::GFx::ASStringManager *)o.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
               name);
    ++isdobj->RefCount;
    v8 = !pObject->GetMember(pObject, pEnv, (const Scaleform::GFx::ASString *)&isdobj, &asval);
    v9 = isdobj;
    v10 = v8;
    --isdobj->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( v10 )
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
      if ( asval.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&asval);
      return 0;
    }
    else
    {
      if ( asval.T.Type == 9 )
      {
        v11 = 0;
        if ( (unsigned int)(pObject->GetObjectType(pObject) - 6) <= 0x26 )
        {
          v12 = Scaleform::GFx::AS2::ObjectInterface::ToASObject(pObject);
          if ( v12 )
            v11 = (Scaleform::GFx::AS2::ObjectInterface *)&v12[4];
          else
            v11 = 0;
        }
        if ( (unsigned int)(pObject->GetObjectType(pObject) - 2) <= 3 )
        {
          v13 = Scaleform::GFx::AS2::ObjectInterface::ToAvmCharacter(pObject);
          if ( v13 )
            v11 = (Scaleform::GFx::AS2::ObjectInterface *)&v13[1];
        }
        Scaleform::GFx::AS2::Value::GetPropertyValue(&asval, pEnv, v11, &asval);
      }
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value(o.pRoot, pEnv, &asval, pval);
      if ( asval.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&asval);
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
    return 0;
  }
}
