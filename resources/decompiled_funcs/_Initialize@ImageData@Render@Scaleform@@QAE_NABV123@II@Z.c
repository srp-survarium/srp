char __thiscall Scaleform::Render::ImageData::Initialize(
        Scaleform::Render::ImageData *this,
        const Scaleform::Render::ImageData *source,
        unsigned int levelIndex,
        unsigned int levelCount)
{
  unsigned int v4; // edi
  Scaleform::Render::ImageFormat Format; // ebx
  char result; // al
  unsigned int v8; // edi
  int v9; // ebx
  __int32 v10; // eax
  __int32 v11; // eax
  int v12; // eax
  int v13; // ecx

  v4 = levelCount;
  if ( !levelCount )
    v4 = source->LevelCount - levelIndex;
  if ( !levelIndex || (source->Flags & 1) != 0 )
  {
    v10 = source->Format & 0xFFF;
    if ( v10 )
    {
      v11 = v10 - 200;
      if ( v11 )
      {
        if ( v11 == 1 )
          v12 = 4;
        else
          v12 = 1;
      }
      else
      {
        v12 = 3;
      }
    }
    else
    {
      v12 = 0;
    }
    v13 = v4;
    if ( (source->Flags & 1) == 0 )
      v13 = 1;
    Scaleform::Render::ImageData::Initialize(
      this,
      source->Format,
      v4,
      &source->pPlanes[levelIndex * v12],
      v12 * v13,
      source->Flags & 1);
    return 1;
  }
  Format = source->Format;
  Scaleform::Render::ImageData::Clear(this);
  result = Scaleform::Render::ImageData::allocPlanes(this, Format, v4, 0);
  if ( !result )
    return result;
  v8 = 0;
  if ( !source->RawPlaneCount )
    return 1;
  v9 = 0;
  do
  {
    Scaleform::Render::ImagePlane::GetMipLevel(
      &source->pPlanes[v9],
      source->Format,
      levelIndex,
      &this->pPlanes[v9],
      v8++);
    ++v9;
  }
  while ( v8 < source->RawPlaneCount );
  return 1;
}
