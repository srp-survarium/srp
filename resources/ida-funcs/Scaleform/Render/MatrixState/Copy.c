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
  memcpy((unsigned __int8 *)&outmat->View3D, (unsigned __int8 *)&inmat->View3D, sizeof(outmat->View3D));
  memcpy((unsigned __int8 *)&outmat->Proj3D, (unsigned __int8 *)&inmat->Proj3D, sizeof(outmat->Proj3D));
  memcpy((unsigned __int8 *)&outmat->Proj3DLeft, (unsigned __int8 *)&inmat->Proj3DLeft, sizeof(outmat->Proj3DLeft));
  memcpy((unsigned __int8 *)&outmat->Proj3DRight, (unsigned __int8 *)&inmat->Proj3DRight, 0xA0u);
  memcpy((unsigned __int8 *)&outmat->Orient3D, (unsigned __int8 *)&inmat->Orient3D, sizeof(outmat->Orient3D));
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
  memcpy((unsigned __int8 *)&outmat->UVPO, (unsigned __int8 *)&inmat->UVPO, sizeof(outmat->UVPO));
  memcpy(
    (unsigned __int8 *)&outmat->ViewRectCompensated3D,
    (unsigned __int8 *)&inmat->ViewRectCompensated3D,
    sizeof(outmat->ViewRectCompensated3D));
  outmat->UVPOChanged = 1;
  outmat->OrientationSet = inmat->OrientationSet;
  outmat->S3DParams = inmat->S3DParams;
  outmat->S3DDisplay = inmat->S3DDisplay;
  outmat->pHAL = inmat->pHAL;
}
