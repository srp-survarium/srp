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
  int v26; // [esp+10h] [ebp-78h]
  Scaleform::Render::Text::Paragraph::FormatRunIterator v27; // [esp+14h] [ebp-74h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat resulta; // [esp+60h] [ebp-28h] BYREF

  v4 = startPos;
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    &v27,
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
  fmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&fmt.FontList, v8);
  Scaleform::StringDH::StringDH(&fmt.Url, v8);
  fmt.pImageDesc.pObject = 0;
  fmt.pFontHandle.pObject = 0;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  v26 = 0;
  if ( v7 > 0 )
  {
    CurTextIndex = v27.CurTextIndex;
    do
    {
      if ( CurTextIndex >= v27.pText->Size )
        break;
      v10 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v27);
      pObject = v10->PlaceHolder.pFormat.pObject;
      if ( pObject )
      {
        if ( v26++ )
        {
          v13 = Scaleform::Render::Text::TextFormat::Intersection(pObject, &resulta, &fmt);
          Scaleform::Render::Text::TextFormat::operator=(&fmt, v13);
          Scaleform::Render::Text::TextFormat::~TextFormat(&resulta);
        }
        else
        {
          Scaleform::Render::Text::TextFormat::operator=(&fmt, pObject);
        }
      }
      Index = v10->PlaceHolder.Index;
      Length = v10->PlaceHolder.Length;
      v7 += v4 - Index - Length;
      v4 = Index + Length;
      if ( v27.FormatIterator.Index < 0 || v27.FormatIterator.Index >= v27.FormatIterator.pArray->Ranges.Data.Size )
      {
        CurTextIndex = v27.pText->Size;
      }
      else
      {
        if ( v27.CurTextIndex >= v27.FormatIterator.pArray->Ranges.Data.Data[v27.FormatIterator.Index].Index )
        {
          CurTextIndex = v27.FormatIterator.pArray->Ranges.Data.Data[v27.FormatIterator.Index].Length + v27.CurTextIndex;
          v27.CurTextIndex = CurTextIndex;
          if ( v27.FormatIterator.Index < (signed int)v27.FormatIterator.pArray->Ranges.Data.Size )
            ++v27.FormatIterator.Index;
          continue;
        }
        CurTextIndex = v27.FormatIterator.pArray->Ranges.Data.Data[v27.FormatIterator.Index].Index;
      }
      v27.CurTextIndex = CurTextIndex;
    }
    while ( v7 > 0 );
  }
  pHeap = fmt.FontList.pHeap;
  result->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&result->FontList, &fmt.FontList, pHeap);
  Scaleform::StringDH::CopyConstructHelper(&result->Url, &fmt.Url, fmt.FontList.pHeap);
  v16 = fmt.pImageDesc.pObject;
  if ( fmt.pImageDesc.pObject )
  {
    ++fmt.pImageDesc.pObject->RefCount;
    v16 = fmt.pImageDesc.pObject;
  }
  v17 = (Scaleform::GFx::Resource *)fmt.pFontHandle.pObject;
  result->pImageDesc.pObject = v16;
  if ( v17 )
  {
    Scaleform::RefCountImpl::AddRef(v17);
    v17 = (Scaleform::GFx::Resource *)fmt.pFontHandle.pObject;
  }
  LetterSpacing = fmt.LetterSpacing;
  ColorV = fmt.ColorV;
  result->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v17;
  FontSize = fmt.FontSize;
  result->LetterSpacing = LetterSpacing;
  PresentMask = fmt.PresentMask;
  result->ColorV = ColorV;
  LOBYTE(ColorV) = fmt.FormatFlags;
  result->FontSize = FontSize;
  result->FormatFlags = ColorV;
  result->PresentMask = PresentMask;
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  v22 = v27.PlaceHolder.pFormat.pObject;
  if ( v27.PlaceHolder.pFormat.pObject )
  {
    --v27.PlaceHolder.pFormat.pObject->RefCount;
    v23 = v22;
    if ( !v22->RefCount )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v22);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
    }
  }
  return result;
}
