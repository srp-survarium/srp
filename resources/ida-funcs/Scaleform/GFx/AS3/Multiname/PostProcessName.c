void __thiscall Scaleform::GFx::AS3::Multiname::PostProcessName(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::ASString fromQName)
{
  Scaleform::GFx::AS3::Value *p_Name; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  char v4; // dl
  Scaleform::GFx::ASStringManager *pManager; // esi
  char *Size; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-4h] BYREF

  p_Name = &this->Name;
  if ( (this->Name.Flags & 0x1F) == 0xA )
  {
    name.pNode = this->Name.value.VS._1.VStr;
    ++name.pNode->RefCount;
    pNode = name.pNode;
    if ( name.pNode->Size )
    {
      v4 = *name.pNode->pData;
      pManager = name.pNode->pManager;
      if ( v4 == 42 )
        goto LABEL_9;
      if ( v4 == 64 && !LOBYTE(fromQName.pNode) )
      {
        this->Kind |= 8u;
        Size = (char *)pNode->Size;
        if ( Size != (char *)2 || *((_BYTE *)pNode->pData + 1) != 42 )
        {
          p_EmptyStringNode = Scaleform::GFx::ASConstString::SubstringNode(&name, (char *)1, Size);
LABEL_10:
          ++p_EmptyStringNode->RefCount;
          fromQName.pNode = p_EmptyStringNode;
          Scaleform::GFx::AS3::Value::Assign(p_Name, &fromQName);
          if ( p_EmptyStringNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
          pNode = name.pNode;
          goto LABEL_13;
        }
LABEL_9:
        p_EmptyStringNode = &pManager->EmptyStringNode;
        goto LABEL_10;
      }
    }
LABEL_13:
    if ( !--pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
