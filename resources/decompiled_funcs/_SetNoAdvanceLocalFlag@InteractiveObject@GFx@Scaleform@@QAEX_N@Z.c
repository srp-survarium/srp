void __thiscall Scaleform::GFx::InteractiveObject::SetNoAdvanceLocalFlag(
        Scaleform::GFx::InteractiveObject *this,
        bool v)
{
  if ( v )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}
