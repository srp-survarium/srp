void __thiscall Scaleform::GFx::AS3::TR::State::exec_getslot(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int slot_index)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebx
  unsigned int v4; // esi
  int *Data; // eax
  Scaleform::GFx::AS3::Tracer *pTracer; // ecx
  Scaleform::GFx::AS3::Traits *ITr; // esi
  Scaleform::GFx::AS3::VM *VMRef; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *SlotCTraits; // eax
  Scaleform::GFx::AS3::VM *v11; // esi
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value::V1U pObject; // esi
  const Scaleform::GFx::AS3::Abc::TraitInfo *TI; // ebp
  Scaleform::GFx::AS3::Tracer *v16; // ecx
  Scaleform::GFx::AS3::Tracer *v17; // ecx
  const Scaleform::GFx::AS3::CallFrame *CF; // ecx
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v19; // [esp-4h] [ebp-44h]
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v20; // [esp-4h] [ebp-44h]
  Scaleform::GFx::AS3::Value v21; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::TR::ReadObject args; // [esp+20h] [ebp-20h] BYREF
  const Scaleform::GFx::AS3::SlotInfo *slot_indexa; // [esp+44h] [ebp+4h]

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = slot_index;
  args.VMRef = this->pTracer->CF->pFile->VMRef;
  args.StateRef = this;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    (Scaleform::GFx::AS3::Value *)&args.ArgObject);
  args.Num = 1;
  pTracer = this->pTracer;
  if ( (args.ArgObject.Flags & 0x1F) != 0 )
  {
    if ( (args.ArgObject.Flags & 0x1F) - 8 < 2 )
      ITr = args.ArgObject.value.VS._1.ITr;
    else
      ITr = Scaleform::GFx::AS3::VM::GetValueTraits(pTracer->CF->pFile->VMRef, &args.ArgObject);
  }
  else
  {
    ITr = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( !ITr )
    goto LABEL_25;
  VMRef = this->pTracer->CF->pFile->VMRef;
  if ( ITr == VMRef->TraitsClassClass.pObject )
    ITr = VMRef->TraitsObject.pObject;
  if ( !ITr )
  {
LABEL_25:
    v21.Flags = 0;
    v21.Bonus.pWeakProxy = 0;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v21);
    goto LABEL_26;
  }
  if ( slot_index > ITr->FirstOwnSlotNum + ITr->VArray.Data.Size )
  {
    CF = this->pTracer->CF;
    v21.Bonus.pWeakProxy = 0;
    v21.value.VS._1.VInt = (int)CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v21.Flags = 72;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v21);
LABEL_26:
    Scaleform::GFx::AS3::Value::~Value(&v21);
    goto LABEL_27;
  }
  slot_indexa = Scaleform::GFx::AS3::Traits::GetSlotInfo(
                  ITr,
                  (Scaleform::GFx::AS3::AbsoluteIndex)(ITr->FirstOwnSlotInd.Index + slot_index - 1));
  SlotCTraits = Scaleform::GFx::AS3::Tracer::GetSlotCTraits(ITr, (Scaleform::GFx::AS3::SlotIndex)slot_index);
  if ( SlotCTraits )
  {
    pObject = (Scaleform::GFx::AS3::Value::V1U)SlotCTraits->ITraits.pObject;
    if ( (*(_DWORD *)slot_indexa & 0x3E0) == 0x20 || (TI = slot_indexa->TI) != 0 && (TI->kind & 0xF) == 4 )
    {
      v16 = this->pTracer;
      v19 = SlotCTraits->ITraits.pObject;
      v21.Bonus.pWeakProxy = 0;
      v21.value.VS._1.VInt = (int)SlotCTraits;
      v21.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v16, v19) & 0xFFFFFFF7)) | 9;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &v21);
    }
    else
    {
      v17 = this->pTracer;
      v20 = SlotCTraits->ITraits.pObject;
      v21.Bonus.pWeakProxy = 0;
      v21.value.VS._1 = pObject;
      v21.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v17, v20) & 0xFFFFFFF7)) | 8;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &v21);
    }
    goto LABEL_26;
  }
  v11 = this->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v21, eClassNotFoundError, v11);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v11,
    v12,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v21.Bonus.pWeakProxy;
  --v21.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    Scaleform::GFx::AS3::TR::ReadObject::~ReadObject(&args);
    return;
  }
LABEL_27:
  Scaleform::GFx::AS3::TR::ReadObject::~ReadObject(&args);
}
