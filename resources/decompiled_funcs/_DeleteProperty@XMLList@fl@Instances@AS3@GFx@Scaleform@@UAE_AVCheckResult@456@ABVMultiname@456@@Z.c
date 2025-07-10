Scaleform::GFx::AS3::CheckResult *__userpurge Scaleform::GFx::AS3::Instances::fl::XMLList::DeleteProperty@<eax>(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this@<ecx>,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        char a4)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v6; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // ebx
  const Scaleform::GFx::ASString *v8; // eax
  int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  unsigned int Size; // ebp
  int v13; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v14; // esi
  const Scaleform::GFx::AS3::Value *v15; // [esp+0h] [ebp-44h]
  Scaleform::GFx::AS3::CheckResult v16; // [esp+13h] [ebp-31h] BYREF
  unsigned int ind; // [esp+14h] [ebp-30h] BYREF
  unsigned int q; // [esp+18h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Value v19; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+2Ch] [ebp-18h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&v16, prop_name, &ind)->Result )
  {
    if ( ind < this->List.Data.Size )
    {
      pObject = this->List.Data.Data[ind].pObject;
      v6 = pObject->Parent.pObject;
      p_List = &this->List;
      if ( v6 )
      {
        if ( pObject->GetKind(pObject) == kAttr )
        {
          v8 = pObject->GetName(pObject);
          Scaleform::GFx::AS3::Value::Value(&v19, v8);
          v10 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, int))pObject->GetCurrNamespace)(
                                                                   pObject,
                                                                   v9);
          Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&mn.Obj, v10, v15);
          Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&v19.Bonus);
          ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, char *))v6->DeleteProperty)(v6, &a4);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        }
        else if ( pObject->GetChildIndex(pObject, (Scaleform::GFx::AS3::CheckResult *)&prop_name, &q)->Result )
        {
          v6->DeleteByIndex(v6, q);
        }
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)p_List,
        ind);
    }
    goto LABEL_9;
  }
  Size = this->List.Data.Size;
  v13 = 0;
  if ( !Size )
  {
LABEL_9:
    v11 = result;
    result->Result = 1;
    return v11;
  }
  while ( 1 )
  {
    v14 = this->List.Data.Data[v13].pObject;
    if ( v14->GetKind(v14) == kElement && !v14->DeleteProperty(v14, &v16, prop_name)->Result )
      break;
    if ( ++v13 >= Size )
    {
      v11 = result;
      result->Result = 1;
      return v11;
    }
  }
  v11 = result;
  result->Result = 0;
  return v11;
}
