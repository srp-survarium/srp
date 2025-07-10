void __thiscall Scaleform::GFx::AS3::Classes::fl::Math::min(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Boolean3 argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v4; // ebp
  const Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::AS3::Value *v6; // edi
  unsigned int v7; // ebx
  const Scaleform::GFx::AS3::Value *v8; // esi
  double v; // st7
  double v10; // [esp+Ch] [ebp-8h]

  v4 = argc;
  if ( argc )
  {
    v5 = argv;
    v6 = result;
    Scaleform::GFx::AS3::Value::Assign(result, argv);
    v7 = 1;
    if ( v4 <= 1 )
    {
LABEL_9:
      Scaleform::GFx::AS3::Value::ToNumberValue(v6, (Scaleform::GFx::AS3::CheckResult *)&result);
    }
    else
    {
      v8 = v5 + 1;
      while ( Scaleform::GFx::AS3::AbstractLessThan((Scaleform::GFx::AS3::CheckResult *)&result, &argc, v6, v8)->Result )
      {
        if ( argc == undefined3 )
        {
          v10 = Scaleform::GFx::NumberUtil::NaN();
          if ( (v6->Flags & 0x1F) > 9 )
          {
            if ( (v6->Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
          }
          v6->Flags = v6->Flags & 0xFFFFFFE0 | 4;
          v6->value.VNumber = v10;
          return;
        }
        if ( argc == false3 )
          Scaleform::GFx::AS3::Value::Assign(v6, v8);
        ++v7;
        ++v8;
        if ( v7 >= v4 )
          goto LABEL_9;
      }
    }
  }
  else
  {
    v = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
    Scaleform::GFx::AS3::Value::SetNumber(result, v);
  }
}
