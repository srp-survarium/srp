void __thiscall Scaleform::GFx::Text::EditorKit::ResetBlink(
        Scaleform::GFx::Text::EditorKit *this,
        bool state,
        bool blocked)
{
  if ( this->IsReadOnly(this) )
  {
    this->Flags &= ~8u;
  }
  else if ( state )
  {
    this->Flags |= 8u;
  }
  else
  {
    this->Flags &= ~8u;
  }
  this->CursorTimer = 0.0;
  if ( blocked )
    this->Flags |= 0x10u;
}
