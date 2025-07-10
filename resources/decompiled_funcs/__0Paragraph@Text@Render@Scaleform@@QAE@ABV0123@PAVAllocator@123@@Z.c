void __thiscall Scaleform::Render::Text::Paragraph::Paragraph(
        Scaleform::Render::Text::Paragraph *this,
        const Scaleform::Render::Text::Paragraph *o,
        Scaleform::Render::Text::Allocator *ptextAllocator)
{
  Scaleform::Render::Text::Allocator *v3; // ebx
  wchar_t *v6; // eax
  unsigned int Size; // ecx
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // ebp
  unsigned int v9; // eax
  unsigned int NewParagraphId; // eax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // eax
  Scaleform::Render::Text::ParagraphFormat *pObject; // esi
  bool v13; // zf
  const Scaleform::Render::Text::TextFormat **v14; // esi
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  Scaleform::Render::Text::TextFormat *v16; // ebx
  Scaleform::Render::Text::TextFormat *v17; // ecx
  unsigned int it; // [esp+10h] [ebp-Ch]
  unsigned int it_4; // [esp+14h] [ebp-8h]
  unsigned int v20; // [esp+18h] [ebp-4h]
  Scaleform::Render::Text::TextFormat *v21; // [esp+18h] [ebp-4h]
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *oa; // [esp+20h] [ebp+4h]
  Scaleform::Render::Text::ParagraphFormat *ob; // [esp+20h] [ebp+4h]
  const Scaleform::Render::Text::Paragraph *oc; // [esp+20h] [ebp+4h]

  v3 = ptextAllocator;
  v6 = (wchar_t *)ptextAllocator->pHeap->Alloc(ptextAllocator->pHeap, 2 * o->Text.Size, 0);
  this->Text.pText = v6;
  Size = o->Text.Size;
  this->Text.Size = Size;
  this->Text.Allocated = Size;
  memcpy((unsigned __int8 *)v6, (unsigned __int8 *)o->Text.pText, 2 * o->Text.Size);
  this->pFormat.pObject = 0;
  p_FormatInfo = &this->FormatInfo;
  this->FormatInfo.Ranges.Data.Data = 0;
  this->FormatInfo.Ranges.Data.Size = 0;
  this->FormatInfo.Ranges.Data.Policy.Capacity = 0;
  v9 = o->FormatInfo.Ranges.Data.Size;
  it = v9;
  oa = o->FormatInfo.Ranges.Data.Data;
  if ( v9 )
  {
    v20 = this->FormatInfo.Ranges.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->FormatInfo.Ranges.Data,
      &this->FormatInfo,
      v9 + v20);
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::ConstructArray(
      &p_FormatInfo->Ranges.Data.Data[v20].Index,
      it,
      oa);
  }
  this->StartIndex = o->StartIndex;
  this->ModCounter = 0;
  NewParagraphId = ptextAllocator->NewParagraphId;
  ptextAllocator->NewParagraphId = NewParagraphId + 1;
  this->UniqueId = NewParagraphId;
  ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(ptextAllocator, o->pFormat.pObject);
  pObject = this->pFormat.pObject;
  ob = ParagraphFormat;
  if ( pObject )
  {
    v13 = pObject->RefCount-- == 1;
    if ( v13 )
    {
      Scaleform::Render::Text::ParagraphFormat::FreeTabStops(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->pFormat.pObject = ob;
  it_4 = 0;
  oc = 0;
  while ( (int)oc >= 0 && it_4 < this->FormatInfo.Ranges.Data.Size )
  {
    v14 = (const Scaleform::Render::Text::TextFormat **)((char *)oc + (unsigned int)p_FormatInfo->Ranges.Data.Data);
    TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(v3, v14[2]);
    v16 = TextFormat;
    if ( TextFormat )
      ++TextFormat->RefCount;
    v17 = (Scaleform::Render::Text::TextFormat *)v14[2];
    v21 = v17;
    if ( v17 )
    {
      v13 = v17->RefCount-- == 1;
      if ( v13 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v17);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
      }
    }
    v14[2] = v16;
    if ( v16 )
    {
      v13 = v16->RefCount-- == 1;
      if ( v13 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    v3 = ptextAllocator;
    if ( (signed int)it_4 < (signed int)this->FormatInfo.Ranges.Data.Size )
    {
      ++it_4;
      oc = (const Scaleform::Render::Text::Paragraph *)((char *)oc + 12);
    }
  }
}
