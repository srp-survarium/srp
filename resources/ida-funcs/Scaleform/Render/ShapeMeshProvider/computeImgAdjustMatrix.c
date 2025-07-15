void __thiscall Scaleform::Render::ShapeMeshProvider::computeImgAdjustMatrix(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::Scale9GridData *s9g,
        unsigned int drawLayer,
        unsigned int imgFillStyle,
        Scaleform::Render::Matrix2x4<float> *mtx)
{
  unsigned int StartPos; // edx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  Scaleform::Render::ShapePathType i; // eax
  char v9; // [esp+17h] [ebp-271h]
  Scaleform::Render::Rect<float> v10; // [esp+18h] [ebp-270h] BYREF
  Scaleform::Render::Matrix2x4<float> viewMtx; // [esp+28h] [ebp-260h] BYREF
  float x; // [esp+54h] [ebp-234h] BYREF
  float y; // [esp+58h] [ebp-230h] BYREF
  float x2; // [esp+5Ch] [ebp-22Ch] BYREF
  float y1; // [esp+60h] [ebp-228h] BYREF
  float v16; // [esp+64h] [ebp-224h] BYREF
  float y2; // [esp+68h] [ebp-220h] BYREF
  _DWORD v18[3]; // [esp+6Ch] [ebp-21Ch] BYREF
  Scaleform::Render::ShapePosInfo v19; // [esp+78h] [ebp-210h] BYREF
  float v20[6]; // [esp+B0h] [ebp-1D8h] BYREF
  Scaleform::Render::Scale9GridInfo v21; // [esp+C8h] [ebp-1C0h] BYREF

  StartPos = this->DrawLayers.Data.Data[drawLayer].StartPos;
  v19.Sfactor = 1.0;
  pObject = this->pShapeData.pObject;
  v10.x1 = 1.0e30;
  v10.y1 = 1.0e30;
  v19.Pos = StartPos;
  v10.x2 = -1.0e30;
  v10.y2 = -1.0e30;
  viewMtx.M[0][0] = 1.0;
  memset(&v19.StartX, 0, 44);
  viewMtx.M[0][1] = 0.0;
  viewMtx.M[0][2] = 0.0;
  viewMtx.M[0][3] = 0.0;
  viewMtx.M[1][0] = 0.0;
  viewMtx.M[1][2] = 0.0;
  viewMtx.M[1][3] = 0.0;
  viewMtx.M[1][1] = 1.0;
  v19.Initialized = 0;
  v9 = 1;
  for ( i = pObject->ReadPathInfo(pObject, &v19, v20, v18);
        i;
        i = this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, &v19, v20, v18) )
  {
    if ( !v9 && i == Shape_NewLayer )
      break;
    v9 = 0;
    if ( v18[0] == imgFillStyle || v18[1] == imgFillStyle )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        this->pShapeData.pObject,
        COERCE_FLOAT(&viewMtx),
        &v19,
        COERCE_FLOAT(v20),
        &v10);
    else
      this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, &v19);
  }
  mtx->M[0][0] = 1.0;
  mtx->M[0][1] = 0.0;
  mtx->M[0][2] = 0.0;
  mtx->M[0][3] = 0.0;
  mtx->M[1][0] = 0.0;
  mtx->M[1][2] = 0.0;
  mtx->M[1][3] = 0.0;
  mtx->M[1][1] = 1.0;
  if ( v10.x2 > (double)v10.x1 && v10.y2 > (double)v10.y1 )
  {
    viewMtx.M[0][0] = 1.0;
    viewMtx.M[1][1] = 1.0;
    viewMtx.M[0][1] = 0.0;
    viewMtx.M[0][2] = 0.0;
    viewMtx.M[0][3] = 0.0;
    viewMtx.M[1][0] = 0.0;
    viewMtx.M[1][2] = 0.0;
    viewMtx.M[1][3] = 0.0;
    Scaleform::Render::Scale9GridInfo::Scale9GridInfo(&v21, s9g, &viewMtx);
    x = v10.x1;
    y = v10.y1;
    x2 = v10.x2;
    v16 = v10.x2;
    y1 = v10.y1;
    y2 = v10.y2;
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &x, &y);
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &x2, &y1);
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &v16, &y2);
    viewMtx.M[0][0] = v10.x1;
    viewMtx.M[0][1] = v10.y1;
    viewMtx.M[0][2] = v10.x2;
    viewMtx.M[1][0] = v10.x2;
    viewMtx.M[0][3] = v10.y1;
    viewMtx.M[1][1] = v10.y2;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(mtx, (float *)&viewMtx, &x);
    Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
  }
}
