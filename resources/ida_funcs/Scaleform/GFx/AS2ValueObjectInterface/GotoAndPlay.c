char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        unsigned int frame,
        bool stop)
{
  Scaleform::GFx::InteractiveObject *v4; // esi

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v4 || (v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return 0;
  v4->GotoFrame(v4, frame - 1);
  v4->SetPlayState(v4, (Scaleform::GFx::PlayState)stop);
  return 1;
}


char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *frame,
        bool stop)
{
  Scaleform::GFx::InteractiveObject *v4; // esi

  v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v4
    || (v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0
    || !v4->GetLabeledFrame(v4, frame, (unsigned int *)&pdata, 1) )
  {
    return 0;
  }
  v4->GotoFrame(v4, (unsigned int)pdata);
  v4->SetPlayState(v4, (Scaleform::GFx::PlayState)stop);
  return 1;
}
