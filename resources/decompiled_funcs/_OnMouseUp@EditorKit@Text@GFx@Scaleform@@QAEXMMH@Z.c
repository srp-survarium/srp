void __thiscall Scaleform::GFx::Text::EditorKit::OnMouseUp(
        Scaleform::GFx::Text::EditorKit *this,
        float x,
        float y,
        char buttons)
{
  unsigned __int16 Flags; // ax

  if ( (buttons & 1) == 0 )
  {
    Flags = this->Flags;
    if ( (Flags & 2) != 0 && (Flags & 0x20) != 0 )
      this->Flags = Flags & 0xFFDF;
  }
}
