unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        char *putf8String,
        unsigned int stringSize,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy)
{
  return Scaleform::Render::Text::StyledText::AppendString(
           this,
           putf8String,
           stringSize,
           newLinePolicy,
           this->pDefaultTextFormat.pObject,
           this->pDefaultParagraphFormat.pObject);
}


unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        char *putf8String,
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
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  wchar_t *v15; // ecx
  int v16; // edi
  unsigned int v17; // ebx
  unsigned int Char_Advance0; // eax
  wchar_t *Position; // esi
  wchar_t *v20; // edi
  unsigned int v21; // eax
  const Scaleform::Render::Text::TextFormat *v22; // esi
  bool v23; // zf
  unsigned int result; // eax
  char *v25; // [esp+10h] [ebp-18h]
  char *v27; // [esp+18h] [ebp-10h]
  unsigned int v28; // [esp+1Ch] [ebp-Ch]
  unsigned int pos; // [esp+20h] [ebp-8h]
  int v30; // [esp+24h] [ebp-4h]

  v6 = stringSize;
  v7 = this;
  v25 = putf8String;
  if ( stringSize == -1 )
    v6 = strlen(putf8String);
  Size = v7->Paragraphs.Data.Size;
  v27 = &putf8String[v6];
  pPara = 0;
  v10 = Size - 1;
  v11 = 0;
  v28 = 0;
  if ( Size - 1 >= 0 && v10 < Size && (pPara = v7->Paragraphs.Data.Data[v10].pPara) != 0 )
    stringSize = pPara->StartIndex;
  else
    stringSize = 0;
  v7->OnTextInserting(v7, stringSize, v6, putf8String);
  v12 = 0;
  while ( 1 )
  {
    v30 = v12 + 1;
    if ( v12 || !pPara )
    {
      pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
      pos = 0;
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
      pos = v13;
    }
    v16 = v11;
    v17 = 0;
    v11 = -1;
    putf8String = v25;
    if ( v25 >= v27 )
      break;
    while ( v11 )
    {
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8String);
      if ( !Char_Advance0 )
        --putf8String;
      if ( newLinePolicy || v16 != 13 || v17 || (v16 = -1, Char_Advance0 != 10) )
      {
        v11 = Char_Advance0;
        if ( Char_Advance0 == 10 )
          goto LABEL_36;
        if ( Char_Advance0 == 13 )
          break;
        ++v17;
      }
      else
      {
        ++v25;
      }
      if ( putf8String >= v27 )
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
                   pos,
                   v17);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        pos,
        v17);
      ++pPara->ModCounter;
      v20 = Position;
      v11 = -1;
      putf8String = v25;
      while ( putf8String < v27 )
      {
        if ( !v11 )
          break;
        v21 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8String);
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
        pos,
        0xFFFFFFFF);
      stringSize += v17 + pos;
      v28 += v17;
      v25 = putf8String;
    }
    if ( v25 >= v27 || !v11 )
      break;
    v12 = v30;
    v7 = this;
  }
  if ( v11 == ((this->RTFlags & 2) != 0 ? 13 : 10) )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v22 = pdefTextFmt;
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, this->pTextAllocator.pObject, pdefTextFmt);
  if ( (v22->PresentMask & 0x100) == 0 )
    return v28;
  v23 = Scaleform::String::GetLength(&v22->Url) == 0;
  result = v28;
  if ( !v23 )
    this->RTFlags |= 1u;
  return result;
}


unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        const __m128i *pstr,
        unsigned int length,
        const Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  return Scaleform::Render::Text::StyledText::AppendString(
           this,
           pstr,
           length,
           NLP_ReplaceCRLF,
           pdefTextFmt,
           pdefParaFmt);
}


unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        const __m128i *pstr,
        unsigned int length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        const Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned int v6; // edx
  Scaleform::Render::Text::StyledText *v7; // ebx
  int v8; // ebp
  signed int Size; // ecx
  signed int v10; // eax
  Scaleform::Render::Text::Paragraph *pPara; // esi
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  wchar_t *v15; // ecx
  unsigned int v16; // edi
  int v17; // eax
  unsigned int v18; // eax
  int v19; // edx
  int v20; // eax
  unsigned int v21; // eax
  wchar_t *pText; // ecx
  int v23; // ebx
  Scaleform::Render::Text::StyledText *v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // ebp
  wchar_t *v27; // ebx
  bool v28; // zf
  unsigned int result; // eax
  unsigned int StartIndex; // [esp+14h] [ebp-18h]
  unsigned int v31; // [esp+18h] [ebp-14h]
  int startPos; // [esp+1Ch] [ebp-10h]
  int v34; // [esp+24h] [ebp-8h]
  wchar_t *v35; // [esp+28h] [ebp-4h]

  v6 = length;
  v7 = this;
  v8 = 0;
  if ( length == -1 )
  {
    length = Scaleform::SFwcslen((const wchar_t *)pstr);
    v6 = length;
  }
  Size = v7->Paragraphs.Data.Size;
  v35 = (wchar_t *)pstr + v6;
  v10 = Size - 1;
  if ( Size - 1 < 0 || v10 >= Size )
  {
    pPara = 0;
    StartIndex = 0;
    v7->OnTextInserting(v7, 0, v6, (const wchar_t *)pstr);
  }
  else
  {
    pPara = v7->Paragraphs.Data.Data[v10].pPara;
    if ( pPara )
    {
      StartIndex = pPara->StartIndex;
      v7->OnTextInserting(v7, StartIndex, v6, (const wchar_t *)pstr);
    }
    else
    {
      StartIndex = 0;
      v7->OnTextInserting(v7, 0, v6, (const wchar_t *)pstr);
    }
  }
  v12 = 0;
  v31 = 0;
  while ( 1 )
  {
    v34 = v12 + 1;
    if ( v12 || !pPara )
    {
      pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
      startPos = 0;
      pPara->StartIndex = StartIndex;
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
      startPos = v13;
      if ( !v13 && pdefParaFmt )
        Scaleform::Render::Text::Paragraph::SetFormat(pPara, v7->pTextAllocator.pObject, pdefParaFmt);
    }
    v16 = 0;
    if ( newLinePolicy == NLP_CompressCRLF && v8 == 13 && pstr->m128i_i16[0] == 10 )
    {
      pstr = (const __m128i *)((char *)pstr + 2);
      if ( !--length )
        break;
    }
    if ( length )
    {
      while ( 1 )
      {
        v8 = pstr->m128i_u16[v16];
        if ( v8 == 10 )
          break;
        if ( v8 != 13 )
        {
          if ( pstr->m128i_i16[v16] )
          {
            if ( ++v16 < length )
              continue;
          }
        }
        goto LABEL_33;
      }
LABEL_35:
      ++v16;
      goto LABEL_36;
    }
LABEL_33:
    if ( v8 == 10 || v8 == 13 )
      goto LABEL_35;
LABEL_36:
    if ( v16 )
    {
      v18 = pPara->Text.Size;
      if ( pPara->Text.Allocated < v18 + v16 )
      {
        v19 = 2 * (v18 + v16);
        if ( pPara->Text.pText )
          v20 = ((int (__stdcall *)(wchar_t *, int))Scaleform::Memory::pGlobalHeap->Realloc)(pPara->Text.pText, v19);
        else
          v20 = ((int (__stdcall *)(int, _DWORD))v7->pTextAllocator.pObject->pHeap->Alloc)(v19, 0);
        pPara->Text.pText = (wchar_t *)v20;
        v18 = pPara->Text.Size;
        pPara->Text.Allocated = v18 + v16;
      }
      v21 = v18 - startPos;
      if ( v21 )
        memmove((int)&pPara->Text.pText[v16 + startPos], (const __m128i *)&pPara->Text.pText[startPos], 2 * v21);
      pText = pPara->Text.pText;
      pPara->Text.Size += v16;
      v23 = (int)&pText[startPos];
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        startPos,
        v16);
      ++pPara->ModCounter;
      v17 = v23;
    }
    else
    {
      v17 = 0;
    }
    memcpy(v17, pstr, 2 * v16);
    pstr = (const __m128i *)((char *)pstr + 2 * v16);
    length -= v16;
    if ( v8 == 10 || v8 == 13 )
    {
      v24 = this;
      if ( v8 != ((this->RTFlags & 2) != 0 ? 13 : 10) )
      {
        v25 = pPara->Text.Size;
        if ( v25 )
        {
          v26 = v25 - 1;
          if ( pPara->Text.pText && v26 < v25 )
            v27 = &pPara->Text.pText[v26];
          else
            v27 = 0;
          if ( !*v27 )
            --v25;
          if ( v25 )
            pPara->Text.pText[v25 - 1] = (unsigned __int8)((this->RTFlags & 2) != 0 ? 13 : 10);
        }
        v8 = (this->RTFlags & 2) != 0 ? 13 : 10;
      }
    }
    else
    {
      v24 = this;
    }
    Scaleform::Render::Text::Paragraph::SetTextFormat(
      pPara,
      v24->pTextAllocator.pObject,
      pdefTextFmt,
      startPos,
      0xFFFFFFFF);
    v31 += v16;
    StartIndex += v16 + startPos;
    if ( pstr >= (const __m128i *)v35 || !v8 )
    {
      v7 = this;
      break;
    }
    v7 = this;
    v12 = v34;
  }
  if ( v8 == ((v7->RTFlags & 2) != 0 ? 13 : 10) )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, v7->pTextAllocator.pObject, pdefTextFmt);
  if ( (pdefTextFmt->PresentMask & 0x100) == 0 )
    return v31;
  v28 = Scaleform::String::GetLength(&pdefTextFmt->Url) == 0;
  result = v31;
  if ( !v28 )
    v7->RTFlags |= 1u;
  return result;
}
