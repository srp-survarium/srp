void __thiscall Scaleform::Render::TreeCacheText::UpdateDistanceFieldUniforms(Scaleform::Render::TreeCacheText *this)
{
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v3; // edx
  int v4; // esi
  double v5; // st7
  double v6; // st7
  float v7; // [esp+4h] [ebp-44h]
  float v8; // [esp+4h] [ebp-44h]
  float v9; // [esp+4h] [ebp-44h]
  float v10; // [esp+4h] [ebp-44h]
  __m128i prgba; // [esp+8h] [ebp-40h] BYREF
  float v12; // [esp+18h] [ebp-30h]
  float v13; // [esp+28h] [ebp-20h]
  float v14; // [esp+2Ch] [ebp-1Ch]
  float v15; // [esp+30h] [ebp-18h]
  float v16; // [esp+34h] [ebp-14h]
  float v17; // [esp+38h] [ebp-10h]
  float v18; // [esp+44h] [ebp-4h]

  if ( (this->TMProvider.Flags & 0x200) != 0 )
  {
    pNode = this->pNode;
    v18 = 9.0;
    v17 = 0.0;
    v16 = 0.0;
    v15 = 0.0;
    v14 = 0.0;
    v13 = 0.0;
    v12 = 0.0;
    v3 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                   + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28)
                   + 20)
       & 0xFFFFFFFE;
    v4 = *(_DWORD *)(v3 + 144) + 168;
    if ( *(float *)(*(_DWORD *)(v3 + 144) + 196) > 0.0 )
    {
      v12 = 1.0;
      v7 = *(float *)(v4 + 28) * 0.05000000074505806;
      v5 = v7;
      if ( v7 > 3.0 )
        v5 = 3.0;
      v8 = v5;
      v17 = v8 * 18.0;
      v13 = *(float *)(v4 + 36) * -0.05000000074505806;
      v14 = -0.05000000074505806 * *(float *)(v4 + 40);
      v9 = v14 * v14 + v13 * v13;
      if ( v9 > 4.0 )
      {
        v10 = sqrt(v9);
        v6 = 2.0 / v10;
        v13 = v13 * v6;
        v14 = v6 * v14;
      }
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)(v4 + 48), (float *)prgba.m128i_i32);
    }
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(&this->M, &prgba, 0x40u);
  }
}
