void __thiscall Scaleform::Render::Text::StyledText::StyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::Allocator *pallocator)
{
  Scaleform::Render::Text::ParagraphFormat *v4; // eax
  Scaleform::Render::Text::ParagraphFormat *pObject; // ebp
  bool v6; // zf
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  Scaleform::Render::Text::TextFormat *v8; // edi
  Scaleform::Render::Text::TextFormat *v9; // ebp
  Scaleform::Render::Text::ParagraphFormat srcfmt; // [esp+10h] [ebp-14h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v11; // [esp+28h] [ebp+4h]

  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::StyledText_vtbl *)&Scaleform::Render::Text::StyledText::`vftable';
  if ( pallocator )
    ++pallocator->RefCount;
  this->pTextAllocator.pObject = pallocator;
  srcfmt.RefCount = 1;
  this->Paragraphs.Data.Data = 0;
  this->Paragraphs.Data.Size = 0;
  this->Paragraphs.Data.Policy.Capacity = 0;
  srcfmt.BlockIndent = 0;
  srcfmt.LeftMargin = 0;
  this->pDefaultParagraphFormat.pObject = 0;
  srcfmt.Indent = 0;
  srcfmt.RightMargin = 0;
  this->pDefaultTextFormat.pObject = 0;
  this->RTFlags = 0;
  srcfmt.pTabStops = 0;
  srcfmt.Leading = 0;
  srcfmt.PresentMask = 0;
  v4 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, &srcfmt);
  pObject = this->pDefaultParagraphFormat.pObject;
  v11 = v4;
  if ( pObject )
  {
    v6 = pObject->RefCount-- == 1;
    if ( v6 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pDefaultParagraphFormat.pObject = v11;
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&srcfmt);
  TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, &pallocator->EntryTextFormat);
  v8 = this->pDefaultTextFormat.pObject;
  v9 = TextFormat;
  if ( v8 )
  {
    v6 = v8->RefCount-- == 1;
    if ( v6 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v8);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  this->pDefaultTextFormat.pObject = v9;
}
