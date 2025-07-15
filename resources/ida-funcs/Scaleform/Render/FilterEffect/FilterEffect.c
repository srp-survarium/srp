void __thiscall Scaleform::Render::FilterEffect::FilterEffect(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        const Scaleform::Render::FilterState *state,
        Scaleform::Render::CacheEffect *next)
{
  int v6; // eax
  Scaleform::Render::SortKeyInterface *v7; // edx
  void *v8; // eax
  Scaleform::Render::SortKeyInterface *pImpl; // ecx
  void *Data; // eax
  int v11; // eax
  Scaleform::Render::SortKeyInterface *v12; // ecx
  void *v13; // eax
  Scaleform::Render::SortKeyInterface *v14; // ecx
  void *v15; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::SortKey v17; // [esp+18h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> ma; // [esp+20h] [ebp-20h] BYREF

  this->pNext = next;
  this->Length = 0;
  this->__vftable = (Scaleform::Render::FilterEffect_vtbl *)&Scaleform::Render::FilterEffect::`vftable';
  this->Contributing = 1;
  Scaleform::Render::SortKey::SortKey(&v17, SortKey_FilterStart, (Scaleform::Render::FilterSet *)state->pData);
  this->StartEntry.pNextPattern = 0;
  this->StartEntry.pChain = 0;
  this->StartEntry.ChainHeight = 0;
  this->StartEntry.IndexHint = 0;
  v7 = *(Scaleform::Render::SortKeyInterface **)v6;
  this->StartEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v6;
  v8 = *(void **)(v6 + 4);
  this->StartEntry.Key.Data = v8;
  v7->AddRef(v7, v8);
  pImpl = v17.pImpl;
  Data = v17.Data;
  this->StartEntry.pBundle.pObject = 0;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  pImpl->Release(pImpl, Data);
  Scaleform::Render::SortKey::SortKey(&v17, SortKey_FilterEnd, 0);
  this->EndEntry.pNextPattern = 0;
  this->EndEntry.pChain = 0;
  this->EndEntry.ChainHeight = 0;
  this->EndEntry.IndexHint = 0;
  v12 = *(Scaleform::Render::SortKeyInterface **)v11;
  this->EndEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v11;
  v13 = *(void **)(v11 + 4);
  this->EndEntry.Key.Data = v13;
  v12->AddRef(v12, v13);
  v14 = v17.pImpl;
  v15 = v17.Data;
  this->EndEntry.pBundle.pObject = 0;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  v14->Release(v14, v15);
  pHandle = m->pHandle;
  this->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)m->pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  ma.M[0][0] = 0.0;
  ma.M[0][1] = 0.0;
  ma.M[0][2] = 0.0;
  ma.M[0][3] = 0.0;
  ma.M[1][0] = 0.0;
  ma.M[1][1] = 0.0;
  ma.M[1][2] = 0.0;
  ma.M[1][3] = 0.0;
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&this->BoundsMatrix, &ma, 1u);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(
    &this->BoundsMatrix,
    (const __m128i *)&m->pHandle->pHeader[1].RefCount
  + (unsigned __int8)byte_874214[5 * (m->pHandle->pHeader->Format & 0xF)],
    0x20u);
}
