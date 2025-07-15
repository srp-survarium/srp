void __thiscall Scaleform::Render::DICommand_CopyChannel::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_CopyChannel *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  int v4; // ebx
  float *v5; // esi
  int v6; // esi
  int v7; // edi
  Scaleform::Render::DrawableImage *pObject; // eax
  float v10[10]; // [esp+10h] [ebp-80h] BYREF
  char v11; // [esp+38h] [ebp-58h] BYREF
  float v12[16]; // [esp+50h] [ebp-40h] BYREF

  v4 = 1;
  v5 = (float *)&v11;
  do
  {
    memset((int)(v5 - 10), 0, 64);
    *(v5 - 10) = 1.0;
    *(v5 - 5) = 1.0;
    *v5 = 1.0;
    v5[5] = 1.0;
    v5 += 16;
    --v4;
  }
  while ( v4 >= 0 );
  v6 = 0;
  v7 = 0;
  switch ( this->DestChannel )
  {
    case Channel_Red:
      v6 = 0;
      break;
    case Channel_Green:
      v6 = 1;
      break;
    case Channel_Blue:
      v6 = 2;
      break;
    case Channel_Alpha:
      v6 = 3;
      break;
    default:
      break;
  }
  switch ( this->SourceChannel )
  {
    case Channel_Red:
      v7 = 0;
      break;
    case Channel_Green:
      v7 = 1;
      break;
    case Channel_Blue:
      v7 = 2;
      break;
    case Channel_Alpha:
      v7 = 3;
      break;
    default:
      break;
  }
  v10[5 * v6] = 0.0;
  memset((int)v12, 0, sizeof(v12));
  pObject = this->pImage.pObject;
  v12[4 * v6 + v7] = 1.0;
  Scaleform::Render::HAL::applyBlendMode(
    context->pHAL,
    (Scaleform::Render::BlendMode)(pObject->Transparent + 15),
    1,
    (Scaleform::String::DataDesc *)1);
  context->pHAL->DrawableCopyChannel(context->pHAL, tex, texgen, (const Scaleform::Render::Matrix4x4<float> *)v10);
}
