void __thiscall Scaleform::GFx::AMP::MessageCurrentState::Read(
        Scaleform::GFx::AMP::MessageCurrentState *this,
        Scaleform::File *str)
{
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Scaleform::GFx::AMP::ServerState::Read(this->State.pObject, *(float *)&str, this->Version);
}
