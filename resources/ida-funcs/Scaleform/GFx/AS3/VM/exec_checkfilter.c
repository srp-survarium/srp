void __thiscall Scaleform::GFx::AS3::VM::exec_checkfilter(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  int v3; // eax
  Scaleform::GFx::AS3::Value::V1U v4; // edx
  int v5; // edi
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  int v7; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3 = pCurrent->Flags & 0x1F;
  if ( (unsigned int)(v3 - 12) > 3
    || (v4 = pCurrent->value.VS._1, !v4.VInt)
    || (v5 = *(_DWORD *)(v4.VInt + 20), *(_DWORD *)(v5 + 60) != 13)
    || (*(_DWORD *)(v5 + 56) & 0x20) != 0 )
  {
    if ( (unsigned int)(v3 - 12) > 3
      || (v6 = pCurrent->value.VS._1, !v6.VInt)
      || (v7 = *(_DWORD *)(v6.VInt + 20), *(_DWORD *)(v7 + 60) != 14)
      || (*(_DWORD *)(v7 + 56) & 0x20) != 0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v10, eFilterError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v8,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v10.Message.pNode;
      --v10.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}
