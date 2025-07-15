void __thiscall Scaleform::GFx::AS3::TR::State::exec_getslot(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::ASStringNode *slot_index)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // ebx
  unsigned int v4; // edi
  int *Data; // eax
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::Tracer *pTracer; // ebp
  Scaleform::GFx::AS3::Traits *ITr; // edi
  Scaleform::GFx::AS3::VM *VMRef; // eax
  signed int v10; // eax
  unsigned int FirstOwnSlotNum; // edx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // ebp
  Scaleform::GFx::AS3::Value::V1U *SlotCTraits; // eax
  const Scaleform::GFx::ASString *DataTypeName; // eax
  Scaleform::GFx::ASStringNode *v15; // esi
  const Scaleform::GFx::AS3::VM::Error *v16; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v19; // ecx
  const Scaleform::GFx::AS3::Abc::TraitInfo *TI; // ebp
  Scaleform::GFx::AS3::Tracer *v21; // ecx
  Scaleform::GFx::AS3::Tracer *v22; // ecx
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v23; // [esp-4h] [ebp-54h]
  const Scaleform::GFx::AS3::InstanceTraits::Traits *v24; // [esp-4h] [ebp-54h]
  Scaleform::GFx::AS3::Value v25; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::TR::ReadObject args; // [esp+30h] [ebp-20h] BYREF

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
  v6 = (unsigned int)slot_index;
  WCode->Size = v4;
  Data[v4 - 1] = v6;
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
    goto LABEL_31;
  VMRef = pTracer->CF->pFile->VMRef;
  if ( ITr == VMRef->TraitsClassClass.pObject )
    ITr = VMRef->TraitsObject.pObject;
  if ( !ITr )
  {
LABEL_31:
    v25.Flags = 0;
    v25.Bonus.pWeakProxy = 0;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v25);
    goto LABEL_32;
  }
  if ( (unsigned int)slot_index > ITr->FirstOwnSlotNum + ITr->VArray.Data.Size )
  {
    v25.Bonus.pWeakProxy = 0;
    v25.value.VS._1.VInt = (int)pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v25.Flags = 72;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->OpStack.Data,
      &v25);
LABEL_32:
    Scaleform::GFx::AS3::Value::~Value(&v25);
    goto LABEL_33;
  }
  v10 = (signed int)slot_index + ITr->FirstOwnSlotInd.Index - 1;
  if ( v10 >= 0 && (FirstOwnSlotNum = ITr->FirstOwnSlotNum, v10 >= FirstOwnSlotNum) )
    p_Value = &ITr->VArray.Data.Data[v10 - FirstOwnSlotNum].Value;
  else
    p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                 (Scaleform::GFx::AS3::Slots *)ITr->Parent,
                                                 (Scaleform::GFx::AS3::AbsoluteIndex)v10);
  SlotCTraits = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::AS3::Tracer::GetSlotCTraits(
                                                     ITr,
                                                     (Scaleform::GFx::AS3::SlotIndex)slot_index);
  if ( SlotCTraits )
  {
    v19 = SlotCTraits[25].ITr;
    if ( (*(_DWORD *)p_Value & 0x3E0) == 0x20 || (TI = p_Value->TI) != 0 && (TI->kind & 0xF) == 4 )
    {
      v23 = SlotCTraits[25].ITr;
      v21 = this->pTracer;
      v25.Bonus.pWeakProxy = 0;
      v25.value.VS._1.VInt = (int)SlotCTraits;
      v25.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v21, v23) & 0xFFFFFFF7)) | 9;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &v25);
    }
    else
    {
      v25.value.VS._1 = SlotCTraits[25];
      v24 = v19;
      v22 = this->pTracer;
      v25.Bonus.pWeakProxy = 0;
      v25.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v22, v24) & 0xFFFFFFF7)) | 8;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->OpStack.Data,
        &v25);
    }
    goto LABEL_32;
  }
  DataTypeName = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(
                   p_Value,
                   (Scaleform::GFx::ASString *)&slot_index,
                   this->pTracer->CF->pFile->VMRef);
  Scaleform::GFx::AS3::Value::Value(&arg1, DataTypeName);
  v15 = (Scaleform::GFx::ASStringNode *)this->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&v25,
    (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
    v15,
    &arg1);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    (Scaleform::GFx::AS3::VM *)v15,
    v16,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v25.Bonus.pWeakProxy;
  --v25.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  Scaleform::GFx::AS3::Value::~Value(&arg1);
  v18 = slot_index;
  --slot_index->RefCount;
  if ( !v18->RefCount )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    Scaleform::GFx::AS3::TR::ReadObject::~ReadObject(&args);
    return;
  }
LABEL_33:
  Scaleform::GFx::AS3::TR::ReadObject::~ReadObject(&args);
}
