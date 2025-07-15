void __thiscall Scaleform::GFx::AMP::Server::AddStrokes(Scaleform::GFx::AMP::Server *this, LONG numStrokes)
{
  InterlockedExchangeAdd((volatile LONG *)&this->Profiling, numStrokes);
}
