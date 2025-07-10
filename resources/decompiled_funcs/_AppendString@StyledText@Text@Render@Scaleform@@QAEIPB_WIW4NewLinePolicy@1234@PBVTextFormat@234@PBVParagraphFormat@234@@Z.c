unsigned int __thiscall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        wchar_t *pstr,
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
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  wchar_t *v15; // ecx
  unsigned int v16; // edi
  unsigned __int8 *v17; // eax
  unsigned int v18; // eax
  int v19; // edx
  int v20; // eax
  unsigned int v21; // eax
  wchar_t *pText; // ecx
  unsigned __int8 *v23; // ebx
  Scaleform::Render::Text::StyledText *v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // ebp
  wchar_t *v27; // ebx
  bool v28; // zf
  unsigned int result; // eax
  unsigned int curOffset; // [esp+14h] [ebp-18h]
  unsigned int totalAppenededLen; // [esp+18h] [ebp-14h]
  unsigned int posInPara; // [esp+1Ch] [ebp-10h]
  unsigned int i; // [esp+24h] [ebp-8h]
  const wchar_t *pend; // [esp+28h] [ebp-4h]

  v6 = length;
  v7 = this;
  v8 = 0;
  if ( length == -1 )
  {
    length = Scaleform::SFwcslen(pstr);
    v6 = length;
  }
  Size = v7->Paragraphs.Data.Size;
  pend = &pstr[v6];
  v10 = Size - 1;
  if ( Size - 1 < 0 || v10 >= Size )
  {
    pPara = 0;
    curOffset = 0;
    v7->OnTextInserting(v7, 0, v6, pstr);
  }
  else
  {
    pPara = v7->Paragraphs.Data.Data[v10].pPara;
    if ( pPara )
    {
      curOffset = pPara->StartIndex;
      v7->OnTextInserting(v7, curOffset, v6, pstr);
    }
    else
    {
      curOffset = 0;
      v7->OnTextInserting(v7, 0, v6, pstr);
    }
  }
  v12 = 0;
  totalAppenededLen = 0;
  while ( 1 )
  {
    i = v12 + 1;
    if ( v12 || !pPara )
    {
      pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
      posInPara = 0;
      pPara->StartIndex = curOffset;
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
      if ( !v13 && pdefParaFmt )
        Scaleform::Render::Text::Paragraph::SetFormat(pPara, v7->pTextAllocator.pObject, pdefParaFmt);
    }
    v16 = 0;
    if ( newLinePolicy == NLP_CompressCRLF && v8 == 13 && *pstr == 10 )
    {
      ++pstr;
      if ( !--length )
        break;
    }
    if ( length )
    {
      while ( 1 )
      {
        v8 = pstr[v16];
        if ( v8 == 10 )
          break;
        if ( v8 != 13 )
        {
          if ( pstr[v16] )
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
      v21 = v18 - posInPara;
      if ( v21 )
        memmove(
          (unsigned __int8 *)&pPara->Text.pText[v16 + posInPara],
          (unsigned __int8 *)&pPara->Text.pText[posInPara],
          2 * v21);
      pText = pPara->Text.pText;
      pPara->Text.Size += v16;
      v23 = (unsigned __int8 *)&pText[posInPara];
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        posInPara,
        v16);
      ++pPara->ModCounter;
      v17 = v23;
    }
    else
    {
      v17 = 0;
    }
    memcpy(v17, (unsigned __int8 *)pstr, 2 * v16);
    pstr += v16;
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
      posInPara,
      0xFFFFFFFF);
    totalAppenededLen += v16;
    curOffset += v16 + posInPara;
    if ( pstr >= pend || !v8 )
    {
      v7 = this;
      break;
    }
    v7 = this;
    v12 = i;
  }
  if ( v8 == ((v7->RTFlags & 2) != 0 ? 13 : 10) )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, v7->pTextAllocator.pObject, pdefTextFmt);
  if ( (pdefTextFmt->PresentMask & 0x100) == 0 )
    return totalAppenededLen;
  v28 = Scaleform::String::GetLength(&pdefTextFmt->Url) == 0;
  result = totalAppenededLen;
  if ( !v28 )
    v7->RTFlags |= 1u;
  return result;
}
