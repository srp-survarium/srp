void __thiscall Scaleform::GFx::AS3::StackReader::CheckObject(
        Scaleform::GFx::AS3::StackReader *this,
        const Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  bool v4; // al
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  v2 = v->Flags & 0x1F;
  if ( !v2 || v2 - 12 <= 3 && !v->value.VS._1.VInt )
  {
    VMRef = this->VMRef;
    v4 = v2 - 12 <= 3 && v->value.VS._1.VInt == 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, (Scaleform::GFx::AS3::VM::ErrorID)(!v4 + 1009), VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      VMRef,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
