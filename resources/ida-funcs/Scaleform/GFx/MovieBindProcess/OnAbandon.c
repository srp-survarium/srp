void __thiscall Scaleform::GFx::MovieBindProcess::OnAbandon(Scaleform::GFx::MovieBindProcess *this, bool started)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // eax

  pObject = this->pBindData.pObject;
  if ( pObject )
  {
    if ( started )
      pObject->BindingCanceled = 1;
    else
      Scaleform::GFx::MovieBindProcess::SetBindState(this, 3u);
  }
}
