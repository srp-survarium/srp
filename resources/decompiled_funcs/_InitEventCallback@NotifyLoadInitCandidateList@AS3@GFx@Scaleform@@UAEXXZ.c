void __thiscall Scaleform::GFx::AS3::NotifyLoadInitCandidateList::InitEventCallback(
        Scaleform::GFx::AS3::NotifyLoadInitCandidateList *this)
{
  Scaleform::GFx::Value *v1; // ebx
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::IMEManager *pObject; // eax
  Scaleform::GFx::AS3::IMEManager *v7; // eax
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  bool (__thiscall *SetMember)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *, const Scaleform::GFx::Value *, bool); // edx
  Scaleform::GFx::AS3::Stage *v10; // eax
  Scaleform::GFx::InteractiveObject *v11; // edi
  int v12; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v13; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // ecx
  Scaleform::GFx::ASString v; // [esp+38h] [ebp-A0h] BYREF
  char v17; // [esp+3Fh] [ebp-99h] BYREF
  Scaleform::GFx::Value func; // [esp+40h] [ebp-98h] BYREF
  Scaleform::GFx::AS3::Value val; // [esp+58h] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value val2; // [esp+68h] [ebp-70h] BYREF
  Scaleform::GFx::Value args; // [esp+78h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+90h] [ebp-48h] BYREF
  Scaleform::GFx::Value result; // [esp+A8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn2; // [esp+C0h] [ebp-18h] BYREF

  v1 = 0;
  v.pNode = 0;
  pMovieRoot = this->pMovieRoot;
  result.pObjectInterface = 0;
  result.Type = VT_Undefined;
  args.pObjectInterface = 0;
  args.Type = VT_Undefined;
  val.Flags = 0;
  val.Bonus.pWeakProxy = 0;
  val2.Flags = 0;
  val2.Bonus.pWeakProxy = 0;
  v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
              pMovieRoot->BuiltinsMgr.pStringManager,
              "contentLoaderInfo");
  ++v.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&func, &v);
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    this->pMovieRoot->pAVM.pObject->PublicNamespace.pObject,
    (const Scaleform::GFx::AS3::Value *)&func);
  if ( ((int)func.pObjectInterface & 0x1F) > 9u )
  {
    if ( ((int)func.pObjectInterface & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&func);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&func);
  }
  pNode = v.pNode;
  --v.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( this->pLoader.pObject->GetProperty(this->pLoader.pObject, &v17, &mn, &val)->Result
    && (this->pASIMEManager.pObject->CandListVal.Type & 0x8F) == 1 )
  {
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pMovieRoot->BuiltinsMgr.pStringManager, "content");
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&func, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(
      &mn2,
      this->pMovieRoot->pAVM.pObject->PublicNamespace.pObject,
      (const Scaleform::GFx::AS3::Value *)&func);
    if ( ((int)func.pObjectInterface & 0x1F) > 9u )
    {
      if ( ((int)func.pObjectInterface & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&func);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&func);
    }
    v5 = v.pNode;
    --v.pNode->RefCount;
    if ( !v5->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    if ( *(_BYTE *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*(_DWORD *)val.value.VS._1.VInt + 16))(
                     val.value.VS._1,
                     &v17,
                     &mn2,
                     &val2) )
    {
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
        this->pMovieRoot,
        &val2,
        (Scaleform::GFx::ASStringNode *)&this->pASIMEManager.pObject->CandListVal);
      pObject = this->pASIMEManager.pObject;
      if ( (pObject->CandListVal.Type & 0x8F) != 1 )
      {
        func.pObjectInterface = 0;
        func.Type = VT_Undefined;
        Scaleform::GFx::Movie::CreateFunction(pObject->pMovie, &func, pObject->CustomFuncCandList.pObject, 0);
        v7 = this->pASIMEManager.pObject;
        pObjectInterface = v7->CandListVal.pObjectInterface;
        SetMember = pObjectInterface->SetMember;
        v.pNode = 0;
        SetMember(
          pObjectInterface,
          v7->CandListVal.mValue.pStringManaged,
          "SendIMEMessage",
          &func,
          (v7->CandListVal.Type & 0x8F) == 10);
        v1 = (Scaleform::GFx::Value *)v.pNode;
        this->pASIMEManager.pObject->CandidateListState = 2;
        v10 = this->pMovieRoot->pStage.pObject;
        v11 = (Scaleform::GFx::InteractiveObject *)this->pLoader.pObject->pDispObj.pObject;
        if ( v10 == (Scaleform::GFx::AS3::Stage *)v1
          || (v12 = (*(int (__thiscall **)(int))(*((_DWORD *)&v10->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v10->AvmObjOffset)
                                               + 20))((int)v10 + 4 * v10->AvmObjOffset),
              (Scaleform::GFx::Value *)v12 == v1) )
        {
          v13 = 0;
        }
        else
        {
          v13 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v12 - 36);
        }
        Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(v13, v11);
        this->pASIMEManager.pObject->OnOpenCandidateList(this->pASIMEManager.pObject);
        this->pASIMEManager.pObject->CandListVal.pObjectInterface->Invoke(
          this->pASIMEManager.pObject->CandListVal.pObjectInterface,
          (void *)this->pASIMEManager.pObject->CandListVal.mValue.IValue,
          v1,
          "Init",
          v1,
          (unsigned int)v1,
          (this->pASIMEManager.pObject->CandListVal.Type & 0x8F) == 10);
        if ( (func.Type & 0x40) != 0 )
          func.pObjectInterface->ObjectRelease(func.pObjectInterface, &func, (void *)func.mValue.IValue);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn2);
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
  }
  if ( (Scaleform::GFx::Value *)mn.Obj.pObject != v1 )
  {
    if ( ((int)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      v15 = mn.Obj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
      }
    }
  }
  if ( (val2.Flags & 0x1F) > 9 )
  {
    if ( (val2.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val2);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val2);
  }
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
  if ( (args.Type & 0x40) != 0 )
  {
    args.pObjectInterface->ObjectRelease(args.pObjectInterface, &args, (void *)args.mValue.IValue);
    args.pObjectInterface = (Scaleform::GFx::Value::ObjectInterface *)v1;
  }
  args.Type = (Scaleform::GFx::Value::ValueType)v1;
  if ( (result.Type & 0x40) != 0 )
    result.pObjectInterface->ObjectRelease(result.pObjectInterface, &result, (void *)result.mValue.IValue);
}
