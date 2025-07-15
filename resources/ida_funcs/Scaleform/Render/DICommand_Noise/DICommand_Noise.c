void __thiscall Scaleform::Render::DICommand_Noise::DICommand_Noise(
        Scaleform::Render::DICommand_Noise *this,
        const Scaleform::Render::DICommand_Noise *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx

  this->__vftable = (Scaleform::Render::DICommand_Noise_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_Noise_vtbl *)&Scaleform::Render::DICommand_Noise::`vftable';
  this->RandomSeed = __that->RandomSeed;
  this->Low = __that->Low;
  this->High = __that->High;
  this->ChannelMask = __that->ChannelMask;
  this->GrayScale = __that->GrayScale;
}
