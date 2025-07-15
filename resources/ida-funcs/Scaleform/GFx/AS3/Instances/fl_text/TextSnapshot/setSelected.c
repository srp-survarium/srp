void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::setSelected(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        const Scaleform::GFx::AS3::Value *result,
        int beginIndex,
        int endIndex,
        bool select)
{
  unsigned int v5; // eax

  v5 = endIndex;
  if ( endIndex <= beginIndex )
    v5 = beginIndex + 1;
  Scaleform::GFx::StaticTextSnapshotData::SetSelected(&this->SnapshotData, beginIndex, v5, select);
}
