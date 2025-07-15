Scaleform::GFx::AS3::AvmTextField::CSSHolder *__thiscall Scaleform::GFx::AS3::AvmTextField::CSSHolder::`scalar deleting destructor'(
        Scaleform::GFx::AS3::AvmTextField::CSSHolder *this,
        char a2)
{
  Scaleform::GFx::AS3::AvmTextField::CSSHolder::~CSSHolder(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
