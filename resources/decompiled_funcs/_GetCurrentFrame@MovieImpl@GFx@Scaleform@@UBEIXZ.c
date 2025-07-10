unsigned int __thiscall Scaleform::GFx::MovieImpl::GetCurrentFrame(Scaleform::GFx::MovieImpl *this)
{
  if ( this->pMainMovie )
    return this->pMainMovie->GetCurrentFrame(this->pMainMovie);
  else
    return 0;
}
