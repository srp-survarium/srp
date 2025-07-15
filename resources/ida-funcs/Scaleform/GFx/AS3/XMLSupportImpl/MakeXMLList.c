Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::MakeXMLList(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // esi
  Scaleform::GFx::AS3::VM *pVM; // ecx
  unsigned int MemSize; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v5; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v7; // eax
  int v8; // [esp+8h] [ebp-4h] BYREF

  v2 = this->GetITraitsXMLList(this);
  pVM = v2->pVM;
  MemSize = v2->MemSize;
  v8 = 337;
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)pVM->MHeap->Alloc(
                                                        pVM->MHeap,
                                                        MemSize,
                                                        (const Scaleform::AllocInfo *)&v8);
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLList::XMLList(v5, v2);
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
