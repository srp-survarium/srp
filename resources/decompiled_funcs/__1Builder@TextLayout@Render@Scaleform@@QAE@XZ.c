void __thiscall Scaleform::Render::TextLayout::Builder::~Builder(Scaleform::Render::TextLayout::Builder *this)
{
  Scaleform::Render::TextLayout::Builder *Data; // eax
  Scaleform::RefCountImpl **Static; // edi

  Data = (Scaleform::Render::TextLayout::Builder *)this->RefCntData.Data;
  Static = this->RefCntData.Static;
  if ( Data != (Scaleform::Render::TextLayout::Builder *)this->RefCntData.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  this->RefCntData.Data = Static;
  this->RefCntData.Size = 0;
  if ( this->Images.Data != this->Images.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Images.Data);
  this->Images.Data = this->Images.Static;
  this->Images.Size = 0;
  if ( this->Fonts.Data != this->Fonts.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Fonts.Data);
  this->Fonts.Data = this->Fonts.Static;
  this->Fonts.Size = 0;
  if ( this->Data.Data != this->Data.Static )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data);
  this->Data.Data = this->Data.Static;
  this->Data.Size = 0;
}
