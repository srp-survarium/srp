void __thiscall Scaleform::GFx::TextField::CollectUrlZones(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // edi
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // eax
  Scaleform::Render::Text::DocView::DocumentText *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // ebp
  unsigned int Length; // ebx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v7; // eax
  unsigned int v8; // esi
  Scaleform::Render::Text::TextFormat *v9; // eax
  const char *v10; // ecx
  Scaleform::Render::Text::StyledText *v11; // edi
  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy> > *p_UrlZones; // esi
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v13; // eax
  Scaleform::Render::Text::TextFormat *v14; // eax
  Scaleform::Render::Text::TextFormat *v15; // esi
  Scaleform::String::DataDesc *pData; // eax
  Scaleform::Render::Text::StyledText *v17; // ecx
  Scaleform::Render::Text::StyledText *v18; // esi
  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy> > *v19; // ecx
  void *v20; // esi
  Scaleform::String v21; // [esp+4h] [ebp-54h] BYREF
  Scaleform::Render::Text::Paragraph *pPara; // [esp+8h] [ebp-50h]
  Scaleform::GFx::TextField *v23; // [esp+Ch] [ebp-4Ch]
  unsigned int v24; // [esp+10h] [ebp-48h]
  unsigned int v25; // [esp+14h] [ebp-44h]
  Scaleform::Render::Text::DocView::DocumentText *v26; // [esp+18h] [ebp-40h]
  unsigned int Size; // [esp+1Ch] [ebp-3Ch]
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> range; // [esp+20h] [ebp-38h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [esp+34h] [ebp-24h] BYREF

  v1 = this;
  pObject = this->pCSSData.pObject;
  v23 = this;
  if ( pObject )
  {
    memset((int)pObject->MouseState, 0, sizeof(pObject->MouseState));
    Scaleform::ArrayDataBase<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,Scaleform::AllocatorGH<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v1->pCSSData.pObject->UrlZones.Ranges.Data,
      &v1->pCSSData.pObject->UrlZones,
      0);
    v26 = v1->pDocument.pObject->pDocument.pObject;
    v3 = v26;
    Scaleform::String::String(&v21);
    v4 = 0;
    v5 = 0;
    Length = 0;
    Size = v3->Paragraphs.Data.Size;
    v25 = 0;
    if ( Size )
    {
      while ( 1 )
      {
        if ( v4 >= v3->Paragraphs.Data.Size )
          pPara = 0;
        else
          pPara = v3->Paragraphs.Data.Data[v4].pPara;
        Scaleform::Render::Text::Paragraph::GetIterator(pPara, &result);
        if ( result.CurTextIndex < result.pText->Size )
        {
          do
          {
            v7 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result);
            v8 = pPara->StartIndex + v7->PlaceHolder.Index;
            v24 = v8;
            v9 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result)->PlaceHolder.pFormat.pObject;
            if ( (v9->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v9->Url) )
            {
              if ( (*(_DWORD *)(v21.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
              {
                if ( v8 == Length + v5
                  && (v10 = (const char *)((Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result)->PlaceHolder.pFormat.pObject->Url.HeapTypeBits
                                          & 0xFFFFFFFC)
                                         + 8),
                      !strcmp((const char *)((v21.HeapTypeBits & 0xFFFFFFFC) + 8), v10)) )
                {
                  Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result)->PlaceHolder.Length;
                }
                else
                {
                  v11 = Scaleform::Render::Text::StyledText::CopyStyledText(
                          v23->pDocument.pObject->pDocument.pObject,
                          v5,
                          (const Scaleform::Render::Text::Paragraph *)(Length + v5));
                  p_UrlZones = &v23->pCSSData.pObject->UrlZones;
                  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
                    p_UrlZones,
                    v5,
                    Length);
                  range.Index = v5;
                  range.Length = Length;
                  if ( v11 )
                    ++v11->RefCount;
                  range.Data.SavedFmt.pObject = v11;
                  range.Data.HitCount = 0;
                  range.Data.OverCount = 0;
                  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
                    p_UrlZones,
                    &range);
                  if ( range.Data.SavedFmt.pObject )
                    Scaleform::RefCountNTSImpl::Release(range.Data.SavedFmt.pObject);
                  Scaleform::String::Clear(&v21);
                  if ( v11 )
                    Scaleform::RefCountNTSImpl::Release(v11);
                  v8 = v24;
                }
              }
              if ( (*(_DWORD *)(v21.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
              {
                v5 = v8;
                Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result)->PlaceHolder.Length;
                v13 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&result);
                Scaleform::String::operator=(&v21, &v13->PlaceHolder.pFormat.pObject->Url);
              }
            }
            Scaleform::Render::Text::Paragraph::FormatRunIterator::operator++(&result);
          }
          while ( result.CurTextIndex < result.pText->Size );
          v1 = v23;
        }
        v14 = result.PlaceHolder.pFormat.pObject;
        if ( result.PlaceHolder.pFormat.pObject )
        {
          --result.PlaceHolder.pFormat.pObject->RefCount;
          v15 = v14;
          if ( !v14->RefCount )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v14);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
          }
        }
        v4 = v25 + 1;
        v25 = v4;
        if ( v4 >= Size )
          break;
        v3 = v26;
      }
    }
    pData = v21.pData;
    if ( (*(_DWORD *)(v21.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
    {
      v17 = v1->pDocument.pObject->pDocument.pObject;
      range.Length = 0;
      range.Data.SavedFmt.pObject = 0;
      v18 = Scaleform::Render::Text::StyledText::CopyStyledText(
              v17,
              v5,
              (const Scaleform::Render::Text::Paragraph *)(Length + v5));
      v19 = &v1->pCSSData.pObject->UrlZones;
      range.Index = (int)v18;
      Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::InsertRange(
        v19,
        v5,
        Length,
        (const Scaleform::GFx::TextField::CSSHolderBase::UrlZone *)&range);
      if ( v18 )
        Scaleform::RefCountNTSImpl::Release(v18);
      pData = v21.pData;
    }
    v20 = (void *)((unsigned int)pData & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pData & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  }
}
