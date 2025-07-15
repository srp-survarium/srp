void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        __m128i *pdata)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v5; // ebx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v9; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // [esp-4h] [ebp-30h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::URLVariables> varObj; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::ASString dataStr; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr gname; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value dataParams; // [esp+1Ch] [ebp-10h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  CurrentDomain = pVM->CurrentDomain;
  gname.pStr = "flash.net.URLVariables";
  gname.Size = 22;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, CurrentDomain);
  v5 = Class;
  if ( Class )
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  dataStr.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                    pdata);
  ++dataStr.pNode->RefCount;
  Scaleform::GFx::AS3::Value::Value(&dataParams, &dataStr);
  varObj.pObject = 0;
  if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
         pVM,
         (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&varObj,
         v5,
         1u,
         &dataParams) )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->data, varObj.pObject);
  }
  if ( varObj.pObject )
  {
    if ( ((int)varObj.pObject & 1) != 0 )
    {
      --varObj.pObject;
    }
    else
    {
      RefCount = varObj.pObject->RefCount;
      pObject = varObj.pObject;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        varObj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (dataParams.Flags & 0x1F) > 9 )
  {
    if ( (dataParams.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&dataParams);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&dataParams);
  }
  pNode = dataStr.pNode;
  --dataStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v5 && ((unsigned __int8)v5 & 1) == 0 )
  {
    v9 = v5->RefCount;
    if ( (v9 & 0x3FFFFF) != 0 )
    {
      v5->RefCount = v9 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
    }
  }
}
