void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::union_(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *toUnion)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  long double height; // st7
  Scaleform::GFx::AS3::Traits *v7; // eax
  char *p_argv; // ecx
  long double x; // st7
  long double y; // st6
  long double v11; // st5
  long double v12; // st4
  long double v13; // st3
  long double v14; // st2
  long double v15; // st1
  long double v16; // rt0
  long double v17; // st1
  long double v18; // st7
  long double v19; // rt1
  long double v20; // st2
  long double v21; // st5
  long double v22; // rt2
  long double v23; // st3
  long double v24; // st6
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::CheckResult v26; // [esp+Fh] [ebp-89h] BYREF
  double bottom2; // [esp+10h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Value argv; // [esp+18h] [ebp-80h] BYREF
  int v29; // [esp+28h] [ebp-70h]
  int v30; // [esp+2Ch] [ebp-6Ch]
  long double v31; // [esp+30h] [ebp-68h]
  int v32; // [esp+38h] [ebp-60h]
  int v33; // [esp+3Ch] [ebp-5Ch]
  long double width; // [esp+40h] [ebp-58h]
  int v35; // [esp+48h] [ebp-50h]
  int v36; // [esp+4Ch] [ebp-4Ch]
  long double v37; // [esp+50h] [ebp-48h]
  Scaleform::GFx::AS3::Value args[4]; // [esp+58h] [ebp-40h] BYREF

  if ( toUnion )
  {
    if ( toUnion->width > 0.0 && toUnion->height > 0.0 )
    {
      if ( this->width > 0.0 && this->height > 0.0 )
      {
        x = this->x;
        y = this->y;
        v11 = this->width + x;
        v12 = this->height + y;
        v13 = toUnion->x;
        v14 = toUnion->y;
        v15 = v13 + toUnion->width;
        bottom2 = v14 + toUnion->height;
        v16 = v15;
        v17 = x;
        v18 = v16;
        if ( v17 <= v13 )
          v13 = v17;
        v19 = v14;
        v20 = v11;
        v21 = v19;
        if ( v20 > v18 )
          v18 = v20;
        v22 = v13;
        v23 = y;
        v24 = v22;
        if ( v23 <= v21 )
          v21 = v23;
        if ( bottom2 >= v12 )
          v12 = bottom2;
        args[0].value.VNumber = v24;
        args[1].value.VNumber = v21;
        pObject = this->pTraits.pObject;
        args[2].value.VNumber = v18 - v24;
        args[0].Flags = 4;
        args[0].Bonus.pWeakProxy = 0;
        args[1].Flags = 4;
        args[1].Bonus.pWeakProxy = 0;
        args[3].value.VNumber = v12 - v21;
        args[2].Flags = 4;
        args[2].Bonus.pWeakProxy = 0;
        args[3].Flags = 4;
        args[3].Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::constructBuiltinObject(pObject->pVM, &v26, result, "flash.geom.Rectangle", 4u, args);
        p_argv = (char *)args;
        goto LABEL_21;
      }
      argv.value.VNumber = toUnion->x;
      v31 = toUnion->y;
      width = toUnion->width;
      height = toUnion->height;
    }
    else
    {
      argv.value.VNumber = this->x;
      v31 = this->y;
      width = this->width;
      height = this->height;
    }
    v37 = height;
    v7 = this->pTraits.pObject;
    v36 = 0;
    v35 = 4;
    v33 = 0;
    v32 = 4;
    v30 = 0;
    v29 = 4;
    argv.Bonus.pWeakProxy = 0;
    argv.Flags = 4;
    Scaleform::GFx::AS3::VM::constructBuiltinObject(v7->pVM, &v26, result, "flash.geom.Rectangle", 4u, &argv);
    p_argv = (char *)&argv;
LABEL_21:
    `vector destructor iterator'(p_argv, 0x10u, 4, (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    return;
  }
  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&bottom2, eConvertNullToObjectError, pVM);
  Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
  v5 = (Scaleform::GFx::ASStringNode *)HIDWORD(bottom2);
  --*(_DWORD *)(HIDWORD(bottom2) + 12);
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
