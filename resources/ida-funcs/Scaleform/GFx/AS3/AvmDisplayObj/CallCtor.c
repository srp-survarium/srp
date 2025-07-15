unsigned int __thiscall Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        bool execute)
{
  unsigned int result; // eax
  _DWORD *v4; // esi
  Scaleform::GFx::AS3::Value::V1U pAS3RawPtr; // eax
  int v6; // ecx
  Scaleform::GFx::AS3::VM *v7; // esi
  unsigned int Size; // edi
  Scaleform::GFx::AS3::Value _this; // [esp+Ch] [ebp-10h] BYREF

  result = (unsigned int)this->pAS3RawPtr;
  if ( !result )
  {
    if ( !this->pAS3CollectiblePtr.pObject )
      return result;
    result = (unsigned int)this->pAS3CollectiblePtr.pObject;
  }
  if ( (result & 1) != 0 )
    --result;
  v4 = *(_DWORD **)(result + 20);
  if ( !v4[17] )
    (*(void (__thiscall **)(_DWORD *))(*v4 + 44))(v4);
  pAS3RawPtr = (Scaleform::GFx::AS3::Value::V1U)this->pAS3RawPtr;
  v6 = v4[17];
  if ( !pAS3RawPtr.VInt )
    pAS3RawPtr = (Scaleform::GFx::AS3::Value::V1U)this->pAS3CollectiblePtr.pObject;
  if ( pAS3RawPtr.VBool )
    --pAS3RawPtr.VInt;
  _this.Flags = 12;
  _this.Bonus.pWeakProxy = 0;
  _this.value.VS._1 = pAS3RawPtr;
  if ( pAS3RawPtr.VInt )
    *(_DWORD *)(pAS3RawPtr.VInt + 16) = (*(_DWORD *)(pAS3RawPtr.VInt + 16) + 1) & 0x8FBFFFFF;
  v7 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].__vftable;
  if ( !v7 )
    goto LABEL_19;
  Size = v7->CallStack.Size;
  (*(void (__thiscall **)(int, Scaleform::GFx::AS3::Value *, _DWORD, _DWORD))(*(_DWORD *)v6 + 72))(v6, &_this, 0, 0);
  if ( v7->CallStack.Size <= Size )
    goto LABEL_19;
  if ( execute )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(v7, 1u);
    if ( v7->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      this->pDispObj->Flags |= 0x20u;
    }
LABEL_19:
    Scaleform::GFx::AS3::Value::~Value(&_this);
    return 0;
  }
  Scaleform::GFx::AS3::Value::~Value(&_this);
  return 1;
}
