void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::currentCountGet(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
        int *result)
{
  Scaleform::GFx::AS3::IntervalTimer *pObject; // eax

  pObject = this->pCoreTimer.pObject;
  if ( pObject )
    *result = pObject->CurrentCount;
  else
    *result = this->CurrentCount;
}
