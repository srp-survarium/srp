void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Transform::pixelBoundsGet(
        Scaleform::GFx::AS3::Instances::fl_geom::Transform *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *result)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DisplayObject *v5; // esi
  Scaleform::GFx::DisplayObject_vtbl *v6; // ebx
  int v7; // eax
  double v8; // st7
  double v9; // st7
  unsigned int Flags; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  Scaleform::GFx::AS3::Value *v17; // esi
  int i; // edi
  unsigned int v19; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Object *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [esp+100h] [ebp-58h] BYREF
  int v23; // [esp+104h] [ebp-54h]
  float v24; // [esp+108h] [ebp-50h] BYREF
  float v25; // [esp+10Ch] [ebp-4Ch]
  float v26; // [esp+110h] [ebp-48h]
  float v27; // [esp+114h] [ebp-44h]
  Scaleform::GFx::AS3::Value v28; // [esp+118h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v29; // [esp+128h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v30; // [esp+138h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v31; // [esp+148h] [ebp-10h] BYREF
  char vars0; // [esp+158h] [ebp+0h] BYREF

  if ( this->pDispObj )
  {
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    pobj.pObject = 0;
    v28.Flags = 0;
    v28.Bonus.pWeakProxy = 0;
    v29.Flags = 0;
    v29.Bonus.pWeakProxy = 0;
    v30.Flags = 0;
    v30.Bonus.pWeakProxy = 0;
    v31.Flags = 0;
    v31.Bonus.pWeakProxy = 0;
    pDispObj = this->pDispObj;
    v5 = this->pDispObj;
    v6 = pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v7 = ((int (*)(void))pDispObj->GetMatrix)();
    v6->GetBounds(v5, (Scaleform::Render::Rect<float> *)&v24, (const Scaleform::Render::Matrix2x4<float> *)v7);
    *(float *)&v23 = v24 * 0.05000000074505806;
    v8 = *(float *)&v23;
    if ( *(float *)&v23 <= 0.0 )
      v9 = v8 - 0.5;
    else
      v9 = v8 + 0.5;
    v23 = (int)v9;
    Flags = v28.Flags;
    if ( (v28.Flags & 0x1F) > 9 )
    {
      if ( (v28.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v28);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v28);
      Flags = v28.Flags;
    }
    v28.Flags = Flags & 0xFFFFFFE0 | 4;
    v28.value.VNumber = (double)v23;
    *(float *)&v23 = v25 * 0.05000000074505806;
    v11 = *(float *)&v23;
    if ( *(float *)&v23 <= 0.0 )
      v12 = v11 - 0.5;
    else
      v12 = v11 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&v29, (double)(int)v12);
    *(float *)&v23 = v26 - v24;
    *(float *)&v23 = *(float *)&v23 * 0.05000000074505806;
    v13 = *(float *)&v23;
    if ( *(float *)&v23 <= 0.0 )
      v14 = v13 - 0.5;
    else
      v14 = v13 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&v30, (double)(int)v14);
    *(float *)&v23 = v27 - v25;
    *(float *)&v23 = *(float *)&v23 * 0.05000000074505806;
    v15 = *(float *)&v23;
    if ( *(float *)&v23 <= 0.0 )
      v16 = v15 - 0.5;
    else
      v16 = v15 + 0.5;
    v23 = (int)v16;
    Scaleform::GFx::AS3::Value::SetNumber(&v31, (double)(int)v16);
    Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, pVM->RectangleClass.pObject, 4u, &v28);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      result,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&pobj);
    v17 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( i = 3; i >= 0; --i )
    {
      v19 = v17[-1].Flags;
      --v17;
      if ( (v19 & 0x1F) > 9 )
      {
        if ( (v19 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v17);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v17);
      }
    }
    if ( pobj.pObject && ((int)pobj.pObject & 1) == 0 )
    {
      RefCount = pobj.pObject->RefCount;
      pObject = pobj.pObject;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pobj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}
