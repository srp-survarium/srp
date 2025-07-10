BOOL __thiscall Scaleform::Render::Text::Highlighter::HasUnderlineHighlight(Scaleform::Render::Text::Highlighter *this)
{
  unsigned int Size; // esi
  int v2; // eax
  unsigned __int8 *i; // edx

  if ( !this->HasUnderline )
  {
    Size = this->Highlighters.Data.Size;
    v2 = 0;
    this->HasUnderline = -1;
    if ( Size )
    {
      for ( i = &this->Highlighters.Data.Data->Info.Flags; (*i & 7) == 0; i += 40 )
      {
        if ( ++v2 >= Size )
          return this->HasUnderline == 1;
      }
      this->HasUnderline = 1;
    }
  }
  return this->HasUnderline == 1;
}
