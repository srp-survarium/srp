unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        const char *putf8String,
        unsigned int stringSize,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        const Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned int v6; // eax
  Scaleform::Render::Text::StyledText *v7; // edi
  signed int Size; // edx
  Scaleform::Render::Text::Paragraph *pPara; // ebp
  signed int v10; // ecx
  int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  wchar_t *v15; // ecx
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int v18; // eax
  wchar_t *Position; // esi
  wchar_t *v20; // edi
  unsigned int v21; // eax
  const Scaleform::Render::Text::TextFormat *v22; // esi
  bool v23; // zf
  unsigned int result; // eax
  const char *pbegin; // [esp+10h] [ebp-18h]
  const char *pend; // [esp+18h] [ebp-10h]
  unsigned int totalAppenededLen; // [esp+1Ch] [ebp-Ch]
  unsigned int posInPara; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v6 = stringSize;
  v7 = this;
  pbegin = putf8String;
  if ( stringSize == -1 )
    v6 = strlen(putf8String);
  Size = v7->Paragraphs.Data.Size;
  pend = &putf8String[v6];
  pPara = 0;
  v10 = Size - 1;
  v11 = 0;
  totalAppenededLen = 0;
  if ( Size - 1 >= 0 && v10 < Size && (pPara = v7->Paragraphs.Data.Data[v10].pPara) != 0 )
    stringSize = pPara->StartIndex;
  else
    stringSize = 0;
  v7->OnTextInserting(v7, stringSize, v6, putf8String);
  v12 = 0;
  while ( 1 )
  {
    i = v12 + 1;
    if ( v12 || !pPara )
    {
      pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
      posInPara = 0;
      pPara->StartIndex = stringSize;
    }
    else
    {
      Scaleform::Render::Text::Paragraph::RemoveTermNull(pPara);
      v13 = pPara->Text.Size;
      if ( v13 )
      {
        v14 = v13 - 1;
        if ( pPara->Text.pText && v14 < v13 )
          v15 = &pPara->Text.pText[v14];
        else
          v15 = 0;
        if ( !*v15 )
          --v13;
      }
      posInPara = v13;
    }
    v16 = v11;
    v17 = 0;
    v11 = -1;
    putf8String = pbegin;
    if ( pbegin >= pend )
      break;
    while ( v11 )
    {
      v18 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8String);
      if ( !v18 )
        --putf8String;
      if ( newLinePolicy || v16 != 13 || v17 || (v16 = -1, v18 != 10) )
      {
        v11 = v18;
        if ( v18 == 10 )
          goto LABEL_36;
        if ( v18 == 13 )
          break;
        ++v17;
      }
      else
      {
        ++pbegin;
      }
      if ( putf8String >= pend )
        break;
    }
    if ( v11 == 10 || v11 == 13 )
LABEL_36:
      ++v17;
    if ( v17 )
    {
      Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
                   &pPara->Text,
                   this->pTextAllocator.pObject,
                   posInPara,
                   v17);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        posInPara,
        v17);
      ++pPara->ModCounter;
      v20 = Position;
      v11 = -1;
      putf8String = pbegin;
      while ( putf8String < pend )
      {
        if ( !v11 )
          break;
        v21 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8String);
        if ( !v21 )
          --putf8String;
        v11 = v21;
        if ( v21 == 13 || v21 == 10 )
          v11 = (this->RTFlags & 2) != 0 ? 13 : 10;
        *v20++ = v11;
        if ( v11 == ((this->RTFlags & 2) != 0 ? 13 : 10) )
          break;
      }
      Scaleform::Render::Text::Paragraph::SetTextFormat(
        pPara,
        this->pTextAllocator.pObject,
        pdefTextFmt,
        posInPara,
        0xFFFFFFFF);
      stringSize += v17 + posInPara;
      totalAppenededLen += v17;
      pbegin = putf8String;
    }
    if ( pbegin >= pend || !v11 )
      break;
    v12 = i;
    v7 = this;
  }
  if ( v11 == ((this->RTFlags & 2) != 0 ? 13 : 10) )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v22 = pdefTextFmt;
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, this->pTextAllocator.pObject, pdefTextFmt);
  if ( (v22->PresentMask & 0x100) == 0 )
    return totalAppenededLen;
  v23 = Scaleform::String::GetLength(&v22->Url) == 0;
  result = totalAppenededLen;
  if ( !v23 )
    this->RTFlags |= 1u;
  return result;
}
