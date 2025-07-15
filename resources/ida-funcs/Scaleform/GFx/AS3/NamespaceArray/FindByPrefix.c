bool __thiscall Scaleform::GFx::AS3::NamespaceArray::FindByPrefix(
        Scaleform::GFx::AS3::NamespaceArray *this,
        const Scaleform::GFx::ASString *pref)
{
  bool v3; // bl
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value *p_Prefix; // eax
  int v8; // ecx
  Scaleform::GFx::ASStringNode *VStr; // ecx
  unsigned int v10; // eax
  unsigned int size; // [esp+10h] [ebp-4h]

  v3 = 0;
  size = this->Namespaces.Data.Size;
  v4 = 0;
  do
  {
    if ( v4 >= size )
      break;
    pObject = this->Namespaces.Data.Data[v4].pObject;
    Flags = pObject->Prefix.Flags;
    p_Prefix = &pObject->Prefix;
    v8 = Flags & 0x1F;
    if ( v8 && ((unsigned int)(v8 - 12) > 3 || p_Prefix->value.VS._1.VInt) )
    {
      VStr = p_Prefix->value.VS._1.VStr;
      v10 = ++VStr->RefCount;
      v3 = VStr == pref->pNode;
      VStr->RefCount = v10 - 1;
      if ( v10 == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    }
    ++v4;
  }
  while ( !v3 );
  return v3;
}
