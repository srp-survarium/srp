void __thiscall Scaleform::GFx::AMP::MessagePort::SetPeerName(Scaleform::GFx::AMP::MessagePort *this, char *name)
{
  Scaleform::String::operator=(&this->PeerName, name);
}
