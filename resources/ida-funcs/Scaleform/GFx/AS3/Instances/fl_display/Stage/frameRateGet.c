void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::frameRateGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        long double *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // ecx
  int v3; // eax

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 4))(v2);
  *result = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 36))(v3);
}
