void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::charCountGet(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        int *result)
{
  *result = Scaleform::GFx::StaticTextSnapshotData::GetCharCount(&this->SnapshotData);
}
