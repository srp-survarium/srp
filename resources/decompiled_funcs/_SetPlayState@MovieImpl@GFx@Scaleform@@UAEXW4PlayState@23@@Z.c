void __thiscall Scaleform::GFx::MovieImpl::SetPlayState(Scaleform::GFx::MovieImpl *this, Scaleform::GFx::PlayState s)
{
  if ( this->pMainMovie )
    this->pMainMovie->SetPlayState(this->pMainMovie, s);
}
