void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::bytesTotalGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *p_pDispObj; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // eax
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v5; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  pObject = this->Content.pObject;
  if ( pObject )
  {
    p_pDispObj = &pObject->pDispObj;
  }
  else
  {
    v6 = 0;
    p_pDispObj = (Scaleform::Ptr<Scaleform::GFx::DisplayObject> *)&v6;
  }
  if ( p_pDispObj->pObject )
  {
    v4 = this->Content.pObject;
    if ( v4 )
    {
      v5 = &v4->pDispObj;
    }
    else
    {
      v6 = 0;
      v5 = (Scaleform::Ptr<Scaleform::GFx::DisplayObject> *)&v6;
    }
    *result = v5->pObject->GetResourceMovieDef(v5->pObject)->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength;
  }
  else
  {
    *result = this->BytesTotal;
  }
}
