void __thiscall Scaleform::Render::StateData::Interface::Interface(
        Scaleform::Render::StateData::Interface *this,
        Scaleform::Render::StateType type)
{
  this->__vftable = (Scaleform::Render::StateData::Interface_vtbl *)&Scaleform::Render::StateData::Interface::`vftable';
  this->Type = type;
  StateType_Interfaces[type] = this;
}
