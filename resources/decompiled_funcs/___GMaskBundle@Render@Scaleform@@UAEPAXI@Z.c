Scaleform::Render::MaskBundle *__thiscall Scaleform::Render::MaskBundle::`scalar deleting destructor'(
        Scaleform::Render::MaskBundle *this,
        char a2)
{
  Scaleform::Render::MaskBundle::~MaskBundle(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
