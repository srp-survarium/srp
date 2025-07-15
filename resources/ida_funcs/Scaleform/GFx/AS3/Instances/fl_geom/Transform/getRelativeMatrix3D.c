void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::getRelativeMatrix3D(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *relativeTo)
{
  int v3; // edi
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v8; // eax
  int i; // ecx
  Scaleform::GFx::DisplayObject *pObject; // ecx
  const Scaleform::Render::Matrix3x4<float> *Inverse; // eax
  Scaleform::GFx::AS3::Value *v12; // esi
  unsigned int Flags; // eax
  char v14; // cl
  unsigned int v15; // edx
  Scaleform::GFx::AS3::Object *v16; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v17; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *v19; // esi
  int j; // edi
  unsigned int v21; // eax
  unsigned int v22; // edx
  Scaleform::GFx::AS3::Object *v23; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+AD8h] [ebp-1E0h] BYREF
  float v25; // [esp+ADCh] [ebp-1DCh]
  Scaleform::GFx::AS3::VM::Error v26; // [esp+AE0h] [ebp-1D8h] BYREF
  Scaleform::Render::Matrix3x4<float> pmat; // [esp+AE8h] [ebp-1D0h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+B18h] [ebp-1A0h] BYREF
  Scaleform::Render::Matrix4x4<float> v29; // [esp+B48h] [ebp-170h] BYREF
  Scaleform::Render::Matrix3x4<float> m; // [esp+B88h] [ebp-130h] BYREF
  Scaleform::GFx::AS3::Value v31; // [esp+BB8h] [ebp-100h] BYREF
  char vars0; // [esp+CB8h] [ebp+0h] BYREF

  v3 = 0;
  if ( relativeTo )
  {
    if ( !relativeTo->pDispObj.pObject )
      relativeTo->CreateStageObject(relativeTo);
    v26.ID = (Scaleform::GFx::AS3::VM::ErrorID)this->pTraits.pObject->pVM;
    pobj.pObject = 0;
    v8 = &v31;
    for ( i = 15; i >= 0; --i )
    {
      v8->Flags = 0;
      v8->Bonus.pWeakProxy = 0;
      ++v8;
    }
    memset((int)&dst, 0, sizeof(dst));
    dst.M[0][0] = 1.0;
    dst.M[1][1] = 1.0;
    dst.M[2][2] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(this->pDispObj, &dst);
    memset((int)&pmat, 0, sizeof(pmat));
    pObject = relativeTo->pDispObj.pObject;
    pmat.M[0][0] = 1.0;
    pmat.M[1][1] = 1.0;
    pmat.M[2][2] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pObject, &pmat);
    Inverse = Scaleform::Render::Matrix3x4<float>::GetInverse(&pmat, (Scaleform::Render::Matrix3x4<float> *)&v29);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m, Inverse, &dst);
    Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v29, &m);
    v12 = &v31;
    do
    {
      Flags = v12->Flags;
      v14 = v12->Flags;
      v25 = v29.M[0][v3];
      if ( (v14 & 0x1Fu) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v12);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v12);
      }
      v15 = v12->Flags & 0xFFFFFFE4;
      v12->value.VNumber = v25;
      v12->Flags = v15 | 4;
      ++v3;
      ++v12;
    }
    while ( v3 < 16 );
    if ( Scaleform::GFx::AS3::ASVM::_constructInstance(
           (Scaleform::GFx::AS3::ASVM *)v26.ID,
           &pobj,
           *(Scaleform::GFx::AS3::Object **)(v26.ID + 400),
           0x10u,
           &v31) )
    {
      pobj.pObject[5].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)this->pDispObj;
    }
    if ( &pobj != result )
    {
      v16 = pobj.pObject;
      if ( pobj.pObject )
      {
        ++pobj.pObject->RefCount;
        v16->RefCount &= 0x8FBFFFFF;
      }
      v17 = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)result->pObject;
      if ( result->pObject )
      {
        if ( ((unsigned __int8)v17 & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)((char *)v17 - 1);
        }
        else
        {
          RefCount = v17->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v17->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
          }
        }
      }
      result->pObject = pobj.pObject;
    }
    v19 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( j = 15; j >= 0; --j )
    {
      v21 = v19[-1].Flags;
      --v19;
      if ( (v21 & 0x1F) > 9 )
      {
        if ( (v21 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v19);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v19);
      }
    }
    if ( pobj.pObject )
    {
      if ( ((int)pobj.pObject & 1) == 0 )
      {
        v22 = pobj.pObject->RefCount;
        v23 = pobj.pObject;
        if ( ((unsigned int)&byte_3FFFFF & v22) != 0 )
        {
          pobj.pObject->RefCount = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
        }
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v26, eNullPointerError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v26.Message.pNode;
    --v26.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
