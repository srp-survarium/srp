void __thiscall Scaleform::GFx::StaticTextSnapshotData::StaticTextSnapshotData(
        Scaleform::GFx::StaticTextSnapshotData *this)
{
  this->StaticTextCharRefs.Data.Data = 0;
  this->StaticTextCharRefs.Data.Size = 0;
  this->StaticTextCharRefs.Data.Policy.Capacity = 0;
  Scaleform::StringLH::StringLH(&this->SnapshotString);
  this->SelectColor.Raw = -256;
}
