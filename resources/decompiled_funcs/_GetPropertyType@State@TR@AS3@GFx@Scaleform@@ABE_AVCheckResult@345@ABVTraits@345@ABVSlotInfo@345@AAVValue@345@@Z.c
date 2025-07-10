Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::TR::State::GetPropertyType(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Traits *obj_traits,
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
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // ebp
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult *v20; // eax
  const Scaleform::GFx::AS3::Abc::TraitInfo *TI; // eax
  Scaleform::GFx::AS3::Tracer *v22; // ecx
  int v23; // [esp-4h] [ebp-24h]
  const Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // [esp-4h] [ebp-24h]
  Scaleform::GFx::AS3::Value other; // [esp+10h] [ebp-10h] BYREF

  v5 = (int)(*(_DWORD *)si << 22) >> 27;
  if ( v5 > 10 )
  {
    v7 = (32 * *(_DWORD *)si) >> 15;
    if ( v7 >= 0 )
    {
      if ( v5 == 11 )
      {
        v23 = (32 * *(_DWORD *)si) >> 15;
        VT = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &other, (Scaleform::GFx::AS3::AbsoluteIndex)v23);
        FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(this, Value);
        Scaleform::GFx::AS3::Value::~Value(&other);
        pTracer = this->pTracer;
        other.Bonus.pWeakProxy = 0;
        other.value.VS._1.VInt = (int)FunctType;
        other.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(pTracer, FunctType) & 0xFFFFFFF7)) | 8;
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
        other.Bonus.pWeakProxy = 0;
        other.value.VS._1.VInt = (int)FunctReturnType;
        other.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v15, FunctReturnType) & 0xFFFFFFF7)) | 8;
      }
      Scaleform::GFx::AS3::Value::Assign(type, &other);
LABEL_17:
      Scaleform::GFx::AS3::Value::~Value(&other);
      v20 = result;
      result->Result = 1;
      return v20;
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
      other.Bonus.pWeakProxy = 0;
      other.value.VS._1.VInt = (int)DataType;
      other.Flags = 9;
      Scaleform::GFx::AS3::Value::Assign(type, &other);
    }
    else
    {
      v22 = this->pTracer;
      pObject = DataType->ITraits.pObject;
      other.Bonus.pWeakProxy = 0;
      other.value.VS._1.VInt = (int)pObject;
      other.Flags = (32 * (Scaleform::GFx::AS3::Tracer::CanBeNull(v22, pObject) & 0xFFFFFFF7)) | 8;
      Scaleform::GFx::AS3::Value::Assign(type, &other);
    }
    goto LABEL_17;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&other, eClassNotFoundError, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    VMRef,
    v18,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)other.Bonus.pWeakProxy;
  --other.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  v20 = result;
  result->Result = 0;
  return v20;
}
