void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::deltaTransformPoint(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *point)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  long double x; // st7
  long double y; // st6
  long double v8; // st5
  long double a; // st4
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value *v11; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM::Error v14; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value args[2]; // [esp+10h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  if ( point )
  {
    x = point->x;
    y = point->y;
    v8 = this->c * y;
    a = this->a;
    args[0].Flags = 4;
    args[1].Flags = 4;
    pObject = this->pTraits.pObject;
    args[0].value.VNumber = v8 + a * x;
    args[0].Bonus.pWeakProxy = 0;
    args[1].Bonus.pWeakProxy = 0;
    args[1].value.VNumber = x * this->b + y * this->d;
    Scaleform::GFx::AS3::VM::constructBuiltinObject(
      pObject->pVM,
      (Scaleform::GFx::AS3::CheckResult *)&point,
      result,
      "flash.geom.Point",
      2u,
      args);
    v11 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      Flags = v11[-1].Flags;
      --v11;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
