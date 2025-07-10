void __thiscall Scaleform::Render::UserDataEffect::UserDataEffect(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        const Scaleform::Render::UserDataState *state,
        Scaleform::Render::CacheEffect *next)
{
  int v5; // eax
  Scaleform::Render::SortKeyInterface *v6; // ecx
  void *v7; // eax
  Scaleform::Render::SortKeyInterface *pImpl; // ecx
  void *Data; // eax
  int v10; // eax
  Scaleform::Render::SortKeyInterface *v11; // ecx
  void *v12; // eax
  Scaleform::Render::SortKeyInterface *v13; // ecx
  void *v14; // eax
  Scaleform::Render::SortKey v15; // [esp+Ch] [ebp-8h] BYREF

  this->pNext = next;
  this->Length = 0;
  this->__vftable = (Scaleform::Render::UserDataEffect_vtbl *)&Scaleform::Render::UserDataEffect::`vftable';
  Scaleform::Render::SortKey::SortKey(&v15, SortKey_UserDataStart, 0);
  this->StartEntry.pNextPattern = 0;
  this->StartEntry.pChain = 0;
  this->StartEntry.ChainHeight = 0;
  this->StartEntry.IndexHint = 0;
  v6 = *(Scaleform::Render::SortKeyInterface **)v5;
  this->StartEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v5;
  v7 = *(void **)(v5 + 4);
  this->StartEntry.Key.Data = v7;
  v6->AddRef(v6, v7);
  pImpl = v15.pImpl;
  Data = v15.Data;
  this->StartEntry.pBundle.pObject = 0;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  pImpl->Release(pImpl, Data);
  Scaleform::Render::SortKey::SortKey(&v15, SortKey_UserDataEnd, 0);
  this->EndEntry.pNextPattern = 0;
  this->EndEntry.pChain = 0;
  this->EndEntry.ChainHeight = 0;
  this->EndEntry.IndexHint = 0;
  v11 = *(Scaleform::Render::SortKeyInterface **)v10;
  this->EndEntry.Key.pImpl = *(Scaleform::Render::SortKeyInterface **)v10;
  v12 = *(void **)(v10 + 4);
  this->EndEntry.Key.Data = v12;
  v11->AddRef(v11, v12);
  v13 = v15.pImpl;
  v14 = v15.Data;
  this->EndEntry.pBundle.pObject = 0;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  v13->Release(v13, v14);
  Scaleform::Render::UserDataEffect::rebuildBundles(this, state);
}
