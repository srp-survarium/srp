void __thiscall Scaleform::Render::D3D1x::RenderEvent::End(Scaleform::Render::D3D1x::RenderEvent *this)
{
  if ( Scaleform::Render::D3D1x::RenderEvent::EndEventFn )
    Scaleform::Render::D3D1x::RenderEvent::EndEventFn();
}
