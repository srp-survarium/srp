void __thiscall Scaleform::GFx::AS2::Value::SetAsCharacterHandle(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::CharacterHandle *pchar)
{
  if ( this->T.Type != 7 || this->V.pCharHandle != pchar )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 7;
    this->NV.Int32Value = (int)pchar;
    if ( pchar )
      ++pchar->RefCount;
  }
}
