void __thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *this,
        Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v)
{
  this->pObject = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}
