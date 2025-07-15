void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::getDefinitionByName(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *pNode; // edx
  const char *pData; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // eax
  Scaleform::StringDataPtr gname; // [esp+4h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value _class; // [esp+Ch] [ebp-10h] BYREF

  pNode = name->pNode;
  _class.Flags = 0;
  _class.Bonus.pWeakProxy = 0;
  pData = pNode->pData;
  gname.pStr = pData;
  if ( pData )
    gname.Size = strlen(pData);
  else
    gname.Size = 0;
  pVM = this->pTraits.pObject->pVM;
  FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
  if ( Scaleform::GFx::AS3::VM::GetClassUnsafe(pVM, &gname, FrameAppDomain, &_class) )
    Scaleform::GFx::AS3::Value::Swap(&_class, result);
  if ( (_class.Flags & 0x1F) > 9 )
  {
    if ( (_class.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_class);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_class);
  }
}
