Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::FindNamespaceByURI(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        const Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  unsigned int Size; // esi
  int v4; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *i; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // eax

  Size = this->Namespaces.Data.Size;
  v4 = 0;
  if ( !Size )
    return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, uri, lp);
  for ( i = this->Namespaces.Data.Data; i->pObject->Uri.pNode != uri->pNode; ++i )
  {
    if ( ++v4 >= Size )
      return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, uri, lp);
  }
  v7 = &this->Namespaces.Data.Data[v4];
  if ( v7 )
    return v7->pObject;
  else
    return Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(this, uri, lp);
}
