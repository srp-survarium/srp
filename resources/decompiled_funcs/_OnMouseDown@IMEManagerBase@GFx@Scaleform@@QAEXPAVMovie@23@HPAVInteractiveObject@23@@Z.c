void __thiscall Scaleform::GFx::IMEManagerBase::OnMouseDown(
        Scaleform::GFx::IMEManagerBase *this,
        Scaleform::GFx::Movie *pmovie,
        int buttonsState,
        Scaleform::GFx::TextField *pitemUnderMousePtr)
{
  Scaleform::GFx::TextField *pObject; // eax
  Scaleform::GFx::TextField *v6; // ecx

  if ( this->IsMovieActive(this, pmovie) )
  {
    pObject = this->pTextField.pObject;
    if ( pObject )
    {
      if ( pitemUnderMousePtr == pObject )
      {
        this->OnFinalize(this);
        v6 = this->pTextField.pObject;
        if ( v6 )
          Scaleform::RefCountNTSImpl::Release(v6);
        this->pTextField.pObject = 0;
      }
    }
  }
}
