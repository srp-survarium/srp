void __thiscall Scaleform::Render::DICommand_Merge::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_Merge *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  int v4; // ebx
  float *v5; // esi
  _DWORD *v6; // ecx
  unsigned int RedMultiplier; // eax
  double v8; // st7
  unsigned int v9; // eax
  double v10; // st6
  unsigned int v11; // eax
  double v12; // st6
  unsigned int v13; // eax
  double v14; // st6
  int v15; // eax
  float *v16; // ecx
  double v17; // st6
  Scaleform::Render::DICommand_Merge *v18; // [esp+Ch] [ebp-94h]
  float v19[4]; // [esp+10h] [ebp-90h]
  _BYTE v20[40]; // [esp+20h] [ebp-80h] BYREF
  char v21; // [esp+48h] [ebp-58h] BYREF
  char v22; // [esp+60h] [ebp-40h] BYREF

  v18 = this;
  v4 = 1;
  v5 = (float *)&v21;
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
  v6 = &v18->__vftable;
  RedMultiplier = v18->RedMultiplier;
  if ( RedMultiplier >= 0x100 )
    RedMultiplier = 256;
  v18 = (Scaleform::Render::DICommand_Merge *)RedMultiplier;
  v8 = (double)RedMultiplier;
  v9 = v6[10];
  v19[0] = v8 * 0.00390625;
  if ( v9 >= 0x100 )
    v9 = 256;
  v18 = (Scaleform::Render::DICommand_Merge *)v9;
  v10 = (double)v9;
  v11 = v6[11];
  v19[1] = v10 * 0.00390625;
  if ( v11 >= 0x100 )
    v11 = 256;
  v18 = (Scaleform::Render::DICommand_Merge *)v11;
  v12 = (double)v11;
  v13 = v6[12];
  v19[2] = v12 * 0.00390625;
  if ( v13 >= 0x100 )
    v13 = 256;
  v18 = (Scaleform::Render::DICommand_Merge *)v13;
  v14 = (double)v13;
  v15 = 0;
  v16 = (float *)&v22;
  v19[3] = 0.00390625 * v14;
  do
  {
    v17 = v19[v15++];
    v16 += 5;
    *(v16 - 21) = 1.0 - v17;
    *(v16 - 5) = v19[v15 - 1];
  }
  while ( v15 < 4 );
  context->pHAL->DrawableMerge(context->pHAL, tex, texgen, (const Scaleform::Render::Matrix4x4<float> *)v20);
}
