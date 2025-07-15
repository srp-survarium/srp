Scaleform::Render::SystemVertexFormat *__thiscall Scaleform::Render::SystemVertexFormat::`scalar deleting destructor'(
        Scaleform::Render::SystemVertexFormat *this,
        char a2)
{
  Scaleform::Render::SystemVertexFormat::~SystemVertexFormat(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
