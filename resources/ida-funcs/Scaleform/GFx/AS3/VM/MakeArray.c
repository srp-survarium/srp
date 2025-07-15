Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *__thiscall Scaleform::GFx::AS3::VM::MakeArray(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v7; // eax
  int v8; // [esp+8h] [ebp-4h] BYREF

  pObject = this->TraitsArray.pObject->ITraits.pObject;
  pVM = pObject->pVM;
  MemSize = pObject->MemSize;
  v8 = 337;
  v5 = (Scaleform::GFx::AS3::Instances::fl::Array *)pVM->MHeap->Alloc(
                                                      pVM->MHeap,
                                                      MemSize,
                                                      (const Scaleform::AllocInfo *)&v8);
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::fl::Array::Array(v5, pObject);
    result->pV = v6;
    return result;
  }
  else
  {
    v7 = result;
    result->pV = 0;
  }
  return v7;
}
