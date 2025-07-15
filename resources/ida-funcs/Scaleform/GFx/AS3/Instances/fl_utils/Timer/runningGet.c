void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::runningGet(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
        bool *result)
{
  Scaleform::GFx::AS3::IntervalTimer *pObject; // ecx

  pObject = this->pCoreTimer.pObject;
  *result = pObject && pObject->IsActive(pObject);
}
