int __thiscall Scaleform::GFx::Stream::GetTagEndPosition(Scaleform::GFx::Stream *this)
{
  unsigned int TagStackEntryCount; // eax

  TagStackEntryCount = this->TagStackEntryCount;
  if ( TagStackEntryCount - 1 >= 2 )
    return 0;
  else
    return *((_DWORD *)&this->FileName.pHeap + TagStackEntryCount);
}
