char __thiscall Scaleform::GFx::AS3ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::RefCountVImpl *pdata,
        Scaleform::GFx::Value *pmc,
        const char *symbolName,
        char *instanceName,
        int depth,
        const Scaleform::GFx::MemberValueSet *initArgs)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // ebp
  volatile int RefCount; // eax
  Scaleform::GFx::DisplayObjContainer *v10; // edi
  Scaleform::GFx::AS3::VM *v11; // esi
  int v12; // eax
  int v13; // eax
  bool v14; // al
  Scaleform::GFx::LogState *v15; // edi
  int v16; // esi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *VInt; // esi
  Scaleform::GFx::ASStringNode *v18; // eax
  const Scaleform::GFx::MemberValueSet *v19; // ebx
  const char *v20; // esi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::AS3::GASRefCountBase *v22; // eax
  int v24; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v25; // esi
  int v26; // edi
  Scaleform::GFx::LogState *v27; // ebx
  Scaleform::Render::TreeNode *v28; // eax
  Scaleform::GFx::InteractiveObject **pmcObj; // [esp+Ch] [ebp-64h]
  Scaleform::GFx::ASString v; // [esp+10h] [ebp-60h] BYREF
  Scaleform::GFx::DisplayObjContainer *parentDispObj; // [esp+14h] [ebp-5Ch]
  Scaleform::GFx::AS3::Value asObj; // [esp+18h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value propval; // [esp+28h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value undefVal; // [esp+38h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value nameVal; // [esp+48h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname propname; // [esp+58h] [ebp-18h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  RefCount = pdata[2].RefCount;
  if ( (unsigned int)(*(_DWORD *)(RefCount + 60) - 23) >= 6 || (*(_DWORD *)(RefCount + 56) & 0x20) != 0 )
    return 0;
  v10 = (Scaleform::GFx::DisplayObjContainer *)pdata[6].__vftable;
  asObj.Flags = 0;
  asObj.Bonus.pWeakProxy = 0;
  v11 = pObject->pAVM.pObject;
  parentDispObj = v10;
  if ( v10
    && (v12 = (*(int (__thiscall **)(int))(*((_DWORD *)&v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v10->AvmObjOffset)
                                         + 20))((int)v10 + 4 * v10->AvmObjOffset)) != 0 )
  {
    v13 = v12 - 36;
  }
  else
  {
    v13 = 0;
  }
  v14 = Scaleform::GFx::AS3::VM::Construct(
          v11,
          symbolName,
          *(Scaleform::GFx::ASStringNode **)(v13 + 20),
          &asObj,
          0,
          0,
          0);
  if ( v11->HandleException )
    goto LABEL_12;
  if ( v14 )
    Scaleform::GFx::AS3::VM::ExecuteCode(v11, 1u);
  if ( v11->HandleException )
  {
LABEL_12:
    v15 = Scaleform::GFx::StateBag::GetLogState(
            &pObject->pMovieImpl->Scaleform::GFx::StateBag,
            (Scaleform::Ptr<Scaleform::GFx::LogState> *)&pdata)->pObject;
    if ( pdata )
      Scaleform::RefCountImpl::Release(pdata);
    if ( v15 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v15->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "attachMovie() failed - export name \"%s\" is not found.",
        symbolName);
    v11->HandleException = 0;
    goto LABEL_17;
  }
  v16 = *(_DWORD *)(asObj.value.VS._1.VInt + 20);
  if ( (unsigned int)(*(_DWORD *)(v16 + 60) - 17) >= 0xC || (*(_DWORD *)(v16 + 56) & 0x20) != 0 )
  {
LABEL_17:
    Scaleform::GFx::AS3::Value::~Value(&asObj);
    return 0;
  }
  VInt = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)asObj.value.VS._1.VInt;
  undefVal.Flags = 0;
  undefVal.Bonus.pWeakProxy = 0;
  pmcObj = (Scaleform::GFx::InteractiveObject **)asObj.value.VS._1.VInt;
  pdata = (Scaleform::RefCountVImpl *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                        pObject->BuiltinsMgr.pStringManager,
                                        instanceName);
  ++pdata[1].RefCount;
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
    VInt,
    &undefVal,
    (const Scaleform::GFx::ASString *)&pdata);
  v18 = (Scaleform::GFx::ASStringNode *)pdata;
  --pdata[1].RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = initArgs;
  if ( initArgs )
  {
    initArgs = 0;
    if ( v19->Data.Size )
    {
      instanceName = 0;
      do
      {
        v20 = &instanceName[(unsigned int)v19->Data.Data];
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       pObject->BuiltinsMgr.pStringManager,
                       (char *)((*(_DWORD *)v20 & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(*(_DWORD *)v20 & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        v.pNode = StringNode;
        Scaleform::GFx::AS3::Value::Value(&nameVal, &v);
        v22 = pObject->pAVM.pObject->PublicNamespace.pObject;
        propname.Kind = MN_QName;
        propname.Obj.pObject = v22;
        if ( v22 )
          v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
        propname.Name.Flags = 0;
        propname.Name.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&propname, &nameVal);
        Scaleform::GFx::AS3::Value::~Value(&nameVal);
        if ( StringNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
        propval.Flags = 0;
        propval.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, (Scaleform::GFx::ASStringNode *)(v20 + 8), &propval);
        ((void (__thiscall *)(Scaleform::GFx::InteractiveObject **, Scaleform::RefCountVImpl **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*pmcObj)->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable)(
          pmcObj,
          &pdata,
          &propname,
          &propval);
        Scaleform::GFx::AS3::Value::~Value(&propval);
        Scaleform::GFx::AS3::Multiname::~Multiname(&propname);
        instanceName += 32;
        initArgs = (const Scaleform::GFx::MemberValueSet *)((char *)initArgs + 1);
      }
      while ( (unsigned int)initArgs < v19->Data.Size );
      v10 = parentDispObj;
    }
  }
  if ( v10
    && (v24 = (*(int (__thiscall **)(int))(*((_DWORD *)&v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v10->AvmObjOffset)
                                         + 20))((int)v10 + 4 * v10->AvmObjOffset)) != 0 )
  {
    v25 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v24 - 36);
  }
  else
  {
    v25 = 0;
  }
  v26 = depth;
  if ( depth > (int)v25->pDispObj[1].pRenNode.pObject )
  {
    v27 = Scaleform::GFx::StateBag::GetLogState(
            &pObject->pMovieImpl->Scaleform::GFx::StateBag,
            (Scaleform::Ptr<Scaleform::GFx::LogState> *)&pdata)->pObject;
    if ( pdata )
      Scaleform::RefCountImpl::Release(pdata);
    if ( v27 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v27->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "DAPI AttachMovie() depth requested (%d) for symbol \"%s\" is too large. Using next highest index (%d) instead.",
        v26,
        symbolName,
        v25->pDispObj[1].pRenNode.pObject);
  }
  if ( v26 < 0 || v26 > (int)v25->pDispObj[1].pRenNode.pObject )
    v28 = v25->pDispObj[1].pRenNode.pObject;
  else
    v28 = (Scaleform::Render::TreeNode *)v26;
  Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(v25, pmcObj[12], v28);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &asObj, (Scaleform::GFx::ASStringNode *)pmc);
  Scaleform::GFx::AS3::Value::~Value(&undefVal);
  Scaleform::GFx::AS3::Value::~Value(&asObj);
  return 1;
}
