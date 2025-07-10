Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::MovieDefImpl::BindTaskData::GetMovieDefImplAddRef(
        Scaleform::GFx::MovieDefImpl::BindTaskData *this)
{
  Scaleform::Lock *p_ImportSourceLock; // edi
  Scaleform::GFx::MovieDefImpl *pDefImpl_Unsafe; // ecx
  Scaleform::GFx::MovieDefImpl *v4; // esi

  p_ImportSourceLock = &this->ImportSourceLock;
  EnterCriticalSection(&this->ImportSourceLock.cs);
  pDefImpl_Unsafe = this->pDefImpl_Unsafe;
  if ( pDefImpl_Unsafe && Scaleform::GFx::Resource::AddRef_NotZero(pDefImpl_Unsafe) )
  {
    v4 = this->pDefImpl_Unsafe;
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    return v4;
  }
  else
  {
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    return 0;
  }
}
