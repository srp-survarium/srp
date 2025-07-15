Scaleform::GFx::InputEventsQueue *__thiscall Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(
        Scaleform::GFx::InputEventsQueue *this)
{
  unsigned int v1; // eax
  unsigned int UsedEntries; // edx
  unsigned int v3; // eax

  if ( this->UsedEntries == 100 )
  {
    v1 = ++this->StartPos;
    this->UsedEntries = 99;
    if ( v1 == 100 )
      this->StartPos = 0;
  }
  UsedEntries = this->UsedEntries;
  v3 = UsedEntries + this->StartPos;
  if ( v3 >= 0x64 )
    v3 -= 100;
  this->UsedEntries = UsedEntries + 1;
  return (Scaleform::GFx::InputEventsQueue *)((char *)this + 40 * v3);
}
