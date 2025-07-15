// attributes: thunk
void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::addEventListener(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *type,
        const Scaleform::GFx::AS3::Value *listener,
        bool useCapture,
        int priority,
        bool useWeakReference)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
    this,
    result,
    type,
    listener,
    useCapture,
    priority,
    useWeakReference);
}
