char __thiscall Scaleform::GFx::AS3ValueObjectInterface::InvokeClosure(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        unsigned int pdata,
        unsigned int dataAux,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::ASStringNode *pargs,
        unsigned int nargs)
{
  Scaleform::GFx::AS3::VM *v6; // ebp
  unsigned int v7; // esi
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::Value *Data; // edi
  Scaleform::GFx::AS3::Value *v11; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::WeakProxy *v13; // eax
  void *v14; // eax
  bool v15; // zf
  Scaleform::GFx::AS3::WeakProxy *v17; // eax
  void *v18; // eax
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+Ch] [ebp-44h]
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-40h]
  Scaleform::Array<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> args; // [esp+14h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value asresult; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value asfn; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+40h] [ebp-10h] BYREF

  v6 = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].__vftable;
  root = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = pdata & 0xFFFFFFFD;
  vm = v6;
  asfn.Flags = 0;
  asfn.Bonus.pWeakProxy = 0;
  asresult.Flags = 0;
  asresult.Bonus.pWeakProxy = 0;
  other.Bonus.pWeakProxy = 0;
  other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(pdata & 0xFFFFFFFD);
  other.value.VS._1.VInt = dataAux;
  if ( (pdata & 2) != 0 )
  {
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    other.Flags = 17;
  }
  else
  {
    other.Flags = 16;
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::Assign(&asfn, &other);
  Scaleform::GFx::AS3::Value::~Value(&other);
  v8 = nargs;
  if ( nargs )
  {
    Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
      &args.Data,
      nargs);
    Data = args.Data.Data;
    do
    {
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(root, pargs++, Data++);
      --v8;
    }
    while ( v8 );
    v6 = vm;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = pdata & 0xFFFFFFFD;
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    v11 = args.Data.Data;
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
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v11, args.Data.Size);
    if ( v11 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  }
  else
  {
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0;
    other.value.VS._1.VInt = pdata & 0xFFFFFFFD;
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pdata & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, &asfn, &other, &asresult, 0, 0, 0);
    Scaleform::GFx::AS3::Value::~Value(&other);
  }
  if ( v6->HandleException )
  {
    Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v6);
    if ( (asresult.Flags & 0x1F) > 9 )
    {
      if ( (asresult.Flags & 0x200) != 0 )
      {
        v13 = asresult.Bonus.pWeakProxy;
        --asresult.Bonus.pWeakProxy->RefCount;
        if ( !v13->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
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
        v14 = asfn.Bonus.pWeakProxy;
        v15 = asfn.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v15 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
          return 0;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asfn);
      }
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
        v17 = asresult.Bonus.pWeakProxy;
        --asresult.Bonus.pWeakProxy->RefCount;
        if ( !v17->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
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
        v18 = asfn.Bonus.pWeakProxy;
        v15 = asfn.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v15 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
          return 1;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&asfn);
      }
    }
    return 1;
  }
}
