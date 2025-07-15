void __thiscall Scaleform::GFx::TextField::SetCSSData(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::TextField::CSSHolderBase *css)
{
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // ecx

  pObject = this->pCSSData.pObject;
  if ( pObject != css )
  {
    if ( pObject && this->pCSSData.Owner )
    {
      this->pCSSData.Owner = 0;
      ((void (__thiscall *)(Scaleform::GFx::TextField::CSSHolderBase *, int))pObject->~Scaleform::GFx::TextField::CSSHolderBase)(
        pObject,
        1);
    }
    this->pCSSData.pObject = css;
  }
  this->pCSSData.Owner = css != 0;
}
