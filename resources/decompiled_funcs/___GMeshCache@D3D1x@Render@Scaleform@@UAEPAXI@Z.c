Scaleform::Render::D3D1x::MeshCache *__thiscall Scaleform::Render::D3D1x::MeshCache::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::MeshCache *this,
        char a2)
{
  Scaleform::Render::D3D1x::MeshCache::~MeshCache(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
