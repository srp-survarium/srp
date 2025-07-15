char __thiscall Scaleform::GFx::MovieImpl::IsDraggingCharacter(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch,
        unsigned int *pmouseIndex)
{
  unsigned int v3; // eax
  Scaleform::GFx::MovieImpl::DragState *i; // ecx

  v3 = 0;
  for ( i = this->CurrentDragStates; i->pCharacter != ch; ++i )
  {
    if ( ++v3 >= 6 )
      return 0;
  }
  if ( pmouseIndex )
    *pmouseIndex = v3;
  return 1;
}
