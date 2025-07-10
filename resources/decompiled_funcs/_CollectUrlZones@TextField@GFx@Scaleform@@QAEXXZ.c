void __thiscall Scaleform::GFx::TextField::CollectUrlZones(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // edi
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // eax
  Scaleform::Render::Text::StyledText *v3; // esi
  unsigned int v4; // eax
  Scaleform::Render::Text::StyledText *v5; // ebp
  unsigned int Length; // ebx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v7; // eax
  unsigned int v8; // esi
  Scaleform::Render::Text::TextFormat *v9; // eax
  const char *v10; // ecx
  Scaleform::RefCountNTSImpl *v11; // edi
  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy> > *p_UrlZones; // esi
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v13; // eax
  Scaleform::Render::Text::TextFormat *v14; // eax
  Scaleform::Render::Text::TextFormat *v15; // esi
  Scaleform::String::DataDesc *pData; // eax
  Scaleform::Render::Text::StyledText *v17; // ecx
  Scaleform::Render::Text::Paragraph *v18; // esi
  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy> > *v19; // ecx
  void *v20; // esi
  Scaleform::String currentUrl; // [esp+4h] [ebp-54h] BYREF
  Scaleform::Render::Text::Paragraph *pPara; // [esp+8h] [ebp-50h]
  Scaleform::GFx::TextField *v23; // [esp+Ch] [ebp-4Ch]
  unsigned int indexInDoc; // [esp+10h] [ebp-48h]
  unsigned int i; // [esp+14h] [ebp-44h]
  Scaleform::Render::Text::StyledText *pstyledText; // [esp+18h] [ebp-40h]
  unsigned int n; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::TextField::CSSHolderBase::UrlZone urlZone; // [esp+20h] [ebp-38h] BYREF
  int v29; // [esp+2Ch] [ebp-2Ch]
  int v30; // [esp+30h] [ebp-28h]
  Scaleform::Render::Text::Paragraph::FormatRunIterator it; // [esp+34h] [ebp-24h] BYREF

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
    pstyledText = v1->pDocument.pObject->pDocument.pObject;
    v3 = pstyledText;
    Scaleform::String::String(&currentUrl);
    v4 = 0;
    v5 = 0;
    Length = 0;
    n = v3->Paragraphs.Data.Size;
    i = 0;
    if ( n )
    {
      while ( 1 )
      {
        if ( v4 >= v3->Paragraphs.Data.Size )
          pPara = 0;
        else
          pPara = v3->Paragraphs.Data.Data[v4].pPara;
        Scaleform::Render::Text::Paragraph::GetIterator(pPara, &it);
        if ( it.CurTextIndex < it.pText->Size )
        {
          do
          {
            v7 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it);
            v8 = pPara->StartIndex + v7->PlaceHolder.Index;
            indexInDoc = v8;
            v9 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it)->PlaceHolder.pFormat.pObject;
            if ( (v9->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v9->Url) )
            {
              if ( (*(_DWORD *)(currentUrl.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
              {
                if ( (Scaleform::Render::Text::StyledText *)v8 == (Scaleform::Render::Text::StyledText *)((char *)v5 + Length)
                  && (v10 = (const char *)((Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it)->PlaceHolder.pFormat.pObject->Url.HeapTypeBits
                                          & 0xFFFFFFFC)
                                         + 8),
                      !strcmp((const char *)((currentUrl.HeapTypeBits & 0xFFFFFFFC) + 8), v10)) )
                {
                  Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it)->PlaceHolder.Length;
                }
                else
                {
                  v11 = (Scaleform::RefCountNTSImpl *)Scaleform::Render::Text::StyledText::CopyStyledText(
                                                        v23->pDocument.pObject->pDocument.pObject,
                                                        (unsigned int)v5,
                                                        (Scaleform::Render::Text::Paragraph *)((char *)v5 + Length));
                  p_UrlZones = &v23->pCSSData.pObject->UrlZones;
                  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
                    p_UrlZones,
                    (int)v5,
                    Length);
                  urlZone.SavedFmt.pObject = v5;
                  urlZone.HitCount = Length;
                  if ( v11 )
                    ++v11->RefCount;
                  urlZone.OverCount = (unsigned int)v11;
                  v29 = 0;
                  v30 = 0;
                  Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
                    p_UrlZones,
                    (const Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *)&urlZone);
                  if ( urlZone.OverCount )
                    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)urlZone.OverCount);
                  Scaleform::String::Clear(&currentUrl);
                  if ( v11 )
                    Scaleform::RefCountNTSImpl::Release(v11);
                  v8 = indexInDoc;
                }
              }
              if ( (*(_DWORD *)(currentUrl.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
              {
                v5 = (Scaleform::Render::Text::StyledText *)v8;
                Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it)->PlaceHolder.Length;
                v13 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&it);
                Scaleform::String::operator=(&currentUrl, &v13->PlaceHolder.pFormat.pObject->Url);
              }
            }
            Scaleform::Render::Text::Paragraph::FormatRunIterator::operator++(&it);
          }
          while ( it.CurTextIndex < it.pText->Size );
          v1 = v23;
        }
        v14 = it.PlaceHolder.pFormat.pObject;
        if ( it.PlaceHolder.pFormat.pObject )
        {
          --it.PlaceHolder.pFormat.pObject->RefCount;
          v15 = v14;
          if ( !v14->RefCount )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v14);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
          }
        }
        v4 = i + 1;
        i = v4;
        if ( v4 >= n )
          break;
        v3 = pstyledText;
      }
    }
    pData = currentUrl.pData;
    if ( (*(_DWORD *)(currentUrl.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
    {
      v17 = v1->pDocument.pObject->pDocument.pObject;
      urlZone.HitCount = 0;
      urlZone.OverCount = 0;
      v18 = Scaleform::Render::Text::StyledText::CopyStyledText(
              v17,
              (unsigned int)v5,
              (Scaleform::Render::Text::Paragraph *)((char *)v5 + Length));
      v19 = &v1->pCSSData.pObject->UrlZones;
      urlZone.SavedFmt.pObject = (Scaleform::Render::Text::StyledText *)v18;
      Scaleform::RangeDataArray<Scaleform::GFx::TextField::CSSHolderBase::UrlZone,Scaleform::Array<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>,2,Scaleform::ArrayDefaultPolicy>>::InsertRange(
        v19,
        (int)v5,
        Length,
        &urlZone);
      if ( v18 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v18);
      pData = currentUrl.pData;
    }
    v20 = (void *)((unsigned int)pData & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pData & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  }
}
