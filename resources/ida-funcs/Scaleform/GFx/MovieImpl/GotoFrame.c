void __thiscall Scaleform::GFx::MovieImpl::GotoFrame(Scaleform::GFx::MovieImpl *this, unsigned int targetFrameNumber)
{
  if ( this->pMainMovie )
    this->pMainMovie->GotoFrame(this->pMainMovie, targetFrameNumber);
}
