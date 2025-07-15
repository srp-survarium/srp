void __thiscall Scaleform::Render::FilterEffect::~FilterEffect(Scaleform::Render::FilterEffect *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v4; // edi
  Scaleform::Render::Bundle *v5; // ecx
  Scaleform::Render::Bundle *v6; // eax
  Scaleform::Render::Bundle *v7; // edi
  Scaleform::Render::Bundle *v8; // ecx

  pHandle = this->BoundsMatrix.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  if ( this->EndEntry.pBundle.pObject )
  {
    pObject = this->EndEntry.pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v4 = this->EndEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v4, &this->EndEntry);
    if ( v4 )
      Scaleform::RefCountNTSImpl::Release(v4);
  }
  v5 = this->EndEntry.pBundle.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  this->EndEntry.Key.pImpl->Release(this->EndEntry.Key.pImpl, this->EndEntry.Key.Data);
  if ( this->StartEntry.pBundle.pObject )
  {
    v6 = this->StartEntry.pBundle.pObject;
    if ( v6 )
      ++v6->RefCount;
    v7 = this->StartEntry.pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v7, &this->StartEntry);
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
  }
  v8 = this->StartEntry.pBundle.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->__vftable = (Scaleform::Render::FilterEffect_vtbl *)&Scaleform::Render::CacheEffect::`vftable';
}
