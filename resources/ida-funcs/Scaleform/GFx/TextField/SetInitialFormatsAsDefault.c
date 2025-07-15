void __thiscall Scaleform::GFx::TextField::SetInitialFormatsAsDefault(Scaleform::GFx::TextField *this)
{
  Scaleform::MemoryHeap *v2; // edi
  Scaleform::GFx::TextFieldDef *pObject; // ecx
  Scaleform::Render::Text::DocView *v4; // eax
  Scaleform::Render::Text::DocView::DocumentText *v5; // eax
  Scaleform::Render::Text::TextFormat *v6; // edi
  Scaleform::Render::Text::ParagraphFormat *v7; // ebp
  const Scaleform::Render::Text::TextFormat *v8; // eax
  const Scaleform::Render::Text::ParagraphFormat *v9; // eax
  Scaleform::MemoryHeap *v10; // eax
  const Scaleform::Render::Text::TextFormat *v11; // eax
  const Scaleform::Render::Text::ParagraphFormat *v12; // eax
  Scaleform::Render::Text::DocView *v13; // ecx
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [esp+10h] [ebp-A0h] BYREF
  Scaleform::Render::Text::ParagraphFormat v15; // [esp+24h] [ebp-8Ch] BYREF
  Scaleform::Render::Text::TextFormat ptextFmt; // [esp+38h] [ebp-78h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+60h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat v18; // [esp+88h] [ebp-28h] BYREF

  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  ptextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&ptextFmt.FontList, v2);
  Scaleform::StringDH::StringDH(&ptextFmt.Url, v2);
  ptextFmt.FontSize = 0;
  pObject = this->pDef.pObject;
  ptextFmt.LetterSpacing = 0;
  ptextFmt.PresentMask = 0;
  v4 = this->pDocument.pObject;
  ptextFmt.pImageDesc.pObject = 0;
  ptextFmt.pFontHandle.pObject = 0;
  ptextFmt.ColorV = -16777216;
  ptextFmt.FormatFlags = 0;
  pparaFmt.RefCount = 1;
  memset(&pparaFmt.pTabStops, 0, 16);
  v5 = v4->pDocument.pObject;
  v6 = v5->pDefaultTextFormat.pObject;
  v7 = v5->pDefaultParagraphFormat.pObject;
  if ( (pObject->Flags & 0x800) != 0 )
  {
    if ( v6 )
      Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v5->pDefaultTextFormat.pObject);
    if ( v7 )
      Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v7);
    v10 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&result, v10);
    v15.RefCount = 1;
    memset(&v15.pTabStops, 0, 16);
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&result);
    Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&v15);
    v11 = Scaleform::Render::Text::TextFormat::Merge(&result, &v18, &ptextFmt);
    Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v11);
    Scaleform::Render::Text::TextFormat::~TextFormat(&v18);
    v12 = Scaleform::Render::Text::ParagraphFormat::Merge(
            &v15,
            (Scaleform::Render::Text::ParagraphFormat *)&v18,
            &pparaFmt);
    Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v12);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&v18);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&v15);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
  }
  else
  {
    Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
    if ( v6 )
    {
      v8 = Scaleform::Render::Text::TextFormat::Merge(v6, &result, &ptextFmt);
      Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v8);
      Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    }
    if ( v7 )
    {
      v9 = Scaleform::Render::Text::ParagraphFormat::Merge(v7, &v15, &pparaFmt);
      Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v9);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&v15);
    }
  }
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject->pDocument.pObject, &ptextFmt);
  v13 = this->pDocument.pObject;
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(v13->pDocument.pObject, &pparaFmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&pparaFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
}
