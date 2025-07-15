Scaleform::GFx::AS3::Instances::fl_text::TextFormat *__thiscall Scaleform::GFx::AS3::Instances::fl_text::TextFormat::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *this,
        char a2)
{
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat::~TextFormat(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
