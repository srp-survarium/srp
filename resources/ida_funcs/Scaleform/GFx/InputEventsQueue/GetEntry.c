const Scaleform::GFx::InputEventsQueueEntry *__thiscall Scaleform::GFx::InputEventsQueue::GetEntry(
        Scaleform::GFx::InputEventsQueue *this)
{
  const Scaleform::GFx::InputEventsQueueEntry *result; // eax
  unsigned int v2; // ebx
  int v3; // edi
  float *p_y; // esi
  unsigned int v5; // eax
  unsigned int UsedEntries; // edx
  unsigned int v7; // eax
  float *v8; // eax
  double v9; // st7
  unsigned int StartPos; // esi

  result = (const Scaleform::GFx::InputEventsQueueEntry *)this->UsedEntries;
  if ( result )
    goto LABEL_12;
  v2 = 0;
  v3 = 1;
  p_y = &this->LastMousePos[0].y;
  do
  {
    if ( (v3 & this->LastMousePosMask) != 0 )
    {
      if ( this->UsedEntries == 100 )
      {
        v5 = ++this->StartPos;
        this->UsedEntries = 99;
        if ( v5 == 100 )
          this->StartPos = 0;
      }
      UsedEntries = this->UsedEntries;
      v7 = UsedEntries + this->StartPos;
      if ( v7 >= 0x64 )
        v7 -= 100;
      v8 = (float *)&this->Queue[v7];
      this->UsedEntries = UsedEntries + 1;
      *v8 = 0.0;
      *((_BYTE *)v8 + 16) = v2;
      v8[1] = *(p_y - 1);
      v9 = *p_y;
      *((_WORD *)v8 + 6) = 0;
      v8[2] = v9;
      *((_BYTE *)v8 + 15) = 64;
      this->LastMousePosMask &= ~v3;
    }
    ++v2;
    p_y += 2;
    v3 *= 2;
  }
  while ( v2 < 6 );
  result = (const Scaleform::GFx::InputEventsQueueEntry *)this->UsedEntries;
  if ( result )
  {
LABEL_12:
    StartPos = this->StartPos;
    this->StartPos = StartPos + 1;
    this->UsedEntries = (unsigned int)&result[-1].u.gamepadAnalogEntry + 35;
    if ( StartPos == 99 )
      this->StartPos = 0;
    return (const Scaleform::GFx::InputEventsQueueEntry *)((char *)this + 40 * StartPos);
  }
  return result;
}
