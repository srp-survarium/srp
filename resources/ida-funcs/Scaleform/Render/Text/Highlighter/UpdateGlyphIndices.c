void __thiscall Scaleform::Render::Text::Highlighter::UpdateGlyphIndices(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::CompositionStringBase *pcs)
{
  unsigned int Size; // eax
  Scaleform::Render::Text::HighlightDesc *v4; // eax
  unsigned int StartPos; // ecx
  unsigned int Length; // edx
  unsigned int CorrectionLen; // edi
  unsigned int CorrectionPos; // ebx
  int Offset; // ebx
  unsigned int i; // [esp+Ch] [ebp-4h]
  int v11; // [esp+14h] [ebp+4h]

  this->CorrectionLen = 0;
  this->CorrectionPos = 0;
  if ( pcs )
  {
    this->CorrectionPos = pcs->GetPosition(pcs);
    this->CorrectionLen = pcs->GetLength(pcs);
  }
  Size = this->Highlighters.Data.Size;
  this->Valid = 0;
  this->HasUnderline = 0;
  if ( Size )
  {
    v11 = 0;
    for ( i = Size; i; --i )
    {
      v4 = &this->Highlighters.Data.Data[v11];
      StartPos = v4->StartPos;
      Length = v4->Length;
      v4->AdjStartPos = v4->StartPos;
      v4->GlyphNum = Length;
      CorrectionLen = this->CorrectionLen;
      if ( CorrectionLen )
      {
        CorrectionPos = this->CorrectionPos;
        if ( Length )
        {
          if ( StartPos > CorrectionPos )
            goto LABEL_13;
          if ( CorrectionPos < Length + StartPos )
          {
            Offset = v4->Offset;
            if ( Offset < 0 )
              v4->GlyphNum = Length + CorrectionLen;
            else
              v4->AdjStartPos = StartPos + Offset;
            goto LABEL_14;
          }
        }
        if ( StartPos > CorrectionPos )
LABEL_13:
          v4->AdjStartPos = StartPos + CorrectionLen;
      }
LABEL_14:
      ++v11;
    }
  }
}
