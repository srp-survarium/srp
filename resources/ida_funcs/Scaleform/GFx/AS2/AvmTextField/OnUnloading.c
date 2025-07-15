char __thiscall Scaleform::GFx::AS2::AvmTextField::OnUnloading(Scaleform::GFx::AS2::AvmButton *this, bool __formal)
{
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->pDispObj);
  return 1;
}


char __thiscall Scaleform::GFx::AS2::AvmTextField::OnUnloading(char *this, bool a2)
{
  return Scaleform::GFx::AS2::AvmTextField::OnUnloading((Scaleform::GFx::AS2::AvmButton *)(this - 24), a2);
}
