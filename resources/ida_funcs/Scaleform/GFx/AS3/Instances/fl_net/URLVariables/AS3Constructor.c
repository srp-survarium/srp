void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString data; // [esp+4h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+8h] [ebp-10h] BYREF

  if ( argc )
  {
    data.pNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
    ++data.pNode->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &data)->Result )
    {
      r.Flags = 0;
      r.Bonus.pWeakProxy = 0;
      Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(this, &r, &data);
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
    pNode = data.pNode;
    --data.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
