char __thiscall Scaleform::GFx::AS3ValueObjectInterface::Invoke(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Object *pdata,
        Scaleform::GFx::Value *presult,
        __m128i *name,
        Scaleform::GFx::ASStringNode *pargs,
        unsigned int nargs,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v8; // eax
  Scaleform::GFx::AMP::ViewStats *v9; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // eax
  Scaleform::GFx::AS3::VM *v11; // ebx
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v16; // eax
  void *Size; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v21; // edi
  bool v22; // zf
  void (__thiscall **v23)(_DWORD, _DWORD, _DWORD); // esi
  unsigned __int64 v24; // rax
  Scaleform::AmpStats *v26; // edi
  void (__thiscall **v27)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v28; // rax
  Scaleform::AmpStats *v29; // edi
  void (__thiscall **v30)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v31; // rax
  unsigned int v32; // ebp
  Scaleform::GFx::AS3::Value *Data; // esi
  Scaleform::GFx::AS3::Value *v35; // esi
  Scaleform::GFx::AS3::VM *v36; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::AmpStats *v38; // edi
  void (__thiscall **v39)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v40; // rax
  Scaleform::AmpStats *v41; // edi
  void (__thiscall **v42)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v43; // rax
  Scaleform::AmpStats *v44; // edi
  void (__thiscall **v45)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v46; // rax
  Scaleform::GFx::AS3::CheckResult result; // [esp+17h] [ebp-99h] BYREF
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+18h] [ebp-98h] BYREF
  int v49; // [esp+24h] [ebp-8Ch]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke; // [esp+28h] [ebp-88h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_; // [esp+38h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+48h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::Value asfn; // [esp+58h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Value asresult; // [esp+68h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+78h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+90h] [ebp-20h]
  int v57; // [esp+94h] [ebp-1Ch]
  Scaleform::GFx::AS3::Multiname mn; // [esp+98h] [ebp-18h] BYREF

  v8 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke,
    v8,
    "ObjectInterface::Invoke",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_Invoke);
  v9 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_,
    v9,
    name->m128i_i8,
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v11 = pObject->pAVM.pObject;
  pStringManager = pObject->BuiltinsMgr.pStringManager;
  root = pObject;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pStringManager, name);
  v14 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  args.Data.Data = (Scaleform::GFx::AS3::Value *)10;
  args.Data.Size = 0;
  args.Data.Policy.Capacity = (unsigned int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    args.Data.Policy.Capacity = 0;
    v49 = v57;
    args.Data.Data = (Scaleform::GFx::AS3::Value *)12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  v16 = &v11->PublicNamespace.pObject->Scaleform::GFx::AS3::GASRefCountBase;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v16;
  if ( v16 )
    v16->RefCount = (v16->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&mn, (const Scaleform::GFx::AS3::Value *)&args);
  if ( ((int)args.Data.Data & 0x1F) > 9u )
  {
    if ( ((int)args.Data.Data & 0x200) != 0 )
    {
      Size = (void *)args.Data.Size;
      v22 = (*(_DWORD *)args.Data.Size)-- == 1;
      if ( v22 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Size);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&args);
    }
  }
  v22 = v14->RefCount-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
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
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Stats = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      p_NativePopCallstack = &_amp_timer_.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_.StartTicks),
        (ProfileTicks - _amp_timer_.StartTicks) >> 32);
    }
    v21 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats;
    v22 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats == 0;
LABEL_21:
    if ( !v22 )
    {
      v23 = (void (__thiscall **)(_DWORD, _DWORD, _DWORD))&v21->NativePopCallstack;
      v24 = Scaleform::Timer::GetProfileTicks();
      (*v23)(
        v21,
        v24 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks),
        (v24 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks) >> 32);
    }
    return 0;
  }
  asfn.Flags = 0;
  asfn.Bonus.pWeakProxy = 0;
  asresult.Flags = 0;
  asresult.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &result, v11, &asfn, valGet)->Result )
  {
    v32 = nargs;
    if ( nargs )
    {
      Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
        &args.Data,
        nargs);
      Data = args.Data.Data;
      do
      {
        Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(root, pargs++, Data++);
        --v32;
      }
      while ( v32 );
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0;
      _this.value.VS._1.VInt = (int)pdata;
      if ( pdata )
        pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
      v35 = args.Data.Data;
      v36 = v11;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v11, &asfn, &_this, &asresult, nargs, args.Data.Data, 0);
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
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v35, args.Data.Size);
      if ( v35 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v35);
    }
    else
    {
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0;
      _this.value.VS._1.VInt = (int)pdata;
      if ( pdata )
        pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v11, &asfn, &_this, &asresult, 0, 0, 0);
      Scaleform::GFx::AS3::Value::~Value(&_this);
      v36 = v11;
    }
    if ( v36->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v36);
      Scaleform::GFx::AS3::Value::~Value(&asresult);
      Scaleform::GFx::AS3::Value::~Value(&asfn);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      v38 = _amp_timer_.Stats;
      if ( _amp_timer_.Stats )
      {
        v39 = &_amp_timer_.Stats->NativePopCallstack;
        v40 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v39)(
          v38,
          v40 - LODWORD(_amp_timer_.StartTicks),
          (v40 - _amp_timer_.StartTicks) >> 32);
      }
      v21 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats;
      v22 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats == 0;
      goto LABEL_21;
    }
    if ( presult )
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, &asresult, (Scaleform::GFx::ASStringNode *)presult);
    Scaleform::GFx::AS3::Value::~Value(&asresult);
    Scaleform::GFx::AS3::Value::~Value(&asfn);
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v41 = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      v42 = &_amp_timer_.Stats->NativePopCallstack;
      v43 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v42)(
        v41,
        v43 - LODWORD(_amp_timer_.StartTicks),
        (v43 - _amp_timer_.StartTicks) >> 32);
    }
    v44 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats )
    {
      v45 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats->NativePopCallstack;
      v46 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v45)(
        v44,
        v46 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks),
        (v46 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v11);
    Scaleform::GFx::AS3::Value::~Value(&asresult);
    Scaleform::GFx::AS3::Value::~Value(&asfn);
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    v26 = _amp_timer_.Stats;
    if ( _amp_timer_.Stats )
    {
      v27 = &_amp_timer_.Stats->NativePopCallstack;
      v28 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v27)(
        v26,
        v28 - LODWORD(_amp_timer_.StartTicks),
        (v28 - _amp_timer_.StartTicks) >> 32);
    }
    v29 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats )
    {
      v30 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.Stats->NativePopCallstack;
      v31 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v30)(
        v29,
        v31 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks),
        (v31 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_Invoke.StartTicks) >> 32);
    }
    return 0;
  }
}
