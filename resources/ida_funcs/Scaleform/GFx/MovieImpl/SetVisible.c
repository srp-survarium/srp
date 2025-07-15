void __thiscall Scaleform::GFx::MovieImpl::SetVisible(Scaleform::GFx::MovieImpl *this, BOOL visible)
{
  if ( this->pMainMovie )
    this->pMainMovie->SetVisible(this->pMainMovie, visible);
}
