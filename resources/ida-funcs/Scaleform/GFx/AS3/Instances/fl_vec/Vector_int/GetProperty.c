Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::GetProperty(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v4; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int ind; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-8h] BYREF

  v4 = prop_name;
  if ( Scaleform::GFx::AS3::GetVectorInd(
         (Scaleform::GFx::AS3::CheckResult *)&prop_name,
         (const Scaleform::GFx::AS3::Multiname *)prop_name,
         (Scaleform::GFx::AS3::Value::V1U *)&ind)->Result )
  {
    if ( ind >= this->V.ValueA.Data.Size )
    {
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eOutOfRangeError, pVM);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v8);
      pNode = v11.Message.pNode;
      --v11.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v6 = result;
      result->Result = 0;
    }
    else
    {
      Scaleform::GFx::AS3::VectorBase<long>::Get(&this->V, ind, value);
      v6 = result;
      result->Result = 1;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(this, result, v4, value);
    return result;
  }
  return v6;
}
