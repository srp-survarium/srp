void __thiscall Scaleform::GFx::Stream::LogTagBytes(Scaleform::GFx::Stream *this)
{
  unsigned int TagStackEntryCount; // eax

  TagStackEntryCount = this->TagStackEntryCount;
  if ( TagStackEntryCount - 1 >= 2 )
    Scaleform::GFx::Stream::LogBytes(this, this->DataSize - this->FilePos - this->Pos);
  else
    Scaleform::GFx::Stream::LogBytes(
      this,
      *((_DWORD *)&this->FileName.pHeap + TagStackEntryCount) + this->DataSize - this->FilePos - this->Pos);
}
