char __thiscall Scaleform::GFx::AS3::VM::GetClassUnsafe(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASStringNode *gname,
        Scaleform::GFx::ASStringNode *appDomain,
        Scaleform::GFx::AS3::Value *result)
{
  long double v5; // rax
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v10; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-8h] BYREF

  LODWORD(v5) = Scaleform::GFx::AS3::VM::GetClass(this, gname, appDomain);
  if ( LODWORD(v5) )
  {
    result->Flags = result->Flags & 0xFFFFFFE0 | 0xD;
    HIDWORD(v5) = v11.Message.pNode;
    result->value.VNumber = v5;
    *(_DWORD *)(LODWORD(v5) + 16) = (*(_DWORD *)(LODWORD(v5) + 16) + 1) & 0x8FBFFFFF;
    return 1;
  }
  else
  {
    if ( !this->HandleException )
    {
      if ( gname->pData )
        v7 = strlen(gname->pData);
      else
        v7 = 0;
      v10.Size = v7;
      v10.pStr = gname->pData;
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eUndefinedVarError, (Scaleform::String)this, v10);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v8,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v11.Message.pNode;
      --v11.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    return 0;
  }
}
