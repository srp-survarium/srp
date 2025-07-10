signed int __thiscall Scaleform::Render::LFSR::Next(Scaleform::Render::LFSR *this, int lfsr)
{
  unsigned int v2; // edx
  unsigned int MaximumOutput; // ecx
  signed int result; // eax

  v2 = Scaleform::Render::LFSR::FeedbackPoly[this->FeedbackIndex];
  MaximumOutput = this->MaximumOutput;
  result = lfsr;
  do
    result = v2 & -(result & 1) ^ (result >> 1);
  while ( result > MaximumOutput );
  return result;
}
