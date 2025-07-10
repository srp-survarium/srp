Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::GetProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v5; // eax
  __int16 Flags; // ax
  Scaleform::GFx::AS3::Value *v7; // eax
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::Value::Extra v9; // edx
  Scaleform::GFx::AS3::Value::V1U v10; // esi
  Scaleform::GFx::AS3::Value::V2U v11; // edi
  Scaleform::GFx::AS3::Value::V2U v12; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value v; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+18h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v5 = prop_name;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v.value.VS._1.VInt = (int)this;
  memset(&prop, 0, 16);
  v.Flags = 12;
  v.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::FindObjProperty(&prop, pVM, &v, v5, FindGet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  Flags = prop.This.Flags;
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
  {
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
           &prop,
           (Scaleform::GFx::AS3::CheckResult *)&prop_name,
           pVM,
           &v,
           valGet)->Result )
    {
      v7 = value;
      v8 = v.Flags;
      v9.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v.Bonus;
      v10 = v.value.VS._1;
      v.Flags = value->Flags;
      v.Bonus.pWeakProxy = value->Bonus.pWeakProxy;
      v11.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      v.value.VS._1.VInt = value->value.VS._1.VInt;
      v12.VObj = (Scaleform::GFx::AS3::Object *)value->value.VS._2;
      value->value.VS._1 = v10;
      v7->Flags = v8;
      v.value.VS._2 = v12;
      v7->Bonus = v9;
      v7->value.VS._2 = v11;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&v);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    Scaleform::GFx::AS3::Value::~Value(&v);
    Flags = prop.This.Flags;
  }
  result->Result = 0;
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = prop.This.Bonus.pWeakProxy;
      --prop.This.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        return result;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
    }
  }
  return result;
}
