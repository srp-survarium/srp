char __thiscall Scaleform::GFx::Button::PointTestLocal(
        Scaleform::GFx::Button *this,
        const Scaleform::Render::Point<float> *pt,
        int hitTestMask)
{
  Scaleform::GFx::Button_vtbl *v4; // edx
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  Scaleform::Render::Rect<float> *v6; // eax
  int v8; // ebx
  Scaleform::GFx::DisplayObjectBase *pObject; // esi
  float *v10; // eax
  Scaleform::Render::Point<float> result; // [esp+60h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v12; // [esp+70h] [ebp-20h] BYREF

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || (hitTestMask & 2) != 0 && !this->GetVisible(this) )
  {
    return 0;
  }
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 1) == 0 )
  {
    v4 = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v12.M[0][0] = 1.0;
    GetBounds = v4->GetBounds;
    v12.M[0][1] = 0.0;
    v12.M[0][2] = 0.0;
    v12.M[0][3] = 0.0;
    v12.M[1][0] = 0.0;
    v12.M[1][2] = 0.0;
    v12.M[1][3] = 0.0;
    v12.M[1][1] = 1.0;
    v6 = GetBounds(this, (Scaleform::Render::Rect<float> *)&result, &v12);
    if ( !Scaleform::Render::Rect<float>::Contains(v6, pt) )
      return 0;
    if ( (hitTestMask & 1) == 0 )
      return 1;
  }
  v8 = 0;
  if ( this->States[3].Characters.Data.Size )
  {
    while ( 1 )
    {
      pObject = this->States[3].Characters.Data.Data[v8].Char.pObject;
      if ( pObject && ((hitTestMask & 2) == 0 || pObject->GetVisible(pObject)) )
      {
        v10 = (float *)pObject->GetMatrix(pObject);
        v12.M[0][0] = *v10;
        v12.M[0][1] = v10[1];
        v12.M[0][2] = v10[2];
        v12.M[0][3] = v10[3];
        v12.M[1][0] = v10[4];
        v12.M[1][1] = v10[5];
        v12.M[1][2] = v10[6];
        v12.M[1][3] = v10[7];
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v12, &result, pt);
        if ( pObject->PointTestLocal(pObject, &result, hitTestMask) )
          break;
      }
      if ( ++v8 >= this->States[3].Characters.Data.Size )
        return 0;
    }
    return 1;
  }
  return 0;
}
