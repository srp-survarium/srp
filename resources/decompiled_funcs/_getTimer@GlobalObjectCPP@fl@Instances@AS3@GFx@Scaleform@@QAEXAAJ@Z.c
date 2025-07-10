void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::getTimer(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        int *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // ecx

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  *result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 40))(v2);
}
