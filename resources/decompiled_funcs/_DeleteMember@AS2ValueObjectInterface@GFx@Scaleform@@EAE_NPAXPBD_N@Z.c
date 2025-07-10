bool __thiscall Scaleform::GFx::AS2ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        char *name,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  bool v7; // bl
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+4h] [ebp-Ch] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&o, this, pdata, (bool)isdobj);
  pObject = o.pObject;
  if ( !o.pObject )
    return 0;
  p_StringContext = &o.pEnv->StringContext;
  isdobj = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)o.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             name,
             strlen(name),
             0);
  ++isdobj->RefCount;
  v7 = pObject->DeleteMember(pObject, p_StringContext, (const Scaleform::GFx::ASString *)&isdobj);
  v8 = isdobj;
  --isdobj->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  return v7;
}
