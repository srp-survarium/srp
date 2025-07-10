char __thiscall Scaleform::GFx::AS3::VM::GetClassUnsafe(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *gname,
        Scaleform::GFx::ASStringNode *appDomain,
        Scaleform::GFx::AS3::Value *result)
{
  long double v5; // rax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+4h] [ebp-8h] BYREF

  LODWORD(v5) = Scaleform::GFx::AS3::VM::GetClass(this, gname, appDomain);
  if ( LODWORD(v5) )
  {
    result->Flags = result->Flags & 0xFFFFFFE0 | 0xD;
    HIDWORD(v5) = v9.Message.pNode;
    result->value.VNumber = v5;
    *(_DWORD *)(LODWORD(v5) + 16) = (*(_DWORD *)(LODWORD(v5) + 16) + 1) & 0x8FBFFFFF;
    return 1;
  }
  else
  {
    if ( !this->HandleException )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v9, eUndefinedVarError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v7,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v9.Message.pNode;
      --v9.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    return 0;
  }
}
