void __thiscall Scaleform::GFx::AS3::Instances::fl_net::Socket::ExecuteIOErrorEvent(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        char *errorStr)
{
  int v3; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&errorStr,
    errorStr);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)errorStr + 10,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
    this,
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)errorStr,
    0);
  if ( errorStr && ((unsigned __int8)errorStr & 1) == 0 )
  {
    v3 = *((_DWORD *)errorStr + 4);
    v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)errorStr;
    if ( ((unsigned int)&byte_3FFFFF & v3) != 0 )
    {
      *((_DWORD *)errorStr + 4) = v3 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
    }
  }
}
