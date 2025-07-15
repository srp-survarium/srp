void __thiscall Scaleform::Render::Text::LineBuffer::GlyphIterator::UpdateDesc(
        Scaleform::Render::Text::LineBuffer::GlyphIterator *this)
{
  Scaleform::Render::Text::ImageDesc *pObject; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  unsigned __int16 Flags; // ax
  Scaleform::GFx::Resource **pNextFormatData; // edx
  Scaleform::GFx::Resource *v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v8; // edx
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *v9; // eax
  unsigned int ColorV; // ecx
  Scaleform::Render::Text::ImageDesc *pImage; // edi
  Scaleform::Render::Text::ImageDesc *v12; // ecx
  unsigned int v13; // edx
  unsigned __int8 v14; // al
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v15; // edx
  Scaleform::Render::Color result; // [esp+8h] [ebp-4h] BYREF

  pObject = this->pImage.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pImage.pObject = 0;
  pGlyphs = this->pGlyphs;
  if ( this->pGlyphs && pGlyphs < this->pEndGlyphs )
  {
    Flags = pGlyphs->Flags;
    if ( (Flags & 0x4000) != 0 )
    {
      if ( (Flags & 0x2000) != 0 )
      {
        pNextFormatData = (Scaleform::GFx::Resource **)this->pNextFormatData;
        v6 = *pNextFormatData;
        if ( *pNextFormatData )
          Scaleform::RefCountImpl::AddRef(*pNextFormatData);
        v7 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
        if ( v7 )
          Scaleform::RefCountImpl::Release(v7);
        this->pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)v6;
        ++this->pNextFormatData;
      }
      v8 = this->pGlyphs;
      if ( (this->pGlyphs->Flags & 0x1000) != 0 )
      {
        v9 = this->pNextFormatData;
        ColorV = v9->ColorV;
        this->ColorV = v9->ColorV;
        this->OrigColor = ColorV;
        this->pNextFormatData = v9 + 1;
      }
      if ( (v8->Flags & 0x800) != 0 )
      {
        pImage = this->pNextFormatData->pImage;
        if ( pImage )
          ++pImage->RefCount;
        v12 = this->pImage.pObject;
        if ( v12 )
          Scaleform::RefCountNTSImpl::Release(v12);
        this->pImage.pObject = pImage;
        ++this->pNextFormatData;
      }
    }
    if ( (this->pGlyphs->Flags & 0x400) != 0 )
    {
      v13 = this->ColorV;
      this->UnderlineStyle = Underline_Single;
      this->UnderlineColor = v13;
    }
    else
    {
      this->UnderlineStyle = Underline_None;
    }
    if ( Scaleform::Render::Text::HighlighterPosIterator::IsFinished(&this->HighlighterIter) )
    {
      v15 = this->pGlyphs;
      this->SelectionColor = 0;
      if ( (v15->Flags & 0x400) != 0 )
      {
        this->UnderlineColor = this->ColorV;
        this->UnderlineStyle = Underline_Single;
      }
    }
    else
    {
      this->ColorV = this->OrigColor;
      if ( (this->pGlyphs->LenAndFontSize & 0xF000) != 0 || (this->pGlyphs->Flags & 8) != 0 )
      {
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 0x10) != 0 )
          this->ColorV = Scaleform::Render::Text::HighlightInfo::GetTextColor(
                           &this->HighlighterIter.CurDesc.Info,
                           &result)->Raw;
        v14 = this->HighlighterIter.CurDesc.Info.Flags;
        if ( (v14 & 7) != 0 )
          this->UnderlineStyle = v14 & 7;
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 0x20) != 0 )
          this->UnderlineColor = Scaleform::Render::Text::HighlightInfo::GetUnderlineColor(
                                   &this->HighlighterIter.CurDesc.Info,
                                   &result)->Raw;
        else
          this->UnderlineColor = this->ColorV;
        if ( (this->HighlighterIter.CurDesc.Info.Flags & 8) != 0 )
          this->SelectionColor = Scaleform::Render::Text::HighlightInfo::GetBackgroundColor(
                                   &this->HighlighterIter.CurDesc.Info,
                                   &result)->Raw;
        else
          this->SelectionColor = 0;
      }
    }
  }
}
