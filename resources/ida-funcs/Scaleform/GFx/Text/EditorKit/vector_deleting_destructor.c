Scaleform::GFx::Text::EditorKit *__thiscall Scaleform::GFx::Text::EditorKit::`vector deleting destructor'(
        Scaleform::GFx::Text::EditorKit *this,
        char a2)
{
  Scaleform::GFx::Text::EditorKit::~EditorKit(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
