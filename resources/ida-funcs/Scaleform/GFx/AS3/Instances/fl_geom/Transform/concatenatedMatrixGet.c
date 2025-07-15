void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::concatenatedMatrixGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // esi
  unsigned int v3; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  const Scaleform::Render::Matrix2x4<float> *v7; // eax
  Scaleform::Render::Matrix2x4<float> *v8; // esi
  int i; // edi
  float v10; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Object *v12; // ecx
  float v13; // [esp+130h] [ebp-8Ch]
  float v14; // [esp+130h] [ebp-8Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+138h] [ebp-84h] BYREF
  Scaleform::GFx::AS3::Value v16; // [esp+13Ch] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value v17; // [esp+14Ch] [ebp-70h]
  Scaleform::GFx::AS3::Value v18; // [esp+15Ch] [ebp-60h]
  Scaleform::GFx::AS3::Value v19; // [esp+16Ch] [ebp-50h]
  Scaleform::GFx::AS3::Value v20; // [esp+17Ch] [ebp-40h]
  Scaleform::GFx::AS3::Value v21; // [esp+18Ch] [ebp-30h]
  Scaleform::Render::Matrix2x4<float> v22; // [esp+19Ch] [ebp-20h] BYREF

  v22.M[0][0] = 1.0;
  pObject = this->pTraits.pObject;
  v22.M[0][1] = 0.0;
  v22.M[0][2] = 0.0;
  v3 = 0;
  v22.M[0][3] = 0.0;
  Flags = 0;
  v22.M[1][0] = 0.0;
  v22.M[1][2] = 0.0;
  pobj.pObject = 0;
  v22.M[1][3] = 0.0;
  v16.Flags = 0;
  v16.Bonus.pWeakProxy = 0;
  v17.Flags = 0;
  v17.Bonus.pWeakProxy = 0;
  v22.M[1][1] = 1.0;
  v18.Flags = 0;
  v18.Bonus.pWeakProxy = 0;
  v19.Flags = 0;
  v19.Bonus.pWeakProxy = 0;
  v20.Flags = 0;
  v20.Bonus.pWeakProxy = 0;
  v21.Flags = 0;
  v21.Bonus.pWeakProxy = 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  pDispObj = this->pDispObj;
  if ( pDispObj )
  {
    do
    {
      v7 = pDispObj->GetMatrix(pDispObj);
      Scaleform::Render::Matrix2x4<float>::Append(&v22, v7);
      pDispObj = pDispObj->pParent;
    }
    while ( pDispObj );
    Flags = v17.Flags;
    v3 = v16.Flags;
  }
  v16.value.VNumber = v22.M[0][0];
  v16.Flags = v3 & 0xFFFFFFE0 | 4;
  v17.value.VNumber = v22.M[1][0];
  v17.Flags = Flags & 0xFFFFFFE0 | 4;
  v18.value.VNumber = v22.M[0][1];
  v18.Flags = v18.Flags & 0xFFFFFFE0 | 4;
  v19.value.VNumber = v22.M[1][1];
  v19.Flags = v19.Flags & 0xFFFFFFE0 | 4;
  v13 = v22.M[0][3] * 0.05000000074505806;
  v20.value.VNumber = v13;
  v20.Flags = v20.Flags & 0xFFFFFFE0 | 4;
  v14 = v22.M[1][3] * 0.05000000074505806;
  v21.value.VNumber = v14;
  v21.Flags = v21.Flags & 0xFFFFFFE0 | 4;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->MatrixClass.pObject, 6u, &v16);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
  v8 = &v22;
  for ( i = 5; i >= 0; --i )
  {
    v10 = v8[-1].M[1][0];
    v8 = (Scaleform::Render::Matrix2x4<float> *)((char *)v8 - 16);
    if ( (LOBYTE(v10) & 0x1Fu) > 9 )
    {
      if ( (LOWORD(v10) & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)v8);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)v8);
    }
  }
  if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
  {
    RefCount = pobj.pObject->RefCount;
    v12 = pobj.pObject;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pobj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
    }
  }
}
