void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::matrixGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  float *v5; // eax
  Scaleform::GFx::AS3::Value *v6; // esi
  int i; // ebx
  unsigned int Flags; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Object *v10; // ecx
  float v11; // [esp+138h] [ebp-8Ch]
  float v12; // [esp+138h] [ebp-8Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+140h] [ebp-84h] BYREF
  Scaleform::GFx::AS3::Value v14; // [esp+144h] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value v15; // [esp+154h] [ebp-70h]
  Scaleform::GFx::AS3::Value v16; // [esp+164h] [ebp-60h]
  Scaleform::GFx::AS3::Value v17; // [esp+174h] [ebp-50h]
  Scaleform::GFx::AS3::Value v18; // [esp+184h] [ebp-40h]
  Scaleform::GFx::AS3::Value v19; // [esp+194h] [ebp-30h]
  float v20; // [esp+1A4h] [ebp-20h] BYREF
  float v21; // [esp+1A8h] [ebp-1Ch]
  float v22; // [esp+1B0h] [ebp-14h]
  float v23; // [esp+1B4h] [ebp-10h]
  float v24; // [esp+1B8h] [ebp-Ch]
  float v25; // [esp+1C0h] [ebp-4h]

  pObject = this->pTraits.pObject;
  pDispObj = this->pDispObj;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  pobj.pObject = 0;
  v14.Flags = 0;
  v14.Bonus.pWeakProxy = 0;
  v15.Flags = 0;
  v15.Bonus.pWeakProxy = 0;
  v16.Flags = 0;
  v16.Bonus.pWeakProxy = 0;
  v17.Flags = 0;
  v17.Bonus.pWeakProxy = 0;
  v18.Flags = 0;
  v18.Bonus.pWeakProxy = 0;
  v19.Flags = 0;
  v19.Bonus.pWeakProxy = 0;
  v5 = (float *)pDispObj->GetMatrix(pDispObj);
  v20 = *v5;
  v21 = v5[1];
  v22 = v5[3];
  v23 = v5[4];
  v24 = v5[5];
  v25 = v5[7];
  v14.value.VNumber = v20;
  v14.Flags = 4;
  v15.value.VNumber = v23;
  v15.Flags = 4;
  v16.value.VNumber = v21;
  v16.Flags = 4;
  v17.value.VNumber = v24;
  v17.Flags = 4;
  v11 = v22 * 0.05000000074505806;
  v18.value.VNumber = v11;
  v18.Flags = 4;
  v12 = v25 * 0.05000000074505806;
  v19.value.VNumber = v12;
  v19.Flags = 4;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->MatrixClass.pObject, 6u, &v14);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
  v6 = (Scaleform::GFx::AS3::Value *)&v20;
  for ( i = 5; i >= 0; --i )
  {
    Flags = v6[-1].Flags;
    --v6;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v6);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
    }
  }
  if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
  {
    RefCount = pobj.pObject->RefCount;
    v10 = pobj.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pobj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
    }
  }
}
