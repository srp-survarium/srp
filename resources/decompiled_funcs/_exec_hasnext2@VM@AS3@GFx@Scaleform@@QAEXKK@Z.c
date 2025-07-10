void __thiscall Scaleform::GFx::AS3::VM::exec_hasnext2(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value::V1U object_reg,
        Scaleform::GFx::AS3::GlobalSlotIndex index_reg)
{
  Scaleform::GFx::AS3::Value *pRF; // ecx
  Scaleform::GFx::AS3::Value *v5; // edi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  int v8; // edx
  Scaleform::GFx::AS3::Value *v9; // esi
  long double VNumber; // kr00_8
  unsigned int Index; // ebp
  Scaleform::GFx::AS3::Value *v12; // ecx
  int v13; // eax
  Scaleform::GFx::AS3::Object *v14; // ebp
  int pObject; // edi
  const Scaleform::GFx::AS3::Value *v16; // eax
  const Scaleform::GFx::AS3::Value *v17; // eax
  Scaleform::GFx::AS3::Value *v18; // ecx
  bool v19; // al
  Scaleform::GFx::AS3::Value *v20; // esi
  long double v21; // kr08_8
  Scaleform::GFx::AS3::Value *v22; // ecx
  bool v23; // cl
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  int v25; // edi
  Scaleform::GFx::AS3::Value *v26; // ecx
  long double v27; // kr10_8
  Scaleform::GFx::AS3::Object *Prototype; // ebp
  Scaleform::GFx::AS3::Value::V1U *v29; // eax
  Scaleform::GFx::AS3::Value::V1U v30; // ebx
  const Scaleform::GFx::AS3::Value *v31; // eax
  const Scaleform::GFx::AS3::Value *Null; // eax
  Scaleform::GFx::AS3::Value *v33; // ecx
  Scaleform::GFx::AS3::Value::V1U v34; // [esp+10h] [ebp-1Ch]
  int v35; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS3::Object *obj; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::Value v37; // [esp+1Ch] [ebp-10h] BYREF

  pRF = this->RegisterFile.pRF;
  v34.VInt = 16 * object_reg.VInt;
  v5 = &pRF[object_reg.VInt];
  if ( index_reg.Index != object_reg.VInt )
  {
    v8 = v5->Flags & 0x1F;
    if ( !v8 || (unsigned int)(v8 - 12) <= 3 && !v5->value.VS._1.VInt )
    {
      v9 = ++this->OpStack.pCurrent;
      v37.Flags = 1;
      v37.Bonus.pWeakProxy = 0;
      v37.value.VS._1.VBool = 0;
      if ( v9 )
      {
        VNumber = v37.value.VNumber;
        v9->Flags = 1;
        v9->Bonus.pWeakProxy = 0;
        v9->value.VNumber = VNumber;
      }
      goto LABEL_43;
    }
    Index = index_reg.Index;
    v12 = &pRF[index_reg.Index];
    index_reg.Index = 0;
    v35 = Index * 16;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(
            v12,
            (Scaleform::GFx::AS3::CheckResult *)&object_reg,
            (Scaleform::GFx::AS3::Value::V1U *)&index_reg)->Result )
      return;
    v13 = v5->Flags & 0x1F;
    if ( (unsigned int)(v13 - 12) > 3 )
    {
      if ( v13 == 11 )
      {
        Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropIndex(
          (Scaleform::GFx::AS3::Instances::fl::QName *)v5->value.VS._1.VInt,
          (Scaleform::GFx::AS3::GlobalSlotIndex *)&object_reg,
          index_reg);
        v22 = &this->RegisterFile.pRF[Index];
        v37.Flags = 3;
        v37.Bonus.pWeakProxy = 0;
        v37.value.VS._1 = object_reg;
        Scaleform::GFx::AS3::Value::Assign(v22, &v37);
        Scaleform::GFx::AS3::Value::~Value(&v37);
        v37.Flags = 1;
        v23 = object_reg.VInt != 0;
        v20 = ++this->OpStack.pCurrent;
        v37.Bonus.pWeakProxy = 0;
        v37.value.VS._1.VBool = v23;
        if ( !v20 )
          goto LABEL_43;
        v20->Bonus.pWeakProxy = 0;
      }
      else
      {
        ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, v5);
        v25 = (int)ValueTraits;
        if ( ValueTraits->TraitsType == Traits_Namespace && (ValueTraits->Flags & 0x20) == 0 && index_reg.Index <= 1 )
        {
          v26 = &this->RegisterFile.pRF[Index];
          v37.Flags = 3;
          v37.Bonus.pWeakProxy = 0;
          v37.value.VS._1.VInt = index_reg.Index + 1;
          Scaleform::GFx::AS3::Value::Assign(v26, &v37);
          Scaleform::GFx::AS3::Value::~Value(&v37);
          v20 = ++this->OpStack.pCurrent;
          v37.Flags = 1;
          v37.Bonus.pWeakProxy = 0;
          v37.value.VS._1.VBool = 1;
          if ( v20 )
          {
            v27 = v37.value.VNumber;
            v20->Bonus.pWeakProxy = 0;
            v20->value.VNumber = v27;
            goto LABEL_42;
          }
LABEL_43:
          Scaleform::GFx::AS3::Value::~Value(&v37);
          return;
        }
        while ( 1 )
        {
          if ( !*(_DWORD *)(v25 + 68) )
            (*(void (__thiscall **)(int))(*(_DWORD *)v25 + 44))(v25);
          Prototype = Scaleform::GFx::AS3::Class::GetPrototype(*(Scaleform::GFx::AS3::Class **)(v25 + 68), v25);
          v29 = (Scaleform::GFx::AS3::Value::V1U *)((int (__thiscall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value::V1U *, _DWORD))Prototype->GetNextDynPropIndex)(
                                                     Prototype,
                                                     &object_reg,
                                                     0);
          v25 = *(_DWORD *)(v25 + 72);
          v30 = *v29;
          if ( !v25 )
            break;
          if ( v30.VInt )
            goto LABEL_37;
        }
        if ( v30.VInt )
        {
LABEL_37:
          Scaleform::GFx::AS3::Value::Value(&v37, Prototype);
          Scaleform::GFx::AS3::Value::Assign(
            (Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v34.VInt),
            v31);
          Scaleform::GFx::AS3::Value::~Value(&v37);
          goto LABEL_39;
        }
        Null = Scaleform::GFx::AS3::Value::GetNull();
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v34.VInt),
          Null);
LABEL_39:
        v33 = (Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v35);
        v37.Flags = 3;
        v37.Bonus.pWeakProxy = 0;
        v37.value.VS._1 = v30;
        Scaleform::GFx::AS3::Value::Assign(v33, &v37);
        Scaleform::GFx::AS3::Value::~Value(&v37);
        v20 = ++this->OpStack.pCurrent;
        v37.Flags = 1;
        v37.Bonus.pWeakProxy = 0;
        v37.value.VS._1.VBool = v30.VInt != 0;
        if ( !v20 )
          goto LABEL_43;
        v20->Bonus.pWeakProxy = 0;
      }
      v20->value.VNumber = v37.value.VNumber;
      goto LABEL_42;
    }
    obj = v5->value.VS._1.VObj;
    ((void (__thiscall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value::V1U *, unsigned int))obj->GetNextDynPropIndex)(
      obj,
      &object_reg,
      index_reg.Index);
    v14 = obj;
    pObject = (int)obj->pTraits.pObject;
    if ( pObject )
    {
      while ( !object_reg.VInt )
      {
        if ( !*(_DWORD *)(pObject + 68) )
          (*(void (__thiscall **)(int))(*(_DWORD *)pObject + 44))(pObject);
        v14 = Scaleform::GFx::AS3::Class::GetPrototype(*(Scaleform::GFx::AS3::Class **)(pObject + 68), pObject);
        object_reg = *(Scaleform::GFx::AS3::Value::V1U *)((int (__thiscall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, _DWORD))v14->GetNextDynPropIndex)(
                                                           v14,
                                                           &v37,
                                                           0);
        pObject = *(_DWORD *)(pObject + 72);
        if ( !pObject )
          goto LABEL_17;
      }
    }
    else
    {
LABEL_17:
      if ( !object_reg.VInt )
      {
        v17 = Scaleform::GFx::AS3::Value::GetNull();
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v34.VInt),
          v17);
        goto LABEL_21;
      }
    }
    if ( v14 != obj )
    {
      Scaleform::GFx::AS3::Value::Value(&v37, v14);
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v34.VInt), v16);
      Scaleform::GFx::AS3::Value::~Value(&v37);
    }
LABEL_21:
    v37.value.VS._1 = object_reg;
    v18 = (Scaleform::GFx::AS3::Value *)((char *)this->RegisterFile.pRF + v35);
    v37.Flags = 3;
    v37.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::Assign(v18, &v37);
    Scaleform::GFx::AS3::Value::~Value(&v37);
    v37.Flags = 1;
    v19 = object_reg.VInt != 0;
    v20 = ++this->OpStack.pCurrent;
    v37.Bonus.pWeakProxy = 0;
    v37.value.VS._1.VBool = v19;
    if ( v20 )
    {
      v21 = v37.value.VNumber;
      v20->Bonus.pWeakProxy = 0;
      v20->value.VNumber = v21;
LABEL_42:
      v20->Flags = 1;
      goto LABEL_43;
    }
    goto LABEL_43;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v37, eInvalidHasNextError, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v6,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v37.Bonus.pWeakProxy;
  --v37.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
}
