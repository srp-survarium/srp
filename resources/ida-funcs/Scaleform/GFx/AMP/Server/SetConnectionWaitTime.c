void __thiscall Scaleform::GFx::AMP::Server::SetConnectionWaitTime(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::MutexImpl *waitTimeMilliseconds)
{
  this->SendingEvent.StateMutex.pImpl = waitTimeMilliseconds;
}
