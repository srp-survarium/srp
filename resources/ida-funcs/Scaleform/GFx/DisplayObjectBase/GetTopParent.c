Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::DisplayObjectBase::GetTopParent(
        Scaleform::GFx::DisplayObjectBase *this,
        BOOL ignoreLockRoot)
{
  if ( this->pParent )
    return this->pParent->GetTopParent(this->pParent, ignoreLockRoot);
  else
    return 0;
}
