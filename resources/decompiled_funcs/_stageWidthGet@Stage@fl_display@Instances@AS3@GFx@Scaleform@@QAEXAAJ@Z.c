void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::stageWidthGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        int *result)
{
  void (__thiscall *v2)(Scaleform::GFx::AS3::VM *); // ecx
  float *v3; // eax
  float v4; // [esp+Ch] [ebp-14h]
  _BYTE v5[16]; // [esp+10h] [ebp-10h] BYREF

  v2 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  v3 = (float *)(*(int (__thiscall **)(void (__thiscall *)(Scaleform::GFx::AS3::VM *), _BYTE *))(*(_DWORD *)v2 + 68))(
                  v2,
                  v5);
  v4 = v3[2] - *v3;
  *result = (int)v4;
}
