void __usercall Scaleform::Render::MaskEffect::~MaskEffect(Scaleform::Render::MaskEffect *this@<ecx>, int a2@<edi>)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // edi
  Scaleform::Render::Bundle *v6; // ecx
  Scaleform::Render::Bundle *v7; // eax
  Scaleform::Render::Bundle *v8; // edi
  Scaleform::Render::Bundle *v9; // ecx
  Scaleform::Render::Bundle *v10; // eax
  Scaleform::Render::Bundle *v11; // edi
  Scaleform::Render::Bundle *v12; // ecx

  pHandle = this->BoundsMatrix.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  if ( this->PopEntry.pBundle.pObject )
  {
    pObject = this->PopEntry.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v5 = this->PopEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v5, &this->PopEntry);
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  v6 = this->PopEntry.pBundle.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  ((void (__thiscall *)(Scaleform::Render::SortKeyInterface *, void *, int))this->PopEntry.Key.pImpl->Release)(
    this->PopEntry.Key.pImpl,
    this->PopEntry.Key.Data,
    a2);
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
  this->EndEntry.Key.pImpl->Release(this->EndEntry.Key.pImpl, this->EndEntry.Key.Data);
  if ( this->StartEntry.pBundle.pObject )
  {
    v10 = this->StartEntry.pBundle.pObject;
    if ( v10 )
      ++v10->RefCount;
    v11 = this->StartEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v11, &this->StartEntry);
    if ( v11 )
      Scaleform::RefCountNTSImpl::Release(v11);
  }
  v12 = this->StartEntry.pBundle.pObject;
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->__vftable = (Scaleform::Render::MaskEffect_vtbl *)&Scaleform::Render::CacheEffect::`vftable';
}
