char __thiscall Scaleform::GFx::AS3::NamespaceArray::Find(
        Scaleform::GFx::AS3::NamespaceArray *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  unsigned int Size; // ebp
  char result; // al
  int v5; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax

  Size = this->Namespaces.Data.Size;
  result = 0;
  v5 = 0;
  if ( Size )
  {
    while ( 1 )
    {
      pObject = this->Namespaces.Data.Data[v5].pObject;
      if ( pObject->Uri.pNode == ns->Uri.pNode && Scaleform::GFx::AS3::StrictEqual(&pObject->Prefix, &ns->Prefix) )
        break;
      if ( ++v5 >= Size )
        return 0;
    }
    return 1;
  }
  return result;
}
