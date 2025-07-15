void __thiscall Scaleform::GFx::AMP::Server::IncrementFontFailures(Scaleform::GFx::AMP::Server *this)
{
  InterlockedExchangeAdd((volatile LONG *)&this->NumStrokes, 1);
}
