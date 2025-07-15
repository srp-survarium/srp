char __thiscall Scaleform::GFx::AS3::Tracer::EmitFindProperty(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        int mn_index,
        bool get_prop,
        Scaleform::GFx::AS3::Abc::Code::OpCode consumer,
        bool show_getprop)
{
  int v7; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // ebx
  Scaleform::GFx::AS3::VM *VMRef; // eax
  Scaleform::GFx::AS3::TR::State::ScopeType v10; // ebp
  int v11; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // eax
  char Slot; // bl
  int v19; // ebp
  signed int v20; // eax
  Scaleform::GFx::AS3::VTable *VT; // eax
  const Scaleform::GFx::AS3::Value *Value; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctType; // ebx
  int v24; // ebp
  Scaleform::GFx::AS3::VMAppDomain *(__thiscall *GetAppDomain)(Scaleform::GFx::AS3::Traits *); // eax
  Scaleform::GFx::AS3::VTable *v26; // eax
  const Scaleform::GFx::AS3::Value *v27; // eax
  Scaleform::GFx::AS3::Multiname v28; // [esp-20h] [ebp-A8h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v29; // [esp-8h] [ebp-90h]
  Scaleform::GFx::AS3::AbsoluteIndex v30; // [esp-4h] [ebp-8Ch]
  Scaleform::GFx::AS3::CheckResult result; // [esp+12h] [ebp-76h] BYREF
  Scaleform::GFx::AS3::CheckResult v32; // [esp+13h] [ebp-75h] BYREF
  int alteredBehaviour; // [esp+14h] [ebp-74h]
  const Scaleform::GFx::AS3::SlotInfo *pSI; // [esp+18h] [ebp-70h]
  unsigned int slot_ind; // [esp+1Ch] [ebp-6Ch]
  Scaleform::GFx::ASString name; // [esp+20h] [ebp-68h] BYREF
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [esp+24h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::Value type; // [esp+28h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v39; // [esp+38h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value v40; // [esp+48h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+58h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Multiname as3_mn; // [esp+70h] [ebp-18h] BYREF

  stype = stScopeStack;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &as3_mn,
    this->CF->pFile,
    &this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
  name.pNode = 0;
  if ( (as3_mn.Kind & 3) == 1 || (as3_mn.Kind & 4) != 0 )
    goto LABEL_75;
  memset(&prop, 0, 16);
  Scaleform::GFx::AS3::TR::State::FindProp(
    st,
    &prop,
    (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&as3_mn,
    &stype,
    (unsigned int *)&name);
  v7 = prop.This.Flags & 0x1F;
  if ( (prop.This.Flags & 0x1F) == 0
    || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0
    || ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
  {
    if ( get_prop )
    {
      v30.Index = 0;
      v29.Index = 0;
      Scaleform::GFx::AS3::Multiname::Multiname(&v28, &as3_mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
             this,
             st,
             v28,
             (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v29.Index,
             v30.Index) )
      {
        goto LABEL_66;
      }
    }
    goto LABEL_74;
  }
  if ( ((int)prop.pSI & 1) != 0 )
    goto LABEL_74;
  slot_ind = prop.SlotIndex;
  pSI = prop.pSI;
  if ( consumer == op_setproperty
    || consumer == op_initproperty
    || (LOBYTE(alteredBehaviour) = 1, !Scaleform::GFx::AS3::SlotInfo::IsClass((Scaleform::GFx::AS3::SlotInfo *)prop.pSI)) )
  {
    LOBYTE(alteredBehaviour) = 0;
  }
  if ( v7 )
  {
    if ( (unsigned int)(v7 - 8) < 2 )
      ITr = prop.This.value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             &prop.This);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  v10 = stype;
  if ( stype < stScopeStack )
  {
LABEL_74:
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
LABEL_75:
    Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
    return 0;
  }
  if ( stype <= stStoredScope )
  {
    if ( (_BYTE)alteredBehaviour )
    {
      v30.Index = alteredBehaviour;
      v29.Index = 0;
      Scaleform::GFx::AS3::Multiname::Multiname(&v28, &as3_mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
             this,
             st,
             v28,
             (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v29.Index,
             v30.Index) )
      {
        goto LABEL_66;
      }
    }
    if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &prop.This, 0) )
    {
      if ( v10 )
      {
        if ( Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &prop.This, 0) )
          goto LABEL_55;
        v30.Index = (int)name.pNode;
        v29.Index = 103;
      }
      else
      {
        v30.Index = (int)name.pNode;
        v29.Index = 101;
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)v29.Index, v30.Index);
    }
LABEL_55:
    if ( !get_prop )
    {
      if ( consumer != op_constructprop )
      {
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          &prop.This);
        goto LABEL_66;
      }
      LOBYTE(alteredBehaviour) = 1;
    }
    v19 = (int)(*(_DWORD *)pSI << 22) >> 27;
    if ( v19 <= 10 || (v20 = (32 * *(_DWORD *)pSI) >> 15, v20 < 0) || (ITr->Flags & 4) != 0 )
    {
      Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, slot_ind);
      type.Flags = 0;
      type.Bonus.pWeakProxy = 0;
      if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(st, &v32, ITr, (Scaleform::GFx::AS3::SlotInfo *)pSI, &type)->Result )
      {
LABEL_40:
        Scaleform::GFx::AS3::Value::~Value(&type);
        goto LABEL_74;
      }
      if ( (_BYTE)alteredBehaviour )
        type.Flags |= 0x400u;
      v30.Index = (int)&type;
    }
    else
    {
      if ( v19 == 11 )
      {
        Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, slot_ind);
        v30.Index = (32 * *(_DWORD *)pSI) >> 15;
        v29.Index = (int)&v39;
        VT = Scaleform::GFx::AS3::Traits::GetVT(ITr);
        Value = Scaleform::GFx::AS3::VTable::GetValue(VT, (Scaleform::GFx::AS3::Value *)v29.Index, v30);
        FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(st, Value);
        Scaleform::GFx::AS3::Value::~Value(&v39);
      }
      else
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_callmethod, v20, 0);
        v24 = *(_DWORD *)pSI;
        GetAppDomain = ITr->GetAppDomain;
        stype = (Scaleform::GFx::AS3::TR::State::ScopeType)this->CF->pFile->VMRef;
        v30.Index = (int)GetAppDomain(ITr);
        v29.Index = (32 * v24) >> 15;
        v28.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)&v40;
        v26 = Scaleform::GFx::AS3::Traits::GetVT(ITr);
        v27 = Scaleform::GFx::AS3::VTable::GetValue(v26, (Scaleform::GFx::AS3::Value *)v28.Name.value.VS._2.VObj, v29);
        FunctType = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                      (Scaleform::GFx::AS3::VM *)stype,
                      v27,
                      (Scaleform::GFx::AS3::VMAppDomain *)v30.Index);
        Scaleform::GFx::AS3::Value::~Value(&v40);
      }
      type.Bonus.pWeakProxy = 0;
      type.value.VS._1.VInt = (int)FunctType;
      type.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctType) & 0xFFFFFFF7)) | 8;
      v30.Index = (int)&type;
    }
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &st->OpStack.Data,
      (Scaleform::GFx::AS3::Value *)v30.Index);
    Scaleform::GFx::AS3::Value::~Value(&type);
LABEL_66:
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
    return 1;
  }
  if ( stype != stGlobalObject )
    goto LABEL_74;
  if ( (_BYTE)alteredBehaviour )
  {
    v30.Index = alteredBehaviour;
    v29.Index = 0;
    Scaleform::GFx::AS3::Multiname::Multiname(&v28, &as3_mn);
    if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
           this,
           st,
           v28,
           (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v29.Index,
           v30.Index) )
    {
      goto LABEL_66;
    }
  }
  if ( get_prop )
  {
    if ( (int)((*(_DWORD *)pSI & 0xFFFFFFE0) << 22) > 1342177280 )
      goto LABEL_74;
    if ( (prop.This.Flags & 0x1F) - 12 <= 3
      && (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)prop.This.value.VS._1.VInt == this->CF->pFile->VMRef->GlobalObject.pObject )
    {
      Scaleform::GFx::AS3::Slots::GetSlotName(
        &ITr->Scaleform::GFx::AS3::Slots,
        &name,
        (Scaleform::GFx::AS3::AbsoluteIndex)slot_ind);
      if ( Scaleform::GFx::ASString::operator==(&name, "undefined") )
      {
        v11 = 1;
        goto LABEL_34;
      }
      if ( Scaleform::GFx::ASString::operator==(&name, "NaN") )
      {
        v11 = 2;
LABEL_34:
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(
          this,
          (Scaleform::GFx::AS3::Abc::Code::OpCode)(v11 != 1 ? op_pushnan : op_pushundefined));
        Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &st->OpStack.Data,
          Undefined);
        pNode = name.pNode;
        v14 = name.pNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        goto LABEL_66;
      }
      v15 = name.pNode;
      v14 = name.pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &prop.This, 0) )
      goto LABEL_74;
    v30.Index = (int)&type;
    v29.Index = (int)pSI;
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0;
    ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &prop.This, 0);
    if ( Scaleform::GFx::AS3::TR::State::GetPropertyType(
           st,
           &result,
           ValueTraits,
           (Scaleform::GFx::AS3::SlotInfo *)v29.Index,
           (Scaleform::GFx::AS3::Value *)v30.Index)->Result )
    {
      if ( (_BYTE)alteredBehaviour )
        type.Flags |= 0x400u;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &st->OpStack.Data,
        &type);
      Scaleform::GFx::AS3::Value::~Value(&type);
      Scaleform::GFx::AS3::Tracer::EmitGetAbsSlot(this, st, slot_ind);
      goto LABEL_66;
    }
    goto LABEL_40;
  }
  Slot = Scaleform::GFx::AS3::Tracer::EmitGetSlot(this, st, &prop.This, slot_ind, 0);
  if ( Slot )
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &st->OpStack.Data,
      &prop.This);
  Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  Scaleform::GFx::AS3::Multiname::~Multiname(&as3_mn);
  return Slot;
}
