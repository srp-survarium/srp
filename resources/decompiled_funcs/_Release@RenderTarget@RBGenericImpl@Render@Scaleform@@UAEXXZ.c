void __thiscall Scaleform::Render::RBGenericImpl::RenderTarget::Release(
        Scaleform::Render::RBGenericImpl::RenderTarget *this)
{
  bool v1; // zf
  bool v2; // sf
  bool v3; // of
  Scaleform::Render::RenderBufferManager *pManager; // esi
  Scaleform::Render::RBGenericImpl::RBCacheListType v5; // edx
  Scaleform::Render::RBGenericImpl::CacheData *p_RefCount; // edx

  if ( --this->RefCount <= 0 )
  {
    if ( this->pBuffer->Scaleform::Render::RBGenericImpl::CacheData::Type != RBuffer_Temporary
      || this->RTStatus == RTS_Lost )
    {
      ((void (__thiscall *)(Scaleform::Render::RBGenericImpl::RenderTarget *, int))this->~Scaleform::Render::RBGenericImpl::RenderTarget)(
        this,
        1);
    }
    else
    {
      v3 = __OFSUB__(this->ListType, 2);
      v1 = this->ListType == RBCL_ThisFrame;
      v2 = this->ListType - 2 < 0;
      pManager = this->pManager;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$EA02E2A925554C6B16FA29F8B6C1D51A::pPrev = this->pPrev;
      v5 = !(v2 ^ v3 | v1) + 5;
      this->ListType = v5;
      p_RefCount = (Scaleform::Render::RBGenericImpl::CacheData *)&pManager[v5 + 4].RefCount;
      this->pNext = p_RefCount->pNext;
      this->pPrev = p_RefCount;
      p_RefCount->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$EA02E2A925554C6B16FA29F8B6C1D51A::pPrev = &this->Scaleform::Render::RBGenericImpl::CacheData;
      p_RefCount->pNext = &this->Scaleform::Render::RBGenericImpl::CacheData;
      this->RTStatus = RTS_Available;
    }
  }
}
