char __thiscall Scaleform::GFx::AS3::Tracer::EmitGetProperty(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::VM *opcode,
        Scaleform::GFx::AS3::TR::State *st,
        const Scaleform::GFx::AS3::TR::ReadMnObject *args,
        int mn_index)
{
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *p_ArgMN; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // ecx
  Scaleform::GFx::AS3::Value::V2U v10; // edi
  int v11; // eax
  int v12; // eax
  const Scaleform::GFx::AS3::SlotInfo *v13; // eax
  Scaleform::GFx::AS3::SlotInfo *v14; // ebx
  int v15; // eax
  Scaleform::GFx::AS3::TR::State *v16; // ebp
  Scaleform::GFx::AS3::VTable *VT; // eax
  const Scaleform::GFx::AS3::Value *Value; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctType; // edi
  int v21; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // ebx
  Scaleform::GFx::AS3::VTable *v23; // eax
  const Scaleform::GFx::AS3::Value *v24; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // edi
  Scaleform::GFx::AS3::TR::State *v26; // edi
  const Scaleform::GFx::AS3::CallFrame *CF; // edx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  Scaleform::GFx::AS3::TR::State *v29; // edi
  Scaleform::GFx::AS3::RefCountCollector<328> *pObject; // edx
  Scaleform::GFx::AS3::Value::V1U nRoots; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v32; // eax
  Scaleform::GFx::AS3::Multiname v33; // [esp-20h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v34; // [esp-8h] [ebp-2Ch]
  Scaleform::GFx::AS3::AbsoluteIndex v35; // [esp-4h] [ebp-28h]
  const Scaleform::GFx::AS3::Multiname *mn; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value type; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+28h] [ebp+4h]

  p_ArgMN = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&args->ArgMN;
  mn = &args->ArgMN;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(
                  this,
                  &args->ArgObject,
                  opcode == (Scaleform::GFx::AS3::VM *)4);
  Data = p_ArgMN->Data.Data;
  v10.VObj = (Scaleform::GFx::AS3::Object *)ValueTraits;
  v11 = (int)p_ArgMN->Data.Data & 3;
  if ( v11 == 1 || ((unsigned __int8)Data & 4) != 0 || ((unsigned __int8)Data & 8) != 0 || !v11 && !p_ArgMN->Data.Size )
    goto fall_back;
  if ( !v10.VObj )
    goto fall_back;
  v12 = p_ArgMN->Data.Policy.Capacity & 0x1F;
  vm = this->CF->pFile->VMRef;
  args = 0;
  if ( v12 == 8 || v12 == 9 )
    goto fall_back;
  if ( ((int)v10.VObj[1].DynAttrs.mHash.pTable & 4) != 0
    || Scaleform::GFx::AS3::Tracer::IsPrimitiveType(this, (Scaleform::GFx::AS3::InstanceTraits::Traits *)v10.VObj) )
  {
LABEL_28:
    CF = this->CF;
    mn = 0;
    FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::FindFixedSlot(
                                                   (const Scaleform::GFx::AS3::SlotInfo *)CF->pFile->VMRef,
                                                   v10.pTraits,
                                                   p_ArgMN,
                                                   (unsigned int *)&mn,
                                                   0);
    if ( FixedSlot )
    {
      v33.Name.value.VS._2 = v10;
      v29 = st;
      type.Flags = 0;
      type.Bonus.pWeakProxy = 0;
      if ( Scaleform::GFx::AS3::TR::State::GetPropertyType(
             st,
             (Scaleform::GFx::AS3::CheckResult *)&st,
             v33.Name.value.VS._2.pTraits,
             FixedSlot,
             &type)->Result )
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &v29->OpStack.Data,
          &type);
        Scaleform::GFx::AS3::Value::~Value(&type);
LABEL_45:
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)opcode, mn_index);
        return 1;
      }
LABEL_23:
      Scaleform::GFx::AS3::Value::~Value(&type);
      return 0;
    }
    if ( v10.VObj == (Scaleform::GFx::AS3::Object *)vm->TraitsVector_int.pObject->ITraits.pObject )
    {
      pObject = (Scaleform::GFx::AS3::RefCountCollector<328> *)vm->TraitsInt.pObject;
      goto LABEL_42;
    }
    if ( v10.VObj == (Scaleform::GFx::AS3::Object *)vm->TraitsVector_uint.pObject->ITraits.pObject )
    {
      pObject = (Scaleform::GFx::AS3::RefCountCollector<328> *)vm->TraitsUint.pObject;
      goto LABEL_42;
    }
    if ( v10.VObj == (Scaleform::GFx::AS3::Object *)vm->TraitsVector_Number.pObject->ITraits.pObject )
    {
      pObject = (Scaleform::GFx::AS3::RefCountCollector<328> *)vm->TraitsNumber.pObject;
      goto LABEL_42;
    }
    if ( v10.VObj == (Scaleform::GFx::AS3::Object *)vm->TraitsVector_String.pObject->ITraits.pObject )
    {
      pObject = (Scaleform::GFx::AS3::RefCountCollector<328> *)vm->TraitsString.pObject;
      goto LABEL_42;
    }
    if ( v10.VObj[1].pUserDataHolder == (Scaleform::GFx::AS3::Object::UserDataHolder *)11
      && ((int)v10.VObj[1].DynAttrs.mHash.pTable & 0x20) == 0 )
    {
      pObject = Scaleform::GFx::AS3::Traits::GetClass(v10.pTraits)->pTraits.pObject[1]._pRCC;
LABEL_42:
      nRoots = (Scaleform::GFx::AS3::Value::V1U)pObject[1].Roots[0].nRoots;
      if ( nRoots.VInt )
      {
        v35.Index = pObject[1].Roots[0].nRoots;
        type.Bonus.pWeakProxy = 0;
        type.value.VS._1 = nRoots;
        type.Flags = (32
                    * (Scaleform::GFx::AS3::Tracer::CanBeNull(
                         this,
                         (const Scaleform::GFx::AS3::InstanceTraits::Traits *)v35.Index)
                     & 0xFFFFFFF7))
                   | 8;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &type);
        Scaleform::GFx::AS3::Value::~Value(&type);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)opcode, mn_index);
        return 1;
      }
    }
fall_back:
    v32 = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    type.Bonus.pWeakProxy = 0;
    type.value.VS._1.VInt = (int)v32;
    type.Flags = 72;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &st->OpStack.Data,
      &type);
    goto LABEL_45;
  }
  if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v10.VObj->SetProperty)(v10) )
  {
    v35.Index = 0;
    v34.Index = 1;
    Scaleform::GFx::AS3::Multiname::Multiname(&v33, (const Scaleform::GFx::AS3::Multiname *)p_ArgMN);
    if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
           this,
           st,
           v33,
           (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v34.Index,
           v35.Index) )
    {
      return 1;
    }
  }
  v13 = Scaleform::GFx::AS3::FindFixedSlot(
          (const Scaleform::GFx::AS3::SlotInfo *)vm,
          v10.pTraits,
          p_ArgMN,
          (unsigned int *)&args,
          0);
  v14 = (Scaleform::GFx::AS3::SlotInfo *)v13;
  if ( !v13 )
    goto LABEL_27;
  v15 = (int)(*(_DWORD *)v13 << 22) >> 27;
  if ( v15 <= 10 )
  {
    v33.Name.value.VS._2 = v10;
    v26 = st;
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0;
    if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(
            st,
            (Scaleform::GFx::AS3::CheckResult *)&st,
            v33.Name.value.VS._2.pTraits,
            v14,
            &type)->Result )
      goto LABEL_23;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &v26->OpStack.Data,
      &type);
    Scaleform::GFx::AS3::Value::~Value(&type);
    if ( (mn->Kind & 4) != 0 )
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
    Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, v26, (unsigned int)args);
    return 1;
  }
  if ( (*(_DWORD *)v14 & 0x4000000) != 0 )
  {
LABEL_27:
    p_ArgMN = (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)mn;
    goto LABEL_28;
  }
  if ( v15 == 11 )
  {
    if ( opcode == (Scaleform::GFx::AS3::VM *)102 )
    {
      v16 = st;
      Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, (unsigned int)args);
      v35.Index = (32 * *(_DWORD *)v14) >> 15;
      v34.Index = (int)&type;
      VT = Scaleform::GFx::AS3::Traits::GetVT(v10.pTraits);
      Value = Scaleform::GFx::AS3::VTable::GetValue(VT, (Scaleform::GFx::AS3::Value *)v34.Index, v35);
      FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(v16, Value);
      Scaleform::GFx::AS3::Value::~Value(&type);
      type.Bonus.pWeakProxy = 0;
      type.value.VS._1.VInt = (int)FunctType;
      type.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctType) & 0xFFFFFFF7)) | 8;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &v16->OpStack.Data,
        &type);
      Scaleform::GFx::AS3::Value::~Value(&type);
      return 1;
    }
    goto LABEL_27;
  }
  if ( (mn->Kind & 4) != 0 )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(
    this,
    (Scaleform::GFx::AS3::Abc::Code::OpCode)(opcode != (Scaleform::GFx::AS3::VM *)4 ? op_callmethod : op_callsupermethod),
    (32 * *(_DWORD *)v14) >> 15,
    0);
  v21 = *(_DWORD *)v14;
  VMRef = this->CF->pFile->VMRef;
  v35.Index = ((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v10.VObj->AS3Constructor)(v10);
  v34.Index = (32 * v21) >> 15;
  v33.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)&type;
  v23 = Scaleform::GFx::AS3::Traits::GetVT(v10.pTraits);
  v24 = Scaleform::GFx::AS3::VTable::GetValue(v23, (Scaleform::GFx::AS3::Value *)v33.Name.value.VS._2.VObj, v34);
  FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                      VMRef,
                      v24,
                      (Scaleform::GFx::AS3::VMAppDomain *)v35.Index);
  Scaleform::GFx::AS3::Value::~Value(&type);
  type.Bonus.pWeakProxy = 0;
  type.value.VS._1.VInt = (int)FunctReturnType;
  type.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctReturnType) & 0xFFFFFFF7)) | 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &st->OpStack.Data,
    &type);
  Scaleform::GFx::AS3::Value::~Value(&type);
  return 1;
}
