void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObject::Construct(
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eConstructOfNonFunctionError, pVM);
  Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
