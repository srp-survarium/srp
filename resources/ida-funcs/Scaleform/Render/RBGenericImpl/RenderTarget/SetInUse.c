void __thiscall Scaleform::Render::RBGenericImpl::RenderTarget::SetInUse(
        Scaleform::Render::RBGenericImpl::RenderTarget *this,
        bool inUse)
{
  Scaleform::Render::RBGenericImpl::CacheData *pManager; // edx
  Scaleform::Render::RBGenericImpl::CacheData *v3; // edx

  if ( inUse )
  {
    if ( this->Type == RBuffer_Temporary )
    {
      pManager = (Scaleform::Render::RBGenericImpl::CacheData *)this->pManager;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = this->pPrev;
      pManager = (Scaleform::Render::RBGenericImpl::CacheData *)((char *)pManager + 44);
      this->ListType = RBCL_InUse;
      this->pNext = pManager->pNext;
      this->pPrev = pManager;
      pManager->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = &this->Scaleform::Render::RBGenericImpl::CacheData;
      pManager->pNext = &this->Scaleform::Render::RBGenericImpl::CacheData;
    }
    this->RTStatus = RTS_InUse;
  }
  else
  {
    if ( this->Type == RBuffer_Temporary && this->ListType < RBCL_ThisFrame )
    {
      v3 = (Scaleform::Render::RBGenericImpl::CacheData *)this->pManager;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = this->pPrev;
      v3 = (Scaleform::Render::RBGenericImpl::CacheData *)((char *)v3 + 52);
      this->ListType = RBCL_ThisFrame;
      this->pNext = v3->pNext;
      this->pPrev = v3;
      v3->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = &this->Scaleform::Render::RBGenericImpl::CacheData;
      v3->pNext = &this->Scaleform::Render::RBGenericImpl::CacheData;
    }
    this->RTStatus = RTS_Available;
  }
}
