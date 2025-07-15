bool __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::IsTabable(Scaleform::GFx::AS3::AvmButton *this)
{
  bool result; // al
  int v3; // ecx

  result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                                         + 228))(*(_DWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags);
  if ( result )
  {
    v3 = *(_DWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags;
    if ( (*(_DWORD *)(v3 + 104) & 0x60) != 0 )
      return (*(_DWORD *)(v3 + 104) & 0x60) == 96;
    else
      return *(_WORD *)(v3 + 108) > 0;
  }
  return result;
}


bool __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::IsTabable(char *this)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::IsTabable((Scaleform::GFx::AS3::AvmButton *)(this - 8));
}
