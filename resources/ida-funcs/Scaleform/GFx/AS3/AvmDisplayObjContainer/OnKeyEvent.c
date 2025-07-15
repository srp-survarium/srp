bool __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnKeyEvent(
        char *this,
        unsigned int a2,
        Scaleform::GFx::AS3::Value *a3)
{
  return Scaleform::GFx::AS2::AvmCharacter::OnKeyEvent(
           (Scaleform::GFx::AS3::Instances::fl_display::Sprite *)(this - 8),
           a2,
           a3);
}
