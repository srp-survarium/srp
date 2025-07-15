char __thiscall Scaleform::Render::ImageData::allocPlanes(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageFormat format,
        unsigned int mipLevelCount,
        bool separateMipmaps)
{
  int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // ebp
  Scaleform::MemoryHeap *v8; // eax
  Scaleform::Render::ImagePlane *v9; // eax

  if ( (format & 0xFFF) != 0 )
  {
    if ( (format & 0xFFF) == 0xC8 )
    {
      v5 = 3;
    }
    else if ( (format & 0xFFF) == 0xC9 )
    {
      v5 = 4;
    }
    else
    {
      v5 = 1;
    }
  }
  else
  {
    v5 = 0;
  }
  v6 = mipLevelCount;
  if ( !separateMipmaps )
    v6 = 1;
  v7 = v5 * v6;
  if ( v7 > 1 )
  {
    if ( (this->Flags & 4) != 0 )
      v8 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    else
      v8 = Scaleform::Memory::pGlobalHeap;
    v9 = (Scaleform::Render::ImagePlane *)v8->Alloc(v8, 20 * v7, 0);
    this->pPlanes = v9;
    if ( !v9 )
    {
      this->RawPlaneCount = 1;
      this->pPlanes = &this->Plane0;
      return 0;
    }
    memset((int)v9, 0, 20 * v7);
    this->Flags |= 2u;
  }
  this->Format = format;
  this->RawPlaneCount = v7;
  this->LevelCount = mipLevelCount;
  if ( separateMipmaps )
    this->Flags |= 1u;
  return 1;
}
