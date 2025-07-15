void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::heightGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        int *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  int v3; // eax

  pObject = this->Content.pObject;
  if ( pObject )
  {
    v3 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->pDispObj.pObject->GetResourceMovieDef)(
           pObject->pDispObj.pObject,
           0);
    *result = (int)((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 28))(v3);
  }
  else
  {
    *result = 0;
  }
}
