void __thiscall Scaleform::GFx::AS3::ArrayBase::ForEach(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::Value *v6; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::V1U v8; // ebp
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  void (__thiscall *GetValueUnsafe)(Scaleform::GFx::AS3::ArrayBase *, unsigned int, Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // ebx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  int j; // edi
  unsigned int v16; // eax
  Scaleform::GFx::AS3::CheckResult v17; // [esp+Bh] [ebp-51h] BYREF
  Scaleform::GFx::AS3::Value result; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value argv[3]; // [esp+2Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+5Ch] [ebp+0h] BYREF
  unsigned int size; // [esp+64h] [ebp+8h]

  v4 = callback;
  if ( (callback->Flags & 0x1F) != 0
    && ((callback->Flags & 0x1F) - 12 > 3 || callback->value.VS._1.VInt)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &v17, callback)->Result )
  {
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
    v8.VInt = 0;
    size = this->GetArraySize(this);
    if ( size )
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
        argv[1].value.VS._1 = v8;
        Scaleform::GFx::AS3::Value::Value(&argv[2], currObj);
        GetValueUnsafe = this->GetValueUnsafe;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0;
        GetValueUnsafe(this, v8.VInt, argv);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, v4, &_this, &result, 3u, argv, 0);
        if ( this->VMRef->HandleException )
          break;
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
        if ( ++v8.VInt >= size )
          goto LABEL_43;
        v4 = callback;
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
    }
LABEL_43:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}
