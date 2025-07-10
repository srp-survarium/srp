void __thiscall Scaleform::GFx::AS3::Classes::fl_system::System::exit(
        Scaleform::GFx::AS3::Classes::fl_system::System *this,
        const Scaleform::GFx::AS3::Value *result,
        unsigned int code)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // eax

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  *((_DWORD *)v3 + 4061) |= 0x200000u;
}
