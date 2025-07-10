char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetCxform(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const Scaleform::Render::Cxform *cx)
{
  Scaleform::GFx::InteractiveObject *v3; // esi

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3
    || v3->GetType(v3) != MouseWheel
    && (v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    return 0;
  }
  Scaleform::GFx::DisplayObjectBase::SetCxform(v3, cx);
  v3->SetAcceptAnimMoves(v3, 0);
  return 1;
}
