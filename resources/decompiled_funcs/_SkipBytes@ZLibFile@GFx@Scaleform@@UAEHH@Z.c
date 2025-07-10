int __thiscall Scaleform::GFx::ZLibFile::SkipBytes(Scaleform::GFx::ZLibFile *this, int numBytes)
{
  return this->Seek(this, numBytes, 1);
}
