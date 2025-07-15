Scaleform::Render::D3D1x::RenderTargetData *__thiscall Scaleform::Render::D3D1x::RenderTargetData::`vector deleting destructor'(
        Scaleform::Render::D3D1x::RenderTargetData *this,
        char a2)
{
  Scaleform::Render::D3D1x::RenderTargetData::~RenderTargetData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
