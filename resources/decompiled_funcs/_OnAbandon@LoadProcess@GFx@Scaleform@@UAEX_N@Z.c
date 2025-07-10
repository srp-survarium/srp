void __thiscall Scaleform::GFx::LoadProcess::OnAbandon(Scaleform::GFx::LoadProcess *this, bool started)
{
  Scaleform::GFx::MovieBindProcess *pObject; // eax
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // eax

  if ( started )
    Scaleform::GFx::MovieDataDef::LoadTaskData::OnMovieDataDefRelease(this->pLoadData.pObject);
  pObject = this->pBindProcess.pObject;
  if ( pObject && !started )
  {
    v4 = pObject->pBindData.pObject;
    if ( v4 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v4, 3u);
  }
}
