void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3childIndex(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        int *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  int *v4; // esi
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-5h] BYREF
  int v6; // [esp+8h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5)->Result )
  {
    pObject = this->List.Data.Data->pObject;
    v4 = result;
    *result = -1;
    if ( pObject->GetChildIndex(pObject, (Scaleform::GFx::AS3::CheckResult *)&result, (unsigned int *)&v6)->Result )
      *v4 = v6;
  }
}
