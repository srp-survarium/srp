void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *binaryData)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v5; // ebx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pObject; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> arrObj; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::StringDataPtr gname; // [esp+10h] [ebp-8h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  CurrentDomain = pVM->CurrentDomain;
  gname.pStr = "flash.utils.ByteArray";
  gname.Size = 21;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, CurrentDomain);
  v5 = Class;
  if ( Class )
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  arrObj.pObject = 0;
  if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
         pVM,
         (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&arrObj,
         Class,
         0,
         0) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(
      arrObj.pObject,
      binaryData->Data.Data,
      binaryData->Data.Size);
    Scaleform::GFx::AS3::Value::Assign(&this->data, arrObj.pObject);
  }
  if ( arrObj.pObject )
  {
    if ( ((int)arrObj.pObject & 1) != 0 )
    {
      --arrObj.pObject;
    }
    else
    {
      RefCount = arrObj.pObject->RefCount;
      pObject = arrObj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        arrObj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( v5 && ((unsigned __int8)v5 & 1) == 0 )
  {
    v8 = v5->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
    {
      v5->RefCount = v8 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
    }
  }
}
