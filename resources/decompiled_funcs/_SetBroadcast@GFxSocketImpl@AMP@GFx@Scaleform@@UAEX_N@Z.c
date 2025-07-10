void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SetBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        BOOL broadcast)
{
  broadcast = broadcast;
  setsockopt(this->Socket, 0xFFFF, 32, (const char *)&broadcast, 4);
}
