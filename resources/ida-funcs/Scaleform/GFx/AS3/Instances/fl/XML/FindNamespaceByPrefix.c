Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::XML::FindNamespaceByPrefix(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        const Scaleform::GFx::ASString *prefix,
        Scaleform::GFx::AS3::Instances::fl::XML *lp)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax

  pObject = this->Parent.pObject;
  if ( pObject != lp )
    return pObject->FindNamespaceByPrefix(pObject, prefix, lp);
  if ( !strcmp(prefix->pNode->pData, "xml") )
    return this->pTraits.pObject->pVM->XMLNamespace.pObject;
  return 0;
}
