void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::contentTypeGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  int v3; // eax

  pObject = this->Content.pObject;
  if ( !pObject )
    goto LABEL_6;
  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->pDispObj.pObject->GetResourceMovieDef)(
                                             pObject->pDispObj.pObject,
                                             0)
                                         + 28)
                             + 12)
                 + 28);
  if ( v3 == 1 )
  {
    Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"application/x-shockwave-flash");
    return;
  }
  if ( v3 == 2 )
    Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"image");
  else
LABEL_6:
    Scaleform::GFx::ASString::operator=(result, (Scaleform::GFx::ASStringNode *)"unknown");
}
