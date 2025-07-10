void __thiscall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Button>(
        Scaleform::GFx::InteractiveObject *this)
{
  unsigned int Flags; // eax
  bool v2; // dl

  Flags = this->Flags;
  v2 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
  if ( (Flags & 0xC) != 0 || (this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) != 0 )
  {
    if ( v2 )
      this->Flags = (unsigned int)Scaleform::GFx::AS2::CreateShadow | Flags;
  }
  else if ( !v2 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}
