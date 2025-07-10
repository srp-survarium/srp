bool __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::DetachChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(this, ch) != 0;
}
