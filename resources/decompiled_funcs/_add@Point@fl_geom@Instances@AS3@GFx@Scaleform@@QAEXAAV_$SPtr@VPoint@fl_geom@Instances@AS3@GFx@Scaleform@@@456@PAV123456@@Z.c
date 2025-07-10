void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Point::add(
        Scaleform::GFx::AS3::Instances::fl_geom::Point *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Point *v)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  long double v6; // st7
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Value *v8; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value args[2]; // [esp+10h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  if ( v )
  {
    v6 = v->x + this->x;
    args[0].Flags = 4;
    args[1].Flags = 4;
    args[0].value.VNumber = v6;
    pObject = this->pTraits.pObject;
    args[1].value.VNumber = v->y + this->y;
    args[0].Bonus.pWeakProxy = 0;
    args[1].Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::VM::constructBuiltinObject(
      pObject->pVM,
      (Scaleform::GFx::AS3::CheckResult *)&v,
      result,
      "flash.geom.Point",
      2u,
      args);
    v8 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      Flags = v8[-1].Flags;
      --v8;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v8);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v8);
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v4);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
