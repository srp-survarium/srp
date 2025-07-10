Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *Constructor; // eax

  Constructor = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::GetConstructor(this->pTraits.pObject);
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(Constructor, result, type);
  return result;
}
