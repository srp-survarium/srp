char __userpurge Scaleform::GFx::SpriteDef::GetLabeledFrame@<al>(
        Scaleform::GFx::SpriteDef *this@<ecx>,
        int a2@<edi>,
        __m128i *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::TranslateFrameString(
           a2,
           &this->NamedFrames,
           label,
           frameNumber,
           translateNumbers);
}
