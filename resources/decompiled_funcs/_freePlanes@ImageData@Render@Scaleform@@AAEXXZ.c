void __thiscall Scaleform::Render::ImageData::freePlanes(Scaleform::Render::ImageData *this)
{
  unsigned __int8 Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // edx

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
    this->pPlanes = &this->Plane0;
  }
  else
  {
    this->pPlanes = &this->Plane0;
  }
}
