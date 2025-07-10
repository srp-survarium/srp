void __thiscall Scaleform::Render::DICommand_CopyPixels::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_CopyPixels *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::Matrix2x4<float> m2; // [esp+2Ch] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> m1; // [esp+4Ch] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+6Ch] [ebp-20h] BYREF

  m2.M[0][0] = 1.0;
  m2.M[0][1] = 0.0;
  m2.M[0][2] = 0.0;
  m2.M[0][3] = -0.5;
  m2.M[1][3] = -0.5;
  m2.M[1][0] = 0.0;
  m2.M[1][2] = 0.0;
  m2.M[1][1] = 1.0;
  m1.M[0][0] = 2.0;
  m1.M[0][1] = 0.0;
  m1.M[0][2] = 0.0;
  m1.M[0][3] = 0.0;
  m1.M[1][0] = 0.0;
  m1.M[1][1] = -2.0;
  m1.M[1][2] = 0.0;
  m1.M[1][3] = 0.0;
  Scaleform::Render::operator*(&result, &m1, &m2);
  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)(this->pImage.pObject->Transparent + 15),
    1,
    (Scaleform::String::DataDesc *)1);
  context->pHAL->DrawableCopyPixels(
    context->pHAL,
    tex,
    texgen,
    &result,
    this->MergeAlpha,
    this->pImage.pObject->Transparent);
}
