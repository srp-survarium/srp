void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::GFx::AS3::VM::Error v9; // [esp+8h] [ebp-8h] BYREF

  v3 = argc;
  if ( argc )
  {
    v8 = argv;
    Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Type);
    if ( v3 >= 2 )
      *((_BYTE *)this + 48) ^= (Scaleform::GFx::AS3::Value::Convert2Boolean(v8 + 1) ^ *((_BYTE *)this + 48)) & 1;
    if ( v3 >= 3 )
      *((_BYTE *)this + 48) ^= (*((_BYTE *)this + 48) ^ (2 * Scaleform::GFx::AS3::Value::Convert2Boolean(v8 + 2))) & 2;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eWrongArgumentCountError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v6);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
