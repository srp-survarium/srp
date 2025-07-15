char __thiscall Scaleform::GFx::MovieImpl::GotoLabeledFrame(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *label,
        int offset)
{
  Scaleform::GFx::MovieDefImpl *pObject; // eax
  const char *v6; // edi
  int v7; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->pMainMovie )
    return 0;
  pObject = this->pMainMovieDef.pObject;
  v6 = (const char *)label;
  v7 = -1;
  if ( pObject->pBindData.pObject->pDataDef.pObject->GetLabeledFrame(
         pObject->pBindData.pObject->pDataDef.pObject,
         (const char *)label,
         (unsigned int *)&v7,
         0) )
  {
    this->GotoFrame(this, offset + v7);
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
