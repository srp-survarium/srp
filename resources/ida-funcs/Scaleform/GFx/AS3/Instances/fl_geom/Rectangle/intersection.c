void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::intersection(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *toIntersect)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Traits *v7; // edx
  long double x; // st7
  long double y; // st6
  long double v10; // st5
  long double v11; // st4
  long double v12; // st7
  long double v13; // st3
  long double v14; // rt1
  long double v15; // st4
  long double v16; // st6
  long double v17; // st3
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  bool res1; // [esp+Fh] [ebp-89h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [esp+10h] [ebp-88h] BYREF
  Scaleform::GFx::AS3::Value argv; // [esp+18h] [ebp-80h] BYREF
  int v22; // [esp+28h] [ebp-70h]
  int v23; // [esp+2Ch] [ebp-6Ch]
  double v24; // [esp+30h] [ebp-68h]
  int v25; // [esp+38h] [ebp-60h]
  int v26; // [esp+3Ch] [ebp-5Ch]
  double v27; // [esp+40h] [ebp-58h]
  int v28; // [esp+48h] [ebp-50h]
  int v29; // [esp+4Ch] [ebp-4Ch]
  double v30; // [esp+50h] [ebp-48h]
  Scaleform::GFx::AS3::Value args[4]; // [esp+58h] [ebp-40h] BYREF

  if ( toIntersect )
  {
    Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::intersects(this, &res1, toIntersect);
    if ( res1 )
    {
      x = toIntersect->x;
      y = toIntersect->y;
      v10 = toIntersect->width + x;
      v11 = x;
      v12 = toIntersect->height + y;
      if ( v11 < this->x )
        v11 = this->x;
      v13 = this->width + this->x;
      if ( v13 <= v10 )
        v10 = v13;
      v14 = v11;
      v15 = y;
      v16 = v14;
      if ( v15 < this->y )
        v15 = this->y;
      v17 = this->height + this->y;
      if ( v17 <= v12 )
        v12 = v17;
      args[0].value.VNumber = v16;
      args[1].value.VNumber = v15;
      pObject = this->pTraits.pObject;
      args[2].value.VNumber = v10 - v16;
      args[0].Flags = 4;
      args[0].Bonus.pWeakProxy = 0;
      args[1].Flags = 4;
      args[1].Bonus.pWeakProxy = 0;
      args[3].value.VNumber = v12 - v15;
      args[2].Flags = 4;
      args[2].Bonus.pWeakProxy = 0;
      args[3].Flags = 4;
      args[3].Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::VM::constructBuiltinObject(
        pObject->pVM,
        (Scaleform::GFx::AS3::CheckResult *)&res1,
        result,
        "flash.geom.Rectangle",
        4u,
        args);
      `vector destructor iterator'(
        (char *)args,
        0x10u,
        4,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
    else
    {
      argv.value.VNumber = 0.0;
      v24 = 0.0;
      v27 = 0.0;
      v7 = this->pTraits.pObject;
      v30 = 0.0;
      argv.Flags = 4;
      argv.Bonus.pWeakProxy = 0;
      v22 = 4;
      v23 = 0;
      v25 = 4;
      v26 = 0;
      v28 = 4;
      v29 = 0;
      Scaleform::GFx::AS3::VM::constructBuiltinObject(
        v7->pVM,
        (Scaleform::GFx::AS3::CheckResult *)&res1,
        result,
        "flash.geom.Rectangle",
        4u,
        &argv);
      `vector destructor iterator'(
        (char *)&argv,
        0x10u,
        4,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v20.Message.pNode;
    --v20.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
