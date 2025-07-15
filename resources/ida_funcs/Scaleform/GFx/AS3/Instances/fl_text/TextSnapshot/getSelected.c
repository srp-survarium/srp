void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot::getSelected(
        Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *this,
        bool *result,
        int beginIndex,
        int endIndex)
{
  unsigned int v4; // eax

  v4 = endIndex;
  if ( endIndex <= beginIndex )
    v4 = beginIndex + 1;
  *result = Scaleform::GFx::StaticTextSnapshotData::IsSelected(&this->SnapshotData, beginIndex, v4);
}
