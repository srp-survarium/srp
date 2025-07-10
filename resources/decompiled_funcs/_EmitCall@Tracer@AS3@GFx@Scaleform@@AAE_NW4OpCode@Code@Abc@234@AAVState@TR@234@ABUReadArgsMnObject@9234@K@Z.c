char __thiscall Scaleform::GFx::AS3::Tracer::EmitCall(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::TR::State *st,
        const Scaleform::GFx::AS3::TR::ReadArgsMnObject *args,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v5; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // ecx
  unsigned int ArgNum; // edx
  Scaleform::GFx::AS3::Multiname *p_ArgMN; // ebx
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  Scaleform::GFx::AS3::Traits *v13; // esi
  Scaleform::GFx::AS3::VM *VMRef; // eax
  const Scaleform::GFx::AS3::SlotInfo *FixedSlot; // eax
  Scaleform::GFx::AS3::SlotInfo *v16; // ebp
  int v17; // eax
  int v18; // esi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // eax
  Scaleform::GFx::AS3::VM *v20; // ebx
  Scaleform::GFx::AS3::VTable *VT; // eax
  const Scaleform::GFx::AS3::Value *Value; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // ebx
  int v24; // esi
  Scaleform::GFx::AS3::Abc::Code::OpCode v25; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v27; // eax
  Scaleform::GFx::ASString *ClassTraits; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // edx
  Scaleform::GFx::AS3::Value::V1U pNode; // eax
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // [esp-4h] [ebp-34h]
  bool tr; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::Traits *tra; // [esp+10h] [ebp-20h]
  unsigned int slot_index; // [esp+14h] [ebp-1Ch] BYREF
  const Scaleform::GFx::AS3::Multiname *mn; // [esp+18h] [ebp-18h]
  Scaleform::GFx::AS3::VM *vm; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value result; // [esp+20h] [ebp-10h] BYREF
  unsigned int argc; // [esp+3Ch] [ebp+Ch]

  v5 = opcode;
  if ( opcode == op_callsuper || (tr = 0, opcode == op_callsupervoid) )
    tr = 1;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, tr);
  Kind = args->ArgMN.Kind;
  ArgNum = args->ArgNum;
  p_ArgMN = &args->ArgMN;
  tra = ValueTraits;
  mn = &args->ArgMN;
  argc = ArgNum;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 || (Kind & 8) != 0 )
    goto LABEL_39;
  if ( (Kind & 3) == 0 && !args->ArgMN.Obj.pObject )
  {
LABEL_38:
    v5 = opcode;
LABEL_39:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v5, mn_index, argc);
    if ( v5 == op_callpropvoid || v5 == op_callsupervoid )
      return 1;
    pObject = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    result.Bonus.pWeakProxy = 0;
    result.Flags = 72;
    goto LABEL_42;
  }
  CF = this->CF;
  v13 = tra;
  slot_index = 0;
  VMRef = CF->pFile->VMRef;
  vm = VMRef;
  if ( !tra
    || (tra->Flags & 4) != 0
    || (FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                      (const Scaleform::GFx::AS3::SlotInfo *)VMRef,
                      tra,
                      (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)p_ArgMN,
                      &slot_index,
                      0),
        (v16 = (Scaleform::GFx::AS3::SlotInfo *)FixedSlot) == 0) )
  {
LABEL_32:
    ClassTraits = Scaleform::GFx::AS3::FindClassTraits(
                    vm,
                    p_ArgMN,
                    (Scaleform::GFx::ASStringNode *)this->CF->pFile->AppDomain);
    if ( ClassTraits )
    {
      if ( (v13->Flags & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, opcode, mn_index, argc);
        if ( opcode == op_callpropvoid || opcode == op_callsupervoid )
          return 1;
        pNode = (Scaleform::GFx::AS3::Value::V1U)ClassTraits[25].pNode;
        result.Bonus.pWeakProxy = 0;
        result.value.VS._1 = pNode;
        result.Flags = 8;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &result);
        goto LABEL_44;
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_callobject, argc);
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ClassTraits[25].pNode;
      result.Bonus.pWeakProxy = 0;
      result.Flags = 8;
LABEL_42:
      result.value.VS._1.VInt = (int)pObject;
      goto LABEL_43;
    }
    goto LABEL_38;
  }
  v17 = *(_DWORD *)FixedSlot;
  v18 = (32 * *(_DWORD *)v16) >> 15;
  if ( v18 < 0 || (v17 & 0x3E0) != 0x160 && !Scaleform::GFx::AS3::SlotInfo::IsGetter(v16) )
  {
LABEL_31:
    v13 = tra;
    goto LABEL_32;
  }
  pFile = this->CF->pFile;
  v20 = pFile->VMRef;
  AppDomain = pFile->AppDomain;
  VT = Scaleform::GFx::AS3::Traits::GetVT(tra);
  Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &result, (Scaleform::GFx::AS3::AbsoluteIndex)v18);
  FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(v20, Value, AppDomain);
  Scaleform::GFx::AS3::Value::~Value(&result);
  v24 = *(_DWORD *)v16;
  if ( (*(_DWORD *)v16 & 0x3E0) == 0x160 )
  {
    if ( opcode == op_callsuper || (v25 = op_callmethod, opcode == op_callsupervoid) )
      v25 = op_callsupermethod;
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v25, (32 * v24) >> 15, argc);
    if ( opcode != op_callpropvoid && opcode != op_callsupervoid )
    {
      result.Bonus.pWeakProxy = 0;
      result.value.VS._1.VInt = (int)FunctReturnType;
      result.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctReturnType) & 0xFFFFFFF7)) | 8;
LABEL_43:
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &st->OpStack.Data,
        &result);
      goto LABEL_44;
    }
LABEL_22:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
    return 1;
  }
  if ( !Scaleform::GFx::AS3::SlotInfo::IsGetter(v16) )
  {
    p_ArgMN = mn;
    goto LABEL_31;
  }
  if ( opcode == op_callsuper || (v27 = op_callgetter, opcode == op_callsupervoid) )
    v27 = op_callsupergetter;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v27, (32 * v24) >> 15, argc);
  if ( opcode == op_callpropvoid || opcode == op_callsupervoid )
    goto LABEL_22;
  result.Bonus.pWeakProxy = 0;
  result.value.VS._1.VInt = (int)FunctReturnType;
  result.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctReturnType) & 0xFFFFFFF7)) | 8;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &st->OpStack.Data,
    &result);
LABEL_44:
  Scaleform::GFx::AS3::Value::~Value(&result);
  return 1;
}
