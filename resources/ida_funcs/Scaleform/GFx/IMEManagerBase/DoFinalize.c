void __thiscall Scaleform::GFx::IMEManagerBase::DoFinalize(Scaleform::GFx::IMEManagerBase *this)
{
  Scaleform::GFx::TextField *pObject; // ecx

  this->OnFinalize(this);
  pObject = this->pTextField.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pTextField.pObject = 0;
}
