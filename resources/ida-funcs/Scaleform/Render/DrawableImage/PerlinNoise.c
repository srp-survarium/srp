void __thiscall Scaleform::Render::DrawableImage::PerlinNoise(
        Scaleform::Render::DrawableImage *this,
        float frequencyX,
        float frequencyY,
        unsigned int numOctaves,
        unsigned int randomSeed,
        bool stitch,
        bool fractal,
        unsigned int channelMask,
        bool grayScale,
        float *offsets,
        unsigned int offsetCount)
{
  Scaleform::Render::DICommand_PerlinNoise *v12; // eax
  Scaleform::Render::DICommand_PerlinNoise v13; // [esp+2Ch] [ebp-A8h] BYREF

  Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
    &v13,
    this,
    frequencyX,
    frequencyY,
    numOctaves,
    randomSeed,
    stitch,
    fractal,
    channelMask,
    grayScale,
    (const __m128i *)offsets,
    offsetCount);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PerlinNoise>(this, v12);
  v13.__vftable = (Scaleform::Render::DICommand_PerlinNoise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v13.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_PerlinNoise_vtbl *))v13.pImage.pObject->Release)(v13.__vftable);
}
