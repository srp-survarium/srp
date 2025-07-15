char __thiscall Scaleform::GFx::SpriteDef::GetLabeledFrame(
        Scaleform::GFx::SpriteDef *this,
        char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
}
