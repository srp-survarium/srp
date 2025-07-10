void Scaleform::Alg::_dynamic_initializer_for__Generator_1__()
{
  DWORD TicksMs; // eax

  TicksMs = Scaleform::Timer::GetTicksMs();
  Scaleform::Alg::Random::Generator::SeedRandom(&Generator_1, TicksMs);
}
