BOOL __thiscall Scaleform::GFx::AS3::AvmButton::GetCursorType(Scaleform::GFx::AS3::AvmButton *this)
{
  return (*(_DWORD *)(*(_DWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                    + 104)
        & 0x10) != 0;
}


BOOL __thiscall Scaleform::GFx::AS3::AvmButton::GetCursorType(char *this)
{
  return Scaleform::GFx::AS3::AvmButton::GetCursorType((Scaleform::GFx::AS3::AvmButton *)(this - 8));
}
