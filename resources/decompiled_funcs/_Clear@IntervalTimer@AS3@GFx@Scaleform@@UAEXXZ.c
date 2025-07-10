void __thiscall Scaleform::GFx::AS3::IntervalTimer::Clear(Scaleform::GFx::AS3::IntervalTimer *this)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *pObject; // ecx
  unsigned int RefCount; // eax

  this->Active = 0;
  pObject = this->TimerObj.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TimerObj.pObject = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)((char *)pObject - 1);
      this->TimerObj.pObject = 0;
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
      this->TimerObj.pObject = 0;
    }
  }
}
