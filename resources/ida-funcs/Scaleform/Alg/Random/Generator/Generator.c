void __thiscall Scaleform::Alg::Random::Generator::Generator(Scaleform::Alg::Random::Generator *this)
{
  DWORD TicksMs; // eax

  this->C = (unsigned int)&loc_587C4;
  this->I = 7;
  TicksMs = Scaleform::Timer::GetTicksMs();
  Scaleform::Alg::Random::Generator::SeedRandom(this, TicksMs);
}
