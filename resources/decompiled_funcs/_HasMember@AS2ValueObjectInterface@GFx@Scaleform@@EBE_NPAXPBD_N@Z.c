char __thiscall Scaleform::GFx::AS2ValueObjectInterface::HasMember(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        char *name,
        Scaleform::GFx::ASStringNode *isdobj)
{
  Scaleform::GFx::AS2::ObjectInterface *pObject; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // edi
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // eax
  bool v8; // bl
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value member; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&o, this, pdata, (bool)isdobj);
  pObject = o.pObject;
  if ( !o.pObject )
    return 0;
  member.T.Type = 0;
  pEnv = o.pEnv;
  isdobj = Scaleform::GFx::ASStringManager::CreateConstStringNode(
             (Scaleform::GFx::ASStringManager *)o.pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
             name,
             strlen(name),
             0);
  ++isdobj->RefCount;
  v6 = !pObject->GetMember(pObject, pEnv, (const Scaleform::GFx::ASString *)&isdobj, &member);
  v7 = isdobj;
  v8 = v6;
  --isdobj->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v8 )
  {
    if ( member.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&member);
    return 0;
  }
  if ( member.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&member);
  return 1;
}
