void __thiscall Scaleform::GFx::AMP::MessageObjectsReport::Read(
        Scaleform::GFx::AMP::MessageObjectsReport *this,
        Scaleform::File *str)
{
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  Scaleform::GFx::AMP::Message::ReadString(str, &this->ObjectsReport);
}
