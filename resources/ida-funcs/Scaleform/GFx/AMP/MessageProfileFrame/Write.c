void __thiscall Scaleform::GFx::AMP::MessageProfileFrame::Write(
        Scaleform::GFx::AMP::MessageProfileFrame *this,
        Scaleform::File *str)
{
  Scaleform::GFx::AMP::Message::Write(this, (unsigned int)str);
  Scaleform::GFx::AMP::ProfileFrame::Write(this->FrameInfo.pObject, str, this->Version);
}
