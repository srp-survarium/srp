void __thiscall Scaleform::GFx::AMP::Server::IncrementFontThrashing(Scaleform::GFx::AMP::Server *this)
{
  InterlockedExchangeAdd((volatile LONG *)&this->SoundMemory, 1);
}
