char __thiscall Scaleform::GFx::AS3::ArrayBase::Every(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // ecx
  unsigned int v6; // edi
  unsigned int v7; // eax
  unsigned int Flags; // eax
  unsigned int v9; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::Value *v11; // esi
  int j; // ebx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  int i; // ebx
  unsigned int v16; // eax
  Scaleform::GFx::AS3::CheckResult v18; // [esp+Bh] [ebp-51h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+2Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+5Ch] [ebp+0h] BYREF
  unsigned int size; // [esp+64h] [ebp+8h]

  if ( (callback->Flags & 0x1F) == 0
    || (callback->Flags & 0x1F) - 12 <= 3 && !callback->value.VS._1.VInt
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &v18, callback)->Result )
  {
    return 0;
  }
  v5 = thisObject;
  v6 = 0;
  v7 = thisObject->Flags & 0x1F;
  if ( !v7 || v7 - 12 <= 3 && !thisObject->value.VS._1.VInt )
    v5 = callback;
  Flags = v5->Flags;
  _this.Bonus.pWeakProxy = v5->Bonus.pWeakProxy;
  _this.value.VNumber = v5->value.VNumber;
  _this.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v5);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v5);
  }
  v9 = this->GetArraySize(this);
  size = v9;
  if ( v9 )
  {
    while ( 1 )
    {
      Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
      argv[0] = *Undefined;
      if ( (Undefined->Flags & 0x1F) > 9 )
      {
        if ( (Undefined->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
      }
      argv[1].Flags = 3;
      argv[1].Bonus.pWeakProxy = 0;
      argv[1].value.VS._1.VInt = v6;
      Scaleform::GFx::AS3::Value::Value(&argv[2], currObj);
      result.Flags = 0;
      result.Bonus.pWeakProxy = 0;
      this->GetValueUnsafe(this, v6, argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, callback, &_this, &result, 3u, argv, 0);
      if ( this->VMRef->HandleException )
        break;
      if ( (result.Flags & 0x1F) != 1 || !result.value.VS._1.VBool )
      {
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
        v14 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( i = 2; i >= 0; --i )
        {
          v16 = v14[-1].Flags;
          --v14;
          if ( (v16 & 0x1F) > 9 )
          {
            if ( (v16 & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(v14);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(v14);
          }
        }
        goto LABEL_44;
      }
      `vector destructor iterator'(
        (char *)argv,
        0x10u,
        3,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v6 >= v9 )
        goto LABEL_45;
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
    v11 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( j = 2; j >= 0; --j )
    {
      v13 = v11[-1].Flags;
      --v11;
      if ( (v13 & 0x1F) > 9 )
      {
        if ( (v13 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
      }
    }
LABEL_44:
    v9 = size;
  }
LABEL_45:
  if ( v6 != v9 )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
        return 0;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
    return 0;
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      return 1;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return 1;
}
