Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Object::SetProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // eax
  Scaleform::GFx::AS3::GASRefCountBase *Size; // ecx
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::VM *v12; // [esp-10h] [ebp-48h]
  Scaleform::GFx::AS3::Value scope; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+20h] [ebp-18h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  memset(&prop, 0, 16);
  v12 = pObject->pVM;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0;
  scope.value.VS._1.VInt = (int)this;
  Scaleform::GFx::AS3::FindObjProperty(&prop, v12, &scope, prop_name, FindSet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  if ( (prop.This.Flags & 0x1F) != 0
    && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
    && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
  {
    Scaleform::GFx::AS3::PropRef::SetSlotValue(&prop, result, pVM, value);
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    return result;
  }
  if ( (this->pTraits.pObject->Flags & 2) == 0 )
    goto LABEL_11;
  v8 = pVM->PublicNamespace.pObject;
  Size = (Scaleform::GFx::AS3::GASRefCountBase *)prop_name->Data.Size;
  if ( ((int)prop_name->Data.Data & 3) == 2 )
  {
    if ( !Scaleform::GFx::AS3::NamespaceSet::Contains(
            (Scaleform::GFx::AS3::NamespaceSet *)Size,
            pVM->PublicNamespace.pObject) )
      goto LABEL_11;
LABEL_15:
    this->AddDynamicSlotValuePair(this, (const Scaleform::GFx::AS3::Value *)&prop_name->Data.Policy, value, aNone);
    result->Result = 1;
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    return result;
  }
  if ( Size[1].pNext == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)v8->Uri.pNode
    && ((*((_BYTE *)v8 + 20) ^ LOBYTE(Size[1].__vftable)) & 0xF) == 0 )
  {
    goto LABEL_15;
  }
LABEL_11:
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&scope, eWriteSealedError, pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    pVM,
    v10,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)scope.Bonus.pWeakProxy;
  --scope.Bonus.pWeakProxy[1].pObject;
  if ( !pWeakProxy->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  result->Result = 0;
  Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  return result;
}
