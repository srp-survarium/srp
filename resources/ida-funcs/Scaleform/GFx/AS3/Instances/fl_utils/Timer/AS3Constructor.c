void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v3; // edi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v7; // ebx
  Scaleform::StringDataPtr v8; // [esp-14h] [ebp-28h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+Ch] [ebp-8h] BYREF

  v3 = argc;
  if ( argc )
  {
    v7 = argv;
    Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->Delay);
    if ( v3 >= 2 )
      Scaleform::GFx::AS3::Value::Convert2Int32(v7 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &this->RepeatCount);
  }
  else
  {
    v8.pStr = "Timer::AS3Constructor";
    v8.Size = 21;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eWrongArgumentCountError, this->pTraits.pObject->pVM, v8, 1, 1, 0);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
