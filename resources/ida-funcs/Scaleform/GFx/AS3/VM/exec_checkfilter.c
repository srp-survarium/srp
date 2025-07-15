void __thiscall Scaleform::GFx::AS3::VM::exec_checkfilter(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  int v3; // ecx
  Scaleform::GFx::AS3::Value::V1U v4; // edx
  int v5; // edi
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  int v7; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::StringDataPtr v14; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v15; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v16; // [esp+Ch] [ebp-8h] BYREF

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
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, pCurrent);
      pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&v15)->pNode->pData;
      v14.pStr = pData;
      if ( pData )
        v10 = strlen(pData);
      else
        v10 = 0;
      v14.Size = v10;
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eFilterError, (Scaleform::String)this, v14);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v11,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v16.Message.pNode;
      --v16.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v13 = v15;
      --v15->RefCount;
      if ( !v13->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
}
