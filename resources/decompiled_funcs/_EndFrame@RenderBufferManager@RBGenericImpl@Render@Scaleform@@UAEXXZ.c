void __thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::EndFrame(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::CacheData *pNext; // edx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // eax
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // edi
  Scaleform::Render::RBGenericImpl::CacheData *v5; // edx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // ecx
  Scaleform::Render::RBGenericImpl::CacheData *v7; // edi
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v8; // edx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v9; // eax
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v10; // ecx
  Scaleform::Render::RBGenericImpl::CacheData *v11; // esi

  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(this, RBCL_Reuse_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(this, RBCL_LRU);
  pNext = this->BufferCache[3].Root.pNext;
  v3 = &this->BufferCache[3];
  if ( pNext != (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3] )
  {
    pPrev = v3->Root.pPrev;
    v3->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v3;
    this->BufferCache[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3];
    pPrev->pNext = this->BufferCache[4].Root.pNext;
    pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[4];
    this->BufferCache[4].Root.pNext->pPrev = pPrev;
    this->BufferCache[4].Root.pNext = pNext;
  }
  v5 = this->BufferCache[2].Root.pNext;
  v6 = &this->BufferCache[2];
  if ( v5 != (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[2] )
  {
    v7 = v6->Root.pPrev;
    v6->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v6;
    this->BufferCache[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[2];
    v7->pNext = this->BufferCache[3].Root.pNext;
    v5->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v3;
    this->BufferCache[3].Root.pNext->pPrev = v7;
    this->BufferCache[3].Root.pNext = v5;
  }
  v8 = (Scaleform::Render::RBGenericImpl::RenderBufferManager *)this->BufferCache[5].Root.pNext;
  v9 = &this->BufferCache[5];
  v10 = &this->BufferCache[6];
  if ( v8 != (Scaleform::Render::RBGenericImpl::RenderBufferManager *)&this->BufferCache[5] )
  {
    v11 = v9->Root.pPrev;
    v9->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v9;
    v9->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v9;
    v11->pNext = v10->Root.pNext;
    v8->__vftable = (Scaleform::Render::RBGenericImpl::RenderBufferManager_vtbl *)v10;
    v10->Root.pNext->pPrev = v11;
    v10->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v8;
  }
}
