Scaleform::GFx::PlayState __thiscall Scaleform::GFx::MovieImpl::GetPlayState(Scaleform::GFx::MovieImpl *this)
{
  if ( this->pMainMovie )
    return this->pMainMovie->GetPlayState(this->pMainMovie);
  else
    return 1;
}
