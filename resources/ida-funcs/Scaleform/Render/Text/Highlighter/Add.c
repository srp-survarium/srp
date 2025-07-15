void __thiscall Scaleform::Render::Text::Highlighter::Add(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlightDesc *merge)
{
  Scaleform::Render::Text::HighlightDesc *v2; // edi
  unsigned int v3; // ebp
  char v4; // bl
  Scaleform::Render::Text::HighlightDesc *v5; // eax
  unsigned int StartPos; // edi
  unsigned int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // edx
  unsigned int Length; // edx
  int v11; // [esp+Ch] [ebp-8h]
  unsigned int Size; // [esp+10h] [ebp-4h]

  v2 = merge;
  v3 = merge->StartPos + merge->Length;
  v4 = 0;
  if ( !this->Highlighters.Data.Size )
  {
LABEL_15:
    Scaleform::Render::Text::Highlighter::CreateNewHighlighter(this, v2);
    return;
  }
  v11 = 0;
  Size = this->Highlighters.Data.Size;
  while ( 1 )
  {
    v5 = &this->Highlighters.Data.Data[v11];
    StartPos = v2->StartPos;
    v7 = v5->StartPos;
    v8 = v5->StartPos + v5->Length;
    if ( v5->StartPos <= StartPos )
    {
      if ( StartPos <= v8 )
      {
        if ( v3 > v8 )
        {
          v5->Length += v3 - v8;
          v5->GlyphNum = v5->Length;
          v4 = 1;
          this->Valid = 0;
          this->HasUnderline = 0;
        }
        goto LABEL_12;
      }
      if ( v7 <= StartPos )
        goto LABEL_12;
    }
    if ( v7 < v3 )
    {
      v9 = v7 - StartPos;
      v5->StartPos -= v9;
      v5->Length += v9;
      Length = v5->Length;
      v5->AdjStartPos = v5->StartPos;
      v5->GlyphNum = Length;
      v4 = 1;
      this->Valid = 0;
      this->HasUnderline = 0;
      if ( v8 <= v3 )
      {
        v5->Length += v3 - v8;
        v5->GlyphNum = v5->Length;
      }
    }
LABEL_12:
    ++v11;
    if ( !--Size )
      break;
    v2 = merge;
  }
  if ( !v4 )
  {
    v2 = merge;
    goto LABEL_15;
  }
}
