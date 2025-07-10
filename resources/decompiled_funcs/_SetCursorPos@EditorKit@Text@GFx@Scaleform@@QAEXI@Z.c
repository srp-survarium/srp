void __thiscall Scaleform::GFx::Text::EditorKit::SetCursorPos(Scaleform::GFx::Text::EditorKit *this, unsigned int pos)
{
  Scaleform::GFx::Text::EditorKit::SetCursorPos(this, pos, (this->Flags & 2) != 0);
}
