void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Vector3D::nearEquals(
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *this,
        bool *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Vector3D *toCompare,
        double tolerance,
        bool allFour)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  long double v8; // st7
  bool v9; // c0
  bool v10; // c3
  long double v11; // st7
  long double v12; // st5
  long double v13; // st5
  bool v14; // al
  bool v15; // zf
  long double v16; // st5
  long double v17; // st6

  if ( toCompare )
  {
    v8 = this->x - toCompare->x;
    if ( v8 < 0.0 )
      v8 = -v8;
    v9 = tolerance < v8;
    v10 = tolerance == v8;
    v11 = tolerance;
    if ( v9 || v10 )
      goto LABEL_14;
    v12 = this->y - toCompare->y;
    if ( v12 < 0.0 )
      v12 = -v12;
    if ( v12 >= tolerance )
      goto LABEL_14;
    v13 = this->z - toCompare->z;
    if ( v13 < 0.0 )
      v13 = -v13;
    if ( v13 >= tolerance )
LABEL_14:
      v14 = 0;
    else
      v14 = 1;
    v15 = !allFour;
    *result = v14;
    if ( !v15 )
    {
      if ( !v14 )
        goto LABEL_21;
      v16 = this->w - toCompare->w;
      v17 = v16;
      if ( v16 < 0.0 )
        v17 = -v16;
      if ( v17 < v11 )
        *result = 1;
      else
LABEL_21:
        *result = 0;
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&tolerance, eConvertNullToObjectError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    v7 = (Scaleform::GFx::ASStringNode *)HIDWORD(tolerance);
    --*(_DWORD *)(HIDWORD(tolerance) + 12);
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
