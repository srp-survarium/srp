void __thiscall Scaleform::GFx::AS3::Instances::CheckTypeTF::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-8h] BYREF

  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->DataTypeClass->pTraits.pObject;
  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(pObject, ClassTraits) )
  {
    Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(this, _this, result, argc, argv);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v9);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
