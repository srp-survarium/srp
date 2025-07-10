char __thiscall Scaleform::GFx::MovieDefImpl::DoesDirectlyImport(
        Scaleform::GFx::MovieDefImpl *this,
        const Scaleform::GFx::MovieDefImpl *import)
{
  Scaleform::Lock *p_ImportSourceLock; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // esi
  unsigned int Size; // ecx
  unsigned int v6; // eax
  const Scaleform::GFx::MovieDefImpl **p_pObject; // edx

  p_ImportSourceLock = &this->pBindData.pObject->ImportSourceLock;
  EnterCriticalSection(&p_ImportSourceLock->cs);
  pObject = this->pBindData.pObject;
  Size = pObject->ImportSourceMovies.Data.Size;
  v6 = 0;
  if ( Size )
  {
    p_pObject = (const Scaleform::GFx::MovieDefImpl **)&pObject->ImportSourceMovies.Data.Data->pObject;
    while ( *p_pObject != import )
    {
      ++v6;
      ++p_pObject;
      if ( v6 >= Size )
        goto LABEL_5;
    }
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    return 1;
  }
  else
  {
LABEL_5:
    LeaveCriticalSection(&p_ImportSourceLock->cs);
    return 0;
  }
}
