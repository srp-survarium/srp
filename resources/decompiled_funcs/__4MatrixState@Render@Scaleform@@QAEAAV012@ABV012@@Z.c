Scaleform::Render::MatrixState *__usercall Scaleform::Render::MatrixState::operator=@<eax>(
        Scaleform::Render::MatrixState *this@<esi>,
        const Scaleform::Render::MatrixState *__that@<edi>)
{
  int y2; // eax
  int x2; // ecx
  int x1; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // ebx

  this->View2D = __that->View2D;
  memcpy((unsigned __int8 *)&this->View3D, (unsigned __int8 *)&__that->View3D, sizeof(this->View3D));
  memcpy((unsigned __int8 *)&this->Proj3D, (unsigned __int8 *)&__that->Proj3D, sizeof(this->Proj3D));
  memcpy((unsigned __int8 *)&this->Proj3DLeft, (unsigned __int8 *)&__that->Proj3DLeft, sizeof(this->Proj3DLeft));
  memcpy((unsigned __int8 *)&this->Proj3DRight, (unsigned __int8 *)&__that->Proj3DRight, 0xA0u);
  memcpy((unsigned __int8 *)&this->Orient3D, (unsigned __int8 *)&__that->Orient3D, sizeof(this->Orient3D));
  y2 = __that->ViewRectOriginal.y2;
  x2 = __that->ViewRectOriginal.x2;
  x1 = __that->ViewRectOriginal.x1;
  this->ViewRectOriginal.y1 = __that->ViewRectOriginal.y1;
  this->ViewRectOriginal.x2 = x2;
  this->ViewRectOriginal.x1 = x1;
  this->ViewRectOriginal.y2 = y2;
  v5 = __that->ViewRect.x2;
  v6 = __that->ViewRect.y2;
  v7 = __that->ViewRect.x1;
  this->ViewRect.y1 = __that->ViewRect.y1;
  this->ViewRect.x2 = v5;
  this->ViewRect.x1 = v7;
  this->ViewRect.y2 = v6;
  this->UserView = __that->UserView;
  memcpy((unsigned __int8 *)&this->UVPO, (unsigned __int8 *)&__that->UVPO, sizeof(this->UVPO));
  memcpy((unsigned __int8 *)&this->ViewRectCompensated3D, (unsigned __int8 *)&__that->ViewRectCompensated3D, 0x42u);
  this->S3DParams = __that->S3DParams;
  this->S3DDisplay = __that->S3DDisplay;
  this->pHAL = __that->pHAL;
  return this;
}
