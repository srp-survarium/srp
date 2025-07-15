void __thiscall Scaleform::GFx::AMP::MessageObjectsReport::Write(
        Scaleform::GFx::AMP::MessageObjectsReport *this,
        Scaleform::File *str)
{
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Scaleform::GFx::AMP::writeString(str, &this->ObjectsReport);
}
