char __thiscall Scaleform::Render::ViewMatrix3DEffect::Update(
        Scaleform::Render::ViewMatrix3DEffect *this,
        const Scaleform::Render::State *stateArg)
{
  Scaleform::Render::BundleEntry *p_StartEntry; // esi
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // ebx
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::Render::SortKeyInterface **v7; // eax
  Scaleform::Render::SortKeyInterface **v8; // esi
  Scaleform::Render::SortKeyInterface *pImpl; // ecx
  Scaleform::Render::SortKey v11; // [esp+8h] [ebp-8h] BYREF

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
  Scaleform::Render::SortKey::SortKey(
    &v11,
    SortKey_ViewMatrix3DStart,
    (Scaleform::Render::Matrix3x4Ref<float> *)stateArg->pData);
  v8 = v7;
  ((void (__stdcall *)(Scaleform::Render::SortKeyInterface *))(*v7)->AddRef)(v7[1]);
  this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = *v8;
  pImpl = v11.pImpl;
  this->StartEntry.Key.Data = v8[1];
  pImpl->Release(pImpl, v11.Data);
  return 1;
}
