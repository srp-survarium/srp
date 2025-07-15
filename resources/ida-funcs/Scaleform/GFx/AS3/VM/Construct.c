bool __thiscall Scaleform::GFx::AS3::VM::Construct(
        Scaleform::GFx::AS3::VM *this,
        const char *gname,
        Scaleform::GFx::ASStringNode *appDomain,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        int extCall)
{
  unsigned int Size; // edi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  unsigned int v12; // esi
  const char *v13; // [esp+8h] [ebp-18h] BYREF
  unsigned int v14; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::AS3::Value value; // [esp+10h] [ebp-10h] BYREF

  Size = this->CallStack.Size;
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0;
  v13 = gname;
  if ( gname )
    v14 = strlen(gname);
  else
    v14 = 0;
  if ( !Scaleform::GFx::AS3::VM::GetClassUnsafe(this, (Scaleform::GFx::ASStringNode *)&v13, appDomain, &value) )
    goto LABEL_10;
  if ( (value.Flags & 0x1F) == 0 || (value.Flags & 0x1F) - 12 <= 3 && !value.value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v13, eConvertNullToObjectError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = (Scaleform::GFx::ASStringNode *)v14;
    --*(_DWORD *)(v14 + 12);
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    goto LABEL_10;
  }
  (*(void (__stdcall **)(Scaleform::GFx::AS3::Value *, unsigned int, const Scaleform::GFx::AS3::Value *, int))(*(_DWORD *)value.value.VS._1.VInt + 48))(
    result,
    argc,
    argv,
    extCall);
  if ( this->HandleException )
  {
LABEL_10:
    Scaleform::GFx::AS3::Value::~Value(&value);
    return 0;
  }
  v12 = this->CallStack.Size;
  Scaleform::GFx::AS3::Value::~Value(&value);
  return v12 > Size;
}
