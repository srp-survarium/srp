void __thiscall Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::NotifyOnLoadComplete(
        Scaleform::GFx::AS2::CandidateListLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        int status)
{
  Scaleform::GFx::AS2::IMEManager *pObject; // eax
  Scaleform::GFx::AS2::MovieRoot *v5; // esi
  Scaleform::GFx::InteractiveObject_vtbl **v6; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value asFunc; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::Value func; // [esp+24h] [ebp-18h] BYREF

  if ( ptarget )
  {
    pObject = this->pASIMEManager.pObject;
    v5 = (Scaleform::GFx::AS2::MovieRoot *)pObject->pMovie->pASMovieRoot.pObject;
    v6 = &ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + ptarget->AvmObjOffset;
    func.pObjectInterface = 0;
    func.Type = VT_Undefined;
    asFunc.T.Type = 0;
    Scaleform::GFx::Movie::CreateFunction(pObject->pMovie, &func, pObject->CustomFuncCandList.pObject, 0);
    Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v5, &func, &asFunc);
    pStringManager = v5->BuiltinsMgr.pStringManager;
    LOBYTE(ptarget) = 0;
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "SendIMEMessage", 0xEu, 0);
    ++ConstStringNode->RefCount;
    ((void (__thiscall *)(char *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::InteractiveObject **))v6[1]->SetMatrix)(
      (char *)v6 + 4,
      penv,
      &ConstStringNode,
      &asFunc,
      &ptarget);
    v8 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    Scaleform::GFx::AS2::Value::~Value(&asFunc);
    if ( (func.Type & 0x40) != 0 )
      func.pObjectInterface->ObjectRelease(func.pObjectInterface, &func, (void *)func.mValue.IValue);
  }
}
