char __thiscall Scaleform::Render::MeshKey::Match(
        Scaleform::Render::MeshKey *this,
        unsigned int layer,
        unsigned int flags,
        const float *keyData,
        const Scaleform::Render::ToleranceParams *cfg)
{
  char v5; // dl
  unsigned int v8; // edx
  float *Data; // esi
  const Scaleform::Render::ToleranceParams *v10; // ebp
  unsigned int v11; // edi
  float *v12; // esi
  float *v13; // edx
  unsigned int v14; // edx
  float *p_pMesh; // edi
  float *v16; // esi
  unsigned int v17; // edx
  float *v18; // esi
  unsigned int v19; // edx
  float *v20; // esi
  unsigned int v21; // edx
  float *v22; // esi
  float v23; // [esp+8h] [ebp+4h]
  float FillUpperScale; // [esp+Ch] [ebp+8h]
  float StrokeUpperScale; // [esp+Ch] [ebp+8h]
  float v26; // [esp+10h] [ebp+Ch]
  float FillLowerScale; // [esp+14h] [ebp+10h]
  float StrokeLowerScale; // [esp+14h] [ebp+10h]

  v5 = flags;
  if ( flags != this->Flags || layer != this->pMesh.pObject->Layer )
    return 0;
  if ( (flags & 0x8000) != 0 )
    return 1;
  if ( (flags & 0x10) != 0 )
  {
    v8 = 0;
    Data = this->Data;
    while ( *Data == keyData[v8] )
    {
      ++v8;
      ++Data;
      if ( v8 >= 8 )
      {
        v10 = cfg;
        v11 = 0;
        v12 = (float *)&this[2];
        v13 = (float *)(keyData + 8);
        while ( *v12 * cfg->Scale9LowerScale <= *v13 && cfg->Scale9UpperScale * *v12 >= *v13 )
        {
          ++v11;
          ++v13;
          ++v12;
          if ( v11 >= 3 )
          {
            v14 = 0;
            p_pMesh = (float *)&this[2].pMesh;
            v16 = (float *)(keyData + 11);
            while ( *p_pMesh == *v16 )
            {
              ++v14;
              ++v16;
              ++p_pMesh;
              if ( v14 >= 2 )
                goto LABEL_38;
            }
            return 0;
          }
        }
        return 0;
      }
    }
  }
  else
  {
    v10 = cfg;
    FillLowerScale = cfg->FillLowerScale;
    FillUpperScale = v10->FillUpperScale;
    if ( (v5 & 0x40) == 0 || v5 < 0 )
    {
      FillLowerScale = v10->FillAliasedLowerScale;
      FillUpperScale = v10->FillAliasedUpperScale;
    }
    switch ( v5 & 7 )
    {
      case 1:
        v21 = 0;
        v22 = this->Data;
        while ( *v22 * FillLowerScale <= keyData[v21] && *v22 * FillUpperScale >= keyData[v21] )
        {
          ++v21;
          ++v22;
          if ( v21 >= 3 )
            goto LABEL_38;
        }
        break;
      case 2:
        StrokeLowerScale = v10->StrokeLowerScale;
        StrokeUpperScale = v10->StrokeUpperScale;
        if ( (v5 & 0x20) != 0 )
        {
          v23 = *(float *)&this[1].pPrev * *keyData;
          v26 = keyData[1] * this->Data[0];
          if ( keyData[2] >= *(float *)&this[1].pNext * 0.9990000128746033
            && keyData[2] <= *(float *)&this[1].pNext * 1.001000046730042
            && 0.9990000128746033 * v26 <= v23
            && 1.001000046730042 * v26 >= v23 )
          {
            StrokeLowerScale = v10->FillLowerScale;
            StrokeUpperScale = v10->FillUpperScale;
          }
        }
        v19 = 0;
        v20 = this->Data;
        while ( *v20 * StrokeLowerScale <= keyData[v19] && *v20 * StrokeUpperScale >= keyData[v19] )
        {
          ++v19;
          ++v20;
          if ( v19 >= 3 )
            goto LABEL_38;
        }
        break;
      case 3:
        v17 = 0;
        v18 = this->Data;
        while ( v10->HintedStrokeLowerScale * *v18 <= keyData[v17] && v10->HintedStrokeUpperScale * *v18 >= keyData[v17] )
        {
          ++v17;
          ++v18;
          if ( v17 >= 3 )
            goto LABEL_38;
        }
        break;
      default:
LABEL_38:
        if ( (1.0 - v10->MorphTolerance) * *((float *)&this->UseCount + this->Size) <= keyData[this->Size - 1]
          && keyData[this->Size - 1] <= (v10->MorphTolerance + 1.0) * *((float *)&this->UseCount + this->Size) )
        {
          return 1;
        }
        break;
    }
  }
  return 0;
}
