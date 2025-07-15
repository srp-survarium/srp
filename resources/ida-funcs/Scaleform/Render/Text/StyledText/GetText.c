Scaleform::String *__thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *retStr)
{
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // edi
  int v4; // esi
  Scaleform::Render::Text::Paragraph *pPara; // eax
  wchar_t *pText; // ecx
  unsigned int Size; // eax
  unsigned int v8; // edx
  wchar_t *v9; // edx

  Scaleform::String::operator=(retStr, (const __m128i *)uri);
  p_Paragraphs = &this->Paragraphs;
  v4 = 0;
  while ( p_Paragraphs && v4 >= 0 && v4 < (signed int)p_Paragraphs->Data.Size )
  {
    pPara = p_Paragraphs->Data.Data[v4].pPara;
    pText = pPara->Text.pText;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v8 = Size - 1;
      if ( pText && v8 < Size )
        v9 = &pText[v8];
      else
        v9 = 0;
      if ( !*v9 )
        --Size;
    }
    Scaleform::String::AppendString(retStr, pText, Size);
    if ( v4 < (signed int)p_Paragraphs->Data.Size )
      ++v4;
  }
  return retStr;
}


void __thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer)
{
  unsigned int Length; // eax
  int v4; // edi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // ebx
  int v6; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // eax
  unsigned int Size; // esi
  const __m128i *pText; // ecx
  unsigned int v10; // eax
  __int16 *v11; // eax

  Length = Scaleform::Render::Text::StyledText::GetLength(this);
  Scaleform::WStringBuffer::Resize(pBuffer, Length + 1);
  v4 = 0;
  p_Paragraphs = &this->Paragraphs;
  v6 = 0;
  while ( p_Paragraphs && v4 >= 0 && v4 < (signed int)p_Paragraphs->Data.Size )
  {
    pPara = p_Paragraphs->Data.Data[v4].pPara;
    Size = pPara->Text.Size;
    pText = (const __m128i *)pPara->Text.pText;
    if ( Size )
    {
      v10 = Size - 1;
      if ( pText && v10 < Size )
        v11 = &pText->m128i_i16[v10];
      else
        v11 = 0;
      if ( !*v11 )
        --Size;
    }
    memcpy((int)&pBuffer->pText[v6], pText, 2 * Size);
    v6 += Size;
    if ( v4 < (signed int)p_Paragraphs->Data.Size )
      ++v4;
  }
  pBuffer->pText[v6] = 0;
}


void __thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int Length; // eax
  unsigned int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  int CurIndex; // edi
  Scaleform::Render::Text::Paragraph *pPara; // eax
  unsigned int Size; // esi
  unsigned int v13; // edx
  wchar_t *v14; // ecx
  unsigned int v15; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+10h] [ebp-8h] BYREF

  Length = endPos;
  if ( endPos == -1 )
    Length = Scaleform::Render::Text::StyledText::GetLength(this);
  v6 = startPos;
  v7 = Length - startPos;
  Scaleform::WStringBuffer::Resize(pBuffer, Length - startPos + 1);
  startPos = 0;
  v8 = v7;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &result, v6, &startPos);
  v9 = startPos;
  CurIndex = result.CurIndex;
  endPos = 0;
  while ( result.pArray && CurIndex >= 0 && CurIndex < (signed int)result.pArray->Data.Size && v8 )
  {
    pPara = result.pArray->Data.Data[CurIndex].pPara;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v13 = Size - 1;
      if ( pPara->Text.pText && v13 < Size )
        v14 = &pPara->Text.pText[v13];
      else
        v14 = 0;
      if ( !*v14 )
        --Size;
    }
    v15 = Size - v9;
    if ( v15 > v8 )
      v15 = v8;
    memcpy((int)&pBuffer->pText[endPos], (const __m128i *)&pPara->Text.pText[v9], 2 * v15);
    endPos += v15;
    v9 = 0;
    v8 -= v15;
    if ( CurIndex < (signed int)result.pArray->Data.Size )
      ++CurIndex;
  }
  pBuffer->pText[endPos] = 0;
}


Scaleform::String *__thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *result)
{
  Scaleform::String::String(result);
  Scaleform::Render::Text::StyledText::GetText(this, result);
  return result;
}
