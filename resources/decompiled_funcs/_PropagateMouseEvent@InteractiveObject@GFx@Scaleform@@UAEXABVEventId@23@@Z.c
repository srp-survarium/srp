int __thiscall Scaleform::GFx::InteractiveObject::PropagateMouseEvent(
        Scaleform::GFx::InteractiveObject *this,
        const Scaleform::GFx::EventId *id)
{
  return ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *))this->OnEvent)(
           this,
           id);
}
