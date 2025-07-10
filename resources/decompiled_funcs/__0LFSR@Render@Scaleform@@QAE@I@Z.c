void __thiscall Scaleform::Render::LFSR::LFSR(Scaleform::Render::LFSR *this, unsigned int maximum)
{
  this->MaximumOutput = maximum;
  this->FeedbackIndex = 0;
  if ( maximum > 1 )
  {
    do
      ++this->FeedbackIndex;
    while ( this->MaximumOutput > 1 << this->FeedbackIndex );
  }
}
