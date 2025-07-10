void __thiscall Scaleform::Render::MaskEffect::MaskEffect(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::MaskEffectState mes,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *areaMatrix,
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
  int v16; // eax
  Scaleform::Render::SortKeyInterface *v17; // ecx
  void *v18; // eax
  Scaleform::Render::SortKeyInterface *v19; // ecx
  void *v20; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::SortKey v22; // [esp+14h] [ebp-8h] BYREF

  this->pNext = next;
  this->Length = 0;
  this->__vftable = (Scaleform::Render::MaskEffect_vtbl *)&Scaleform::Render::MaskEffect::`vftable';
  Scaleform::Render::SortKey::SortKey(&v22, (Scaleform::Render::SortKeyMaskType)(mes == MES_Clipped));
  this->StartEntry.pNextPattern = 0;
  this->StartEntry.pChain = 0;
  this->StartEntry.ChainHeight = 0;
  this->StartEntry.IndexHint = 0;
  v7 = *(Scaleform::Render::SortKeyInterface **)v6;
  this->StartEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v6;
  v8 = *(void **)(v6 + 4);
  this->StartEntry.Key.Data = v8;
  v7->AddRef(v7, v8);
  pImpl = v22.pImpl;
  Data = v22.Data;
  this->StartEntry.pBundle.pObject = 0;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  pImpl->Release(pImpl, Data);
  Scaleform::Render::SortKey::SortKey(&v22, SortKeyMask_End);
  this->EndEntry.pNextPattern = 0;
  this->EndEntry.pChain = 0;
  this->EndEntry.ChainHeight = 0;
  this->EndEntry.IndexHint = 0;
  v12 = *(Scaleform::Render::SortKeyInterface **)v11;
  this->EndEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v11;
  v13 = *(void **)(v11 + 4);
  this->EndEntry.Key.Data = v13;
  v12->AddRef(v12, v13);
  v14 = v22.pImpl;
  v15 = v22.Data;
  this->EndEntry.pBundle.pObject = 0;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  v14->Release(v14, v15);
  Scaleform::Render::SortKey::SortKey(&v22, SortKeyMask_Pop);
  this->PopEntry.pNextPattern = 0;
  this->PopEntry.pChain = 0;
  this->PopEntry.ChainHeight = 0;
  this->PopEntry.IndexHint = 0;
  v17 = *(Scaleform::Render::SortKeyInterface **)v16;
  this->PopEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v16;
  v18 = *(void **)(v16 + 4);
  this->PopEntry.Key.Data = v18;
  v17->AddRef(v17, v18);
  v19 = v22.pImpl;
  v20 = v22.Data;
  this->PopEntry.pBundle.pObject = 0;
  this->PopEntry.pSourceNode = node;
  this->PopEntry.Removed = 0;
  v19->Release(v19, v20);
  this->MES = mes;
  pHandle = areaMatrix->pHandle;
  this->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)areaMatrix->pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
}
