Scaleform::Render::MatrixState *__thiscall Scaleform::Render::MatrixState::`scalar deleting destructor'(
        Scaleform::Render::MatrixState *this,
        char a2)
{
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
