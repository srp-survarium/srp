int __cdecl Scaleform::GFx::AS3::Impl::CompareFunct(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *Funct,
        Scaleform::GFx::AS3::Value *a,
        Scaleform::GFx::AS3::Value *b)
{
  unsigned int Flags; // eax
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::AS3::Value *v7; // esi
  int i; // edi
  unsigned int v9; // eax
  int v11; // esi
  long double n; // [esp+Ch] [ebp-40h] BYREF
  long double v13; // [esp+14h] [ebp-38h]
  Scaleform::GFx::AS3::Value result; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value argv[2]; // [esp+2Ch] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h] BYREF

  Flags = a->Flags;
  argv[0].Bonus.pWeakProxy = a->Bonus.pWeakProxy;
  argv[0].value.VNumber = a->value.VNumber;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0;
  argv[0].Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(a);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(a);
  }
  v5 = b->Flags;
  argv[1].Bonus.pWeakProxy = b->Bonus.pWeakProxy;
  argv[1].value.VNumber = b->value.VNumber;
  argv[1].Flags = v5;
  if ( (v5 & 0x1F) > 9 )
  {
    if ( (v5 & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(b);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(b);
  }
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, Funct, Undefined, &result, 2u, argv, 0);
  if ( vm->HandleException )
  {
    v7 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      v9 = v7[-1].Flags;
      --v7;
      if ( (v9 & 0x1F) > 9 )
      {
        if ( (v9 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v7);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
      }
    }
    if ( (result.Flags & 0x1F) <= 9 )
      return 0;
    if ( (result.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
      return 0;
    }
    goto LABEL_19;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Number(&result, (Scaleform::GFx::AS3::CheckResult *)&a, &n)->Result )
  {
    v13 = n;
    if ( n == -INFINITY )
    {
      `vector destructor iterator'(
        (char *)argv,
        0x10u,
        2,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
          return -1;
        }
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
      return -1;
    }
    else
    {
      v13 = n;
      if ( n == INFINITY )
        goto LABEL_32;
      if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(n) )
      {
        `vector destructor iterator'(
          (char *)argv,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        Scaleform::GFx::AS3::Value::~Value(&result);
        return -1;
      }
      if ( Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(n) )
      {
LABEL_32:
        `vector destructor iterator'(
          (char *)argv,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        Scaleform::GFx::AS3::Value::~Value(&result);
        return 1;
      }
      if ( n == 0.0 )
      {
        v11 = 0;
      }
      else if ( n >= 0.0 )
      {
        v11 = 1;
      }
      else
      {
        v11 = -1;
      }
      `vector destructor iterator'(
        (char *)argv,
        0x10u,
        2,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      Scaleform::GFx::AS3::Value::~Value(&result);
      return v11;
    }
  }
  else
  {
    `vector destructor iterator'(
      (char *)argv,
      0x10u,
      2,
      (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    if ( (result.Flags & 0x1F) <= 9 )
      return 0;
    if ( (result.Flags & 0x200) == 0 )
    {
LABEL_19:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      return 0;
    }
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
    return 0;
  }
}
