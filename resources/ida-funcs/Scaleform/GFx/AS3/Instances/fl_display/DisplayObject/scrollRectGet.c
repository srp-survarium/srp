void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scrollRectGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // esi
  long double x1; // st7
  long double v5; // st7
  long double v6; // st7
  long double v7; // st6
  long double v8; // st7
  long double v9; // st7
  long double v10; // st7
  long double v11; // st7
  long double v12; // st7
  Scaleform::GFx::AS3::Value *v13; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value argv[4]; // [esp+48h] [ebp-40h] BYREF
  char vars0; // [esp+88h] [ebp+0h] BYREF

  pScrollRect = this->pDispObj.pObject->pScrollRect;
  if ( pScrollRect )
  {
    x1 = pScrollRect->Rectangle.x1;
    argv[0].Bonus.pWeakProxy = 0;
    argv[1].Flags = 0;
    v5 = x1 * 0.05;
    argv[1].Bonus.pWeakProxy = 0;
    argv[2].Flags = 0;
    argv[2].Bonus.pWeakProxy = 0;
    argv[3].Flags = 0;
    argv[3].Bonus.pWeakProxy = 0;
    if ( v5 <= 0.0 )
      v6 = v5 - 0.5;
    else
      v6 = v5 + 0.5;
    argv[0].Flags = 4;
    argv[0].value.VNumber = (double)(int)v6;
    v7 = 0.05 * pScrollRect->Rectangle.y1;
    if ( v7 <= 0.0 )
      v8 = v7 - 0.5;
    else
      v8 = v7 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[1], (double)(int)v8);
    v9 = (pScrollRect->Rectangle.x2 - pScrollRect->Rectangle.x1) * 0.05;
    if ( v9 <= 0.0 )
      v10 = v9 - 0.5;
    else
      v10 = v9 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[2], (double)(int)v10);
    v11 = (pScrollRect->Rectangle.y2 - pScrollRect->Rectangle.y1) * 0.05;
    if ( v11 <= 0.0 )
      v12 = v11 - 0.5;
    else
      v12 = v11 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[3], (double)(int)v12);
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
      result,
      (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.Size,
      4u,
      argv);
    v13 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( i = 3; i >= 0; --i )
    {
      Flags = v13[-1].Flags;
      --v13;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v13);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
      }
    }
  }
  else
  {
    pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)((char *)pObject - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
        result->pObject = 0;
      }
    }
  }
}
