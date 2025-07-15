void __thiscall Scaleform::Render::ImageData::Clear(Scaleform::Render::ImageData *this)
{
  unsigned __int8 Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // edx
  Scaleform::Render::Palette *pObject; // ebp

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
  }
  this->Flags &= ~4u;
  this->pPlanes = &this->Plane0;
  this->Format = Image_None;
  this->Use = 0;
  this->LevelCount = 0;
  this->RawPlaneCount = 1;
  pObject = this->pPalette.pObject;
  if ( pObject && InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  this->pPalette.pObject = 0;
  this->Plane0.Width = 0;
  this->Plane0.Height = 0;
  this->Plane0.Pitch = 0;
  this->Plane0.DataSize = 0;
  this->Plane0.pData = 0;
}
