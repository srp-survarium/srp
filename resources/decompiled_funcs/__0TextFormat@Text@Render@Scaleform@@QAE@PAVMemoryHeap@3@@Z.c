void __thiscall Scaleform::Render::Text::TextFormat::TextFormat(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::MemoryHeap *pheap)
{
  this->RefCount = 1;
  Scaleform::StringDH::StringDH(&this->FontList, pheap);
  Scaleform::StringDH::StringDH(&this->Url, pheap);
  this->pImageDesc.pObject = 0;
  this->pFontHandle.pObject = 0;
  this->FormatFlags = 0;
  this->PresentMask = 0;
  this->ColorV = -16777216;
  this->LetterSpacing = 0;
  this->FontSize = 0;
}
