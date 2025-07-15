void __thiscall Scaleform::GFx::AS3::Tracer::Tracer(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::MemoryHeap *heap,
        const Scaleform::GFx::AS3::CallFrame *cf,
        int wc,
        const Scaleform::GFx::AS3::Abc::MethodInfo *we)
{
  const Scaleform::GFx::AS3::CallFrame *v5; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v6; // edx
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  const Scaleform::MemoryHeap *v9; // edi
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  unsigned int v14; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v16; // ecx
  unsigned int v17; // edi
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::GFx::AS3::TR::State *v19; // eax
  Scaleform::MemoryHeap *v20; // eax
  Scaleform::MemoryHeap *v21; // edi
  const Scaleform::MemoryHeap *v22; // eax
  unsigned int v23; // ebp
  Scaleform::GFx::AS3::TR::State **Data; // eax
  Scaleform::GFx::AS3::TR::State **v25; // ebp
  const Scaleform::GFx::AS3::CallFrame *v26; // ecx
  Scaleform::GFx::AS3::Value::V1U OriginationTraits; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_SelfSize; // ebp
  const Scaleform::GFx::AS3::CallFrame *v29; // eax
  int Ind; // ecx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v31; // edx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  int local_reg_count; // eax
  unsigned int v34; // ebx
  unsigned int v35; // eax
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *v36; // ecx
  unsigned int v37; // edi
  int v38; // ebx
  Scaleform::Pair<double,unsigned long> *v39; // eax
  Scaleform::GFx::AS3::Value *v40; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v41; // eax
  Scaleform::GFx::AS3::VM *v42; // ecx
  Scaleform::GFx::AS3::Value::V1U pObject; // eax
  bool v44; // cl
  bool v45; // zf
  Scaleform::GFx::AS3::Value *v46; // ecx
  void *v47; // eax
  Scaleform::MemoryHeap *pParent; // eax
  _BYTE *v49; // eax
  char v50; // dl
  const Scaleform::GFx::AS3::VM::Error *v51; // eax
  Scaleform::GFx::ASStringNode *v52; // eax
  Scaleform::GFx::AS3::Value *v53; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::TR::Block *v55; // eax
  Scaleform::MemoryHeap *v56; // ecx
  Scaleform::GFx::AS3::VM *vm; // [esp+10h] [ebp-1Ch]
  unsigned int param_count; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::ASStringNode *v59; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::Value val; // [esp+1Ch] [ebp-10h] BYREF

  v5 = cf;
  v6 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)we;
  v8 = (Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *)wc;
  this->CF = cf;
  this->WCode = v8;
  this->__vftable = (Scaleform::GFx::AS3::Tracer_vtbl *)&Scaleform::GFx::AS3::Tracer::`vftable';
  this->WException = v6;
  v9 = heap;
  this->Heap = heap;
  this->State = sError;
  this->NeedToCheck = 0;
  this->Done = 0;
  this->CurrOffset = 0;
  heap = (Scaleform::MemoryHeap *)v5->pFile->File.pObject->MethodBodies.Info.Data.Data[v5->MBIIndex.Ind]->code.code.Data;
  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
    (Scaleform::GFx::AS3::Abc::StringView *)&heap,
    (Scaleform::StringDataPtr *)&param_count);
  v10 = param_count;
  this->BCode.pStr = (const char *)param_count;
  this->BCode.Size = (unsigned int)v59;
  this->PrintOffset = 0;
  this->CurrBlock = 0;
  v11 = (const unsigned __int8 *)v10;
  Size = this->BCode.Size;
  this->pCode = v11;
  this->CodeEnd = Size;
  this->OrigOpcodePos.Data.Data = 0;
  this->OrigOpcodePos.Data.Size = 0;
  this->OrigOpcodePos.Data.Policy.Capacity = 0;
  this->OrigOpcodePos.Data.pHeap = v9;
  this->NewOpcodePos.Data.Data = 0;
  this->NewOpcodePos.Data.Size = 0;
  this->NewOpcodePos.Data.Policy.Capacity = 0;
  this->NewOpcodePos.Data.pHeap = v9;
  this->PosToRecalculate.Data.Data = 0;
  this->PosToRecalculate.Data.Size = 0;
  this->PosToRecalculate.Data.Policy.Capacity = 0;
  this->PosToRecalculate.Data.pHeap = v9;
  this->Orig2newPosMap.Data.Data = 0;
  this->Orig2newPosMap.Data.Size = 0;
  this->Orig2newPosMap.Data.Policy.Capacity = 0;
  this->Orig2newPosMap.Data.pHeap = v9;
  this->States.Data.Data = 0;
  this->States.Data.Size = 0;
  this->States.Data.Policy.Capacity = 0;
  this->States.Data.pHeap = v9;
  this->Blocks.Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
  this->Blocks.Root.pNext = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
  this->CatchTraits.Data.Data = 0;
  this->CatchTraits.Data.Size = 0;
  this->CatchTraits.Data.Policy.Capacity = 0;
  this->CatchTraits.Data.pHeap = v9;
  VMRef = this->CF->pFile->VMRef;
  vm = VMRef;
  this->NeedToCheck = VMRef->UI->NeedToCheck;
  this->State = sStep;
  v14 = VMRef->CallStack.Size;
  this->PrintOffset = v14;
  if ( v14 )
    this->PrintOffset = v14 - 1;
  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  if ( WCode->Size )
  {
    if ( (WCode->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( WCode->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, WCode->Data);
        WCode->Data = 0;
      }
      WCode->Policy.Capacity = 0;
    }
  }
  else if ( !WCode->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      0);
  }
  WCode->Size = 0;
  v16 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  if ( this->BCode.Size > v16->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v16,
      v16,
      this->BCode.Size);
  v17 = this->BCode.Size;
  pHeap = this->Orig2newPosMap.Data.pHeap;
  if ( v17 >= this->Orig2newPosMap.Data.Size )
  {
    if ( v17 >= this->Orig2newPosMap.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->Orig2newPosMap,
        pHeap,
        v17 + (v17 >> 2));
  }
  else if ( v17 < this->Orig2newPosMap.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->Orig2newPosMap,
      pHeap,
      this->BCode.Size);
  }
  this->Orig2newPosMap.Data.Size = v17;
  v19 = (Scaleform::GFx::AS3::TR::State *)this->Heap->Alloc(this->Heap, 68, 0);
  if ( v19 )
  {
    Scaleform::GFx::AS3::TR::State::State(v19, (int)this, 0);
    v21 = v20;
    heap = v20;
  }
  else
  {
    heap = 0;
    v21 = 0;
  }
  v22 = this->States.Data.pHeap;
  v23 = this->States.Data.Size + 1;
  if ( v23 >= this->States.Data.Size )
  {
    if ( v23 >= this->States.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->States.Data,
        v22,
        v23 + (v23 >> 2));
  }
  else if ( v23 < this->States.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->States.Data,
      v22,
      this->States.Data.Size + 1);
  }
  Data = this->States.Data.Data;
  this->States.Data.Size = v23;
  v25 = &Data[v23 - 1];
  if ( v25 )
    *v25 = (Scaleform::GFx::AS3::TR::State *)v21;
  v26 = this->CF;
  OriginationTraits = (Scaleform::GFx::AS3::Value::V1U)v26->OriginationTraits;
  p_SelfSize = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v21->SelfSize;
  if ( (*(_DWORD *)(OriginationTraits.VInt + 56) & 0x20) != 0 )
  {
    val.Flags = 9;
LABEL_29:
    val.Bonus.pWeakProxy = 0;
    val.value.VS._1 = OriginationTraits;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v21->SelfSize,
      &val);
    goto LABEL_30;
  }
  v38 = v26->Invoker.Flags & 0x1F;
  val.Flags = 8;
  if ( (_BYTE)v38 != 14 )
    goto LABEL_29;
  val.Bonus.pWeakProxy = 0;
  val.value.VS._1.VInt = (int)v26->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v21->SelfSize,
    &val);
LABEL_30:
  Scaleform::GFx::AS3::Value::~Value(&val);
  LOBYTE(v21->Info.pParent->__vftable) |= 1u;
  v29 = this->CF;
  Ind = v29->MBIIndex.Ind;
  v31 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)v29->pFile->File.pObject->Methods.Info.Data.Data[v29->pFile->File.pObject->MethodBodies.Info.Data.Data[Ind]->method_info_ind];
  pFile = v29->pFile;
  we = (const Scaleform::GFx::AS3::Abc::MethodInfo *)v31;
  local_reg_count = pFile->File.pObject->MethodBodies.Info.Data.Data[Ind]->local_reg_count;
  v34 = 1;
  if ( local_reg_count > 1 )
  {
    cf = (const Scaleform::GFx::AS3::CallFrame *)(local_reg_count - 1);
    do
    {
      if ( (_S10_0 & 1) == 0 )
      {
        _S10_0 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v35 = p_SelfSize->Size;
      v36 = (Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *)p_SelfSize[1].Data;
      v37 = v35 + 1;
      wc = (int)v36;
      if ( v35 + 1 >= v35 )
      {
        if ( v37 >= p_SelfSize->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_SelfSize,
            v36,
            v37 + (v37 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)&p_SelfSize->Data[v35 + 1],
          0xFFFFFFFF);
        if ( v37 < p_SelfSize->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_SelfSize,
            (const void *)wc,
            v37);
      }
      v39 = p_SelfSize->Data;
      p_SelfSize->Size = v37;
      v40 = (Scaleform::GFx::AS3::Value *)&v39[v37 - 1];
      if ( v40 )
      {
        *v40 = v;
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            ++v.Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(&v);
        }
      }
      cf = (const Scaleform::GFx::AS3::CallFrame *)((char *)cf - 1);
    }
    while ( cf );
  }
  param_count = we->ParamTypes.Data.Size;
  if ( !param_count )
  {
LABEL_63:
    if ( (we->Flags & 4) != 0 )
    {
      val.value.VS._1.VInt = (int)vm->TraitsArray.pObject->ITraits.pObject;
    }
    else
    {
      if ( (we->Flags & 1) == 0 )
      {
LABEL_75:
        v55 = (Scaleform::GFx::AS3::TR::Block *)this->Heap->Alloc(this->Heap, 24, 0);
        if ( v55 )
        {
          v56 = heap;
          *((_DWORD *)v55 + 2) |= 1u;
          v55->Type = 0;
          v55->State = (Scaleform::GFx::AS3::TR::State *)v56;
          v55->From = 0;
        }
        else
        {
          v55 = 0;
        }
        v55->pPrev = this->Blocks.Root.pPrev;
        v55->pNext = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
        this->Blocks.Root.pPrev->pNext = v55;
        this->Blocks.Root.pPrev = v55;
        return;
      }
      val.value.VS._1.VInt = (int)vm->TraitsArray.pObject->ITraits.pObject;
    }
    v53 = (Scaleform::GFx::AS3::Value *)&p_SelfSize->Data[v34];
    val.Flags = 8;
    val.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::Assign(v53, &val);
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        pWeakProxy = val.Bonus.pWeakProxy;
        v45 = val.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v45 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    *((_BYTE *)&heap->Info.pParent->__vftable + (v34 >> 3)) |= 1 << (v34 & 7);
    goto LABEL_75;
  }
  wc = 16;
  cf = 0;
  while ( 1 )
  {
    v41 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
            vm,
            this->CF->pFile,
            &this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*(_DWORD *)(&cf->DiscardResult
                                                                                           + (unsigned int)we->ParamTypes.Data.Data)]);
    if ( !v41 )
      break;
    v42 = this->CF->pFile->VMRef;
    pObject = (Scaleform::GFx::AS3::Value::V1U)v41->ITraits.pObject;
    v44 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v42->TraitsInt.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v42->TraitsUint.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v42->TraitsNumber.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v42->TraitsBoolean.pObject->ITraits.pObject;
    v45 = !v44;
    v46 = (Scaleform::GFx::AS3::Value *)((char *)p_SelfSize->Data + wc);
    val.value.VS._1 = pObject;
    val.Bonus.pWeakProxy = 0;
    val.Flags = (32 * (!v45 ? 0 : 2)) | 8;
    Scaleform::GFx::AS3::Value::Assign(v46, &val);
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        v47 = val.Bonus.pWeakProxy;
        v45 = val.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v45 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v47);
        memset(&val.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    pParent = heap->Info.pParent;
    cf = (const Scaleform::GFx::AS3::CallFrame *)((char *)cf + 4);
    wc += 16;
    v49 = (char *)pParent + (v34 >> 3);
    v50 = 1 << (v34++ & 7);
    *v49 |= v50;
    if ( v34 - 1 >= param_count )
      goto LABEL_63;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&param_count, eClassNotFoundError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    vm,
    v51,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v52 = v59;
  --v59->RefCount;
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
}
