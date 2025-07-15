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
      this->Flags = (unsigned int)&loc_400000 | Flags;
  }
  else if ( !v2 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}


void __thiscall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(
        Scaleform::GFx::InteractiveObject *this)
{
  unsigned int Flags; // eax
  bool v3; // al
  int v4; // eax

  Flags = this->Flags;
  v3 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
  v4 = Scaleform::GFx::Sprite::CheckAdvanceStatus((Scaleform::GFx::Sprite *)this, v3);
  if ( v4 == -1 )
  {
    this->Flags |= (unsigned int)&loc_400000;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}


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
    this->Flags |= (unsigned int)&loc_400000;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}
