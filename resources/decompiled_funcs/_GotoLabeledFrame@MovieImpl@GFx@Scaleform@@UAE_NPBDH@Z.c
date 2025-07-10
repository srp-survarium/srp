char __thiscall Scaleform::GFx::MovieImpl::GotoLabeledFrame(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *label,
        int offset)
{
  Scaleform::GFx::MovieDefImpl *pObject; // eax
  const char *v6; // edi
  unsigned int targetFrame; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->pMainMovie )
    return 0;
  pObject = this->pMainMovieDef.pObject;
  v6 = (const char *)label;
  targetFrame = -1;
  if ( pObject->pBindData.pObject->pDataDef.pObject->GetLabeledFrame(
         pObject->pBindData.pObject->pDataDef.pObject,
         (const char *)label,
         &targetFrame,
         0) )
  {
    this->GotoFrame(this, offset + targetFrame);
    return 1;
  }
  else
  {
    Scaleform::GFx::StateBag::GetLogState(
      &this->Scaleform::GFx::StateBag,
      (Scaleform::Ptr<Scaleform::GFx::LogState> *)&label);
    if ( label )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        label + 3,
        "MovieImpl::GotoLabeledFrame('%s') unknown label",
        v6);
      if ( label )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)label);
    }
    return 0;
  }
}
