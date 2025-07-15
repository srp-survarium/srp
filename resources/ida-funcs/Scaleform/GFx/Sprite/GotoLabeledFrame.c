char __thiscall Scaleform::GFx::Sprite::GotoLabeledFrame(Scaleform::GFx::Sprite *this, const char *label, int offset)
{
  Scaleform::GFx::TimelineDef *pObject; // ecx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  pObject = this->pDef.pObject;
  v6 = -1;
  if ( pObject->GetLabeledFrame(pObject, label, (unsigned int *)&v6, 0) )
  {
    this->GotoFrame(this, offset + v6);
    return 1;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogWarning(
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "MovieImpl::GotoLabeledFrame('%s') unknown label",
      label);
    return 0;
  }
}
