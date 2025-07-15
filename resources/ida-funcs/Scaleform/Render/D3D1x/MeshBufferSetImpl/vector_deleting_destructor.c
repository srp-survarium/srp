Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *__thiscall Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vector deleting destructor'(
        Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *this,
        char a2)
{
  Scaleform::Render::D3D1x::MeshBufferSet::~MeshBufferSet(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
