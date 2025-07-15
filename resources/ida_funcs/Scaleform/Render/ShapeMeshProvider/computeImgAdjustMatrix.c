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
  char v9; // [esp+1145h] [ebp-271h]
  Scaleform::Render::Rect<float> v10; // [esp+1146h] [ebp-270h] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [esp+1156h] [ebp-260h] BYREF
  float x; // [esp+1182h] [ebp-234h] BYREF
  float y; // [esp+1186h] [ebp-230h] BYREF
  float x2; // [esp+118Ah] [ebp-22Ch] BYREF
  float y1; // [esp+118Eh] [ebp-228h] BYREF
  float v16; // [esp+1192h] [ebp-224h] BYREF
  float y2; // [esp+1196h] [ebp-220h] BYREF
  _DWORD v18[3]; // [esp+119Ah] [ebp-21Ch] BYREF
  Scaleform::Render::ShapePosInfo v19; // [esp+11A6h] [ebp-210h] BYREF
  float v20[6]; // [esp+11DEh] [ebp-1D8h] BYREF
  Scaleform::Render::Scale9GridInfo v21; // [esp+11F6h] [ebp-1C0h] BYREF

  StartPos = this->DrawLayers.Data.Data[drawLayer].StartPos;
  v19.Sfactor = 1.0;
  pObject = this->pShapeData.pObject;
  v10.x1 = 1.0e30;
  v10.y1 = 1.0e30;
  v19.Pos = StartPos;
  v10.x2 = -1.0e30;
  v10.y2 = -1.0e30;
  trans.M[0][0] = 1.0;
  memset(&v19.StartX, 0, 44);
  trans.M[0][1] = 0.0;
  trans.M[0][2] = 0.0;
  trans.M[0][3] = 0.0;
  trans.M[1][0] = 0.0;
  trans.M[1][2] = 0.0;
  trans.M[1][3] = 0.0;
  trans.M[1][1] = 1.0;
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
        COERCE_FLOAT(&trans),
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
    trans.M[0][0] = 1.0;
    trans.M[1][1] = 1.0;
    trans.M[0][1] = 0.0;
    trans.M[0][2] = 0.0;
    trans.M[0][3] = 0.0;
    trans.M[1][0] = 0.0;
    trans.M[1][2] = 0.0;
    trans.M[1][3] = 0.0;
    Scaleform::Render::Scale9GridInfo::Scale9GridInfo(&v21, s9g, &trans);
    x = v10.x1;
    y = v10.y1;
    x2 = v10.x2;
    v16 = v10.x2;
    y1 = v10.y1;
    y2 = v10.y2;
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &x, &y);
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &x2, &y1);
    Scaleform::Render::Scale9GridInfo::Transform(&v21, &v16, &y2);
    trans.M[0][0] = v10.x1;
    trans.M[0][1] = v10.y1;
    trans.M[0][2] = v10.x2;
    trans.M[1][0] = v10.x2;
    trans.M[0][3] = v10.y1;
    trans.M[1][1] = v10.y2;
    Scaleform::Render::Matrix2x4<float>::SetParlToParl(mtx, (const float *)&trans, &x);
    Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
  }
}
