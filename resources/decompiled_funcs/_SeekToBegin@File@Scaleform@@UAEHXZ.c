int __thiscall Scaleform::File::SeekToBegin(Scaleform::File *this)
{
  return this->Seek(this, 0, 0);
}
