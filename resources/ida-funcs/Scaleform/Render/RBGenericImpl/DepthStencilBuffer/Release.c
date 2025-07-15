void __thiscall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::Release(
        Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this)
{
  bool v1; // zf
  bool v2; // sf
  bool v3; // of
  Scaleform::Render::RBGenericImpl::CacheData *v4; // eax
  Scaleform::Render::RenderBufferManager *pManager; // ecx
  int v6; // edx
  int p_RefCount; // ecx

  if ( --this->RefCount <= 0 )
  {
    v3 = __OFSUB__(this->ListType, 2);
    v1 = this->ListType == RBCL_ThisFrame;
    v2 = this->ListType - 2 < 0;
    v4 = &this->Scaleform::Render::RBGenericImpl::CacheData;
    pManager = this->pManager;
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$33C6E2185EE5619ED4522D9BD84BBA53::pPrev = v4->pPrev;
    v6 = !(v2 ^ v3 | v1) + 5;
    p_RefCount = (int)&pManager[v6 + 4].RefCount;
    v4->ListType = v6;
    v4->pNext = *(Scaleform::Render::RBGenericImpl::CacheData **)(p_RefCount + 4);
    v4->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)p_RefCount;
    **(_DWORD **)(p_RefCount + 4) = v4;
    *(_DWORD *)(p_RefCount + 4) = v4;
  }
}
