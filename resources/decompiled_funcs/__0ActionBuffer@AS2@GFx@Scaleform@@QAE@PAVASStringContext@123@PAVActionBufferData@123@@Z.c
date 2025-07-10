void __thiscall Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::Resource *pbufferData)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *RefCount; // eax

  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::ActionBuffer_vtbl *)&Scaleform::GFx::AS2::ActionBuffer::`vftable';
  if ( pbufferData )
    Scaleform::RefCountImpl::AddRef(pbufferData);
  this->pBufferData.pObject = (Scaleform::GFx::AS2::ActionBufferData *)pbufferData;
  pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
  this->Dictionary.Data.Data = 0;
  this->Dictionary.Data.Size = 0;
  this->Dictionary.Data.Policy.Capacity = 0;
  RefCount = (Scaleform::GFx::ASStringNode *)pObject[8].RefCount;
  this->Dictionary.Data.DefaultValue.pNode = RefCount;
  ++RefCount->RefCount;
  this->DeclDictProcessedAt = -1;
}
