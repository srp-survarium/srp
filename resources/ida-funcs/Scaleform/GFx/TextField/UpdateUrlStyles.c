void __thiscall Scaleform::GFx::TextField::UpdateUrlStyles(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField::CSSHolderBase *pObject; // eax
  unsigned int Size; // eax
  const Scaleform::Render::Text::StyleManagerBase *v4; // eax
  const Scaleform::Render::Text::TextFormat *v5; // ebp
  const Scaleform::Render::Text::StyleManagerBase *v6; // eax
  const Scaleform::Render::Text::TextFormat *v7; // ebx
  Scaleform::MemoryHeap *v8; // edi
  const Scaleform::Render::Text::TextFormat *v9; // eax
  const Scaleform::Render::Text::TextFormat *v10; // eax
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *Data; // ecx
  unsigned int Index; // ebx
  const Scaleform::Render::Text::Paragraph *v13; // edi
  Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone> *v14; // ebp
  Scaleform::Render::Text::StyledText *v15; // eax
  Scaleform::RefCountNTSImpl *v16; // ecx
  Scaleform::Render::Text::StyledText *v17; // edi
  int v18; // [esp+1Ch] [ebp-58h]
  unsigned int v19; // [esp+20h] [ebp-54h]
  Scaleform::Render::Text::TextFormat fmt; // [esp+24h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+4Ch] [ebp-28h] BYREF

  pObject = this->pCSSData.pObject;
  if ( pObject )
  {
    Size = pObject->UrlZones.Ranges.Data.Size;
    if ( Size )
    {
      v18 = 0;
      v19 = Size;
      do
      {
        if ( this->pCSSData.pObject->HasASStyleSheet(this->pCSSData.pObject) )
        {
          v4 = this->pCSSData.pObject->GetTextStyleManager(this->pCSSData.pObject);
          v5 = (const Scaleform::Render::Text::TextFormat *)v4->GetStyle(v4, CSS_Tag, (const char *)&stru_809F70, -1u);
          v6 = this->pCSSData.pObject->GetTextStyleManager(this->pCSSData.pObject);
          v7 = (const Scaleform::Render::Text::TextFormat *)v6->GetStyle(v6, CSS_Tag, "a:link", -1u);
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
          if ( v5 )
          {
            v9 = Scaleform::Render::Text::TextFormat::Merge(&fmt, &result, v5);
            Scaleform::Render::Text::TextFormat::operator=(&fmt, v9);
            Scaleform::Render::Text::TextFormat::~TextFormat(&result);
          }
          if ( v7 )
          {
            v10 = Scaleform::Render::Text::TextFormat::Merge(&fmt, &result, v7);
            Scaleform::Render::Text::TextFormat::operator=(&fmt, v10);
            Scaleform::Render::Text::TextFormat::~TextFormat(&result);
          }
          Data = this->pCSSData.pObject->UrlZones.Ranges.Data.Data;
          Index = Data[v18].Index;
          v13 = (const Scaleform::Render::Text::Paragraph *)(Index + Data[v18].Length);
          Scaleform::Render::Text::DocView::SetTextFormat(this->pDocument.pObject, &fmt, Index, (unsigned int)v13);
          v14 = &this->pCSSData.pObject->UrlZones.Ranges.Data.Data[v18];
          v15 = Scaleform::Render::Text::StyledText::CopyStyledText(
                  this->pDocument.pObject->pDocument.pObject,
                  Index,
                  v13);
          v16 = v14->Data.SavedFmt.pObject;
          v17 = v15;
          if ( v16 )
            Scaleform::RefCountNTSImpl::Release(v16);
          v14->Data.SavedFmt.pObject = v17;
          Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
        }
        ++v18;
        --v19;
      }
      while ( v19 );
    }
  }
}
