Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *__thiscall Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Classes::fl_geom::Vector3D *this,
        char a2)
{
  Scaleform::GFx::AS3::Classes::fl_geom::Vector3D::~Vector3D(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
