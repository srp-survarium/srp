void __thiscall Scaleform::GFx::AS3::Classes::fl::Error::throwError(
        Scaleform::GFx::AS3::Classes::fl::Error *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  v7.pStr = "class_::Error::throwError()";
  v7.Size = 27;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, this->pTraits.pObject->pVM, v7);
  Scaleform::GFx::AS3::VM::ThrowError(this->pTraits.pObject->pVM, v5);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
