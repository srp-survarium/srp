void __thiscall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  unsigned int Flags; // eax
  int v3; // eax

  Flags = this->Flags;
  LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
  v3 = this->CheckAdvanceStatus(this, Flags);
  if ( v3 == -1 )
  {
    this->Flags |= (unsigned int)&loc_400000;
  }
  else if ( v3 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}
