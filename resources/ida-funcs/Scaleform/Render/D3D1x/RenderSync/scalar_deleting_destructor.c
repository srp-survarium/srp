Scaleform::Render::D3D1x::RenderSync *__thiscall Scaleform::Render::D3D1x::RenderSync::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::RenderSync *this,
        char a2)
{
  Scaleform::Render::D3D1x::RenderSync::~RenderSync(this, this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
