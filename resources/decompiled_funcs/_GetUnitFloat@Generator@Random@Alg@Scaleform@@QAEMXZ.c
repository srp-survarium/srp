double __thiscall Scaleform::Alg::Random::Generator::GetUnitFloat(Scaleform::Alg::Random::Generator *this)
{
  unsigned int v1; // esi
  __int64 v2; // rax
  int v3; // edi

  v1 = ((unsigned __int8)this->I + 1) & 7;
  this->I = v1;
  v2 = this->C + 716514398LL * this->Q[v1];
  v3 = HIDWORD(v2) + v2;
  this->C = HIDWORD(v2);
  if ( (unsigned int)(HIDWORD(v2) + v2) < HIDWORD(v2) )
  {
    ++v3;
    this->C = HIDWORD(v2) + 1;
  }
  this->Q[v1] = -2 - v3;
  return (float)((double)((unsigned int)(-2 - v3) >> 8) / 16777215.0);
}
