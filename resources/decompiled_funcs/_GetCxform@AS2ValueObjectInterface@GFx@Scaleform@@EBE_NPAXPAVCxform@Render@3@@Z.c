char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Cxform *pcx)
{
  Scaleform::GFx::InteractiveObject *v3; // esi

  v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v3
    || v3->GetType(v3) != MouseWheel
    && (v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    return 0;
  }
  qmemcpy(pcx, Scaleform::GFx::DisplayObjectBase::GetCxform(v3), sizeof(Scaleform::Render::Cxform));
  return 1;
}
