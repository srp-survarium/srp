// local variable allocation has failed, the output may be wrong!
Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::Environment::FindTarget(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *path,
        char excludeFlags)
{
  Scaleform::GFx::InteractiveObject *Target; // ebx
  char *pData; // esi
  char *v7; // eax
  char *v8; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString subpart; // [esp+8h] [ebp-8h] BYREF
  int first_call; // [esp+Ch] [ebp-4h] OVERLAPPED

  if ( !path->pNode->Size )
  {
    if ( (*((_BYTE *)this + 194) & 2) != 0 )
      return 0;
    else
      return this->Target;
  }
  Target = this->Target;
  pData = (char *)path->pNode->pData;
  subpart.pNode = (Scaleform::GFx::ASStringNode *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++subpart.pNode->RefCount;
  if ( *pData == 47 )
  {
    Target = Target->GetTopParent(Target, 0);
    ++pData;
  }
  LOBYTE(first_call) = 1;
  while ( 2 )
  {
    v7 = pData;
    if ( !*pData )
    {
LABEL_14:
      v8 = 0;
      goto LABEL_15;
    }
    while ( *v7 == 46 )
    {
      if ( v7[1] != 46 )
        goto LABEL_18;
      ++v7;
LABEL_13:
      if ( !*++v7 )
        goto LABEL_14;
    }
    if ( *v7 != 47 )
      goto LABEL_13;
LABEL_18:
    v8 = v7;
LABEL_15:
    if ( v8 == pData )
    {
      if ( (excludeFlags & 4) == 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          this,
          "Invalid path '%s'",
          path->pNode->pData);
    }
    else
    {
      if ( v8 )
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       pData,
                       v8 - pData);
      else
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       pData);
      v10 = StringNode;
      StringNode->RefCount += 2;
      pNode = subpart.pNode;
      --subpart.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      subpart.pNode = v10;
      if ( v10->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      if ( subpart.pNode->Size )
      {
        if ( Target )
          v13 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + Target->AvmObjOffset)
                                           + 4))((int)Target + 4 * Target->AvmObjOffset);
        else
          v13 = 0;
        Target = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int, Scaleform::GFx::ASString *, int))(*(_DWORD *)v13 + 108))(
                                                        v13,
                                                        &subpart,
                                                        first_call);
      }
      if ( Target && v8 )
      {
        pData = v8 + 1;
        LOBYTE(first_call) = 0;
        continue;
      }
    }
    break;
  }
  v14 = subpart.pNode;
  --subpart.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  return Target;
}
