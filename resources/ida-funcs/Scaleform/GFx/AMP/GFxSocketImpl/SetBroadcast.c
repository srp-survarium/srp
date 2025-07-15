void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::SetBroadcast(
        Scaleform::GFx::AMP::GFxSocketImpl *this,
        BOOL broadcast)
{
  broadcast = broadcast;
  ((void (__stdcall *)(unsigned int, int, int, BOOL *, int))(&off_8E3A98 + 21))(this->Socket, 0xFFFF, 32, &broadcast, 4);
}
