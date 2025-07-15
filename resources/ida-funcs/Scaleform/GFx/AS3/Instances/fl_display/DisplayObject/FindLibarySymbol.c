BOOL __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::FindLibarySymbol(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::CharacterCreateInfo *pccinfo,
        Scaleform::GFx::MovieDefImpl *pdefImpl)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edx
  Scaleform::GFx::MovieDefImpl *v4; // eax
  Scaleform::GFx::CharacterCreateInfo *v5; // ebp
  Scaleform::GFx::AS3::Traits *pObject; // edi
  char ExportedResource; // bl
  void *v8; // esi
  Scaleform::GFx::Resource *v9; // ecx
  __int16 v10; // ax
  Scaleform::GFx::ResourceBinding *pBinding; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString className; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::ASVM *asvm; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::ResourceBindData resBindData; // [esp+18h] [ebp-8h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  v4 = pdefImpl;
  v5 = pccinfo;
  pccinfo->pCharDef = 0;
  v5->pResource = 0;
  v5->pBindDefImpl = v4;
  pObject = this->pTraits.pObject;
  asvm = pVM;
  if ( pObject )
  {
    do
    {
      if ( (pObject->Flags & 0x10) == 0 )
        break;
      if ( v5->pCharDef )
        return 1;
      if ( v5->pResource )
        break;
      pObject->GetQualifiedName(pObject, &className, qnfWithDot);
      resBindData.pResource.pObject = 0;
      resBindData.pBinding = 0;
      Scaleform::String::String((Scaleform::String *)&pccinfo, (const __m128i *)className.pNode->pData);
      ExportedResource = Scaleform::GFx::MovieImpl::FindExportedResource(
                           asvm->pMovieRoot->pMovieImpl,
                           pdefImpl,
                           &resBindData,
                           (const Scaleform::String *)&pccinfo);
      v8 = (void *)((unsigned int)pccinfo & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pccinfo & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      v9 = resBindData.pResource.pObject;
      if ( ExportedResource )
      {
        v10 = resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject);
        v9 = resBindData.pResource.pObject;
        pBinding = resBindData.pBinding;
        if ( v10 < 0 )
          v5->pCharDef = (Scaleform::GFx::CharacterDef *)resBindData.pResource.pObject;
        else
          v5->pResource = resBindData.pResource.pObject;
        v5->pBindDefImpl = pBinding->pOwnerDefImpl;
      }
      else
      {
        pObject = pObject->pParent.pObject;
      }
      if ( v9 )
        Scaleform::GFx::Resource::Release(v9);
      pNode = className.pNode;
      --className.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    while ( pObject );
    if ( v5->pCharDef )
      return 1;
  }
  return v5->pResource != 0;
}
