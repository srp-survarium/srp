Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::Paragraph::GetTextFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::TextFormat *result,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int v4; // ebp
  unsigned int v6; // eax
  int v7; // ebx
  Scaleform::MemoryHeap *v8; // esi
  unsigned int CurTextIndex; // ecx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v10; // esi
  Scaleform::Render::Text::TextFormat *pObject; // ecx
  const Scaleform::Render::Text::TextFormat *v13; // eax
  int Index; // ecx
  unsigned int Length; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *v16; // eax
  Scaleform::GFx::Resource *v17; // ecx
  __int16 LetterSpacing; // ax
  unsigned int ColorV; // edx
  unsigned __int16 FontSize; // cx
  unsigned __int16 PresentMask; // ax
  Scaleform::Render::Text::TextFormat *v22; // eax
  Scaleform::Render::Text::TextFormat *v23; // edi
  Scaleform::MemoryHeap *pHeap; // [esp-4h] [ebp-8Ch]
  unsigned int i; // [esp+10h] [ebp-78h]
  Scaleform::Render::Text::Paragraph::FormatRunIterator it; // [esp+14h] [ebp-74h] BYREF
  Scaleform::Render::Text::TextFormat finalTextFmt; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat v29; // [esp+60h] [ebp-28h] BYREF

  v4 = startPos;
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    &it,
    &this->FormatInfo,
    &this->Text,
    startPos);
  v6 = endPos;
  if ( endPos < startPos )
    v6 = startPos;
  if ( v6 == -1 )
    v7 = 0x7FFFFFFF;
  else
    v7 = v6 - startPos;
  v8 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  finalTextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&finalTextFmt.FontList, v8);
  Scaleform::StringDH::StringDH(&finalTextFmt.Url, v8);
  finalTextFmt.pImageDesc.pObject = 0;
  finalTextFmt.pFontHandle.pObject = 0;
  finalTextFmt.ColorV = -16777216;
  finalTextFmt.LetterSpacing = 0;
  finalTextFmt.FontSize = 0;
  finalTextFmt.FormatFlags = 0;
  finalTextFmt.PresentMask = 0;
  i = 0;
  if ( v7 > 0 )
  {
    CurTextIndex = it.CurTextIndex;
    do
    {
      if ( CurTextIndex >= it.pText->Size )
        break;
      v10 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it);
      pObject = v10->PlaceHolder.pFormat.pObject;
      if ( pObject )
      {
        if ( i++ )
        {
          v13 = Scaleform::Render::Text::TextFormat::Intersection(pObject, &v29, &finalTextFmt);
          Scaleform::Render::Text::TextFormat::operator=(&finalTextFmt, v13);
          Scaleform::Render::Text::TextFormat::~TextFormat(&v29);
        }
        else
        {
          Scaleform::Render::Text::TextFormat::operator=(&finalTextFmt, pObject);
        }
      }
      Index = v10->PlaceHolder.Index;
      Length = v10->PlaceHolder.Length;
      v7 += v4 - Index - Length;
      v4 = Index + Length;
      if ( it.FormatIterator.Index < 0 || it.FormatIterator.Index >= it.FormatIterator.pArray->Ranges.Data.Size )
      {
        CurTextIndex = it.pText->Size;
      }
      else
      {
        if ( it.CurTextIndex >= it.FormatIterator.pArray->Ranges.Data.Data[it.FormatIterator.Index].Index )
        {
          CurTextIndex = it.FormatIterator.pArray->Ranges.Data.Data[it.FormatIterator.Index].Length + it.CurTextIndex;
          it.CurTextIndex = CurTextIndex;
          if ( it.FormatIterator.Index < (signed int)it.FormatIterator.pArray->Ranges.Data.Size )
            ++it.FormatIterator.Index;
          continue;
        }
        CurTextIndex = it.FormatIterator.pArray->Ranges.Data.Data[it.FormatIterator.Index].Index;
      }
      it.CurTextIndex = CurTextIndex;
    }
    while ( v7 > 0 );
  }
  pHeap = finalTextFmt.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &finalTextFmt.FontList, pHeap);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &finalTextFmt.Url, finalTextFmt.FontList.pHeap);
  v16 = finalTextFmt.pImageDesc.pObject;
  if ( finalTextFmt.pImageDesc.pObject )
  {
    ++finalTextFmt.pImageDesc.pObject->RefCount;
    v16 = finalTextFmt.pImageDesc.pObject;
  }
  v17 = (Scaleform::GFx::Resource *)finalTextFmt.pFontHandle.pObject;
  result->pImageDesc.pObject = v16;
  if ( v17 )
  {
    Scaleform::RefCountImpl::AddRef(v17);
    v17 = (Scaleform::GFx::Resource *)finalTextFmt.pFontHandle.pObject;
  }
  LetterSpacing = finalTextFmt.LetterSpacing;
  ColorV = finalTextFmt.ColorV;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v17;
  FontSize = finalTextFmt.FontSize;
  result->LetterSpacing = LetterSpacing;
  PresentMask = finalTextFmt.PresentMask;
  result->ColorV = ColorV;
  LOBYTE(ColorV) = finalTextFmt.FormatFlags;
  result->FontSize = FontSize;
  result->FormatFlags = ColorV;
  result->PresentMask = PresentMask;
  Scaleform::Render::Text::TextFormat::~TextFormat(&finalTextFmt);
  v22 = it.PlaceHolder.pFormat.pObject;
  if ( it.PlaceHolder.pFormat.pObject )
  {
    --it.PlaceHolder.pFormat.pObject->RefCount;
    v23 = v22;
    if ( !v22->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v22);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
    }
  }
  return result;
}
