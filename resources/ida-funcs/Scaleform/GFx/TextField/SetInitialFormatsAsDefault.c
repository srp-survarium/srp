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
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [esp+10h] [ebp-A0h] BYREF
  Scaleform::Render::Text::ParagraphFormat eParagraphFmt; // [esp+24h] [ebp-8Ch] BYREF
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [esp+38h] [ebp-78h] BYREF
  Scaleform::Render::Text::TextFormat eTextFmt; // [esp+60h] [ebp-50h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+88h] [ebp-28h] BYREF

  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  defaultTextFmt.RefCount = 1;
  Scaleform::StringDH::StringDH(&defaultTextFmt.FontList, v2);
  Scaleform::StringDH::StringDH(&defaultTextFmt.Url, v2);
  defaultTextFmt.FontSize = 0;
  pObject = this->pDef.pObject;
  defaultTextFmt.LetterSpacing = 0;
  defaultTextFmt.PresentMask = 0;
  v4 = this->pDocument.pObject;
  defaultTextFmt.pImageDesc.pObject = 0;
  defaultTextFmt.pFontHandle.pObject = 0;
  defaultTextFmt.ColorV = -16777216;
  defaultTextFmt.FormatFlags = 0;
  defaultParagraphFmt.RefCount = 1;
  memset(&defaultParagraphFmt.pTabStops, 0, 16);
  v5 = v4->pDocument.pObject;
  v6 = v5->pDefaultTextFormat.pObject;
  v7 = v5->pDefaultParagraphFormat.pObject;
  if ( (pObject->Flags & 0x800) != 0 )
  {
    if ( v6 )
      Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v5->pDefaultTextFormat.pObject);
    if ( v7 )
      Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, v7);
    v10 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&eTextFmt, v10);
    eParagraphFmt.RefCount = 1;
    memset(&eParagraphFmt.pTabStops, 0, 16);
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&eTextFmt);
    Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&eParagraphFmt);
    v11 = Scaleform::Render::Text::TextFormat::Merge(&eTextFmt, &result, &defaultTextFmt);
    Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v11);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    v12 = Scaleform::Render::Text::ParagraphFormat::Merge(
            &eParagraphFmt,
            (Scaleform::Render::Text::ParagraphFormat *)&result,
            &defaultParagraphFmt);
    Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, v12);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops((Scaleform::Render::Text::ParagraphFormat *)&result);
    Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&eParagraphFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&eTextFmt);
  }
  else
  {
    Scaleform::GFx::TextField::GetInitialFormats(this, &defaultTextFmt, &defaultParagraphFmt);
    if ( v6 )
    {
      v8 = Scaleform::Render::Text::TextFormat::Merge(v6, &eTextFmt, &defaultTextFmt);
      Scaleform::Render::Text::TextFormat::operator=(&defaultTextFmt, v8);
      Scaleform::Render::Text::TextFormat::~TextFormat(&eTextFmt);
    }
    if ( v7 )
    {
      v9 = Scaleform::Render::Text::ParagraphFormat::Merge(v7, &eParagraphFmt, &defaultParagraphFmt);
      Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, v9);
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&eParagraphFmt);
    }
  }
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject->pDocument.pObject, &defaultTextFmt);
  v13 = this->pDocument.pObject;
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(v13->pDocument.pObject, &defaultParagraphFmt);
  this->Flags |= (unsigned int)&_sbh_sizeHeaderList;
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&defaultParagraphFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
}
