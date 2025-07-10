void __thiscall Scaleform::GFx::AS3::Classes::Function::Construct(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+0h] [ebp-8h] BYREF

  if ( argc )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eFunctionConstructorError, pVM);
    Scaleform::GFx::AS3::VM::ThrowEvalError(pVM, v6);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct(this, _this, 0, argv, extCall);
  }
}
