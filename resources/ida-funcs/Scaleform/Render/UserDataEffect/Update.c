char __thiscall Scaleform::Render::UserDataEffect::Update(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::UserDataState *stateArg)
{
  Scaleform::Render::BundleEntry *p_StartEntry; // esi
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::Bundle *v5; // edi
  Scaleform::RefCountNTSImpl *v6; // ecx

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
  Scaleform::Render::UserDataEffect::rebuildBundles(this, stateArg);
  return 1;
}
