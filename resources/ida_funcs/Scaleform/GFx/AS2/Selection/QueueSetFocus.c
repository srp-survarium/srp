void __cdecl Scaleform::GFx::AS2::Selection::QueueSetFocus(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  unsigned int Size; // esi
  Scaleform::GFx::AS2::Value *v6; // ecx
  unsigned int v7; // esi
  Scaleform::GFx::AS2::Value *Data; // ebp
  Scaleform::GFx::ASMovieRootBase *v9; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int v11; // edx
  unsigned int v12; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // edi
  Scaleform::GFx::MovieImpl::LevelInfo *v14; // ecx
  Scaleform::GFx::InteractiveObject *v15; // edi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v17; // esi
  Scaleform::RefCountNTSImpl *v18; // ecx
  Scaleform::RefCountNTSImpl *v19; // ecx
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> params; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+18h] [ebp-10h] BYREF

  memset(&params, 0, sizeof(params));
  if ( pNewFocus )
  {
    pObject = pNewFocus->pNameHandle.pObject;
    v.T.Type = 7;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pNewFocus);
    v.NV.Int32Value = (int)pObject;
    if ( pObject )
      ++pObject->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &params.Data,
      &params,
      1u);
    Size = params.Data.Size;
    v6 = &params.Data.Data[params.Data.Size - 1];
    if ( &params.Data.Data[params.Data.Size] == (Scaleform::GFx::AS2::Value *)16 )
      goto LABEL_10;
  }
  else
  {
    v.T.Type = 1;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &params.Data,
      &params,
      1u);
    Size = params.Data.Size;
    v6 = &params.Data.Data[params.Data.Size - 1];
    if ( &params.Data.Data[params.Data.Size] == (Scaleform::GFx::AS2::Value *)16 )
      goto LABEL_11;
  }
  Scaleform::GFx::AS2::Value::Value(v6, &v);
  if ( v.T.Type >= 5u )
LABEL_10:
    Scaleform::GFx::AS2::Value::DropRefs(&v);
LABEL_11:
  v.T.Type = 4;
  v.NV.Int32Value = fmt;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &params.Data,
    &params,
    Size + 1);
  v7 = params.Data.Size;
  if ( &params.Data.Data[params.Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
  {
    Scaleform::GFx::AS2::Value::Value(&params.Data.Data[params.Data.Size - 1], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  v.T.Type = 3;
  v.NV.NumberValue = (double)controllerIdx;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &params.Data,
    &params,
    v7 + 1);
  Data = params.Data.Data;
  if ( &params.Data.Data[params.Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
  {
    Scaleform::GFx::AS2::Value::Value(&params.Data.Data[params.Data.Size - 1], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  v9 = penv->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  pMovieImpl = v9->pMovieImpl;
  v11 = pMovieImpl->MovieLevels.Data.Size;
  v12 = 0;
  if ( v11 )
  {
    v13 = pMovieImpl->MovieLevels.Data.Data;
    v14 = v13;
    while ( v14->Level )
    {
      ++v12;
      ++v14;
      if ( v12 >= v11 )
        goto LABEL_21;
    }
    v15 = v13[v12].pSprite.pObject;
  }
  else
  {
LABEL_21:
    v15 = 0;
  }
  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v9[3].pMovieImpl,
               AP_Frame);
  v17 = inserted;
  inserted->Type = Entry_CFunction;
  if ( v15 )
    ++v15->RefCount;
  v18 = inserted->pCharacter.pObject;
  if ( v18 )
    Scaleform::RefCountNTSImpl::Release(v18);
  v17->pCharacter.pObject = v15;
  v19 = v17->pActionBuffer.pObject;
  if ( v19 )
    Scaleform::RefCountNTSImpl::Release(v19);
  v17->pActionBuffer.pObject = 0;
  v17->CFunction = (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))Scaleform::GFx::AS2::Selection::DoTransferFocus;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &v17->FunctionParams,
    &params);
  Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(Data, params.Data.Size);
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
}
