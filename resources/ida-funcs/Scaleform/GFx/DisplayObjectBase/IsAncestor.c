char __thiscall Scaleform::GFx::DisplayObjectBase::IsAncestor(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax

  pParent = ch->pParent;
  if ( !pParent )
    return 0;
  while ( pParent != this )
  {
    pParent = pParent->pParent;
    if ( !pParent )
      return 0;
  }
  return 1;
}
