void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::concatenatedColorTransformGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::DisplayObject *pDispObj; // esi
  unsigned int v5; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  const Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::Cxform *v9; // esi
  int i; // edi
  float v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Object *v13; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+180h] [ebp-A4h] BYREF
  Scaleform::GFx::AS3::Value v15; // [esp+184h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value v16; // [esp+194h] [ebp-90h]
  Scaleform::GFx::AS3::Value v17; // [esp+1A4h] [ebp-80h]
  Scaleform::GFx::AS3::Value v18; // [esp+1B4h] [ebp-70h]
  Scaleform::GFx::AS3::Value v19; // [esp+1C4h] [ebp-60h]
  Scaleform::GFx::AS3::Value v20; // [esp+1D4h] [ebp-50h]
  Scaleform::GFx::AS3::Value v21; // [esp+1E4h] [ebp-40h]
  Scaleform::GFx::AS3::Value v22; // [esp+1F4h] [ebp-30h]
  Scaleform::Render::Cxform v23; // [esp+204h] [ebp-20h] BYREF

  pobj.pObject = 0;
  Scaleform::Render::Cxform::Cxform(&v23);
  pObject = this->pTraits.pObject;
  pDispObj = this->pDispObj;
  v5 = 0;
  Flags = 0;
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
  v20.Flags = 0;
  v20.Bonus.pWeakProxy = 0;
  v21.Flags = 0;
  v21.Bonus.pWeakProxy = 0;
  v22.Flags = 0;
  v22.Bonus.pWeakProxy = 0;
  pVM = (Scaleform::GFx::AS3::ASVM *)pObject->pVM;
  if ( pDispObj )
  {
    do
    {
      Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(pDispObj);
      Scaleform::Render::Cxform::Append(&v23, Cxform);
      pDispObj = pDispObj->pParent;
    }
    while ( pDispObj );
    Flags = v16.Flags;
    v5 = v15.Flags;
  }
  v15.value.VNumber = v23.M[0][0];
  v15.Flags = v5 & 0xFFFFFFE0 | 4;
  v16.value.VNumber = v23.M[0][1];
  v16.Flags = Flags & 0xFFFFFFE0 | 4;
  v17.value.VNumber = v23.M[0][2];
  v17.Flags = v17.Flags & 0xFFFFFFE0 | 4;
  v18.value.VNumber = v23.M[0][3];
  v18.Flags = v18.Flags & 0xFFFFFFE0 | 4;
  v19.value.VNumber = v23.M[1][0] * 255.0;
  v19.Flags = v19.Flags & 0xFFFFFFE0 | 4;
  v20.value.VNumber = v23.M[1][1] * 255.0;
  v20.Flags = v20.Flags & 0xFFFFFFE0 | 4;
  v21.value.VNumber = v23.M[1][2] * 255.0;
  v21.Flags = v21.Flags & 0xFFFFFFE0 | 4;
  v22.value.VNumber = v23.M[1][3] * 255.0;
  v22.Flags = v22.Flags & 0xFFFFFFE0 | 4;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->ColorTransformClass.pObject, 8u, &v15);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
    result,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
  v9 = &v23;
  for ( i = 7; i >= 0; --i )
  {
    v11 = v9[-1].M[1][0];
    v9 = (Scaleform::Render::Cxform *)((char *)v9 - 16);
    if ( (LOBYTE(v11) & 0x1Fu) > 9 )
    {
      if ( (LOWORD(v11) & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)v9);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)v9);
    }
  }
  if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
  {
    RefCount = pobj.pObject->RefCount;
    v13 = pobj.pObject;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pobj.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
    }
  }
}
