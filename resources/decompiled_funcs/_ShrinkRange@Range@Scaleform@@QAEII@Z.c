unsigned int __thiscall Scaleform::Range::ShrinkRange(Scaleform::Range *this, unsigned int lengthDelta)
{
  unsigned int Length; // eax
  unsigned int result; // eax

  Length = this->Length;
  if ( lengthDelta <= Length )
  {
    result = Length - lengthDelta;
    this->Length = result;
  }
  else
  {
    this->Length = 0;
    return this->Length;
  }
  return result;
}
