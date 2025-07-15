char __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::CreateLibraryObject(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::MovieDefImpl *ResourceMovieDef; // eax
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  bool v5; // bl
  void *v6; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  __int16 v9; // ax
  Scaleform::GFx::Resource *v10; // ecx
  Scaleform::GFx::SoundResource *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASString className; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::String v14; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceBindData resBindData; // [esp+14h] [ebp-8h] BYREF

  if ( this->pSoundResource.pObject )
    return 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  ResourceMovieDef = Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(pVM, this);
  this->pMovieDef = ResourceMovieDef;
  if ( !ResourceMovieDef )
    return 0;
  pObject = this->pTraits.pObject;
  if ( (pObject->Flags & 0x10) == 0 )
    return 0;
  pObject->GetQualifiedName(pObject, &className, qnfWithDot);
  resBindData.pResource.pObject = 0;
  resBindData.pBinding = 0;
  Scaleform::String::String(&v14, (const __m128i *)className.pNode->pData);
  v5 = Scaleform::GFx::MovieImpl::FindExportedResource(pVM->pMovieRoot->pMovieImpl, this->pMovieDef, &resBindData, &v14) == 0;
  v6 = (void *)(v14.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v14.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
  if ( v5 )
  {
    if ( resBindData.pResource.pObject )
      Scaleform::GFx::Resource::Release(resBindData.pResource.pObject);
    pNode = className.pNode;
    --className.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 0;
  }
  if ( resBindData.pResource.pObject )
  {
    v9 = resBindData.pResource.pObject->GetResourceTypeCode(resBindData.pResource.pObject);
    v10 = resBindData.pResource.pObject;
    if ( (v9 & 0x400) != 0 )
    {
      v11 = (Scaleform::GFx::SoundResource *)resBindData.pResource.pObject;
      if ( resBindData.pResource.pObject )
      {
        Scaleform::RefCountImpl::AddRef(resBindData.pResource.pObject);
        v10 = resBindData.pResource.pObject;
      }
      if ( this->pSoundResource.pObject )
      {
        Scaleform::GFx::Resource::Release(this->pSoundResource.pObject);
        v10 = resBindData.pResource.pObject;
      }
      this->pSoundResource.pObject = v11;
    }
    if ( v10 )
      Scaleform::GFx::Resource::Release(v10);
  }
  v12 = className.pNode;
  --className.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return 1;
}
