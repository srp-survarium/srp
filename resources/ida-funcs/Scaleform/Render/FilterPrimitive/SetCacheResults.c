void __thiscall Scaleform::Render::FilterPrimitive::SetCacheResults(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::FilterPrimitive::CacheState state,
        Scaleform::Render::RenderTarget **results,
        unsigned int count)
{
  Scaleform::Render::FilterPrimitive *v4; // edi
  unsigned int v5; // ebx
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // esi
  Scaleform::Render::RenderTarget *v7; // edi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  const Scaleform::Render::Matrix2x4<float> *v10; // eax
  Scaleform::Render::Matrix2x4<float> m; // [esp+10h] [ebp-20h] BYREF

  v4 = this;
  this->Caching = state;
  v5 = 0;
  CacheResults = this->CacheResults;
  do
  {
    if ( v5 < count && results )
    {
      v7 = results[v5];
      if ( v7 )
        v7->AddRef(v7);
      if ( CacheResults->pObject )
        CacheResults->pObject->Release(CacheResults->pObject);
      CacheResults->pObject = v7;
      v4 = this;
    }
    else
    {
      if ( CacheResults->pObject )
        CacheResults->pObject->Release(CacheResults->pObject);
      CacheResults->pObject = 0;
    }
    ++v5;
    ++CacheResults;
  }
  while ( v5 < 2 );
  if ( state == Cache_Mesh )
  {
    pHandle = v4->FilterArea.pHandle;
    if ( (pHandle->pHeader->Format & 2) != 0 )
    {
      pHeader = pHandle->pHeader;
      if ( (pHeader->Format & 2) != 0 )
        v10 = (const Scaleform::Render::Matrix2x4<float> *)(&pHeader[1].RefCount
                                                          + 4
                                                          * (unsigned __int8)byte_874211[5 * (pHeader->Format & 0xF)]);
      else
        v10 = &Scaleform::Render::Matrix2x4<float>::Identity;
      m.M[0][0] = 0.0;
      m.M[0][1] = 0.0;
      m.M[0][2] = 0.0;
      m.M[0][3] = 0.0;
      m.M[1][0] = 0.0;
      m.M[1][1] = 0.0;
      m.M[1][2] = 0.0;
      m.M[1][3] = 0.0;
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&v4->FilterArea, v10);
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&v4->FilterArea, &m, 1u);
    }
  }
}
