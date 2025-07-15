void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::setSelectColor(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::Render::Color hexColor)
{
  hexColor.Channels.Alpha = -1;
  Scaleform::GFx::StaticTextSnapshotData::SetSelectColor(&this->SnapshotData, &hexColor);
}
