Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *VectorInd; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int ind; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  VectorInd = Scaleform::GFx::AS3::GetVectorInd(
                (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                prop_name,
                (Scaleform::GFx::AS3::Value::V1U *)&ind);
  pObject = this->pTraits.pObject;
  if ( VectorInd->Result )
  {
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Set(
      &this->V,
      result,
      ind,
      value,
      (const Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject[1]._pRCC);
    return result;
  }
  else
  {
    pVM = pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eWriteSealedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowReferenceError(pVM, v10);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v8 = result;
    result->Result = 0;
  }
  return v8;
}
