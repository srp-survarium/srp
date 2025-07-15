void __thiscall Scaleform::GFx::AMP::MessageCurrentState::Write(
        Scaleform::GFx::AMP::MessageCurrentState *this,
        Scaleform::File *str)
{
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Scaleform::GFx::AMP::ServerState::Write(this->State.pObject, str, this->Version);
}
