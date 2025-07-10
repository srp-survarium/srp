void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::startDrag(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        bool lockCenter,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *bounds)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  long double x; // st7
  double v8; // st7
  long double v9; // st5
  double v10; // st7
  Scaleform::GFx::MovieImpl::DragState st; // [esp+8h] [ebp-24h] BYREF
  float boundsa; // [esp+38h] [ebp+Ch]
  float boundsb; // [esp+38h] [ebp+Ch]
  float boundsc; // [esp+38h] [ebp+Ch]
  float boundsd; // [esp+38h] [ebp+Ch]

  pMovieImpl = this->pDispObj.pObject->pASRoot->pMovieImpl;
  if ( !Scaleform::GFx::MovieImpl::IsDragging(pMovieImpl, 0) )
  {
    st.LockCenter = 0;
    st.BoundLT.y = 0.0;
    st.Bound = 0;
    st.BoundLT.x = 0.0;
    st.BoundRB.y = 0.0;
    st.MouseIndex = -1;
    st.BoundRB.x = 0.0;
    st.CenterDelta.y = 0.0;
    st.CenterDelta.x = 0.0;
    if ( bounds )
    {
      x = bounds->x;
      st.Bound = 1;
      boundsa = x;
      v8 = boundsa;
      st.BoundLT.x = boundsa * 20.0;
      boundsb = bounds->y;
      st.BoundLT.y = boundsb * 20.0;
      v9 = v8 + bounds->width;
      v10 = boundsb;
      boundsc = v9;
      st.BoundRB.x = boundsc * 20.0;
      boundsd = v10 + bounds->height;
      st.BoundRB.y = 20.0 * boundsd;
    }
    st.pCharacter = (Scaleform::GFx::InteractiveObject *)this->pDispObj.pObject;
    Scaleform::GFx::MovieImpl::DragState::InitCenterDelta(&st, lockCenter, 0);
    Scaleform::GFx::MovieImpl::SetDragState(pMovieImpl, &st);
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList((Scaleform::GFx::InteractiveObject *)this->pDispObj.pObject);
  }
}
