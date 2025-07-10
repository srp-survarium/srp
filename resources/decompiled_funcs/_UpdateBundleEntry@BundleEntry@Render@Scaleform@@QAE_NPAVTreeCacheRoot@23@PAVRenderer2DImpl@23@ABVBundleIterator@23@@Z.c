char __thiscall Scaleform::Render::BundleEntry::UpdateBundleEntry(
        Scaleform::Render::BundleEntry *this,
        Scaleform::Render::TreeCacheRoot *tr,
        Scaleform::Render::Renderer2DImpl *r,
        const Scaleform::Render::BundleIterator *ibundles)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v6; // edi

  this->Key.pImpl->UpdateBundleEntry(this->Key.pImpl, this->Key.Data, this, tr, r, ibundles);
  if ( this->pBundle.pObject )
  {
    pObject = this->pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v6 = this->pBundle.pObject;
    if ( v6->NeedUpdate )
      Scaleform::Render::Bundle::UpdateChain(v6, this);
    Scaleform::RefCountNTSImpl::Release(v6);
  }
  return 1;
}
