Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByPrefix(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::ASString *prefix,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  unsigned int Size; // ecx
  int v5; // ebx
  int v6; // edi
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value *p_Prefix; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v13; // eax
  char v14; // [esp+13h] [ebp-5h]
  unsigned int nsize; // [esp+14h] [ebp-4h]

  Size = this->Namespaces.Data.Size;
  v5 = 0;
  v6 = 0;
  nsize = Size;
  if ( !Size )
    return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, prefix, lp);
  VStr = (Scaleform::GFx::ASStringNode *)prefix;
  while ( 1 )
  {
    pObject = this->Namespaces.Data.Data[v6].pObject;
    Flags = pObject->Prefix.Flags;
    p_Prefix = &pObject->Prefix;
    if ( (Flags & 0x1F) != 0xA
      || (VStr = p_Prefix->value.VS._1.VStr, ++VStr->RefCount, v5 |= 1u, v14 = 1, VStr != prefix->pNode) )
    {
      v14 = 0;
    }
    if ( (v5 & 1) != 0 )
    {
      v5 &= ~1u;
      if ( VStr->RefCount-- == 1 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
        Size = nsize;
      }
    }
    if ( v14 )
      break;
    if ( ++v6 >= Size )
      return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, prefix, lp);
  }
  v13 = &this->Namespaces.Data.Data[v6];
  if ( v13 )
    return v13->pObject;
  else
    return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, prefix, lp);
}
