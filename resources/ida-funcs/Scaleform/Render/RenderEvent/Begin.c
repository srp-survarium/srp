void __thiscall Scaleform::Render::RenderEvent::Begin(
        Scaleform::Render::RenderEvent *this,
        Scaleform::String eventName)
{
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(eventName.HeapTypeBits & 0xFFFFFFFC));
}
