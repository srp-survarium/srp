void __thiscall Scaleform::Render::DrawableImage::Noise(
        Scaleform::Render::DrawableImage *this,
        unsigned int randomSeed,
        unsigned int low,
        unsigned int high,
        unsigned int channelMask,
        bool grayscale)
{
  Scaleform::Render::DICommand_Noise cmd; // [esp+4h] [ebp-1Ch] BYREF

  cmd.__vftable = (Scaleform::Render::DICommand_Noise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( this )
    this->AddRef(this);
  cmd.Low = low;
  cmd.High = high;
  cmd.RandomSeed = randomSeed;
  cmd.GrayScale = grayscale;
  cmd.pImage.pObject = this;
  cmd.__vftable = (Scaleform::Render::DICommand_Noise_vtbl *)&Scaleform::Render::DICommand_Noise::`vftable';
  cmd.ChannelMask = channelMask;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Noise>(this, &cmd);
  cmd.__vftable = (Scaleform::Render::DICommand_Noise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_Noise_vtbl *))cmd.pImage.pObject->Release)(cmd.__vftable);
}
