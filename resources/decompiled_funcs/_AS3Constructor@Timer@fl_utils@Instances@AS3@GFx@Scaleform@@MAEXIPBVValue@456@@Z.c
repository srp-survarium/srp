void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
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
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Delay);
    if ( v3 >= 2 )
      Scaleform::GFx::AS3::Value::Convert2Int32(v8 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->RepeatCount);
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
