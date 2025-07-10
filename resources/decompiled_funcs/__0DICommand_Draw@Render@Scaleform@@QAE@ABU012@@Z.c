void __thiscall Scaleform::Render::DICommand_Draw::DICommand_Draw(
        Scaleform::Render::DICommand_Draw *this,
        const Scaleform::Render::DICommand_Draw *__that)
{
  Scaleform::Render::DrawableImage *pObject; // ecx
  int y2; // eax
  int y1; // edx
  int x2; // ecx

  this->__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand::`vftable';
  pObject = __that->pImage.pObject;
  if ( pObject )
    pObject->AddRef(pObject);
  this->pImage.pObject = __that->pImage.pObject;
  this->__vftable = (Scaleform::Render::DICommand_Draw_vtbl *)&Scaleform::Render::DICommand_Draw::`vftable';
  this->pRoot = __that->pRoot;
  y2 = __that->ClipRect.y2;
  y1 = __that->ClipRect.y1;
  x2 = __that->ClipRect.x2;
  this->ClipRect.x1 = __that->ClipRect.x1;
  this->ClipRect.y2 = y2;
  this->ClipRect.y1 = y1;
  this->ClipRect.x2 = x2;
  this->HasClipRect = __that->HasClipRect;
}
