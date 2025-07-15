Scaleform::Render::MatrixState *__thiscall Scaleform::Render::MatrixState::operator=(
        Scaleform::Render::MatrixState *this,
        const Scaleform::Render::MatrixState *__that,
        int a3)
{
  Scaleform::Render::Matrix2x4<float>::SetMatrix(
    &__that->View2D,
    (const Scaleform::Render::Matrix2x4<float> *)(a3 + 16));
  memcpy((unsigned __int8 *)&__that->View3D, (unsigned __int8 *)(a3 + 48), sizeof(__that->View3D));
  memcpy((unsigned __int8 *)&__that->Proj3D, (unsigned __int8 *)(a3 + 96), sizeof(__that->Proj3D));
  memcpy((unsigned __int8 *)&__that->Proj3DLeft, (unsigned __int8 *)(a3 + 160), sizeof(__that->Proj3DLeft));
  memcpy((unsigned __int8 *)&__that->Proj3DRight, (unsigned __int8 *)(a3 + 224), sizeof(__that->Proj3DRight));
  Scaleform::Render::Matrix2x4<float>::SetMatrix(&__that->User, (const Scaleform::Render::Matrix2x4<float> *)(a3 + 288));
  Scaleform::Render::Matrix2x4<float>::SetMatrix(
    &__that->User3D,
    (const Scaleform::Render::Matrix2x4<float> *)(a3 + 320));
  Scaleform::Render::Matrix2x4<float>::SetMatrix(
    &__that->Orient2D,
    (const Scaleform::Render::Matrix2x4<float> *)(a3 + 352));
  memcpy((unsigned __int8 *)&__that->Orient3D, (unsigned __int8 *)(a3 + 384), sizeof(__that->Orient3D));
  Scaleform::Render::Rect<int>::SetRect(&__that->ViewRectOriginal, (const Scaleform::Render::Rect<int> *)(a3 + 448));
  Scaleform::Render::Rect<int>::SetRect(&__that->ViewRect, (const Scaleform::Render::Rect<int> *)(a3 + 464));
  Scaleform::Render::Matrix2x4<float>::SetMatrix(
    &__that->UserView,
    (const Scaleform::Render::Matrix2x4<float> *)(a3 + 480));
  memcpy((unsigned __int8 *)&__that->UVPO, (unsigned __int8 *)(a3 + 512), sizeof(__that->UVPO));
  memcpy((unsigned __int8 *)&__that->ViewRectCompensated3D, (unsigned __int8 *)(a3 + 576), 0x42u);
  qmemcpy(&__that->S3DParams, (const void *)(a3 + 644), 0x1Cu);
  return (Scaleform::Render::MatrixState *)__that;
}
