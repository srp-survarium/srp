Scaleform::Render::RBGenericImpl::CacheData *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType bufferType,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // ebp
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // esi
  bool v7; // dl
  _DWORD *v8; // ecx
  unsigned int v10; // edi
  unsigned int Height; // edx
  unsigned int v12; // ecx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v13; // [esp+10h] [ebp-4h]
  bool RequireExactDepthStencil; // [esp+18h] [ebp+4h]

  pPrev = this->BufferCache[ltype].Root.pPrev;
  v6 = &this->BufferCache[ltype];
  v13 = v6;
  if ( pPrev != (Scaleform::Render::RBGenericImpl::CacheData *)v6 )
  {
    RequireExactDepthStencil = this->RequireExactDepthStencil;
    do
    {
      v7 = RequireExactDepthStencil && bufferType == RBuffer_DepthStencil;
      v8 = &pPrev->pBuffer->__vftable;
      if ( v8[2] == bufferType && pPrev->Format == format )
      {
        if ( v7 )
        {
          if ( size->Width == v8[5] && size->Height == v8[6] )
            return pPrev;
        }
        else
        {
          v10 = v8[5];
          if ( size->Width <= v10 )
          {
            Height = size->Height;
            v12 = v8[6];
            if ( Height <= v12 && (27 * v10 * v12) >> 5 <= size->Width * Height )
              return pPrev;
          }
          v6 = v13;
        }
      }
      pPrev = pPrev->pPrev;
    }
    while ( pPrev != (Scaleform::Render::RBGenericImpl::CacheData *)v6 );
  }
  return 0;
}
