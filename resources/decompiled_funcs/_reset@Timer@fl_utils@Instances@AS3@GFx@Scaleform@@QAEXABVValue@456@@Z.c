void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::Timer::reset(
        Scaleform::GFx::AS3::Instances::fl_utils::Timer *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Timer::stop(this, result);
  this->CurrentCount = 0;
}
