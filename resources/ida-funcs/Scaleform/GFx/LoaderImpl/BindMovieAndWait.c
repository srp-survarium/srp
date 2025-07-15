Scaleform::GFx::MovieDefImpl *__cdecl Scaleform::GFx::LoaderImpl::BindMovieAndWait(
        Scaleform::GFx::MovieDefImpl *pm,
        Scaleform::GFx::MovieBindProcess *pbp,
        Scaleform::GFx::LoadStates *pls,
        char loadConstants,
        Scaleform::GFx::LoaderImpl::LoadStackItem *ploadStack)
{
  Scaleform::GFx::LoaderImpl::LoadStackItem *v5; // esi
  Scaleform::GFx::LoaderImpl::LoadStackItem *v6; // eax
  bool v7; // al
  const __m128i *v8; // eax
  const __m128i *v9; // eax
  char *pData; // eax
  Scaleform::StringBuffer v12; // [esp+10h] [ebp-18h] BYREF

  if ( pbp && ((loadConstants & 1) != 0 || !Scaleform::GFx::LoadStates::SubmitBackgroundTask(pls, pbp)) )
    pbp->Execute(pbp);
  v5 = ploadStack;
  v6 = ploadStack;
  if ( !ploadStack )
  {
LABEL_8:
    if ( (loadConstants & 1) != 0 )
    {
      v7 = Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(pm->pBindData.pObject, 0x200u);
    }
    else
    {
      if ( (loadConstants & 2) == 0 )
        return pm;
      v7 = Scaleform::GFx::MovieDefImpl::BindTaskData::WaitForBindStateFlags(pm->pBindData.pObject, 0x100u);
    }
    if ( !v7 )
      goto LABEL_20;
    return pm;
  }
  while ( v6->pDefImpl != pm )
  {
    v6 = v6->pNext;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( !v6->pNext )
    return pm;
  if ( !pls->pLog.pObject )
  {
LABEL_20:
    Scaleform::GFx::Resource::Release(pm);
    return 0;
  }
  Scaleform::StringBuffer::StringBuffer(&v12, Scaleform::Memory::pGlobalHeap);
  do
  {
    v8 = (const __m128i *)v5->pDefImpl->GetFileURL(v5->pDefImpl);
    Scaleform::StringBuffer::AppendString(&v12, v8, 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendChar(&v12, 0xAu);
    v5 = v5->pNext;
  }
  while ( v5 );
  v9 = (const __m128i *)pm->GetFileURL(pm);
  Scaleform::StringBuffer::AppendString(&v12, v9, 0xFFFFFFFF);
  pData = v12.pData;
  if ( !v12.pData )
    pData = (char *)uri;
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
    &pls->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
    "Recursive import detected. Import stack:\n%s",
    pData);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v12);
  Scaleform::GFx::Resource::Release(pm);
  return 0;
}
