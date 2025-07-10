void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::transformPoint(
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
  long double v11; // st5
  Scaleform::GFx::AS3::Value *v12; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM::Error v15; // [esp+8h] [ebp-28h] BYREF
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
    v11 = v8 + a * x + this->tx;
    args[0].Bonus.pWeakProxy = 0;
    args[1].Bonus.pWeakProxy = 0;
    args[0].value.VNumber = v11;
    args[1].value.VNumber = x * this->b + y * this->d + this->ty;
    Scaleform::GFx::AS3::VM::constructBuiltinObject(
      pObject->pVM,
      (Scaleform::GFx::AS3::CheckResult *)&point,
      result,
      "flash.geom.Point",
      2u,
      args);
    v12 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      Flags = v12[-1].Flags;
      --v12;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v12);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v15.Message.pNode;
    --v15.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
