void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::matrix3DGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  int v3; // edi
  Scaleform::GFx::AS3::Value *v4; // eax
  int i; // ecx
  const __m128i *v6; // eax
  Scaleform::GFx::AS3::Value *v7; // esi
  unsigned int Flags; // eax
  char v9; // cl
  unsigned int v10; // edx
  Scaleform::GFx::AS3::Object *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v12; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  int j; // edi
  unsigned int v16; // eax
  unsigned int v17; // edx
  Scaleform::GFx::AS3::Object *v18; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+6B8h] [ebp-17Ch] BYREF
  Scaleform::GFx::AS3::ASVM *pVM; // [esp+6BCh] [ebp-178h]
  float v21; // [esp+6C0h] [ebp-174h]
  Scaleform::Render::Matrix3x4<float> dst; // [esp+6C4h] [ebp-170h] BYREF
  Scaleform::Render::Matrix4x4<float> v23; // [esp+6F4h] [ebp-140h] BYREF
  Scaleform::GFx::AS3::Value v24; // [esp+734h] [ebp-100h] BYREF
  char vars0; // [esp+834h] [ebp+0h] BYREF

  v3 = 0;
  if ( this->pDispObj )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    pobj.pObject = 0;
    v4 = &v24;
    for ( i = 15; i >= 0; --i )
    {
      v4->Flags = 0;
      v4->Bonus.pWeakProxy = 0;
      ++v4;
    }
    v6 = (const __m128i *)this->pDispObj->GetMatrix3D(this->pDispObj);
    memcpy((int)&dst, v6, sizeof(dst));
    Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v23, &dst);
    v7 = &v24;
    do
    {
      Flags = v7->Flags;
      v9 = v7->Flags;
      v21 = v23.M[0][v3];
      if ( (v9 & 0x1Fu) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v7);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
      }
      v10 = v7->Flags & 0xFFFFFFE4;
      v7->value.VNumber = v21;
      v7->Flags = v10 | 4;
      ++v3;
      ++v7;
    }
    while ( v3 < 16 );
    if ( Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->Matrix3DClass.pObject, 0x10u, &v24) )
      pobj.pObject[5].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)this->pDispObj;
    if ( &pobj != result )
    {
      pObject = pobj.pObject;
      if ( pobj.pObject )
      {
        ++pobj.pObject->RefCount;
        pObject->RefCount &= 0x8FBFFFFF;
      }
      v12 = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)result->pObject;
      if ( result->pObject )
      {
        if ( ((unsigned __int8)v12 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)((char *)v12 - 1);
        }
        else
        {
          RefCount = v12->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v12->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
      result->pObject = pobj.pObject;
    }
    v14 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( j = 15; j >= 0; --j )
    {
      v16 = v14[-1].Flags;
      --v14;
      if ( (v16 & 0x1F) > 9 )
      {
        if ( (v16 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v14);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v14);
      }
    }
    if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
    {
      v17 = pobj.pObject->RefCount;
      v18 = pobj.pObject;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        pobj.pObject->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
      }
    }
  }
}
