char __thiscall Scaleform::GFx::AS3::NamespaceSet::Contains(
        Scaleform::GFx::AS3::NamespaceSet *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  unsigned int Size; // esi
  int v3; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *i; // ecx

  Size = this->Namespaces.Data.Size;
  v3 = 0;
  if ( !Size )
    return 0;
  for ( i = this->Namespaces.Data.Data;
        i->pObject->Uri.pNode != ns->Uri.pNode || ((*((_BYTE *)ns + 20) ^ *((_BYTE *)i->pObject + 20)) & 0xF) != 0;
        ++i )
  {
    if ( ++v3 >= Size )
      return 0;
  }
  return 1;
}
