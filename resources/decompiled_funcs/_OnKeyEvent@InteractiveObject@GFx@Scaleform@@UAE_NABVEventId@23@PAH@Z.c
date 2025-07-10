int __thiscall Scaleform::GFx::InteractiveObject::OnKeyEvent(
        Scaleform::GFx::InteractiveObject *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  return ((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *))this->OnEvent)(
           this,
           id);
}
