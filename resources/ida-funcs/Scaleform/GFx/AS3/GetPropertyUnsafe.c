Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::GetPropertyUnsafe(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  _DWORD *VInt; // ecx
  int v6; // eax
  int v7; // esi
  Scaleform::GFx::AS3::PropRef prop; // [esp+4h] [ebp-18h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3
    && ((VInt = (_DWORD *)_this->value.VS._1.VInt,
         v6 = VInt[5],
         v7 = *(_DWORD *)(v6 + 60),
         (*(_BYTE *)(v6 + 56) & 1) != 0)
     || (v7 == 13 || v7 == 14) && (*(_DWORD *)(v6 + 56) & 0x20) == 0) )
  {
    (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *, Scaleform::GFx::AS3::Value *))(*VInt + 28))(
      VInt,
      result,
      prop_name,
      value);
    return result;
  }
  else
  {
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::FindObjProperty(&prop, vm, _this, prop_name, FindGet);
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, result, vm, value, valGet);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
    else
    {
      result->Result = 0;
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
      return result;
    }
  }
}
