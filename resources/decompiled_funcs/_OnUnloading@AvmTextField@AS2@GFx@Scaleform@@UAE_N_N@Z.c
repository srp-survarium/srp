char __thiscall Scaleform::GFx::AS2::AvmTextField::OnUnloading(Scaleform::GFx::AS2::AvmButton *this, bool __formal)
{
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->pDispObj);
  return 1;
}
