void __thiscall Scaleform::Render::Text::Allocator::Allocator(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::MemoryHeap *pheap,
        unsigned __int8 flags)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::Text::Allocator_vtbl *)&Scaleform::Render::Text::Allocator::`vftable';
  this->TextFormatStorage.pTable = 0;
  this->ParagraphFormatStorage.pTable = 0;
  this->TextFormatStorageCap = 100;
  this->ParagraphFormatStorageCap = 100;
  this->NewParagraphId = 1;
  this->pHeap = pheap;
  this->EntryTextFormat.RefCount = 1;
  Scaleform::StringDH::StringDH(&this->EntryTextFormat.FontList, pheap);
  Scaleform::StringDH::StringDH(&this->EntryTextFormat.Url, pheap);
  this->EntryTextFormat.pImageDesc.pObject = 0;
  this->EntryTextFormat.pFontHandle.pObject = 0;
  this->EntryTextFormat.LetterSpacing = 0;
  this->EntryTextFormat.FormatFlags = 0;
  this->EntryTextFormat.ColorV = -16777216;
  this->EntryTextFormat.FontSize = 0;
  this->EntryTextFormat.PresentMask = 0;
  this->Flags = flags;
}
