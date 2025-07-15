Scaleform::Render::Text::Paragraph *__thiscall Scaleform::Render::Text::Allocator::AllocateParagraph(
        Scaleform::Render::Text::Allocator *this)
{
  Scaleform::Render::Text::Paragraph *result; // eax
  unsigned int NewParagraphId; // ecx

  result = (Scaleform::Render::Text::Paragraph *)this->pHeap->Alloc(this->pHeap, 40, 0);
  if ( !result )
    return 0;
  result->Text.pText = 0;
  result->Text.Size = 0;
  result->Text.Allocated = 0;
  result->pFormat.pObject = 0;
  result->FormatInfo.Ranges.Data.Data = 0;
  result->FormatInfo.Ranges.Data.Size = 0;
  result->FormatInfo.Ranges.Data.Policy.Capacity = 0;
  result->StartIndex = 0;
  result->ModCounter = 0;
  NewParagraphId = this->NewParagraphId;
  this->NewParagraphId = NewParagraphId + 1;
  result->UniqueId = NewParagraphId;
  return result;
}
