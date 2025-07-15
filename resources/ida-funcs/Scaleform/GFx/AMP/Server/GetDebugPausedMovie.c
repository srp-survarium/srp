Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats> *__thiscall Scaleform::GFx::AMP::Server::GetDebugPausedMovie(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats> *result)
{
  Scaleform::Lock *p_MovieLock; // ebx
  int v4; // edi
  Scaleform::GFx::AMP::Server::ViewProfile *pObject; // edi
  Scaleform::GFx::Resource *v7; // ecx
  Scaleform::GFx::AMP::ViewStats **p_pObject; // edi

  p_MovieLock = &this->MovieLock;
  EnterCriticalSection(&this->MovieLock.cs);
  v4 = 0;
  if ( this->MovieStats.Data.Size )
  {
    while ( !Scaleform::GFx::AMP::ViewStats::IsDebugPaused(this->MovieStats.Data.Data[v4].pObject->AdvanceTimings.pObject) )
    {
      if ( ++v4 >= this->MovieStats.Data.Size )
        goto LABEL_4;
    }
    pObject = this->MovieStats.Data.Data[v4].pObject;
    v7 = (Scaleform::GFx::Resource *)pObject->AdvanceTimings.pObject;
    p_pObject = &pObject->AdvanceTimings.pObject;
    if ( v7 )
      Scaleform::RefCountImpl::AddRef(v7);
    result->pObject = *p_pObject;
    LeaveCriticalSection(&p_MovieLock->cs);
    return result;
  }
  else
  {
LABEL_4:
    result->pObject = 0;
    LeaveCriticalSection(&p_MovieLock->cs);
    return result;
  }
}
