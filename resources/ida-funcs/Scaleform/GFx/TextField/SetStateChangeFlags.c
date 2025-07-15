void __thiscall Scaleform::GFx::TextField::SetStateChangeFlags(Scaleform::GFx::TextField *this, unsigned __int8 flags)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  bool v5; // al
  int v6; // eax

  v3 = this->Scaleform::GFx::InteractiveObject::Flags;
  this->Flags |= 0x4000u;
  this->Scaleform::GFx::InteractiveObject::Flags = v3 & 0xFFF0FFFF | ((flags & 0xF | 0x10) << 16);
  if ( !Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
    Scaleform::GFx::InteractiveObject::AddToPlayList(this);
  v4 = this->Scaleform::GFx::InteractiveObject::Flags;
  v5 = (v4 & 0x200000) != 0 && (v4 & 0x400000) == 0;
  v6 = Scaleform::GFx::TextField::CheckAdvanceStatus(this, v5);
  if ( v6 == -1 )
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
  }
  else if ( v6 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}
