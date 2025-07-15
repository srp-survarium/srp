Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByURI(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        const Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax

  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return pObject->FindNamespaceByURI(pObject, uri, lp);
  if ( !strcmp(uri->pNode->pData, Scaleform::GFx::AS3::NS_XML) )
    return this->pTraits.pObject->pVM->XMLNamespace.pObject;
  return 0;
}
