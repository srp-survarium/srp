void __thiscall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
        Scaleform::Render::DICommand_PerlinNoise *this,
        const Scaleform::Render::DICommand_PerlinNoise *other)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  unsigned int v4; // eax

  this->__vftable = (Scaleform::Render::DICommand_PerlinNoise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = other->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = other->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_PerlinNoise_vtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable';
  this->FrequencyX = other->FrequencyX;
  this->FrequencyY = other->FrequencyY;
  this->NumOctaves = other->NumOctaves;
  this->RandomSeed = other->RandomSeed;
  this->Stitch = other->Stitch;
  this->FractalNoise = other->FractalNoise;
  this->ChannelMask = other->ChannelMask;
  this->GrayScale = other->GrayScale;
  this->OffsetCount = other->OffsetCount;
  if ( other->OffsetCount )
  {
    v4 = 4 * other->OffsetCount;
    if ( v4 > 0x80 )
      v4 = 128;
    memcpy((unsigned __int8 *)this->Offsets, (unsigned __int8 *)other->Offsets, v4);
  }
}


void __thiscall Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
        Scaleform::Render::DICommand_PerlinNoise *this,
        Scaleform::Render::DrawableImage *image,
        float frequencyX,
        float frequencyY,
        unsigned int octaves,
        unsigned int seed,
        bool stitch,
        bool fractal,
        unsigned int channels,
        bool grayScale,
        float *offsets,
        unsigned int offsetCount)
{
  unsigned int v13; // ecx

  this->__vftable = (Scaleform::Render::DICommand_PerlinNoise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( image )
    image->AddRef(image);
  this->pImage.pObject = image;
  this->FrequencyX = frequencyX;
  this->NumOctaves = octaves;
  this->FrequencyY = frequencyY;
  this->RandomSeed = seed;
  this->FractalNoise = fractal;
  this->Stitch = stitch;
  this->ChannelMask = channels;
  this->__vftable = (Scaleform::Render::DICommand_PerlinNoise_vtbl *)&Scaleform::Render::DICommand_PerlinNoise::`vftable';
  this->GrayScale = grayScale;
  v13 = offsetCount;
  if ( offsetCount >= 0x10 )
    v13 = 16;
  this->OffsetCount = v13;
  if ( offsetCount )
    memcpy((unsigned __int8 *)this->Offsets, (unsigned __int8 *)offsets, 4 * offsetCount);
}
