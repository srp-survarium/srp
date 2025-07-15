Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::Environment::FindTarget(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *path,
        char excludeFlags)
{
  Scaleform::GFx::InteractiveObject *Target; // ebx
  __m128i *pData; // esi
  __m128i *v7; // eax
  __m128i *v8; // edi
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // eax
  int v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *RefCount; // [esp+8h] [ebp-8h] BYREF
  int v16; // [esp+Ch] [ebp-4h]

  if ( !path->pNode->Size )
  {
    if ( (*((_BYTE *)this + 194) & 2) != 0 )
      return 0;
    else
      return this->Target;
  }
  Target = this->Target;
  pData = (__m128i *)path->pNode->pData;
  RefCount = (Scaleform::GFx::ASStringNode *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  if ( pData->m128i_i8[0] == 47 )
  {
    Target = Target->GetTopParent(Target, 0);
    pData = (__m128i *)((char *)pData + 1);
  }
  LOBYTE(v16) = 1;
  while ( 2 )
  {
    v7 = pData;
    if ( !pData->m128i_i8[0] )
    {
LABEL_14:
      v8 = 0;
      goto LABEL_15;
    }
    while ( v7->m128i_i8[0] == 46 )
    {
      if ( v7->m128i_i8[1] != 46 )
        goto LABEL_18;
      v7 = (__m128i *)((char *)v7 + 1);
LABEL_13:
      v7 = (__m128i *)((char *)v7 + 1);
      if ( !v7->m128i_i8[0] )
        goto LABEL_14;
    }
    if ( v7->m128i_i8[0] != 47 )
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
                       (char *)v8 - (char *)pData);
      else
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       (Scaleform::GFx::ASStringManager *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       pData);
      v10 = StringNode;
      StringNode->RefCount += 2;
      v11 = RefCount;
      --RefCount->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      RefCount = v10;
      if ( v10->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      if ( RefCount->Size )
      {
        if ( Target )
          v13 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + Target->AvmObjOffset)
                                           + 4))((int)Target + 4 * Target->AvmObjOffset);
        else
          v13 = 0;
        Target = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int, Scaleform::GFx::ASStringNode **, int))(*(_DWORD *)v13 + 108))(
                                                        v13,
                                                        &RefCount,
                                                        v16);
      }
      if ( Target && v8 )
      {
        pData = (__m128i *)&v8->m128i_i8[1];
        LOBYTE(v16) = 0;
        continue;
      }
    }
    break;
  }
  v14 = RefCount;
  --RefCount->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  return Target;
}
