void __thiscall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(
        Scaleform::GFx::InteractiveObject *this)
{
  unsigned int Flags; // eax
  bool v3; // al
  int v4; // eax

  Flags = this->Flags;
  v3 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
  v4 = Scaleform::GFx::TextField::CheckAdvanceStatus((Scaleform::GFx::TextField *)this, v3);
  if ( v4 == -1 )
  {
    this->Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}
