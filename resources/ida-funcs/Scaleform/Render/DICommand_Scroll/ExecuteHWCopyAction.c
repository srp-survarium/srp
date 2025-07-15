void __thiscall Scaleform::Render::DICommand_Scroll::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::HAL *pHAL; // ecx
  float (__thiscall *GetViewportScaling)(Scaleform::Render::HAL *); // edx
  double v7; // st7
  Scaleform::Render::Matrix2x4<float> m2; // [esp+Ch] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> m1; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+4Ch] [ebp-20h] BYREF

  m2.M[0][0] = 1.0;
  m2.M[0][1] = 0.0;
  pHAL = context->pHAL;
  m2.M[0][2] = 0.0;
  GetViewportScaling = pHAL->GetViewportScaling;
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
  v7 = ((double (__thiscall *)(Scaleform::Render::HAL *))GetViewportScaling)(pHAL);
  m1.M[1][1] = v7 + v7;
  m1.M[1][2] = 0.0;
  m1.M[1][3] = 0.0;
  Scaleform::Render::operator*(&result, &m1, &m2);
  context->pHAL->DrawableCopyback(context->pHAL, *tex, &result, &texgen[1]);
  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)(this->pImage.pObject->Transparent + 15),
    1,
    (Scaleform::String::DataDesc *)1);
}
