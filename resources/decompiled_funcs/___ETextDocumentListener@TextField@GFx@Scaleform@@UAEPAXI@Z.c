Scaleform::Render::Text::TextFilter *__thiscall Scaleform::GFx::TextField::TextDocumentListener::`vector deleting destructor'(
        Scaleform::Render::Text::TextFilter *this,
        char a2)
{
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
