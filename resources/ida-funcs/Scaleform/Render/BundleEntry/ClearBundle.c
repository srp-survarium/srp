void __thiscall Scaleform::Render::BundleEntry::ClearBundle(Scaleform::Render::BundleEntry *this)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v3; // edi
  Scaleform::Render::Bundle *v4; // ecx

  if ( this->pBundle.pObject )
  {
    pObject = this->pBundle.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v3 = this->pBundle.pObject;
    Scaleform::Render::Bundle::RemoveEntry(v3, this);
    if ( v3 )
      Scaleform::RefCountNTSImpl::Release(v3);
  }
  v4 = this->pBundle.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  this->pBundle.pObject = 0;
  this->IndexHint = 0;
}
