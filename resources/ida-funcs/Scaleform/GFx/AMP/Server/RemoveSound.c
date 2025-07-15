void __thiscall Scaleform::GFx::AMP::Server::RemoveSound(Scaleform::GFx::AMP::Server *this, unsigned int soundMem)
{
  InterlockedExchangeAdd((volatile LONG *)&this->SocketFactory, -soundMem);
}
