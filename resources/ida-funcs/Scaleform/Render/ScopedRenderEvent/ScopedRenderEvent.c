void __thiscall Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(
        Scaleform::Render::ScopedRenderEvent *this,
        Scaleform::Render::RenderEvent *evt,
        Scaleform::String eventName,
        bool trigger)
{
  bool v4; // zf
  Scaleform::Render::RenderEvent_vtbl *v6; // esi
  Scaleform::String v7; // [esp-4h] [ebp-Ch] BYREF

  v4 = !trigger;
  this->EventObj = evt;
  if ( !v4 )
  {
    v6 = evt->__vftable;
    v7.pData = (Scaleform::String::DataDesc *)this;
    Scaleform::String::String(&v7, &eventName);
    ((void (__thiscall *)(Scaleform::Render::RenderEvent *, Scaleform::String::DataDesc *))v6->Begin)(
      this->EventObj,
      v7.pData);
  }
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(eventName.HeapTypeBits & 0xFFFFFFFC));
}
