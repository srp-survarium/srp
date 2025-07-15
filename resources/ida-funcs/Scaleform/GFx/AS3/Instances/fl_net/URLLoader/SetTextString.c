void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        char *pdata)
{
  const Scaleform::GFx::AS3::Value *v3; // eax
  Scaleform::GFx::ASStringNode *v4; // eax
  Scaleform::GFx::AS3::Value v5; // [esp+4h] [ebp-10h] BYREF

  pdata = (char *)Scaleform::GFx::ASStringManager::CreateStringNode(
                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                    pdata);
  ++*((_DWORD *)pdata + 3);
  Scaleform::GFx::AS3::Value::Value(&v5, (const Scaleform::GFx::ASString *)&pdata);
  Scaleform::GFx::AS3::Value::Assign(&this->data, v3);
  if ( (v5.Flags & 0x1F) > 9 )
  {
    if ( (v5.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v5);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v5);
  }
  v4 = (Scaleform::GFx::ASStringNode *)pdata;
  --*((_DWORD *)pdata + 3);
  if ( !v4->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}
