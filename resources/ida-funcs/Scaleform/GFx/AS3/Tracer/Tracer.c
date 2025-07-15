void __thiscall Scaleform::GFx::AS3::Tracer::Tracer(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::MemoryHeap *heap,
        unsigned int cf,
        Scaleform::GFx::AS3::VM *wc,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *we)
{
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v6; // edx
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  const Scaleform::MemoryHeap *v9; // edi
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int Size; // ecx
  Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *VMRef; // eax
  char v14; // dl
  unsigned int Capacity; // eax
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *v17; // ecx
  unsigned int v18; // edi
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::GFx::AS3::TR::State *v20; // eax
  Scaleform::MemoryHeap *v21; // eax
  const Scaleform::MemoryHeap *v22; // eax
  unsigned int v23; // ebp
  Scaleform::GFx::AS3::TR::State **Data; // eax
  Scaleform::GFx::AS3::TR::State **v25; // ebp
  Scaleform::GFx::AS3::Value::V1U *v26; // edi
  Scaleform::GFx::AS3::Value::V1U v27; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_SelfSize; // ebp
  int v29; // edx
  const Scaleform::GFx::AS3::CallFrame *v30; // eax
  int local_reg_count; // eax
  unsigned int v32; // eax
  unsigned int v33; // edi
  Scaleform::Pair<double,unsigned long> *v34; // edx
  int v35; // edi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  int v37; // edi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v38; // eax
  Scaleform::GFx::AS3::VM *v39; // ecx
  Scaleform::GFx::AS3::Value::V1U pObject; // eax
  bool v41; // cl
  bool v42; // zf
  Scaleform::GFx::AS3::Value *v43; // ecx
  void *v44; // eax
  Scaleform::MemoryHeap *pParent; // eax
  Scaleform::GFx::AS3::Value::V1U *InternedString; // eax
  Scaleform::GFx::AS3::Value::V1U v47; // ecx
  Scaleform::GFx::AS3::VM *v48; // edi
  const Scaleform::GFx::AS3::VM::Error *v49; // eax
  Scaleform::GFx::ASStringNode *v50; // eax
  Scaleform::GFx::AS3::WeakProxy *v51; // eax
  Scaleform::GFx::ASStringNode *v52; // eax
  unsigned int v53; // edi
  Scaleform::GFx::AS3::Value *v54; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::TR::Block *v56; // eax
  Scaleform::MemoryHeap *v57; // ecx
  int v58; // [esp+10h] [ebp-20h]
  int v59; // [esp+10h] [ebp-20h]
  const Scaleform::GFx::AS3::Abc::MethodInfo *mi; // [esp+14h] [ebp-1Ch]
  unsigned int param_count; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::ASStringNode *v62; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value val; // [esp+20h] [ebp-10h] BYREF

  v5 = cf;
  v6 = we;
  v8 = (Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *)wc;
  this->CF = (const Scaleform::GFx::AS3::CallFrame *)cf;
  this->WCode = v8;
  this->__vftable = (Scaleform::GFx::AS3::Tracer_vtbl *)&Scaleform::GFx::AS3::Tracer::`vftable';
  this->WException = v6;
  v9 = heap;
  this->Heap = heap;
  this->State = sError;
  this->NeedToCheck = 0;
  this->Done = 0;
  this->CurrOffset = 0;
  heap = *(Scaleform::MemoryHeap **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 20) + 60) + 180)
                                               + 4 * *(_DWORD *)(v5 + 24))
                                   + 36);
  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
    (Scaleform::GFx::AS3::Abc::StringView *)&heap,
    (Scaleform::StringDataPtr *)&param_count);
  v10 = param_count;
  this->BCode.pStr = (const char *)param_count;
  this->BCode.Size = (unsigned int)v62;
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
  VMRef = (Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *)this->CF->pFile->VMRef;
  v14 = *(_BYTE *)(VMRef[1].Data.Policy.Capacity + 8);
  wc = (Scaleform::GFx::AS3::VM *)VMRef;
  this->NeedToCheck = v14;
  this->State = sStep;
  Capacity = VMRef[11].Data.Policy.Capacity;
  this->PrintOffset = Capacity;
  if ( Capacity )
    this->PrintOffset = Capacity - 1;
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
  v17 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->WCode;
  if ( this->BCode.Size > v17->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v17,
      v17,
      this->BCode.Size);
  v18 = this->BCode.Size;
  pHeap = this->Orig2newPosMap.Data.pHeap;
  if ( v18 >= this->Orig2newPosMap.Data.Size )
  {
    if ( v18 >= this->Orig2newPosMap.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->Orig2newPosMap,
        pHeap,
        v18 + (v18 >> 2));
  }
  else if ( v18 < this->Orig2newPosMap.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)&this->Orig2newPosMap,
      pHeap,
      this->BCode.Size);
  }
  this->Orig2newPosMap.Data.Size = v18;
  v20 = (Scaleform::GFx::AS3::TR::State *)this->Heap->Alloc(this->Heap, 68, 0);
  if ( v20 )
  {
    Scaleform::GFx::AS3::TR::State::State(v20, (int)this, 0);
    heap = v21;
  }
  else
  {
    heap = 0;
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
    *v25 = (Scaleform::GFx::AS3::TR::State *)heap;
  v26 = (Scaleform::GFx::AS3::Value::V1U *)this->CF;
  v27 = v26[8];
  p_SelfSize = (Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&heap->SelfSize;
  if ( (*(_DWORD *)(v27.VInt + 56) & 0x20) != 0 )
  {
    val.value.VS._1 = v26[8];
    val.Flags = 9;
  }
  else
  {
    v29 = v26[20].VInt & 0x1F;
    val.Flags = 8;
    if ( (_BYTE)v29 == 14 )
      val.value.VS._1.VInt = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v26[5].VInt + 20) + 292) + 100);
    else
      val.value.VS._1 = v27;
  }
  val.Bonus.pWeakProxy = 0;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&heap->SelfSize,
    &val);
  Scaleform::GFx::AS3::Value::~Value(&val);
  LOBYTE(heap->Info.pParent->__vftable) |= 1u;
  v30 = this->CF;
  mi = v30->pFile->File.pObject->Methods.Info.Data.Data[v30->pFile->File.pObject->MethodBodies.Info.Data.Data[v30->MBIIndex.Ind]->method_info_ind];
  local_reg_count = v30->pFile->File.pObject->MethodBodies.Info.Data.Data[v30->MBIIndex.Ind]->local_reg_count;
  cf = 1;
  if ( local_reg_count > 1 )
  {
    v58 = local_reg_count - 1;
    do
    {
      if ( (_S15 & 1) == 0 )
      {
        _S15 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v32 = p_SelfSize->Size;
      v33 = v32 + 1;
      we = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)p_SelfSize[1].Data;
      if ( v32 + 1 >= v32 )
      {
        if ( v33 >= p_SelfSize->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_SelfSize,
            we,
            v33 + (v33 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)&p_SelfSize->Data[v32 + 1],
          0xFFFFFFFF);
        if ( v33 < p_SelfSize->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_SelfSize,
            we,
            v33);
      }
      v34 = p_SelfSize->Data;
      p_SelfSize->Size = v33;
      v35 = v33;
      if ( &v34[v35] != (Scaleform::Pair<double,unsigned long> *)16 )
      {
        v34[v35 - 1] = (Scaleform::Pair<double,unsigned long>)v;
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            ++v.Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(&v);
        }
      }
      --v58;
    }
    while ( v58 );
  }
  param_count = mi->ParamTypes.Data.Size;
  if ( !param_count )
  {
LABEL_63:
    if ( (mi->Flags & 4) != 0 )
    {
      val.value.VS._1.VInt = (int)wc->TraitsArray.pObject->ITraits.pObject;
    }
    else
    {
      if ( (mi->Flags & 1) == 0 )
      {
LABEL_86:
        v56 = (Scaleform::GFx::AS3::TR::Block *)this->Heap->Alloc(this->Heap, 24, 0);
        if ( v56 )
        {
          v57 = heap;
          *((_DWORD *)v56 + 2) |= 1u;
          v56->Type = 0;
          v56->State = (Scaleform::GFx::AS3::TR::State *)v57;
          v56->From = 0;
        }
        else
        {
          v56 = 0;
        }
        v56->pPrev = this->Blocks.Root.pPrev;
        v56->pNext = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
        this->Blocks.Root.pPrev->pNext = v56;
        this->Blocks.Root.pPrev = v56;
        return;
      }
      val.value.VS._1.VInt = (int)wc->TraitsArray.pObject->ITraits.pObject;
    }
    v53 = cf;
    v54 = (Scaleform::GFx::AS3::Value *)&p_SelfSize->Data[cf];
    val.Flags = 8;
    val.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::Assign(v54, &val);
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        pWeakProxy = val.Bonus.pWeakProxy;
        v42 = val.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v42 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    *((_BYTE *)&heap->Info.pParent->__vftable + (v53 >> 3)) |= 1 << (v53 & 7);
    goto LABEL_86;
  }
  v59 = 1;
  we = 0;
  while ( 1 )
  {
    pFile = this->CF->pFile;
    v37 = (int)&pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*(int *)((char *)&we->info.Data.Data
                                                                                 + (unsigned int)mi->ParamTypes.Data.Data)];
    v38 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(wc, pFile, (Scaleform::GFx::AS3::Abc::Multiname *)v37);
    if ( !v38 )
      break;
    v39 = this->CF->pFile->VMRef;
    pObject = (Scaleform::GFx::AS3::Value::V1U)v38->ITraits.pObject;
    v41 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v39->TraitsInt.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v39->TraitsUint.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v39->TraitsNumber.pObject->ITraits.pObject
       || (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject.VInt == v39->TraitsBoolean.pObject->ITraits.pObject;
    v42 = !v41;
    v43 = (Scaleform::GFx::AS3::Value *)&p_SelfSize->Data[v59];
    val.value.VS._1 = pObject;
    val.Bonus.pWeakProxy = 0;
    val.Flags = (32 * (!v42 ? 0 : 2)) | 8;
    Scaleform::GFx::AS3::Value::Assign(v43, &val);
    if ( (val.Flags & 0x1F) > 9 )
    {
      if ( (val.Flags & 0x200) != 0 )
      {
        v44 = val.Bonus.pWeakProxy;
        v42 = val.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v42 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
        memset(&val.Bonus, 0, 12);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
      }
    }
    pParent = heap->Info.pParent;
    we = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)((char *)we + 4);
    ++v59;
    *((_BYTE *)&pParent->__vftable + (cf >> 3)) |= 1 << (cf & 7);
    if ( cf++ >= param_count )
      goto LABEL_63;
  }
  InternedString = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::AS3::VMFile::GetInternedString(
                                                        this->CF->pFile,
                                                        (Scaleform::GFx::ASString *)&heap,
                                                        *(Scaleform::GFx::ASStringNode **)(v37 + 8));
  val.Flags = 10;
  val.Bonus.pWeakProxy = 0;
  v47 = *InternedString;
  val.value.VS._1 = *InternedString;
  if ( InternedString->VInt == *(_DWORD *)(InternedString->VInt + 4) + 56 )
  {
    val.value.VS._1.VInt = 0;
    val.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v62;
    val.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(v47.VInt + 12);
  }
  v48 = wc;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&param_count,
    (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
    (Scaleform::GFx::ASStringNode *)wc,
    &val);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v48,
    v49,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v50 = v62;
  --v62->RefCount;
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
    {
      v51 = val.Bonus.pWeakProxy;
      --val.Bonus.pWeakProxy->RefCount;
      if ( !v51->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v51);
      val.Flags &= 0xFFFFFDE0;
      memset(&val.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
    }
  }
  v52 = (Scaleform::GFx::ASStringNode *)heap;
  --heap->SelfSize;
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
}
