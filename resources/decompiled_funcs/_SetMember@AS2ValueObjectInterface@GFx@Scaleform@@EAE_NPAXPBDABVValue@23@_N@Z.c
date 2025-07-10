bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::ASStringNode *pdata,
        char *name,
        const Scaleform::GFx::Value *value,
        bool isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  bool v8; // bl
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value asval; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(
    &o,
    this,
    (Scaleform::GFx::AS2::ObjectInterface *)pdata,
    isdobj);
  pObject = o.pObject;
  if ( !o.pObject )
    return 0;
  asval.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(o.pRoot, value, &asval);
  pEnv = o.pEnv;
  isdobj = 0;
  pdata = Scaleform::GFx::ASStringManager::CreateStringNode(
            (Scaleform::GFx::ASStringManager *)o.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            name);
  ++pdata->RefCount;
  v8 = pObject->SetMember(
         pObject,
         pEnv,
         (const Scaleform::GFx::ASString *)&pdata,
         &asval,
         (const Scaleform::GFx::AS2::PropFlags *)&isdobj);
  v9 = pdata;
  --pdata->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( asval.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&asval);
  return v8;
}
