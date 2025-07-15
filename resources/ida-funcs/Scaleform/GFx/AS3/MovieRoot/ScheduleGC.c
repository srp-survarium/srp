void __thiscall Scaleform::GFx::AS3::MovieRoot::ScheduleGC(Scaleform::GFx::AS3::MovieRoot *this, unsigned int gcFlags)
{
  int v2; // eax

  if ( gcFlags )
  {
    if ( gcFlags == 1 )
    {
      v2 = 16;
    }
    else if ( gcFlags == 2 )
    {
      v2 = 32;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = 8;
  }
  this->MemContext.pObject->ASGC.pObject->CollectionScheduledFlags = v2 & 0xFFFFFFF3 | 8;
}
