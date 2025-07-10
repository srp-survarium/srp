int __thiscall Scaleform::Render::ImageData::GetPlaneCount(Scaleform::Render::ImageData *this)
{
  int LevelCount; // edx

  LevelCount = 1;
  if ( (this->Flags & 1) != 0 )
    LevelCount = this->LevelCount;
  return LevelCount * this->RawPlaneCount;
}
