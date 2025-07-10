bool __thiscall Scaleform::GFx::AS3::AvmTextField::IsTabable(Scaleform::GFx::AS3::AvmTextField *this)
{
  bool result; // al
  Scaleform::GFx::TextField *v3; // ecx

  result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                                         + 228))(*(_DWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
  if ( result )
  {
    v3 = *(Scaleform::GFx::TextField **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags;
    if ( (v3->Scaleform::GFx::InteractiveObject::Flags & 0x60) != 0 )
      return (v3->Scaleform::GFx::InteractiveObject::Flags & 0x60) == 96;
    else
      return v3->TabIndex > 0 || (unsigned __int8)Scaleform::GFx::TextField::IsReadOnly(v3) == 0;
  }
  return result;
}
