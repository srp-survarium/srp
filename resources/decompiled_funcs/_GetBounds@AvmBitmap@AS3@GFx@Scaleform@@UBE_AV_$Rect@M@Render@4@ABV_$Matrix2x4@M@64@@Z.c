Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::AS3::AvmBitmap::GetBounds(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  double v3; // st7
  Scaleform::GFx::ImageResource *pObject; // eax
  double v6; // st6
  Scaleform::GFx::ImageResource *v7; // ecx
  int v8; // eax
  float v10; // [esp+B8h] [ebp-58h]
  float v11; // [esp+B8h] [ebp-58h]
  float v12; // [esp+BCh] [ebp-54h]
  Scaleform::Render::Rect<float> pr; // [esp+C0h] [ebp-50h] BYREF
  int v14; // [esp+D0h] [ebp-40h] BYREF
  int v15; // [esp+D4h] [ebp-3Ch]
  float v16; // [esp+D8h] [ebp-38h]
  float v17; // [esp+DCh] [ebp-34h]
  Scaleform::Render::Rect<float> v18; // [esp+E0h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v19; // [esp+F0h] [ebp-20h] BYREF

  v3 = 0.0;
  pr.x1 = 0.0;
  pObject = this->pImage.pObject;
  pr.y1 = 0.0;
  v6 = 0.0;
  v10 = 0.0 + 0.0;
  pr.x2 = v10;
  pr.y2 = v10;
  if ( pObject )
  {
    pObject->pImage->GetRect(pObject->pImage, (Scaleform::Render::Rect<unsigned long> *)&v14);
    v7 = this->pImage.pObject;
    v19.M[0][0] = 1.0;
    v19.M[0][1] = 0.0;
    v19.M[0][2] = 0.0;
    v19.M[0][3] = 0.0;
    v19.M[1][0] = 0.0;
    v19.M[1][2] = 0.0;
    v19.M[1][3] = 0.0;
    v19.M[1][1] = 1.0;
    v8 = (int)v7->pImage->GetAsImage(v7->pImage);
    if ( v8 )
    {
      (*(void (__thiscall **)(int, Scaleform::Render::Matrix2x4<float> *))(*(_DWORD *)v8 + 56))(v8, &v19);
      v18.x1 = (float)(unsigned int)(20 * v14);
      v18.y1 = (float)(unsigned int)(20 * v15);
      v18.x2 = (float)(unsigned int)(20 * LODWORD(v16));
      v18.y2 = (float)(unsigned int)(20 * LODWORD(v17));
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v19, &pr, (__m128 *)&v18);
    }
    else
    {
      v18.x1 = (float)(unsigned int)(20 * v14);
      v18.y1 = (float)(unsigned int)(20 * v15);
      v18.x2 = (float)(unsigned int)(20 * LODWORD(v16));
      v18.y2 = (float)(unsigned int)(20 * LODWORD(v17));
      pr.x1 = v18.x1;
      pr.y1 = v18.y1;
      pr.x2 = v18.x2;
      pr.y2 = v18.y2;
    }
    v3 = 0.0;
    v6 = 0.0;
  }
  v11 = pr.x2 - pr.x1;
  v12 = pr.y2 - pr.y1;
  v18.x1 = v3;
  v18.y1 = v18.x1;
  v18.x2 = v11 + v6;
  v18.y2 = v6 + v12;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, (__m128 *)&v18);
  return result;
}
