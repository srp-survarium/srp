char __thiscall Scaleform::Render::FilterEffect::Update(
        Scaleform::Render::FilterEffect *this,
        const Scaleform::Render::State *stateArg)
{
  Scaleform::Render::BundleEntry *p_StartEntry; // edi
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // ebp
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::Render::Bundle *v7; // eax
  Scaleform::Render::Bundle *v8; // ebp
  Scaleform::Render::Bundle *v9; // ecx
  Scaleform::Render::SortKeyInterface **v10; // eax
  Scaleform::Render::SortKeyInterface **v11; // edi
  void *Data; // eax
  Scaleform::Render::SortKeyInterface **v13; // eax
  Scaleform::Render::SortKeyInterface **v14; // edi
  void *v15; // eax
  Scaleform::Render::SortKey v17; // [esp+14h] [ebp-8h] BYREF

  p_StartEntry = &this->StartEntry;
  if ( this->StartEntry.pBundle.pObject )
  {
    pObject = this->StartEntry.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v5 = this->StartEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v5, &this->StartEntry);
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  v6 = p_StartEntry->pBundle.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  p_StartEntry->pBundle.pObject = 0;
  p_StartEntry->IndexHint = 0;
  if ( this->EndEntry.pBundle.pObject )
  {
    v7 = this->EndEntry.pBundle.pObject;
    if ( v7 )
      ++v7->RefCount;
    v8 = this->EndEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v8, &this->EndEntry);
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
  }
  v9 = this->EndEntry.pBundle.pObject;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  this->EndEntry.pBundle.pObject = 0;
  this->EndEntry.IndexHint = 0;
  Scaleform::Render::SortKey::SortKey(&v17, SortKey_FilterStart, (Scaleform::Render::FilterSet *)stateArg->pData);
  v11 = v10;
  (*v10)->AddRef(*v10, v10[1]);
  this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = *v11;
  Data = v17.Data;
  this->StartEntry.Key.Data = v11[1];
  v17.pImpl->Release(v17.pImpl, Data);
  Scaleform::Render::SortKey::SortKey(&v17, SortKey_FilterEnd, 0);
  v14 = v13;
  (*v13)->AddRef(*v13, v13[1]);
  this->EndEntry.Key.pImpl->Release(this->EndEntry.Key.pImpl, this->EndEntry.Key.Data);
  this->EndEntry.Key.pImpl = *v14;
  v15 = v17.Data;
  this->EndEntry.Key.Data = v14[1];
  v17.pImpl->Release(v17.pImpl, v15);
  return 1;
}
