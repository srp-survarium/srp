char __thiscall Scaleform::GFx::AS3ValueObjectInterface::Invoke(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Object *pdata,
        Scaleform::GFx::Value *presult,
        char *name,
        Scaleform::GFx::ASStringNode *pargs,
        unsigned int nargs,
        bool isdobj)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::VM *v9; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v12; // eax
  void *Size; // eax
  bool v14; // zf
  Scaleform::GFx::AS3::VM *v15; // ecx
  unsigned int v17; // ebp
  Scaleform::GFx::AS3::Value *Data; // esi
  Scaleform::GFx::AS3::Value *v20; // esi
  Scaleform::GFx::AS3::VM *v21; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-7Dh] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-7Ch]
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+18h] [ebp-78h]
  int v26; // [esp+1Ch] [ebp-74h]
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+20h] [ebp-70h] BYREF
  int v28; // [esp+2Ch] [ebp-64h]
  Scaleform::GFx::AS3::Value asresult; // [esp+30h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value asfn; // [esp+40h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+50h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+60h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+78h] [ebp-18h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pStringManager = pObject->BuiltinsMgr.pStringManager;
  v9 = pObject->pAVM.pObject;
  root = pObject;
  vm = v9;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, name);
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  args.Data.Data = (Scaleform::GFx::AS3::Value *)10;
  args.Data.Size = 0;
  args.Data.Policy.Capacity = (unsigned int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    args.Data.Policy.Capacity = 0;
    v28 = v26;
    args.Data.Data = (Scaleform::GFx::AS3::Value *)12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v12 = v9->PublicNamespace.pObject;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v12;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, (const Scaleform::GFx::AS3::Value *)&args);
  if ( ((int)args.Data.Data & 0x1F) > 9u )
  {
    if ( ((int)args.Data.Data & 0x200) != 0 )
    {
      Size = (void *)args.Data.Size;
      v14 = (*(_DWORD *)args.Data.Size)-- == 1;
      if ( v14 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Size);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&args);
    }
  }
  v14 = StringNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::Object::FindProperty(
    pdata,
    &prop,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&mn,
    FindGet);
  if ( (prop.This.Flags & 0x1F) == 0
    || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0
    || ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
  {
    goto LABEL_21;
  }
  asfn.Flags = 0;
  asfn.Bonus.pWeakProxy = 0;
  asresult.Flags = 0;
  asresult.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &result, v9, &asfn, valGet)->Result )
  {
    v15 = v9;
LABEL_20:
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v15);
    Scaleform::GFx::AS3::Value::~Value(&asresult);
    Scaleform::GFx::AS3::Value::~Value(&asfn);
LABEL_21:
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    return 0;
  }
  v17 = nargs;
  if ( nargs )
  {
    Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
      &args.Data,
      nargs);
    Data = args.Data.Data;
    do
    {
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(root, pargs++, Data++);
      --v17;
    }
    while ( v17 );
    _this.Flags = 12;
    _this.Bonus.pWeakProxy = 0;
    _this.value.VS._1.VInt = (int)pdata;
    if ( pdata )
      pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
    v20 = args.Data.Data;
    v21 = vm;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &asfn, &_this, &asresult, nargs, args.Data.Data, 0);
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        pWeakProxy = _this.Bonus.pWeakProxy;
        --_this.Bonus.pWeakProxy->RefCount;
        if ( !pWeakProxy->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v20, args.Data.Size);
    if ( v20 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  }
  else
  {
    _this.Flags = 12;
    _this.Bonus.pWeakProxy = 0;
    _this.value.VS._1.VInt = (int)pdata;
    if ( pdata )
      pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &asfn, &_this, &asresult, 0, 0, 0);
    Scaleform::GFx::AS3::Value::~Value(&_this);
    v21 = vm;
  }
  if ( v21->HandleException )
  {
    v15 = v21;
    goto LABEL_20;
  }
  if ( presult )
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, &asresult, (Scaleform::GFx::ASStringNode *)presult);
  Scaleform::GFx::AS3::Value::~Value(&asresult);
  Scaleform::GFx::AS3::Value::~Value(&asfn);
  Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  return 1;
}
