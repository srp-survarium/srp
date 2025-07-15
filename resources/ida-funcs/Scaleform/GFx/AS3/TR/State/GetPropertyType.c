Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::TR::State::GetPropertyType(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Traits *obj_traits,
        Scaleform::GFx::AS3::SlotInfo *si,
        Scaleform::GFx::AS3::Value *type)
{
  int v5; // eax
  int v7; // esi
  Scaleform::GFx::AS3::VTable *VT; // eax
  const Scaleform::GFx::AS3::Value *Value; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctType; // esi
  Scaleform::GFx::AS3::Tracer *pTracer; // ecx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // ebp
  Scaleform::GFx::AS3::VTable *v13; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // eax
  Scaleform::GFx::AS3::Tracer *v15; // ecx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // ebx
  const Scaleform::GFx::ASString *DataTypeName; // eax
  const Scaleform::GFx::AS3::VM::Error *v19; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS3::CheckResult *v22; // eax
  const Scaleform::GFx::AS3::Abc::TraitInfo *TI; // eax
  Scaleform::GFx::AS3::Tracer *v24; // ecx
  int v25; // [esp-4h] [ebp-34h]
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // [esp-4h] [ebp-34h]
  Scaleform::GFx::AS3::Value v27; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+20h] [ebp-10h] BYREF

  v5 = (int)(*(_DWORD *)si << 22) >> 27;
  if ( v5 > 10 )
  {
    v7 = (32 * *(_DWORD *)si) >> 15;
    if ( v7 >= 0 )
    {
      if ( v5 == 11 )
      {
        v25 = (32 * *(_DWORD *)si) >> 15;
        VT = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &arg1, (Scaleform::GFx::AS3::AbsoluteIndex)v25);
        FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(this, Value);
        Scaleform::GFx::AS3::Value::~Value(&arg1);
        pTracer = this->pTracer;
        v27.Bonus.pWeakProxy = 0;
        v27.value.VS._1.VInt = (int)FunctType;
        v27.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(pTracer, FunctType) & 0xFFFFFFF7)) | 8;
      }
      else
      {
        AppDomain = this->pTracer->CF->pFile->AppDomain;
        v13 = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                            this->pTracer->CF->pFile->VMRef,
                            &v13->VTMethods.Data.Data[v7],
                            AppDomain);
        v15 = this->pTracer;
        v27.Bonus.pWeakProxy = 0;
        v27.value.VS._1.VInt = (int)FunctReturnType;
        v27.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v15, FunctReturnType) & 0xFFFFFFF7)) | 8;
      }
      Scaleform::GFx::AS3::Value::Assign(type, &v27);
LABEL_19:
      Scaleform::GFx::AS3::Value::~Value(&v27);
      v22 = result;
      result->Result = 1;
      return v22;
    }
  }
  VMRef = this->pTracer->CF->pFile->VMRef;
  DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(si, VMRef);
  if ( DataType )
  {
    if ( (*(_DWORD *)si & 0x3E0) == 0x20
      || (TI = si->TI) != 0 && (TI->kind & 0xF) == 4
      || Scaleform::GFx::AS3::SlotInfo::IsClassType(si) )
    {
      v27.Bonus.pWeakProxy = 0;
      v27.value.VS._1.VInt = (int)DataType;
      v27.Flags = 9;
      Scaleform::GFx::AS3::Value::Assign(type, &v27);
    }
    else
    {
      v24 = this->pTracer;
      pObject = DataType->ITraits.pObject;
      v27.Bonus.pWeakProxy = 0;
      v27.value.VS._1.VInt = (int)pObject;
      v27.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v24, pObject) & 0xFFFFFFF7)) | 8;
      Scaleform::GFx::AS3::Value::Assign(type, &v27);
    }
    goto LABEL_19;
  }
  DataTypeName = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(si, (Scaleform::GFx::ASString *)&type, VMRef);
  Scaleform::GFx::AS3::Value::Value(&arg1, DataTypeName);
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&v27,
    (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
    (Scaleform::GFx::ASStringNode *)VMRef,
    &arg1);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    VMRef,
    v19,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v27.Bonus.pWeakProxy;
  --v27.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  Scaleform::GFx::AS3::Value::~Value(&arg1);
  v21 = (Scaleform::GFx::ASStringNode *)type;
  --type->value.VS._2.VObj;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  v22 = result;
  result->Result = 0;
  return v22;
}
