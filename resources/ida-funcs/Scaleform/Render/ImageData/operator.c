Scaleform::Render::ImageData *__thiscall Scaleform::Render::ImageData::operator=(
        Scaleform::Render::ImageData *this,
        const Scaleform::Render::ImageData *rhs)
{
  unsigned __int8 Flags; // al
  Scaleform::Render::ImagePlane *pPlanes; // edx
  Scaleform::Render::ImagePlane *p_Plane0; // ebx
  Scaleform::Render::Palette *pObject; // eax
  Scaleform::Render::Palette *v8; // ebp
  int v9; // edx
  Scaleform::Render::ImagePlane *v10; // eax
  unsigned int v11; // ecx
  unsigned int Height; // ebp
  unsigned int Width; // ebx
  Scaleform::Render::ImagePlane *v14; // eax
  unsigned int DataSize; // ebp
  Scaleform::Render::ImagePlane *v16; // eax
  unsigned __int8 *pData; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-4h]
  unsigned int Pitch; // [esp+20h] [ebp+4h]

  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
  {
    pPlanes = this->pPlanes;
    this->Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pPlanes);
  }
  p_Plane0 = &this->Plane0;
  this->pPlanes = &this->Plane0;
  this->Format = rhs->Format;
  this->Use = rhs->Use;
  this->Flags = rhs->Flags;
  this->LevelCount = rhs->LevelCount;
  this->RawPlaneCount = rhs->RawPlaneCount;
  pObject = rhs->pPalette.pObject;
  if ( pObject )
    InterlockedExchangeAdd(&pObject->RefCount.Value, 1);
  v8 = this->pPalette.pObject;
  if ( v8 && InterlockedExchangeAdd(&v8->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  this->pPalette.pObject = rhs->pPalette.pObject;
  p_Plane0->Width = rhs->Plane0.Width;
  this->Plane0.Height = rhs->Plane0.Height;
  this->Plane0.Pitch = rhs->Plane0.Pitch;
  this->Plane0.DataSize = rhs->Plane0.DataSize;
  this->Plane0.pData = rhs->Plane0.pData;
  if ( (rhs->Flags & 2) == 0 )
  {
    this->pPlanes = p_Plane0;
    return this;
  }
  this->Flags &= ~2u;
  Scaleform::Render::ImageData::allocPlanes(this, this->Format, this->LevelCount, this->Flags & 1);
  v9 = 0;
  if ( !rhs->RawPlaneCount )
    return this;
  do
  {
    v10 = rhs->pPlanes;
    v11 = (unsigned __int16)v9;
    Height = v10[v11].Height;
    Width = v10[v11].Width;
    v14 = &v10[v11];
    v19 = Height;
    pData = v14->pData;
    DataSize = v14->DataSize;
    Pitch = v14->Pitch;
    v16 = &this->pPlanes[v11];
    v16->Height = v19;
    v16->Pitch = Pitch;
    ++v9;
    v16->Width = Width;
    v16->DataSize = DataSize;
    v16->pData = pData;
  }
  while ( (unsigned __int16)v9 < rhs->RawPlaneCount );
  return this;
}
