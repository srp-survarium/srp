void __thiscall Scaleform::Render::DICommand_ColorTransform::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_ColorTransform *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::DrawableImage *pObject; // eax
  float v6; // [esp+50h] [ebp-24h]
  float v7[8]; // [esp+54h] [ebp-20h] BYREF

  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)(this->pImage.pObject->Transparent + 15),
    1,
    (Scaleform::String::DataDesc *)1);
  pObject = this->pImage.pObject;
  qmemcpy(v7, &this->Cx, sizeof(v7));
  if ( !pObject->Transparent )
  {
    v6 = v7[7] + v7[3];
    v7[0] = v7[0] * v6;
    v7[4] = v7[4] * v6;
    v7[1] = v7[1] * v6;
    v7[5] = v7[5] * v6;
    v7[2] = v7[2] * v6;
    v7[6] = v6 * v7[6];
    v7[3] = 1.0;
    v7[7] = 0.0;
  }
  context->pHAL->DrawableCxform(context->pHAL, tex + 1, &texgen[1], (const Scaleform::Render::Cxform *)v7);
}
