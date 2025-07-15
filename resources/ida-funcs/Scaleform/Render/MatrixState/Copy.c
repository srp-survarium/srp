void __cdecl Scaleform::Render::MatrixState::Copy(
        Scaleform::Render::MatrixState *outmat,
        Scaleform::Render::MatrixState *inmat)
{
  int y2; // eax
  int x2; // ecx
  int x1; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // ebx

  outmat->View2D = inmat->View2D;
  memcpy((int)&outmat->View3D, (const __m128i *)&inmat->View3D, sizeof(outmat->View3D));
  memcpy((int)&outmat->Proj3D, (const __m128i *)&inmat->Proj3D, sizeof(outmat->Proj3D));
  memcpy((int)&outmat->Proj3DLeft, (const __m128i *)&inmat->Proj3DLeft, sizeof(outmat->Proj3DLeft));
  memcpy((int)&outmat->Proj3DRight, (const __m128i *)&inmat->Proj3DRight, 0xA0u);
  memcpy((int)&outmat->Orient3D, (const __m128i *)&inmat->Orient3D, sizeof(outmat->Orient3D));
  y2 = inmat->ViewRectOriginal.y2;
  x2 = inmat->ViewRectOriginal.x2;
  x1 = inmat->ViewRectOriginal.x1;
  outmat->ViewRectOriginal.y1 = inmat->ViewRectOriginal.y1;
  outmat->ViewRectOriginal.x2 = x2;
  outmat->ViewRectOriginal.x1 = x1;
  outmat->ViewRectOriginal.y2 = y2;
  v5 = inmat->ViewRect.x2;
  v6 = inmat->ViewRect.y2;
  v7 = inmat->ViewRect.x1;
  outmat->ViewRect.y1 = inmat->ViewRect.y1;
  outmat->ViewRect.x2 = v5;
  outmat->ViewRect.x1 = v7;
  outmat->ViewRect.y2 = v6;
  outmat->UserView = inmat->UserView;
  memcpy((int)&outmat->UVPO, (const __m128i *)&inmat->UVPO, sizeof(outmat->UVPO));
  memcpy(
    (int)&outmat->ViewRectCompensated3D,
    (const __m128i *)&inmat->ViewRectCompensated3D,
    sizeof(outmat->ViewRectCompensated3D));
  outmat->UVPOChanged = 1;
  outmat->OrientationSet = inmat->OrientationSet;
  outmat->S3DParams = inmat->S3DParams;
  outmat->S3DDisplay = inmat->S3DDisplay;
  outmat->pHAL = inmat->pHAL;
}
