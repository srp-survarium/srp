void __thiscall Scaleform::GFx::AMP::ViewStats::SetMovieDef(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::MovieDef *movieDef)
{
  Scaleform::Lock *p_ViewLock; // ebx

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  if ( movieDef )
  {
    this->Version = movieDef->GetVersion(movieDef);
    this->Width = movieDef->GetWidth(movieDef);
    this->Height = movieDef->GetHeight(movieDef);
    this->FrameRate = movieDef->GetFrameRate(movieDef);
    this->FrameCount = movieDef->GetFrameCount(movieDef);
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}
