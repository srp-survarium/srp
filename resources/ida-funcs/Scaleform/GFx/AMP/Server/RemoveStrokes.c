void __thiscall Scaleform::GFx::AMP::Server::RemoveStrokes(Scaleform::GFx::AMP::Server *this, unsigned int numStrokes)
{
  InterlockedExchangeAdd((volatile LONG *)&this->Profiling, -numStrokes);
}
