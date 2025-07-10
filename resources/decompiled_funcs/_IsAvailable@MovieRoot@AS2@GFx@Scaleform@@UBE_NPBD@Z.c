char __thiscall Scaleform::GFx::AS2::MovieRoot::IsAvailable(Scaleform::GFx::AS2::MovieRoot *this, char *pathToVar)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  int v4; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // edx
  unsigned int v8; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::AS2::Environment *v11; // esi
  char IsAvailable; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString path; // [esp+0h] [ebp-4h] BYREF

  path.pNode = (Scaleform::GFx::ASStringNode *)this;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v4 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v4 >= Size )
      return 0;
  }
  if ( !Data[v4].pSprite.pObject )
    return 0;
  v8 = 0;
  v9 = Data;
  while ( v9->Level )
  {
    ++v8;
    ++v9;
    if ( v8 >= Size )
    {
      pObject = 0;
      goto LABEL_13;
    }
  }
  pObject = Data[v8].pSprite.pObject;
LABEL_13:
  v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                         + pObject->AvmObjOffset)
                                                                       + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  path.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pathToVar);
  ++path.pNode->RefCount;
  IsAvailable = Scaleform::GFx::AS2::Environment::IsAvailable(v11, &path, 0);
  pNode = path.pNode;
  --path.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return IsAvailable;
}
