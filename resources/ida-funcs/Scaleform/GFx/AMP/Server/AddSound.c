void __thiscall Scaleform::GFx::AMP::Server::AddSound(Scaleform::GFx::AMP::Server *this, LONG soundMem)
{
  InterlockedExchangeAdd((volatile LONG *)&this->SocketFactory, soundMem);
}
