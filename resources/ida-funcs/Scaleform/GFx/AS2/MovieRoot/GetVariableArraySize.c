unsigned int __thiscall Scaleform::GFx::AS2::MovieRoot::GetVariableArraySize(
        Scaleform::GFx::AS2::MovieRoot *this,
        __m128i *ppathToVar)
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
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::Object *v13; // esi
  unsigned int RootIndex; // esi
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  __int64 v17; // [esp-18h] [ebp-30h]
  Scaleform::GFx::ASStringNode *StringNode; // [esp+4h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v19; // [esp+8h] [ebp-10h] BYREF

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
      goto LABEL_12;
    }
  }
  pObject = Data[v8].pSprite.pObject;
LABEL_12:
  v11 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                         + pObject->AvmObjOffset)
                                                                       + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 ppathToVar);
  ++StringNode->RefCount;
  HIDWORD(v17) = &v19;
  LODWORD(v17) = &StringNode;
  v19.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v11, v17, 0, 0, 0)
    || v19.T.Type != 6
    || (v12 = Scaleform::GFx::AS2::Value::ToObject(&v19, v11), (v13 = v12) == 0)
    || v12->GetObjectType(&v12->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
  {
    if ( v19.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v19);
    v16 = StringNode;
    --StringNode->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    return 0;
  }
  RootIndex = v13[1].RootIndex;
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v15 = StringNode;
  --StringNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  return RootIndex;
}
