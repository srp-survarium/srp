bool __thiscall Scaleform::GFx::AS3::Instances::fl_text::Font::CreateLibraryObject(
        Scaleform::GFx::AS3::Instances::fl_text::Font *this)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // esi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  bool v5; // bl
  void *v6; // esi
  Scaleform::GFx::AS3::MovieRoot *pMovieRoot; // edi
  Scaleform::GFx::LogState *v8; // esi
  const char *pData; // esi
  Scaleform::GFx::LogState *v10; // edi
  Scaleform::Render::Font *v11; // esi
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString className; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceBindData resBindData; // [esp+18h] [ebp-8h] BYREF

  if ( this->pFont.pObject )
    return 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
  if ( !ResourceMovieDef )
    return 0;
  pObject = this->pTraits.pObject;
  if ( (pObject->Flags & 0x10) == 0 )
    return 0;
  pObject->GetQualifiedName(pObject, &className, qnfWithDot);
  resBindData.pResource.pObject = 0;
  resBindData.pBinding = 0;
  Scaleform::String::String((Scaleform::String *)&result, (const __m128i *)className.pNode->pData);
  v5 = Scaleform::GFx::MovieImpl::FindExportedResource(
         pVM->pMovieRoot->pMovieImpl,
         ResourceMovieDef,
         &resBindData,
         (const Scaleform::String *)&result) == 0;
  v6 = (void *)((unsigned int)result.pObject & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)result.pObject & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( v5 )
  {
    pMovieRoot = pVM->pMovieRoot;
    v8 = Scaleform::GFx::StateBag::GetLogState(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
    if ( v8 )
    {
      pData = className.pNode->pData;
      v10 = Scaleform::GFx::StateBag::GetLogState(&pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v10->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Attaching a font with class '%s' failed",
        pData);
    }
LABEL_20:
    if ( resBindData.pResource.pObject )
      Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
    goto LABEL_22;
  }
  if ( resBindData.pResource.pObject )
  {
    if ( (resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject) & 0x200) != 0 )
    {
      v11 = (Scaleform::Render::Font *)resBindData.pResource.pObject[1].__vftable;
      if ( v11 )
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)resBindData.pResource.pObject[1].__vftable);
      v12 = (Scaleform::RefCountVImpl *)this->pFont.pObject;
      if ( v12 )
        Scaleform::RefCountImpl::Release(v12);
      this->pFont.pObject = v11;
    }
    goto LABEL_20;
  }
LABEL_22:
  pNode = className.pNode;
  --className.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 0;
}
