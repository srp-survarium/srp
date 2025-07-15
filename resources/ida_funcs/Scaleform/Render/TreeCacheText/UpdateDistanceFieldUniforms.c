void __thiscall Scaleform::Render::TreeCacheText::UpdateDistanceFieldUniforms(Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v3; // edx
  int v4; // esi
  double v5; // st7
  double v6; // st7
  float Offseta; // [esp+4h] [ebp-44h]
  float Offsetb; // [esp+4h] [ebp-44h]
  float Offset; // [esp+4h] [ebp-44h]
  float Offsetc; // [esp+4h] [ebp-44h]
  Scaleform::Render::DistFieldUniforms data; // [esp+8h] [ebp-40h] BYREF

  if ( (this->TMProvider.Flags & 0x200) != 0 )
  {
    pNode = this->pNode;
    data.Width = 9.0;
    data.ShadowWidth = 0.0;
    data.ShadowOffset[3] = 0.0;
    data.ShadowOffset[2] = 0.0;
    data.ShadowOffset[1] = 0.0;
    data.ShadowOffset[0] = 0.0;
    data.ShadowEnable = 0.0;
    v3 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                   + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                   + 20)
       & 0xFFFFFFFE;
    v4 = *(_DWORD *)(v3 + 144) + 168;
    if ( *(float *)(*(_DWORD *)(v3 + 144) + 196) > 0.0 )
    {
      data.ShadowEnable = 1.0;
      Offseta = *(float *)(v4 + 28) * 0.05000000074505806;
      v5 = Offseta;
      if ( Offseta > 3.0 )
        v5 = 3.0;
      Offsetb = v5;
      data.ShadowWidth = Offsetb * 18.0;
      data.ShadowOffset[0] = *(float *)(v4 + 36) * -0.05000000074505806;
      data.ShadowOffset[1] = -0.05000000074505806 * *(float *)(v4 + 40);
      Offset = data.ShadowOffset[1] * data.ShadowOffset[1] + data.ShadowOffset[0] * data.ShadowOffset[0];
      if ( Offset > 4.0 )
      {
        Offsetc = sqrt(Offset);
        v6 = 2.0 / Offsetc;
        data.ShadowOffset[0] = data.ShadowOffset[0] * v6;
        data.ShadowOffset[1] = v6 * data.ShadowOffset[1];
      }
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)(v4 + 48), data.ShadowColor);
    }
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(&this->M, (unsigned __int8 *)&data, 0x40u);
  }
}
