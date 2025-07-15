void __thiscall Scaleform::GFx::AS2::IMEManager::BroadcastSetIMEName(
        Scaleform::GFx::AS2::IMEManager *this,
        __m128i *pString)
{
  Scaleform::GFx::Movie *pMovie; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v5; // eax
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::InteractiveObject *pMainMovie; // ebx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v10; // edi
  Scaleform::RefCountNTSImpl *v11; // ecx
  Scaleform::RefCountNTSImpl *v12; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > a; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+10h] [ebp-10h] BYREF

  pMovie = this->pMovie;
  memset(&a, 0, sizeof(a));
  if ( pMovie )
  {
    pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovie->pASMovieRoot.pObject;
    LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
    v5 = (*(int (__thiscall **)(int))(*((_DWORD *)&LevelMovie->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + LevelMovie->AvmObjOffset)
                                    + 124))((int)LevelMovie + 4 * LevelMovie->AvmObjOffset);
    StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(*(Scaleform::GFx::AS2::GlobalContext **)(v5 + 116));
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, pString);
    ++StringNode->RefCount;
    v.T.Type = 5;
    v.NV.Int32Value = (int)StringNode;
    ++StringNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &a.Data,
      &a,
      1u);
    if ( &a.Data.Data[a.Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
      Scaleform::GFx::AS2::Value::Value(&a.Data.Data[a.Data.Size - 1], &v);
    pMainMovie = pObject->pMovieImpl->pMainMovie;
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(&pObject->ActionQueue, AP_Frame);
    v10 = inserted;
    inserted->Type = Entry_CFunction;
    if ( pMainMovie )
      ++pMainMovie->RefCount;
    v11 = inserted->pCharacter.pObject;
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
    v10->pCharacter.pObject = pMainMovie;
    v12 = v10->pActionBuffer.pObject;
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    v10->pActionBuffer.pObject = 0;
    v10->CFunction = Scaleform::GFx::AS2::IMEManager::OnBroadcastSetIMEName;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &v10->FunctionParams,
      &a);
    Scaleform::GFx::AS2::Value::~Value(&v);
    if ( StringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>::~Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *)&a);
}
