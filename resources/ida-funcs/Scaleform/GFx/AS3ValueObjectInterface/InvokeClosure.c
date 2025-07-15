char __thiscall Scaleform::GFx::AS3ValueObjectInterface::InvokeClosure(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        unsigned int pdata,
        unsigned int dataAux,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::ASStringNode *pargs,
        unsigned int nargs)
{
  Scaleform::GFx::AMP::ViewStats *v7; // eax
  Scaleform::GFx::AS3::VM *v8; // ebp
  unsigned int v9; // esi
  unsigned int v10; // ebx
  Scaleform::GFx::AS3::Value *Data; // edi
  Scaleform::GFx::AS3::Value *v13; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::WeakProxy *v15; // eax
  Scaleform::GFx::AS3::WeakProxy *v16; // eax
  Scaleform::AmpStats *Stats; // ebx
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::WeakProxy *v21; // eax
  Scaleform::GFx::AS3::WeakProxy *v22; // eax
  Scaleform::AmpStats *v23; // ebx
  void (__thiscall **v24)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v25; // rax
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+10h] [ebp-54h]
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-50h]
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+18h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::Value asfn; // [esp+24h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value asresult; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+44h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure; // [esp+54h] [ebp-10h] BYREF

  v7 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure,
    v7,
    "ObjectInterface::InvokeClosure",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_InvokeClosure);
  v8 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  root = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = pdata & 0xFFFFFFFD;
  vm = v8;
  asfn.Flags = 0;
  asfn.Bonus.pWeakProxy = 0;
  asresult.Flags = 0;
  asresult.Bonus.pWeakProxy = 0;
  other.Bonus.pWeakProxy = 0;
  other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(pdata & 0xFFFFFFFD);
  other.value.VS._1.VInt = dataAux;
  if ( (pdata & 2) != 0 )
  {
    if ( v9 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    other.Flags = 17;
  }
  else
  {
    other.Flags = 16;
    if ( v9 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::Assign(&asfn, &other);
  Scaleform::GFx::AS3::Value::~Value(&other);
  v10 = nargs;
  if ( nargs )
  {
    Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
      &args.Data,
      nargs);
    Data = args.Data.Data;
    do
    {
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(root, pargs++, Data++);
      --v10;
    }
    while ( v10 );
    v8 = vm;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = pdata & 0xFFFFFFFD;
    if ( v9 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    v13 = args.Data.Data;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &asfn, &other, &asresult, nargs, args.Data.Data, 0);
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        pWeakProxy = other.Bonus.pWeakProxy;
        --other.Bonus.pWeakProxy->RefCount;
        if ( !pWeakProxy->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v13, args.Data.Size);
    if ( v13 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  else
  {
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = pdata & 0xFFFFFFFD;
    if ( v9 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, &asfn, &other, &asresult, 0, 0, 0);
    Scaleform::GFx::AS3::Value::~Value(&other);
  }
  if ( v8->HandleException )
  {
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v8);
    if ( (asresult.Flags & 0x1F) > 9 )
    {
      if ( (asresult.Flags & 0x200) != 0 )
      {
        v15 = asresult.Bonus.pWeakProxy;
        --asresult.Bonus.pWeakProxy->RefCount;
        if ( !v15->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
        asresult.Flags &= 0xFFFFFDE0;
        memset(&asresult.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asresult);
      }
    }
    if ( (asfn.Flags & 0x1F) > 9 )
    {
      if ( (asfn.Flags & 0x200) != 0 )
      {
        v16 = asfn.Bonus.pWeakProxy;
        --asfn.Bonus.pWeakProxy->RefCount;
        if ( !v16->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
        asfn.Flags &= 0xFFFFFDE0;
        memset(&asfn.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asfn);
      }
    }
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats )
    {
      p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    if ( presult )
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, &asresult, (Scaleform::GFx::ASStringNode *)presult);
    if ( (asresult.Flags & 0x1F) > 9 )
    {
      if ( (asresult.Flags & 0x200) != 0 )
      {
        v21 = asresult.Bonus.pWeakProxy;
        --asresult.Bonus.pWeakProxy->RefCount;
        if ( !v21->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
        asresult.Flags &= 0xFFFFFDE0;
        memset(&asresult.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asresult);
      }
    }
    if ( (asfn.Flags & 0x1F) > 9 )
    {
      if ( (asfn.Flags & 0x200) != 0 )
      {
        v22 = asfn.Bonus.pWeakProxy;
        --asfn.Bonus.pWeakProxy->RefCount;
        if ( !v22->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
        asfn.Flags &= 0xFFFFFDE0;
        memset(&asfn.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asfn);
      }
    }
    v23 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats )
    {
      v24 = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.Stats->NativePopCallstack;
      v25 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v24)(
        v23,
        v25 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.StartTicks),
        (v25 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_InvokeClosure.StartTicks) >> 32);
    }
    return 1;
  }
}
