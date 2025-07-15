void __thiscall Scaleform::GFx::InteractiveObject::SetBlendMode(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Render::BlendMode blend)
{
  Scaleform::GFx::DisplayObjectBase::SetBlendMode(this, blend);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
}
