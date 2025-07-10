void __thiscall Scaleform::Render::Text::Highlighter::SetSelectColor(
        Scaleform::Render::Text::Highlighter *this,
        const Scaleform::Render::Color *color)
{
  unsigned int Size; // edx
  int v3; // eax

  Size = this->Highlighters.Data.Size;
  if ( Size )
  {
    v3 = 0;
    do
    {
      this->Highlighters.Data.Data[v3++].Info.BackgroundColor = *color;
      --Size;
    }
    while ( Size );
  }
  this->HasUnderline = 0;
  this->Valid = 0;
}
