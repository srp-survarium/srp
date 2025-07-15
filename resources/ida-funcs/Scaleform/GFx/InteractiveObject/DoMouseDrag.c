void __thiscall Scaleform::GFx::InteractiveObject::DoMouseDrag(
        Scaleform::GFx::InteractiveObject *this,
        unsigned int mouseIndex)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int v5; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  double x; // st7
  double v8; // st7
  double y; // st7
  double v10; // st7
  Scaleform::Render::Point<float> p; // [esp+24h] [ebp-80h] BYREF
  Scaleform::Render::Point<float> result; // [esp+2Ch] [ebp-78h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+34h] [ebp-70h] BYREF
  Scaleform::Render::Matrix2x4<float> v14; // [esp+54h] [ebp-50h] BYREF
  Scaleform::GFx::MovieImpl::DragState st; // [esp+80h] [ebp-24h] BYREF

  st.BoundLT.y = 0.0;
  st.BoundLT.x = 0.0;
  pASRoot = this->pASRoot;
  st.BoundRB.y = 0.0;
  st.BoundRB.x = 0.0;
  st.CenterDelta.y = 0.0;
  st.CenterDelta.x = 0.0;
  st.pCharacter = 0;
  st.LockCenter = 0;
  st.Bound = 0;
  st.MouseIndex = -1;
  pMovieImpl = pASRoot->pMovieImpl;
  Scaleform::GFx::MovieImpl::GetDragState(pMovieImpl, mouseIndex, &st);
  if ( this == st.pCharacter )
  {
    if ( mouseIndex < 6 )
      v5 = (unsigned int)&pMovieImpl->mMouseState[mouseIndex];
    else
      v5 = 0;
    pParent = this->pParent;
    p.x = *(float *)(v5 + 32);
    p.y = *(float *)(v5 + 36);
    v14.M[0][0] = 1.0;
    v14.M[0][1] = 0.0;
    v14.M[0][2] = 0.0;
    v14.M[0][3] = 0.0;
    v14.M[1][0] = 0.0;
    v14.M[1][2] = 0.0;
    v14.M[1][3] = 0.0;
    v14.M[1][1] = 1.0;
    if ( pParent )
    {
      pmat.M[0][0] = 1.0;
      pmat.M[1][1] = 1.0;
      pmat.M[0][1] = 0.0;
      pmat.M[0][2] = 0.0;
      pmat.M[0][3] = 0.0;
      pmat.M[1][0] = 0.0;
      pmat.M[1][2] = 0.0;
      pmat.M[1][3] = 0.0;
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
      v14.M[0][0] = pmat.M[0][0];
      v14.M[0][1] = pmat.M[0][1];
      v14.M[0][2] = pmat.M[0][2];
      v14.M[0][3] = pmat.M[0][3];
      v14.M[1][0] = pmat.M[1][0];
      v14.M[1][1] = pmat.M[1][1];
      v14.M[1][2] = pmat.M[1][2];
      v14.M[1][3] = pmat.M[1][3];
    }
    Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v14, &result, &p);
    result.x = st.CenterDelta.x + result.x;
    result.y = st.CenterDelta.y + result.y;
    if ( st.Bound )
    {
      x = result.x;
      if ( st.BoundRB.x <= (double)result.x )
        x = st.BoundRB.x;
      p.x = x;
      v8 = p.x;
      if ( st.BoundLT.x > (double)p.x )
        v8 = st.BoundLT.x;
      result.x = v8;
      y = result.y;
      if ( st.BoundRB.y <= (double)result.y )
        y = st.BoundRB.y;
      p.x = y;
      v10 = p.x;
      if ( st.BoundLT.y > (double)p.x )
        v10 = st.BoundLT.y;
      result.y = v10;
    }
    this->SetAcceptAnimMoves(this, 0);
    ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->SetX)(
      this,
      COERCE_UNSIGNED_INT64(result.x * 0.05),
      HIDWORD(COERCE_UNSIGNED_INT64(result.x * 0.05)));
    ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, _DWORD, _DWORD))this->SetY)(
      this,
      COERCE_UNSIGNED_INT64(result.y * 0.05),
      HIDWORD(COERCE_UNSIGNED_INT64(result.y * 0.05)));
  }
}
