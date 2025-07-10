Scaleform::GFx::AS3::Instances::fl::Namespace *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::FindNamespaceByURI(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        const Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *result; // eax

  pObject = this->TargetObject.pObject;
  if ( !pObject )
    return 0;
  while ( !Scaleform::GFx::AS3::IsXMLObject(pObject) )
  {
    if ( Scaleform::GFx::AS3::IsXMLListObject(pObject) )
    {
      result = (Scaleform::GFx::AS3::Instances::fl::Namespace *)pObject[1].pNext;
      if ( result && result->Uri.pNode == uri->pNode )
        return result;
      pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)pObject[1].__vftable;
    }
    if ( !pObject )
      return 0;
  }
  return (Scaleform::GFx::AS3::Instances::fl::Namespace *)((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::Object *, const Scaleform::GFx::ASString *, _DWORD))pObject->__vftable[2].GetNextPropertyName)(
                                                            pObject,
                                                            uri,
                                                            0);
}
