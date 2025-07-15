unsigned int __thiscall Scaleform::GFx::AMP::ViewStats::GetInstructionTime(
        Scaleform::GFx::AMP::ViewStats *this,
        unsigned int samplePeriod)
{
  unsigned int v2; // edi
  unsigned int RawTicks; // edi
  unsigned int result; // eax
  int v6; // edx
  unsigned int SkipSamples; // eax
  int v8; // edx

  v2 = 0;
  if ( samplePeriod )
  {
    if ( this->LastTimer )
      v2 = (Scaleform::Timer::GetRawTicks() - LODWORD(this->LastTimer)) * samplePeriod;
    SkipSamples = this->SkipSamples;
    if ( SkipSamples )
    {
      this->SkipSamples = SkipSamples - 1;
      result = v2;
      LODWORD(this->LastTimer) = 0;
      HIDWORD(this->LastTimer) = 0;
    }
    else
    {
      LODWORD(this->LastTimer) = Scaleform::Timer::GetRawTicks();
      HIDWORD(this->LastTimer) = v8;
      this->SkipSamples = 2
                        * samplePeriod
                        * (unsigned __int64)Scaleform::Alg::Random::Generator::NextRandom(&this->RandomGen)
                        / 0xFFFFFFFF;
      return v2;
    }
  }
  else
  {
    RawTicks = Scaleform::Timer::GetRawTicks();
    result = RawTicks - LODWORD(this->LastTimer);
    LODWORD(this->LastTimer) = RawTicks;
    HIDWORD(this->LastTimer) = v6;
  }
  return result;
}
