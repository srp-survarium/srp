void __thiscall Scaleform::GFx::AS3::Class::Call(
        Scaleform::GFx::AS3::Class *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::AS3::VM *v8; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-8h] BYREF

  if ( argc == 1 )
  {
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS3::Traits *, const Scaleform::GFx::AS3::Value *const, Scaleform::GFx::AS3::Value *))this->pTraits.pObject->Scaleform::GFx::AS3::Object::__vftable[1].ForEachChild_GC)(
           this->pTraits.pObject,
           argv,
           result) )
    {
      return;
    }
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      pVM,
      v7,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    v8 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eCoerceArgumentCountError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v8,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::RangeErrorTI);
  }
  pNode = v11.Message.pNode;
  --v11.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
