Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::MovieRoot::CreateEventObject(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const Scaleform::GFx::ASString *type,
        bool bubbles,
        bool cancelable)
{
  this->CheckAvm(this);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
    (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)this->pAVM.pObject->EventDispatcherClass.pObject,
    result,
    type,
    bubbles,
    cancelable);
  return result;
}
