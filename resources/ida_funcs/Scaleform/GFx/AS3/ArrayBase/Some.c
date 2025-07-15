char __thiscall Scaleform::GFx::AS3::ArrayBase::Some(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Value *v6; // ecx
  unsigned int Flags; // eax
  unsigned int v8; // ebp
  unsigned int v9; // esi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // edi
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  int j; // edi
  unsigned int v16; // eax
  Scaleform::GFx::AS3::CheckResult v17; // [esp+Bh] [ebp-51h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+2Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+5Ch] [ebp+0h] BYREF

  if ( (callback->Flags & 0x1F) == 0
    || (callback->Flags & 0x1F) - 12 <= 3 && !callback->value.VS._1.VInt
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &v17, callback)->Result )
  {
    return 0;
  }
  v6 = thisObject;
  if ( (thisObject->Flags & 0x1F) == 0 || (thisObject->Flags & 0x1F) - 12 <= 3 && !thisObject->value.VS._1.VInt )
    v6 = callback;
  Flags = v6->Flags;
  _this.Bonus.pWeakProxy = v6->Bonus.pWeakProxy;
  _this.value.VNumber = v6->value.VNumber;
  _this.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v6);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v6);
  }
  v8 = this->GetArraySize(this);
  v9 = 0;
  if ( v8 )
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
      argv[1].value.VS._1.VInt = v9;
      Scaleform::GFx::AS3::Value::Value(&argv[2], currObj);
      result.Flags = 0;
      result.Bonus.pWeakProxy = 0;
      this->GetValueUnsafe(this, v9, argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, callback, &_this, &result, 3u, argv, 0);
      if ( this->VMRef->HandleException )
      {
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
        v11 = (Scaleform::GFx::AS3::Value *)&retaddr;
        for ( i = 2; i >= 0; --i )
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
        goto LABEL_23;
      }
      if ( (result.Flags & 0x1F) != 1 )
        break;
      if ( result.value.VS._1.VBool )
      {
        if ( (result.Flags & 0x1F) > 9 )
        {
          if ( (result.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
        `vector destructor iterator'(
          (char *)argv,
          0x10u,
          3,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
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
      `vector destructor iterator'(
        (char *)argv,
        0x10u,
        3,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v9 >= v8 )
        goto LABEL_23;
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
    v14 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( j = 2; j >= 0; --j )
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
    if ( (_this.Flags & 0x1F) <= 9 )
      return 0;
    if ( (_this.Flags & 0x200) == 0 )
      goto LABEL_59;
    goto LABEL_25;
  }
LABEL_23:
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
LABEL_25:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      return 0;
    }
LABEL_59:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return 0;
}
