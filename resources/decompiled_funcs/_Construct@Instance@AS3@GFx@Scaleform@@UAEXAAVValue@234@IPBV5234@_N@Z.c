void __thiscall Scaleform::GFx::AS3::Instance::Construct(
        Scaleform::GFx::AS3::Instance *this,
        Scaleform::GFx::AS3::Value *__formal,
        unsigned int a3,
        const Scaleform::GFx::AS3::Value *a4,
        bool a5)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotConstructorError, pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    pVM,
    v6,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v8.Message.pNode;
  --v8.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
