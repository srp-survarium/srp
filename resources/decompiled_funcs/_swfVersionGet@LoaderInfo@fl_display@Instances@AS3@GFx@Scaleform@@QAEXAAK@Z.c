void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::swfVersionGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        unsigned int *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  int v3; // eax

  pObject = this->Content.pObject;
  if ( pObject )
  {
    v3 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject *, _DWORD))pObject->pDispObj.pObject->GetResourceMovieDef)(
           pObject->pDispObj.pObject,
           0);
    *result = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 16))(v3);
  }
  else
  {
    *result = 0;
  }
}
