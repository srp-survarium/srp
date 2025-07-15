Scaleform::Render::MaskEffect *__userpurge Scaleform::Render::MaskEffect::`vector deleting destructor'@<eax>(
        Scaleform::Render::MaskEffect *this@<ecx>,
        int a2@<edi>,
        char a3)
{
  Scaleform::Render::MaskEffect::~MaskEffect(this, a2);
  if ( (a3 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
