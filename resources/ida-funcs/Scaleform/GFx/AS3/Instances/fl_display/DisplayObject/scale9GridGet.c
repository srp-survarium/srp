void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scale9GridGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle> *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v4; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *v7; // ecx
  unsigned int RefCount; // eax
  float v9; // [esp+FCh] [ebp-64h]
  float v10; // [esp+FCh] [ebp-64h]
  float v11; // [esp+FCh] [ebp-64h]
  float v12; // [esp+FCh] [ebp-64h]
  float v13; // [esp+FCh] [ebp-64h]
  float v14; // [esp+FCh] [ebp-64h]
  Scaleform::GFx::AS3::Value v15; // [esp+100h] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v16; // [esp+110h] [ebp-50h] BYREF
  _DWORD v17[2]; // [esp+120h] [ebp-40h] BYREF
  double v18; // [esp+128h] [ebp-38h]
  int v19; // [esp+130h] [ebp-30h]
  int v20; // [esp+134h] [ebp-2Ch]
  double v21; // [esp+138h] [ebp-28h]
  int v22; // [esp+140h] [ebp-20h]
  int v23; // [esp+144h] [ebp-1Ch]
  double v24; // [esp+148h] [ebp-18h]
  int v25; // [esp+150h] [ebp-10h]
  int v26; // [esp+154h] [ebp-Ch]
  double v27; // [esp+158h] [ebp-8h]
  char vars0; // [esp+160h] [ebp+0h] BYREF

  if ( Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this->pDispObj.pObject) )
  {
    Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj.pObject, &v16);
    pObject = this->pTraits.pObject;
    v17[1] = 0;
    v20 = 0;
    v9 = v16.x1 * 0.05000000074505806;
    v23 = 0;
    v26 = 0;
    v18 = v9;
    v15.Flags = 0;
    v15.Bonus.pWeakProxy = 0;
    v17[0] = 4;
    v19 = 4;
    v22 = 4;
    v25 = 4;
    v10 = v16.y1 * 0.05000000074505806;
    v21 = v10;
    v11 = v16.x2 - v16.x1;
    v12 = v11 * 0.05000000074505806;
    v24 = v12;
    v13 = v16.y2 - v16.y1;
    v14 = 0.05000000074505806 * v13;
    v27 = v14;
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS3::Value *, int, _DWORD *, int))(*(_DWORD *)pObject->pVM[1].ScopeStack.Data.Size
                                                                                           + 48))(
      pObject->pVM[1].ScopeStack.Data.Size,
      &v15,
      4,
      v17,
      1);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v15.value.VS._1.VInt);
    if ( (v15.Flags & 0x1F) > 9 )
    {
      if ( (v15.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    }
    v4 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( i = 3; i >= 0; --i )
    {
      Flags = v4[-1].Flags;
      --v4;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v4);
      }
    }
  }
  else
  {
    v7 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *)((char *)v7 - 1);
        result->pObject = 0;
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
        result->pObject = 0;
      }
    }
  }
}
