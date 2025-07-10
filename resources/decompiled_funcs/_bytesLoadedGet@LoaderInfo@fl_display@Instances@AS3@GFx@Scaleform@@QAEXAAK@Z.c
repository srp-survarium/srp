void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::bytesLoadedGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        unsigned int *result)
{
  char v2; // bl
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  Scaleform::RefCountNTSImpl *v5; // ecx
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *p_pDispObj; // eax
  Scaleform::GFx::DisplayObject *v7; // edi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // eax
  Scaleform::RefCountNTSImpl *v9; // ecx
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v10; // eax
  Scaleform::GFx::DisplayObject *v11; // esi
  Scaleform::RefCountNTSImpl *v12; // [esp+8h] [ebp-8h] BYREF
  Scaleform::RefCountNTSImpl *v13; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  v13 = 0;
  pObject = this->Content.pObject;
  if ( pObject )
  {
    v5 = v12;
    p_pDispObj = &pObject->pDispObj;
  }
  else
  {
    v5 = 0;
    v2 = 1;
    v12 = 0;
    p_pDispObj = (Scaleform::Ptr<Scaleform::GFx::DisplayObject> *)&v12;
  }
  v7 = p_pDispObj->pObject;
  if ( (v2 & 1) != 0 )
  {
    v2 &= ~1u;
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release(v5);
  }
  if ( v7 )
  {
    v8 = this->Content.pObject;
    if ( v8 )
    {
      v9 = v13;
      v10 = &v8->pDispObj;
    }
    else
    {
      v2 |= 2u;
      v9 = 0;
      v13 = 0;
      v10 = (Scaleform::Ptr<Scaleform::GFx::DisplayObject> *)&v13;
    }
    v11 = v10->pObject;
    if ( (v2 & 2) != 0 )
    {
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release(v9);
    }
    *result = v11->GetResourceMovieDef(v11)->pBindData.pObject->BytesLoaded;
  }
  else
  {
    *result = this->BytesLoaded;
  }
}
