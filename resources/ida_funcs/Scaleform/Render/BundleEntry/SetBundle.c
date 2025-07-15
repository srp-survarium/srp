void __thiscall Scaleform::Render::BundleEntry::SetBundle(
        Scaleform::Render::BundleEntry *this,
        Scaleform::Render::Bundle *b,
        unsigned __int16 indexHint)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // edi
  Scaleform::Render::Bundle *v6; // ecx

  pObject = this->pBundle.pObject;
  if ( pObject )
  {
    if ( pObject != b )
    {
      ++pObject->RefCount;
      v5 = this->pBundle.pObject;
      Scaleform::Render::Bundle::RemoveEntry(v5, this);
      if ( v5 )
        Scaleform::RefCountNTSImpl::Release(v5);
    }
  }
  if ( b )
    ++b->RefCount;
  v6 = this->pBundle.pObject;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  this->pBundle.pObject = b;
  this->IndexHint = indexHint;
}
